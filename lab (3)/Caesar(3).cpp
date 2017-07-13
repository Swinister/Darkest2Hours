
// COS30008, Tutorial 4, 2016

#include "Caesar.h"

#include <cctype>

using namespace std;

Caesar::Caesar() : fCharacterFrequenciesBefore(), fCharacterFrequenciesAfter()
{}

void Caesar::shiftByFour( std::ifstream& aInput, std::ofstream& aOutput )
{
	char lOldChar = aInput.get();
	char lNewChar;

	while ( aInput.good() )
	{
		if ( isalpha( lOldChar ) )
		{
			bool lLower = islower( lOldChar );
		
			lOldChar = toupper( lOldChar );

			fCharacterFrequenciesBefore[lOldChar - 'A']++;

			lNewChar = 'A' + ((lOldChar - 'A' + 4) % 26); 

			fCharacterFrequenciesAfter[lNewChar - 'A']++;

			if ( lLower )
			{
				lNewChar = tolower( lNewChar );
			}

			aOutput.put( lNewChar );
		}
		else
		{
			aOutput.put( lOldChar );
		}

		lOldChar = aInput.get();
	}
}

ostream& operator<<( ostream& aOStream, const Caesar& aObject )
{
	cout << "Character frequencies (before, after):" << endl;
	for ( int i = 0; i < 26; i++ )
	{
		cout << (char)('A' + i) << ": " 
			 <<  aObject.fCharacterFrequenciesBefore[i] << ", "
			 <<  aObject.fCharacterFrequenciesAfter[i] << endl;
	}

	return aOStream;
}
