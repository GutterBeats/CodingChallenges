//
//  Arguments.hpp
//  ccwc
//
//  Created by Anthony Lesch on 5/14/24.
//

#pragma once

#include <sstream>
#include <string>

struct Argument {

	Argument() = default;
	virtual ~Argument() { }
	
	/** Operate on the given file. */
	virtual void Operate(std::stringstream& file) = 0;
	
	/** Get the flag associated with this argument. */
	virtual char GetFlag() = 0;
	
	virtual bool GetIsDefault() { return false; }
};

struct ByteCount final : public Argument {
	virtual void Operate(std::stringstream& file) override;
	
	virtual char GetFlag() override { return 'c'; }
	
	virtual bool GetIsDefault() override { return true; }
};

struct WordCount final : public Argument {
	virtual void Operate(std::stringstream& file) override;
	
	virtual char GetFlag() override { return 'w'; }
	
	virtual bool GetIsDefault() override { return true; }
};

struct LineCount final : public Argument {
	virtual void Operate(std::stringstream& file) override;
	
	virtual char GetFlag() override { return 'l'; }
	
	virtual bool GetIsDefault() override { return true; }
};

struct CharacterCount final : public Argument {
	virtual void Operate(std::stringstream& file) override;
	
	virtual char GetFlag() override { return 'm'; }
};
