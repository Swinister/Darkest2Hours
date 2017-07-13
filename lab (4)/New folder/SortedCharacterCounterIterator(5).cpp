
// COS30008, Tutorial 5, 2017

#include "SortedCharacterCounterIterator.h"

using namespace std;

SortedCharacterCounterIterator::SortedCharacterCounterIterator( CharacterCounter& aCounter )
{
	// initialize frequency map
	for ( int i = 0; i < 256; i++ )
	{
		fMaps[i] = FrequencyMap( i, aCounter[i] );
	}

	// use bubble sort to sort the map from lowest to highest frequency
	for ( int i = 255; i > 0; i-- )
	{
		for ( int j = 0; j < i; j++ )
		{
			if ( fMaps[j].getFrequency() > fMaps[j+1].getFrequency() )
			{
				// swap ith and jth element (bubble larger to right)
				FrequencyMap temp = fMaps[j];
				fMaps[j] = fMaps[j+1];
				fMaps[j+1] = temp;
			}
		}
	}

	// position index on the rightmost non-zero element
	fIndex = 255;
	while ( fIndex >= 0 && fMaps[fIndex].getFrequency() == 0 )
	{
		fIndex--;
	}
}

const FrequencyMap& SortedCharacterCounterIterator::operator*() const	// return current frequency map
{
	return fMaps[fIndex];
}

SortedCharacterCounterIterator& SortedCharacterCounterIterator::operator++()   	// prefix
{
	// position index on next non-zero element
	fIndex--;
	while ( fIndex >= 0 && fMaps[fIndex].getFrequency() == 0 )
	{
		fIndex--;
	}
	return *this;
}

SortedCharacterCounterIterator SortedCharacterCounterIterator::operator++( int ) 	// postfix (extra unused argument)
{
	SortedCharacterCounterIterator temp = *this;

	// recycle previous implementation (we do not want code duplication)
	++(*this);

	return temp;
}

bool SortedCharacterCounterIterator::operator==( const SortedCharacterCounterIterator& aOther ) const 
{
	// How do we determine equivalence?
	// - same index
	// - same underlying collection
	// Problem: It is not feasible to test the underlying collection.
	// Solution: Observe iterator context, that is, we only compare
	//           iterators originating (statically) from the same 
	//           character counter.

	return fIndex == aOther.fIndex;
}

bool SortedCharacterCounterIterator::operator!=( const SortedCharacterCounterIterator& aOther) const
{
	return !(*this == aOther);
}

SortedCharacterCounterIterator SortedCharacterCounterIterator::begin() const
{
	// Problem: We do not have access to the original character counter.
	// Solution: Create a copy and set the copy's fIndex to 255;

	SortedCharacterCounterIterator temp = *this;
	// position index on the rightmost non-zero element
	temp.fIndex = 255;
	while ( temp.fIndex >= 0 && temp.fMaps[temp.fIndex].getFrequency() == 0 )
	{
		temp.fIndex--;
	}
	return temp;
}

SortedCharacterCounterIterator SortedCharacterCounterIterator::end() const
{
	// Problem: We do not have access to the original character counter.
	// Solution: Create a copy and set the copy's fIndex to -1;

	SortedCharacterCounterIterator temp = *this;
	temp.fIndex = -1;
	return temp;
}
