
// COS30008, Tutorial 5, 2017

#pragma once

#include "CharacterCounter.h"
#include "FrequencyMap.h"

class CharacterCounterIterator
{
private:
	FrequencyMap fMaps[256];
	int fIndex;

public:
	CharacterCounterIterator( CharacterCounter& aCounter );

	const FrequencyMap& operator*() const;          // return current frequency map
	CharacterCounterIterator& operator++();         // prefix
	CharacterCounterIterator operator++( int ); 	// postfix (extra unused argument)
	bool operator==( const CharacterCounterIterator& aOther ) const; 
	bool operator!=( const CharacterCounterIterator& aOther) const;

	CharacterCounterIterator begin() const;
	CharacterCounterIterator end() const;
};
