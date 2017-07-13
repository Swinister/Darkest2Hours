
// COS30008, Tutorial 5, 2017

#pragma once

#include <iostream>

class CharacterCounter
{
private:
	int fTotalNumberOfCharacters;
	int fCharacterCounts[256];

public:
  CharacterCounter();

  void count( unsigned char aCharacter );		// We count all 256 byte values

  friend std::ostream& operator<<( std::ostream& aOStream, 
	                               const CharacterCounter& aCharacterCounter );

  // new tutorial 5: frequency indexer method
  int operator[]( unsigned char aCharacter ) const;
};
