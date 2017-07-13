
// COS30008, Tutorial 5, 2017

#pragma once

#include "CharacterCounter.h"
#include "FrequencyMap.h"

class SortedCharacterCounterIterator
{
private:
	FrequencyMap fMaps[256];
	int fIndex;

public:
	SortedCharacterCounterIterator( CharacterCounter& aCounter );

	const FrequencyMap& operator*() const;              // return current frequency map
	SortedCharacterCounterIterator& operator++();   	// prefix
	SortedCharacterCounterIterator operator++( int ); 	// postfix (extra unused argument)
	bool operator==( const SortedCharacterCounterIterator& aOther ) const; 
	bool operator!=( const SortedCharacterCounterIterator& aOther) const;

	SortedCharacterCounterIterator begin() const;
	SortedCharacterCounterIterator end() const;
};
