
// COS30008, Tutorial 5, 2017

#include "FrequencyMap.h"

FrequencyMap::FrequencyMap() : fChar(0), fFrequency(0)
{}

FrequencyMap::FrequencyMap( char aChar, int aFrequency )
{
	// intialize with concrete values
	fChar = aChar;
	fFrequency = aFrequency;
}

// read-only getters
char FrequencyMap::getCharacter() const
{
	return fChar;
}

int FrequencyMap::getFrequency() const
{
	return fFrequency;
}
