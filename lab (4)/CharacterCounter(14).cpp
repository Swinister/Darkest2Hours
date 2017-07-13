
// COS30008, Tutorial 5, 2017

#include "CharacterCounter.h"

#include <stdexcept>

using namespace std;

CharacterCounter::CharacterCounter() : fTotalNumberOfCharacters(), fCharacterCounts()
{}

void CharacterCounter::count( unsigned char aCharacter )
{
	fCharacterCounts[aCharacter]++;
	fTotalNumberOfCharacters++;
}

ostream& operator<<( ostream& aOStream, const CharacterCounter& aCharacterCounter )
{
	aOStream << "Character counts for " 
		     << aCharacterCounter.fTotalNumberOfCharacters << " characters:" << endl;

	for ( int i = 0; i < 256; i++ )
	{
		if ( aCharacterCounter.fCharacterCounts[i] != 0 )
		{
			aOStream << (char)i << ":\t" << aCharacterCounter.fCharacterCounts[i] << endl;
		}
	}

	return aOStream;
}

// new tutorial 5: frequency indexer method
int CharacterCounter::operator[]( unsigned char aCharacter ) const
{
	return fCharacterCounts[aCharacter];
}
