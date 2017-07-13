
// COS30008, Tutorial 4, 2016

#include "CharacterCounter.h"

#include <fstream>

using namespace std;

int main( int argc, char* argv[] )
{
	if ( argc < 3 )
	{
		cerr << "Argumens missing" << endl;
		cerr << "Usage: FileCharacterCounter infile outfile" << endl;
		return 1;	// program failed
	}

	// set up input file
	ifstream lInput;	// declare an input file variable

	lInput.open( argv[1], ifstream::in ); // open an input text file

	if ( !lInput.good() )
	{
		cerr << "Cannot open input file: " << argv[1] << endl;
		return 2;	// program failed (input)
	}

	// set up output file
	ofstream lOutput;	// declare an output file variable

	lOutput.open( argv[2], ofstream::out ); // open an output text file

	if ( !lOutput.good() )
	{
		cerr << "Cannot open output file: " << argv[2] << endl;
		lInput.close();	// never forget, we must close input file
		return 3;		// program failed (output)
	}

	CharacterCounter lCounter;

	unsigned char lChar;

	while ( lInput >> lChar )
	{
		lCounter.count( lChar );
	}

	lOutput << lCounter;

	lInput.close();
	lOutput.close();
	
	return 0;
}
