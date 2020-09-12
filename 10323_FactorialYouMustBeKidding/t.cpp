// UVA-ID: #10323
// "Factorial! You Must Be Kidding!!!"
// (cl) by mabp, month-year.
#include <iostream>
using namespace std;

typedef unsigned long long ULONG;

ULONG Factorial( ULONG N );

int main( int argc, char *argv[] ){

  long Number;

  while( cin >> Number ){

    // NEGATIVE FACTORIALS ARE VERY TRICKY... I HAD TO LOOK FOR HELP ON THE FORUM... I'M STILL NOT CONVEINCED ABOUT THIS... +-
    if ( Number < 0 ){
      if( ( ( Number * -1 ) % 2 ) == 0 )
	cout << "Underflow!" << endl;
      else
	cout << "Overflow!" << endl;
    }
    else{
      if( Number < 8)
	cout << "Underflow!" << endl;
      else if( Number > 13 )
	cout << "Overflow!" << endl;
      else
	cout << Factorial( (ULONG) Number ) << endl;
    }
  }

  return 0;
}



ULONG Factorial( ULONG N ){
  if( N == 0 )
    return 1;
  else
    return ( N * Factorial( N - 1 ) );
}


