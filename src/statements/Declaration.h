/*
 * Copyright (c) 2010-2013 <Joseph Babb, Michael Cassollary, Joohyung Lee>
 *
 * For information on how to contact the authors, please visit
 *	http://reasoning.eas.asu.edu/cplus2asp
 *
 * This file is part of the cplus2asp system.
 *
 * cplus2asp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * cplus2asp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <list>

#include <boost/type_traits/is_base_of.hpp>
#include <boost/static_assert.hpp>
#include <boost/iterator/iterator_facade.hpp>

#include "config.h"		// autoheader header

#include "statements/Statement.h"
#include "Location.h"

#include "elements/Binding.h"
#include "elements/Identifier_base.h"

namespace cplus_parser {

/**
 * @brief The various kinds of declarations that occur.
 */
enum DeclarationType {
	DECL_CONSTANT,			///< A declaration of 1 or more constant identifiers.
	DECL_VARIABLE,			///< A declaration of 1 or more variable identifiers.
	DECL_SORT,				///< A declaration of 1 or more sort identifiers.
	DECL_OBJECT				///< A declaration of 1 or more object identifiers.
};


/**
 * @brief A statement representing a declaration of various identifiers.
 */
template<typename pelem_base_t>
class Declaration : public Statement<pelem_base_t> 
{


	BOOST_STATIC_ASSERT_MSG(
		(boost::is_base_of<ParseElement_base, pelem_base_t>::value),
		"pelem_base_t must be a descendant of ParseElement_base"
	);

public:
	/**************************************************************************/
	/* Types */
	/**************************************************************************/

	/**
	 * @brief A single identifier's declaration.
	 */
	struct IdentifierDecl {
		Binder* binder;									///< The binder specifying identifier information.
		Identifier_base<pelem_base_t>* identifier;		///< The identifier being bound by the binder.
	};

public:

	/**
	 * @brief An iterator used to access each individual declaration.
	 * Note: Dereferencing the iterator points to a temporary memory location that should not be saved.
	 */
	class const_iterator
		: public boost::iterator_facade<
			const_iterator, 
			IdentifierDecl const, 
			boost::forward_traversal_tag
		>
	{
		friend class boost::iterator_core_access;
	private:
		/******************************************************/
		/* Members */
		/******************************************************/
		typename std::list<Binding<pelem_base_t>*>::const_iterator mOuterIt;			///< The outer iterator.
		typename std::list<Identifier_base<pelem_base_t>*>::const_iterator mInnerIt;	///< The inner iterator.

		typename std::list<Binding<pelem_base_t>*>::const_iterator mOuterEnd;			///< The end of the outer iterator.

		IdentifierDecl mTempRef;											///< A temporary working space for each declaration.
		bool mSet;															///< Whether the temp working space is valid.	
	public:
		/******************************************************/
		/* Constructors / Destructors */
		/******************************************************/
		/**
		 * @brief Do not use. For internal purposes only.
		 */
		inline const_iterator() { /* Intentionally left blank */ }

		/**
		 * @brief Initializes the iterator and points it to an arbitrary position.
		 * @param outer The position of the outer iterator.
		 * @param inner The position of the inner iterator.
		 * @param outerBound The end of the outer iterator.
		 */
		const_iterator(
			typename std::list<Binding<pelem_base_t>*>::const_iterator const& outer, 
			typename Binding<pelem_base_t*>::const_iterator const& inner,
			typename std::list<Binding<pelem_base_t>*>::const_iterator const& outerBound);

		/**
		 * @brief Initializes the iterator to the position of the provided iterator.
		 * @param outer The position of the outer iterator.
		 * @param inner The position of the inner iterator.
		 */
		const_iterator(const_iterator const& other);


		/// Basic Destructor
		virtual inline ~const_iterator() { /* Intentionally left blank */ }

	private:
		/******************************************************/
		/* Core functionality */
		/******************************************************/
		/// See http://www.boost.org/doc/libs/1_53_0/libs/iterator/doc/iterator_facade.html#tutorial-example

		/**
		 * @brief Increments the position of the iterator.
		 * If the iterator is at the end, the position remains the same.
		 */
		void increment();

		/// Checks if two iterators point to the same entry by comparing their component iterators.
		inline bool equal(const_iterator const& other) { 
			return (mOuterIt == other.mOuterIt  && mInnerIt == other.mInnerIt)
				|| (mOuterIt == mOuterEnd && other.mOuterIt == other.mOuterEnd); // special case if both iterators are at the end.
		}

		/// Gets the entry the iterator points to.
		IdentifierDecl const& dereference() const { if (!mSet) set(); return mTempRef; }

		/**
		 * @brief updates the internal working area of the iterator with the current position.
		 */
		void set();
	};

private:

	/**************************************************************************/
	/* Members */
	/**************************************************************************/
	std::list<Binding<pelem_base_t>*>* mBinderList;			///< The list of all binder statements in the declaration.
	DeclarationType mType;									///< The type of identifier that this declaration is for.

public:
	/**************************************************************************/
	/* Constructors / Destructors*/
	/**************************************************************************/
	
	/**
	 * @brief Initializes the declaration.
	 * @param type The type of declaration that this object represents.
	 * @param loc The location of declaration.
	 * @param bindings A list of bindings that are included in this statement, or NULL to create an empty declaration statement.
	 * NOTE: The declaration takes ownership of the memory associated with the bindings list.
	 */
	inline Declaration(
		DeclarationType type, 
		Location const& loc, 
		std::list<Binding<pelem_base_t>*>* bindings = NULL)
		: Statement<pelem_base_t>(DECLARATION, loc), mType(type) { 
		if (bindings) mBinderList = bindings;
		else mBinderList = new std::list<Binding<pelem_base_t>*>();
	}

	inline ~Declaration() {
		size_t sz = mBinderList->size();
		for (; sz; sz--) { delete mBinderList->front(); mBinderList->pop_front(); }
	}


	/**************************************************************************/
	/* Accessors / Mutators */
	/**************************************************************************/
	/// Gets the type of declaration being represented.
	inline DeclarationType subtype() const { return mType; }

	/**
	 * @brief Gets an iterator corresponding to the beginning of the declaration list.
	 */
	inline const_iterator begin() const { 
		return new const_iterator(
			mBinderList->begin(), 
			(mBinderList->size) ? mBinderList->first->begin() : mBinderList->begin(),	// hacked iterator argument if this is an empty declaration.
			mBinderList->end()
		);
	}

	/**
	 * @brief Gets an iterator corresponding to the end of the declaration list.
	 */
	inline const_iterator end() const { 
		return new const_iterator(
			mBinderList->end(), 
			(mBinderList->size) ? mBinderList->first->end() : mBinderList->end(),	// hacked iterator argument if this is an empty declaration.
			mBinderList->end()
		);
	}

	/**
	 * @brief Adds a binding statement to the declaration.
	 * @param binding The binding to add to the declaration.
	 * NOTE:  This object takes ownership of the memory associated with binding.
	 */
	inline void add(Binding<pelem_base_t>* binding) { mBinderList->push_back(binding); }

};



}; /* end namespace cplus_parser */

// Include the implementation file
#include "statements/Declaration.impl.h"