// UVA-ID: 713
// "Adding Reversed Numbers"
// (cl) by mabp, January-2015.
#include <iostream>
#include <string>
using namespace std;

int main( int argc, char *argv[] ){

  int Size;
  cin >> Size;
  
  string StringNumber1;
  string StringNumber2;
  for( int L = 0; L < Size; L++ ){

    // Read Strings
    cin >> StringNumber1;
    cin >> StringNumber2;

    // Order Strings by size
    if( StringNumber1.size() < StringNumber2.size() ){
      string str_aux;
      str_aux = StringNumber2;
      StringNumber2 = StringNumber1;
      StringNumber1 = str_aux;
    }
    
    // Adding 0's
    int Difference = StringNumber1.size() - StringNumber2.size();
    for( int K = 0; K < Difference; K++ )
      StringNumber2 = StringNumber2 + "0";

    //Sum Numbers
    int Carry = 0;
    string Sum = "";
    for( int K = 0; K < StringNumber1.size(); K++ ){
      int DigitSum = ( StringNumber1[ K ] - '0' ) + ( StringNumber2[ K ] - '0' ) + Carry;
      Carry = DigitSum / 10;
      Sum.push_back( ( DigitSum % 10 ) + '0' );
    }
    if( Carry > 0 )
    Sum.push_back( Carry + '0' );
    
    // Count Zeros at the end
    int CountZeros = 0;
    for( int K = 0; K < Sum.size(); K++){
      if( Sum[ K ] == '0' )
	CountZeros++;
      else
	break;
    }
    
    // Print output
    for( int K = CountZeros; K < Sum.size(); K++ )
      cout << Sum[ K ];
    cout << endl;

  }

  return 0;
}
