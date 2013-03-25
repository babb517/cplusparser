
#include <iostream>
#include <cstdarg>
#include <cstdio>

#include "details/Scanner.h"
#include "details/Token.h"
#include "Location.h"
#include "Handler.h"


class MHandler :  public cplus_parser::MessageHandler {
public:

	inline MHandler() { }

	virtual inline bool message(MessageFlag flags, char const* msg, ...) {
		std::cerr << "Message:\n"
			<< '\t' << "Location: NOT_PROVIDED\n"
			<< '\t' << "Value: '";

		char* c = new char[1024];

		va_list argptr;
		va_start(argptr, msg);
		vsprintf(c, msg, argptr);
		va_end(argptr);

		std::cerr << c << "\n";

	}

	virtual inline bool message(cplus_parser::Location const& loc, MessageFlag flags, char const* msg, ...) {
		std::cerr << "Message:\n"
			<< '\t' << "Location: " << loc.begin_file << ":: " << loc.begin_line << ":" << loc.begin_col << " - "
									<< loc.end_file   << ":: " << loc.end_line   << ":" << loc.end_col << "\n"
			<< '\t' << "Value: '";

		char* c = new char[1024];

		va_list argptr;
		va_start(argptr, msg);
		vsprintf(c, msg, argptr);
		va_end(argptr);

		std::cerr << c << "\n";
	}
};


class ScannerTester {
private:
	cplus_parser::details::Scanner* scanner;
	MHandler handler;

public:
	inline ScannerTester(char const* file)
	{ 
		scanner = new cplus_parser::details::Scanner(&handler);
		scanner->appendFile(file, file); 
	
	}

	inline ~ScannerTester() {
		delete scanner;
	}

	inline int test() {
		cplus_parser::details::Token t;
		do {
			scanner->lex(t);
			std::cout << "Token:\n"
				<< '\t' << "Location: " << t.loc().begin_file << ":: " << t.loc().begin_line << ":" << t.loc().begin_col << " - "
										<< t.loc().end_file   << ":: " << t.loc().end_line   << ":" << t.loc().end_col << "\n"
				<< '\t' << "Value: '" << t.data() << "'\n";

		} while (t.type() != cplus_parser::details::TokenType::T_EOF);
		return 0;
	}

};

int main( int argc, const char** argv ) {
	if (argc != 2) {
		std::cerr << "Error: Please specify exactly one file to tokenize.";
		return 1;
	}

	ScannerTester* test = new ScannerTester(argv[1]);
	return test->test();

}
