//
//  InputParser.hpp
//  ccwc
//
//  Created by Anthony Lesch on 5/14/24.
//

#pragma once

#include <vector>
#include <string>

struct InputParser final {
	InputParser(int argc, const char* argv[]);
	
	const char& GetCommandOption(const char option) const;
	
	bool OptionExists(const char option) const;
	
	const char ValidateInputArguments(std::vector<class Argument*> args);
	
	const std::string& GetFile() const { return file; }
	
	bool IsEmpty() const;
	
	static const char EMPTY;
	
private:
	std::vector<char> tokens;
	std::string file;
};
