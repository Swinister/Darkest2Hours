
// COS30008, Tutorial 10, 2017

#include "SimpleString.h"

#include <cstring>

using namespace std;

SimpleString::SimpleString()
{
	fCharacters = new char[1];
	*fCharacters = '\0';
}

SimpleString::~SimpleString()
{
	delete fCharacters;
}


SimpleString& SimpleString::operator+( const char aCharacter )
{
    char *Temp = new char[strlen(fCharacters) + 2];
    unsigned int i = 0;
    
    for ( ; i < strlen( fCharacters ); i++ )
        Temp[i] = fCharacters[i];
    
    Temp[i++] = aCharacter;
    Temp[i] = '\0';
    
    delete fCharacters;
    fCharacters = Temp;
    return *this;
}

const char* SimpleString::operator*() const
{ 
    return fCharacters;
}

#if TEST >= 1

SimpleString::SimpleString( const SimpleString& aOtherString )
{
	unsigned long lLength = strlen(aOtherString.fCharacters) + 1;
  	fCharacters = new char[lLength];
  
  	for ( unsigned int i = 0; i < lLength; i++ )
    	fCharacters[i] = aOtherString.fCharacters[i];
}

#endif

#if TEST >= 3

SimpleString& SimpleString::operator=( const SimpleString& aOtherString )
{
    if ( &aOtherString != this )
	{
		delete fCharacters;
	
		unsigned long lLength = strlen(aOtherString.fCharacters) + 1;
  		fCharacters = new char[lLength];
  
  		for ( unsigned int i = 0; i < lLength; i++ )
    		fCharacters[i] = aOtherString.fCharacters[i];
	}

	return *this;
}

#endif

#if TEST >= 5

SimpleString* SimpleString::clone()
{
	return new SimpleString( *this );
}

#endif
