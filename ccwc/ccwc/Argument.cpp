//
//  Arguments.cpp
//  ccwc
//
//  Created by Anthony Lesch on 5/14/24.
//

#include "Argument.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <locale>

#define OUT(count) std::cout << count << " "

void ByteCount::Operate(std::stringstream& file) {
	file.seekg(0, file.end);
	
	OUT(file.tellg());
}

void WordCount::Operate(std::stringstream& file) {
	int count = 0;
	std::string line;
	
	while (std::getline(file, line)) {
		char prevChar = '\0';
		for (char c : line) {
			if (iswspace(c) && !iswspace(prevChar) && prevChar != '\0') {
				++count;
			}
			
			prevChar = c;
		}
	}
	
	OUT(count);
}

void LineCount::Operate(std::stringstream& file) {
	int count = 0;
	std::string line;
	
	while (std::getline(file, line)) {
		++count;
	}
	
	OUT(count);
}

void CharacterCount::Operate(std::stringstream& file) {
	int count = 0;
	char c;
	
	setlocale(LC_ALL, "");
	while (file.get(c)) {
		count += mblen(&c, MB_CUR_MAX);
	}
	
	OUT(count);
}
