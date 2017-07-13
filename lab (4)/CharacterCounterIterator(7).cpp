
// COS30008, Tutorial 5, 2017

#include "CharacterCounterIterator.h"

using namespace std;

CharacterCounterIterator::CharacterCounterIterator( CharacterCounter& aCounter )
{
	// initialize frequency map
	for ( int i = 0; i < 256; i++ )
	{
		fMaps[i] = FrequencyMap( i, aCounter[i] );
	}

	// position index on first non-zero element (check operator++)

	fIndex=0;
	while ( fIndex < 256 && fMaps[fIndex].getFrequency() == 0 )
	{
		fIndex++;
	}
}

const FrequencyMap& CharacterCounterIterator::operator*() const	// return current frequency map
{
	return fMaps[fIndex];
}

CharacterCounterIterator& CharacterCounterIterator::operator++()   	// prefix
{
	// position index on next non-zero element
	fIndex++;
	while ( fIndex < 256 && fMaps[fIndex].getFrequency() == 0 )
	{
		fIndex++;
	}
	return *this;
}

CharacterCounterIterator CharacterCounterIterator::operator++( int ) 	// postfix (extra unused argument)
{
	CharacterCounterIterator temp = *this;

	// recycle previous implementation (we do not want code duplication)
	++(*this);

	return temp;
}

bool CharacterCounterIterator::operator==( const CharacterCounterIterator& aOther ) const 
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

bool CharacterCounterIterator::operator!=( const CharacterCounterIterator& aOther) const
{
	return !(*this == aOther);
}

CharacterCounterIterator CharacterCounterIterator::begin() const
{
	// Problem: We do not have access to the original character counter.
	// Solution: Create a copy and set the copy's fIndex to first non-zero element;

	CharacterCounterIterator temp = *this;
	temp.fIndex = -1;	// start before 0 (i.e., -1)
	++temp;				// sets fIndex to 0 or the first non-zero frequency map
	
	return temp;
}

CharacterCounterIterator CharacterCounterIterator::end() const
{
	// Problem: We do not have access to the original character counter.
	// Solution: Create a copy and set the copy's fIndex to 256;

	CharacterCounterIterator temp = *this;
	temp.fIndex = 256;
	return temp;
}
