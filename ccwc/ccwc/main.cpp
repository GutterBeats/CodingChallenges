//
//  main.cpp
//  ccwc
//
//  Created by Anthony Lesch on 5/14/24.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "Argument.hpp"
#include "InputParser.hpp"

#define ERROR(message, ...) printf(message, ##__VA_ARGS__); printf("\n"); return -1

Argument* args[] = {
	new LineCount(),
	new WordCount(),
	new ByteCount(),
	new CharacterCount()
};

int main(int argc, const char* argv[]) {
	InputParser parser(argc, argv);
	
	std::vector<Argument*> arguments(args, args + sizeof(args) / sizeof(Argument*));
	char invalidArg = parser.ValidateInputArguments(arguments);
	
	if (invalidArg != InputParser::EMPTY) {
		ERROR("Invalid argument specified: -%c", invalidArg);
	}
	
	std::ifstream file;
	file.open(parser.GetFile(), std::ios::in);
	
	std::stringstream input;
	if (file.good()) {
		input << file.rdbuf();
	}
	else {
		input << std::cin.rdbuf();
	}
	
	if (!input.good()) {
		ERROR("Invalid or Missing file. File argument must be last in list or piped into program.");
	}
	
	for (Argument* arg : arguments) {
		input.clear();
		input.seekg(0, input.beg);
		
		if ((parser.IsEmpty() && arg->GetIsDefault()) || parser.OptionExists(arg->GetFlag())) {
			arg->Operate(input);
		}
	}

	file.close();
	std::cout << parser.GetFile() << std::endl;
	
	return 0;
}
