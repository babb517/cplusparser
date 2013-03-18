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

#include <boost/type_traits/is_base_of.hpp>
#include <boost/static_assert.hpp>

#include "config.h"		// autoheader header


namespace cplus_parser {

/**
 * @brief A statement representing a variety of different causal laws.
 */
template<typename pelem_base_t>
class CausalLaw : public Statement<pelem_base_t> {

	BOOST_STATIC_ASSERT_MSG(
		(boost::is_base_of<ParseElement_base, pelem_base_t>::value),
		"pelem_base_t must be a descendant of ParseElement_base"
	);

public:
	/************************************************************/
	/* Types */
	/************************************************************/
	/**
	 * @brief A list of the different causal law forms.
	 */
	typedef enum {
		CL_CAUSED,							///< A basic causal law						'caused F if G ifcons G2 after H unless U when M following N where X'.
		CL_CAUSES,							///< A 'causes' shortcut law				'H causes F if G unless U when M where X'.
		CL_EXOGENOUS,						///< exogenous shortcut law					'exogenous c where X'.
		CL_INERTIAL,						///< inertial shortcut law					'inertial c where X'.
		CL_RIGID,							///< rigid shortcut law						'rigid c where X'.8
		CL_DEFAULT,							///< default shortcut law.					'default F where X'.
		CL_NONEXECUTABLE,					///< nonexecutable shortcut law				'nonexecutable F if G when M where X.
		CL_CONSTRAINT,						///< constraint shortcut law.				'constraint F after H unless U when M following N where X'.
		CL_NEVER,							///< never shortcut law.					'never F after H unless U when M following N where X'.
		CL_IMPOSSIBLE,						///< impossible shortcut law.				'impossible F after H unless U when M following N where X'.
		CL_ALWAYS,							///< always shortcut law.					'always F when M where X'.
		CL_MAY_CAUSE,						///< may cause shortcut law.				'H may cause F if G when M where X'.
		CL_POSSIBLY_CAUSED,					///< possibly caused shortcut law.			'possibly caused F if G ifcons G2 after H unless U when M following N where X'.
		CL_INCREMENTS,						///< increments additive causal law.		'H increments F by B if G when M where X'.	
		CL_DECREMENTS						///< decrements additive causal law.		'H decrements F by B if G when M where X'.

 	} CausalLawType;


private:
	/************************************************************/
	/* Members */
	/************************************************************/
	CausalLawType mType;				///< The type of causal law.
	pelem_base_t* mAction;				///< The action executed for the 'causes' style laws.
	pelem_base_t* mHead;				///< The head formula (or NULL for 'false').
	pelem_base_t* mBy;					///< The by body (or NULL).
	pelem_base_t* mIf;					///< The if body (or NULL).
	pelem_base_t* mIfcons;				///< The ifcons body (or NULL).
	pelem_base_t* mAfter;				///< The after body (or NULL).
	pelem_base_t* mUnless;				///< The unless body (or NULL).
	pelem_base_t* mWhen;				///< The when body (or NULL).
	pelem_base_t* mFollowing;			///< The following body (or NULL).
	pelem_base_t* mWhere;				///< The where body (or NULL).


public:
	/************************************************************/
	/* Constructors / Destructors */
	/************************************************************/
	/**
	 * @brief Basic Constructor.
	 * @param _type			The type of causal law which this object represents.
	 * @param _action		The action executed for the 'causes' style laws (or NULL).
	 * @param _head			The head formula (or NULL for 'false').
	 * @param _by			The by body (or NULL if N/A).
	 * @param _if			The if body (or NULL for top).
	 * @param _ifcons		The ifcons body (or NULL for top).
	 * @param _after		The after body (or NULL for top).
	 * @param _unless		The unless body (or NULL for bottom).
	 * @param _when			The when body (or NULL for top).
	 * @param _following	The following body (or NULL for top).
	 * @param _where		The where body (or NULL for top).
	 * NOTE: Takes ownership of each of the associated memory blocks. Their lifetimes become bound to this object.
	 */
	inline CausalLaw(
		CausalLawType _type,
		pelem_base_t* _action
		pelem_base_t* _head,
		pelem_base_t* _by,
		pelem_base_t* _if,
		pelem_base_t* _ifcons,
		pelem_base_t* _after,
		pelem_base_t* _unless,
		pelem_base_t* _when,
		pelem_base_t* _following,
		pelem_base_t* _where
		)
		: Statement<pelem_base_t>(CAUSAL_LAW), mType(_type), mAction(_action),
		mHead(_head), mBy(_by), mIf(_if), mIfcons(_ifCons), 
		mAfter(_after), mUnless(_unless), mWhen(_when), 
		mFollowing(_following), mWhere(_where)
	{ /* Intentionally Left Blank */ }

	/** 
	 * @brief Destructor
	 * Deallocates all memory associated with the object.
	 */
	inline virtual ~CausalLaw() {
		if (mAction) delete mAction;
		if (mHead) delete mHead;
		if (mBy) delete mBy;
		if (mIf) delete mIf;
		if (mIfCons) delete mIfCons;
		if (mAfter) delete mAfter;
		if (mUnless) delete mUnless;
		if (mWhen) delete mWhen;
		if (mFollowing) delete mFollowing;
		if (mWhere) delete mWhere;
	}

	/************************************************************/
	/* Accessors */
	/************************************************************/

	/// Gets the type of causal law being represented.
	inline CausalLawType subtype() const { return mType; }
	/// Basic accessor for the corresponding part of the law.
	inline pelem_base_t const* action() const { return mAction; }
	/// Basic accessor for the corresponding part of the law.
	inline pelem_base_t const* head() const { return mHead; }
	/// Basic accessor for the corresponding part of the law.
	inline pelem_base_t const* byBody() const { return mBy; }
	/// Basic accessor for the corresponding part of the law.
	inline pelem_base_t const* ifBody() const { return mIf; }
	/// Basic accessor for the corresponding part of the law.
	inline pelem_base_t const* ifconsBody() const { return mIfcons; }
	/// Basic accessor for the corresponding part of the law.
	inline pelem_base_t const* afterBody() const { return mAfter; }
	/// Basic accessor for the corresponding part of the law.
	inline pelem_base_t const* unlessBody() const { return mUnless; }
	/// Basic accessor for the corresponding part of the law.
	inline pelem_base_t const* whenBody() const { return mWhen; }
	/// Basic accessor for the corresponding part of the law.
	inline pelem_base_t const* followingBody() const { return mFollowing; }
	/// Basic accessor for the corresponding part of the law.
	inline pelem_base_t const* whereBody() const { return mWhere; }

	/************************************************************/
	/* Static Helpers */
	/************************************************************/

	/// Makes a 'caused' causal law.
	/// 'caused F if G ifcons G2 after H unless U when M following N where X'.
	template <typename pelem_base_t>
	static inline CausalLaw<pelem_base_t>* mkCaused(
		pelem_base_t* _head,
		pelem_base_t* _if,
		pelem_base_t* _ifcons,
		pelem_base_t* _after,
		pelem_base_t* _unless,
		pelem_base_t* _when,
		pelem_base_t* _following,
		pelem_base_t* _where
		)
	{ return new CausalLaw<pelem_base_t>(CL_CAUSED, NULL, _head, NULL, _if, _ifcons, _after, _unless, _when, _following, _where); }

	/// Makes a 'causes' causal law.
	/// 'H causes F if G unless U when M where X'.
	template <typename pelem_base_t>
	static inline CausalLaw<pelem_base_t>* mkCauses(
		pelem_base_t* _action,
		pelem_base_t* _head,
		pelem_base_t* _if,
		pelem_base_t* _when,
		pelem_base_t* _where
		)
	{ return new CausalLaw<pelem_base_t>(CL_CAUSES, _action, _head, NULL, _if, NULL, NULL, NULL, _when, NULL, _where); }

	/// Makes an 'exogenous' causal law.
	/// 'exogenous c where X'.
	template <typename pelem_base_t>
	static inline CausalLaw<pelem_base_t>* mkExogenous(
		pelem_base_t* _head,
		pelem_base_t* _where
		)
	{ return new CausalLaw<pelem_base_t>(CL_EXOGENOUS, NULL, _head, NULL, NULL, NULL, NULL, NULL, NULL, NULL, _where); }

	/// Makes an 'inertial' causal law.
	/// 'inertial c where X'.
	template <typename pelem_base_t>
	static inline CausalLaw<pelem_base_t>* mkInertial(
		pelem_base_t* _head,
		pelem_base_t* _where
		)
	{ return new CausalLaw<pelem_base_t>(CL_INERTIAL, NULL, _head, NULL, NULL, NULL, NULL, NULL, NULL, NULL, _where); }

	/// Makes a 'rigid' causal law.
	/// 'rigid c where X'.
	template <typename pelem_base_t>
	static inline CausalLaw<pelem_base_t>* mkRigid(
		pelem_base_t* _head,
		pelem_base_t* _where
		)
	{ return new CausalLaw<pelem_base_t>(CL_RIGID, NULL, _head, NULL, NULL, NULL, NULL, NULL, NULL, NULL, _where); }

	/// Makes a 'default' causal law.
	/// 'default F where X'.
	template <typename pelem_base_t>
	static inline CausalLaw<pelem_base_t>* mkDefault(
		pelem_base_t* _head,
		pelem_base_t* _where
		)
	{ return new CausalLaw<pelem_base_t>(CL_INERTIAL, NULL, _head, NULL, NULL, NULL, NULL, NULL, NULL, NULL, _where); }

	/// Makes a 'nonexecutable' causal law.
	/// 'nonexecutable F if G when M where X.
	template <typename pelem_base_t>
	static inline CausalLaw<pelem_base_t>* mkNonexecutable(
		pelem_base_t* _head,
		pelem_base_t* _if,
		pelem_base_t* _when,
		pelem_base_t* _where
		)
	{ return new CausalLaw<pelem_base_t>(CL_EXOGENOUS, NULL, _head, NULL, _if, NULL, NULL, NULL, _when, NULL, _where); }

	/// Makes a 'constraint' causal law.
	/// 'constraint F after H unless U when M following N where X'.
	template <typename pelem_base_t>
	static inline CausalLaw<pelem_base_t>* mkConstraint(
		pelem_base_t* _head,
		pelem_base_t* _after,
		pelem_base_t* _unless,
		pelem_base_t* _when,
		pelem_base_t* _following,
		pelem_base_t* _where
		)
	{ return new CausalLaw<pelem_base_t>(CL_CONSTRAINT, NULL, _head, NULL, NULL, NULL, _after, _unless, _when, _following, _where); }

	/// Makes a 'never' causal law.
	/// 'never F after H unless U when M following N where X'.
	template <typename pelem_base_t>
	static inline CausalLaw<pelem_base_t>* mkNever(
		pelem_base_t* _head,
		pelem_base_t* _after,
		pelem_base_t* _unless,
		pelem_base_t* _when,
		pelem_base_t* _following,
		pelem_base_t* _where
		)
	{ return new CausalLaw<pelem_base_t>(CL_NEVER, NULL, _head, NULL, NULL, NULL, _after, _unless, _when, _following, _where); }

	/// Makes an 'impossible' causal law.
	/// 'impossible F after H unless U when M following N where X'.
	template <typename pelem_base_t>
	static inline CausalLaw<pelem_base_t>* mkImpossible(
		pelem_base_t* _head,
		pelem_base_t* _after,
		pelem_base_t* _unless,
		pelem_base_t* _when,
		pelem_base_t* _following,
		pelem_base_t* _where
		)
	{ return new CausalLaw<pelem_base_t>(CL_IMPOSSIBLE, NULL, _head, NULL, NULL, NULL, _after, _unless, _when, _following, _where); }

	/// Makes an 'always' causal law.
	/// 'always F when M where X'.
	template <typename pelem_base_t>
	static inline CausalLaw<pelem_base_t>* mkAlways(
		pelem_base_t* _head,
		pelem_base_t* _when,
		pelem_base_t* _where
		)
	{ return new CausalLaw<pelem_base_t>(CL_ALWAYS, NULL, _head, NULL, NULL, NULL, NULL, NULL, _when, NULL, _where); }

	/*
		CL_INCREMENTS,						///< increments additive causal law.		
		CL_DECREMENTS						///< decrements additive causal law.		'H decrements F by B if G when M where X'.
	*/

	/// Makes a 'may cause' causal law.
	/// 'H may cause F if G when M where X'.
	template <typename pelem_base_t>
	static inline CausalLaw<pelem_base_t>* mkMayCause(
		pelem_base_t* _action,
		pelem_base_t* _head,
		pelem_base_t* _if,
		pelem_base_t* _when,
		pelem_base_t* _where
		)
	{ return new CausalLaw<pelem_base_t>(CL_MAY_CAUSE, _action, _head, NULL, _if, NULL, NULL, NULL, _when, NULL, _where); }

	/// Makes a 'possibly caused' causal law.
	/// 'possibly caused F if G ifcons G2 after H unless U when M following N where X'.
	template <typename pelem_base_t>
	static inline CausalLaw<pelem_base_t>* mkPossiblyCaused(
		pelem_base_t* _head,
		pelem_base_t* _if,
		pelem_base_t* _ifcons,
		pelem_base_t* _after,
		pelem_base_t* _unless,
		pelem_base_t* _when,
		pelem_base_t* _following,
		pelem_base_t* _where
		)
	{ return new CausalLaw<pelem_base_t>(CL_POSSIBLY_CAUSED, NULL, _head, NULL, _if, _ifcons, _after, _unless, _when, _following, _where); }

	/// Makes a 'increments' causal law.
	/// 'H increments F by B if G when M where X'.	
	template <typename pelem_base_t>
	static inline CausalLaw<pelem_base_t>* mkIncrements(
		pelem_base_t* _action,
		pelem_base_t* _head,
		pelem_base_t* _by,
		pelem_base_t* _if,
		pelem_base_t* _when,
		pelem_base_t* _where
		)
	{ return new CausalLaw<pelem_base_t>(CL_INCREMENTS, _action, _head, _by, _if, NULL, NULL, NULL, _when, NULL, _where); }

	/// Makes a 'decrements' causal law.
	/// 'H decrements F by B if G when M where X'.	
	template <typename pelem_base_t>
	static inline CausalLaw<pelem_base_t>* mkDecrements(
		pelem_base_t* _action,
		pelem_base_t* _head,
		pelem_base_t* _by,
		pelem_base_t* _if,
		pelem_base_t* _when,
		pelem_base_t* _where
		)
	{ return new CausalLaw<pelem_base_t>(CL_DECREMENTS, _action, _head, _by, _if, NULL, NULL, NULL, _when, NULL, _where); }
};



}; /* end namespace cplus_parser */