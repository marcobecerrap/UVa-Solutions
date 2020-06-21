// UVA-ID: 11332
// "Summing Digits"
// (cl) by mabp, January-2015.
#include <iostream>
#include <string>
using namespace std;

int SummingDigits( int Number );


int main( int argc, char *argv[] ){

  string InputString;
  
  while( cin >> InputString ){

    // Summing digits from input string
    int Sum = 0;
    for( int K = 0; K < InputString.size(); K++ )
      Sum += InputString[ K ] - '0';
    
    Sum = SummingDigits( Sum );
    
    if( Sum == 0 )
      break;

    cout << Sum << endl;
  }

  return 0;
}

int SummingDigits( int Number ){ 
  // The Max Number is 82 from 1,999,999,999

  if( ( Number / 10 ) == 0 )
    return Number;
  else
    return SummingDigits( (Number % 10) + ( Number / 10 ) );

}
