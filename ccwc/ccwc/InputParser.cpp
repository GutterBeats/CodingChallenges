//
//  InputParser.cpp
//  ccwc
//
//  Created by Anthony Lesch on 5/14/24.
//

#include <string>
#include <fstream>

#include "InputParser.hpp"
#include "Argument.hpp"

const char InputParser::EMPTY = ' ';

InputParser::InputParser(int argc, const char* argv[]) {
	for (int i = 1; i < argc; ++i) {
		std::string option(argv[i]);
		
		if ((i + 1) == argc) {
			std::ifstream file;
			file.open(option, std::ios::in);
			
			if (file.good()) {
				this->file = option;
			}
			
			file.close();
			break;
		}
		
		if (!option.starts_with("-")) {
			continue;
		}
		
		for (int i = 1; i < option.size(); ++i) {
			this->tokens.push_back(option.at(i));
		}
	}
}

const char& InputParser::GetCommandOption(const char option) const {
	std::vector<char>::const_iterator itr
		= std::find(this->tokens.begin(), this->tokens.end(), option);
	
	if (itr != this->tokens.end() && ++itr != this->tokens.end()) {
		return *itr;
	}
	
	return InputParser::EMPTY;
}

const char InputParser::ValidateInputArguments(std::vector<Argument*> args) {
	for (char c : tokens) {
		bool valid = false;
		for (Argument* arg : args) {
			if (arg->GetFlag() == c) {
				valid = true;
				break;
			}
		}
		
		if (!valid) {
			return c;
		}
	}
	
	return InputParser::EMPTY;
}

bool InputParser::OptionExists(const char option) const {
	return std::find(this->tokens.begin(), this->tokens.end(), option) != this->tokens.end();
}

bool InputParser::IsEmpty() const {
	return tokens.empty();
}
