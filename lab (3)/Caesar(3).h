
// COS30008, Tutorial 4, 2016

#pragma once

#include <iostream>	
#include <fstream>	// file stream library

class Caesar
{
private:
	int fCharacterFrequenciesBefore[26];
	int fCharacterFrequenciesAfter[26];

public:
	Caesar();

	void shiftByFour( std::ifstream& aInput, std::ofstream& aOutput );

	friend std::ostream& operator<<( std::ostream& aOStream, const Caesar& aObject );
};
