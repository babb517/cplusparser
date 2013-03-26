
#include <iostream>
#include <cstdarg>
#include <cstdio>
#include <cstring>

#include "details/Scanner.h"
#include "details/Token.h"
#include "Location.h"
#include "Handler.h"


class MHandler :  public cplus_parser::MessageHandler {
private:
	bool verbose;

public:

	inline MHandler(bool _verbose = false)
		: verbose(_verbose) { }

	virtual inline bool message(MessageFlag flags, char const* msg, ...) {
		if (!verbose && !(msglevel(flags) & ~MSG_DEBUG_SCANNER_VERBOSE)) return false;
		std::cerr << "Message:\n"
			<< '\t' << "Location: NOT_PROVIDED\n"
			<< '\t' << "Value: '";

		char* c = new char[1024];




		va_list argptr;
		va_start(argptr, msg);
		vsprintf(c, msg, argptr);
		va_end(argptr);

		std::cerr << c << "'\n";
		return true;

	}

	virtual inline bool message(cplus_parser::Location const& loc, MessageFlag flags, char const* msg, ...) {
		if (!verbose && !(msglevel(flags) & ~MSG_DEBUG_SCANNER_VERBOSE)) return false;
		std::cerr << "Message:\n"
			<< '\t' << "Location: " << loc.str() << "\n"
			<< '\t' << "Value: '";

		char* c = new char[1024];

		va_list argptr;
		va_start(argptr, msg);
		vsprintf(c, msg, argptr);
		va_end(argptr);

		std::cerr << c << "'\n";
		return true;
	}
};


class ScannerTester {
private:
	cplus_parser::details::Scanner* scanner;
	MHandler handler;

	char const* insert_file;
	char const* append_file;
	char const* inject_str;


public:
	inline ScannerTester(char const* file, char const* insert_file, char const* append_file, char const* inject_str, bool verbose)
		: handler(verbose)
	{ 
		scanner = new cplus_parser::details::Scanner(&handler);
		scanner->appendFile(file, file); 
		this->insert_file = insert_file;
		this->append_file = append_file;
		this->inject_str = inject_str;
	}

	inline ~ScannerTester() {
		delete scanner;
	}

	inline int test() {
		cplus_parser::details::Token t;
		cplus_parser::Location loc;

		do {
			scanner->lex(t);
			std::cout << "Token:\n"
				<< '\t' << "Location: " << t.loc().str() << "\n"
				<< '\t' << "Value: '" << t.c_str() << "'\n";

			if (t.type() == cplus_parser::details::TokenType::T_DEBUG_INSERT && insert_file) {
				scanner->insertFile(insert_file, insert_file);
			} else if (t.type() == cplus_parser::details::TokenType::T_DEBUG_APPEND && append_file) {
				scanner->appendFile(append_file, append_file);
			} else if (t.type() == cplus_parser::details::TokenType::T_DEBUG_INJECT && inject_str) {
				// The location needs to be copied so we can reuse it.
				loc = t.loc();
				scanner->inject(inject_str, loc);
			}


		} while (t.type() != cplus_parser::details::TokenType::T_EOF);
		return 0;
	}

};

void showHelp() {
	std::cout 
		<< "%~~ Scanner Test Routine ~~%\n"
		<< " --inject [string]\n"
		<< "          Specify a string to inject into the file following\n"
		<< "          each occurrence of the '#debug_inject_string.' keyword.\n"
		<< " --insert [file]\n"
		<< "          Specify a file to insert into the file following each\n"
 		<< "          occurrence of the '#debug_insert_file.' keyword.\n"
		<< " --append [file]\n"
		<< "          Specify a file to append to the end of the open files on\n"
		<< "          each occurrence of the '#debug_append_file.' keyword.\n"
		<< " --verbose\n"
		<< "          Displays verbose scanner debugging output.\n"
		<< " --help -h -?\n"
		<< "          Displays this dialog.\n"
		<< "\n";         
}

int main( int argc, const char** argv ) {

	char const* file=NULL, *insert_file=NULL, *append_file=NULL, *inject_str=NULL;
	bool verbose = false;

	for (int i = 0; i < argc; i++) {
		if (!strcmp(argv[i], "--inject")) {
			if (++i == argc) {
				std::cerr << "Error: Expected a string to inject following '--inject'.";
				return 1;
			} else {
				inject_str = argv[i];
			}
		} else if (!strcmp(argv[i], "--insert")) {
			if (++i == argc) {
				std::cerr << "Error: Expected a file to insert following '--insert'.";
				return 1;
			} else {
				insert_file = argv[i];
			}
		} else if (!strcmp(argv[i], "--append")) {
			if (++i == argc) {
				std::cerr << "Error: Expected a file to append following '--append'.";
				return 1;
			} else {
				append_file = argv[i];
			}
		} else if (!strcmp(argv[i],"--verbose")) {
			verbose = true;
		} else if (
				argv[i][0] == '-'
				| !strcmp(argv[i],"?")) {
			showHelp();
		} else {
			file = argv[i];
		}
	}

	if (!file) {
		std::cerr << "Error: Please specify a files to tokenize.\n";
		return 1;
	}


	ScannerTester* test = new ScannerTester(file, insert_file, append_file, inject_str, verbose);
	return test->test();

}
