#pragma once

#ifndef FUZZYCONFREADER_H
#define FUZZYCONFREADER_H

#include "ConfReader.h"
class FuzzyConfReader :
	public ConfReader
{
public:
	FuzzyConfReader(void);
	~FuzzyConfReader(void);
};

#endif