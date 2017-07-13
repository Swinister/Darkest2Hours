
// COS30008, Tutorial 5, 2017

#pragma once

class FrequencyMap
{
private:
	char fChar;
	int fFrequency;

public:
	FrequencyMap();	// needed to declare arrays
	FrequencyMap( char aChar, int aFrequency ); // initialize with concrete values

	// read-only getters
	char getCharacter() const;
	int getFrequency() const;
};

