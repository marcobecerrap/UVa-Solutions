// UVA-ID: #575
// "Skew Binary"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

typedef unsigned long long ULONG;

ULONG SkewBinaryConversion( string InputString );
ULONG GetSkewBinaryNumber( int idx );
string ReverseString( string InputString );


int main( int argc, char *argv[] ){

  string InputString;
  
  ULONG InputNumber;
  
  while( getline( cin, InputString ) ){
    InputNumber = 0;
    InputNumber = SkewBinaryConversion( InputString );
    if( InputNumber == 0 )
      break;

    cout << InputNumber << endl;
  }

  return 0;
}

ULONG SkewBinaryConversion( string InputString ){
  ULONG RetNumber = 0;
  
  InputString = ReverseString( InputString );

  for( int K = 0; K < InputString.length(); K++ ){
    if( InputString[ K ] < '1' || InputString[ K ] > '9' )
      continue;
    RetNumber += ( InputString[ K ] - '0' )*GetSkewBinaryNumber( K + 1 );
  }
  
  return RetNumber;
}

ULONG GetSkewBinaryNumber( int idx ){ 
  ULONG Number = 0;  
  if( idx > 0 ){
    Number = 1;
    for( int K = 0; K < ( idx - 1 ); K++ )
      Number = ( Number << 1 ) + 1;
  }
  return Number;
}

string ReverseString( string InputString ){
  string RetString;
  for( int K = ( InputString.length() - 1 ); K >= 0; K-- )
    RetString.push_back( InputString[ K ] );

  return RetString;
}
