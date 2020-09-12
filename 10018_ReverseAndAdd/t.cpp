// UVA-ID: #10018
// "Reverse and Add"
// (cl) by mabp, sep-2013.
#include <iostream>
#include <vector>
using namespace std;
typedef long long LLONG;

void ExceedTimeLimit();
bool IsPalindrome( LLONG N, LLONG *R );

int main( int argc, char *argv[] ){

  int nCases;
  LLONG Num;
  LLONG RevNum;
  cin >> nCases;
  
  for( int K = 0; K < nCases; K++ ){
    int iCount = 0;
    cin >> Num; 

    while( IsPalindrome( Num, &RevNum ) == false ){
      Num = Num + RevNum;
      iCount++;
    }

    cout << iCount << " " << Num << endl;
  }

  return 0;
}

bool IsPalindrome( LLONG N, LLONG *R ){
  bool ReturnCondition = true;
  vector <int> DigitSet;
  int last_digit = 0;
  while( N > 0 ){
    last_digit = N % 10;
    DigitSet.push_back( last_digit );
    N = ( N - last_digit ) / 10; 
  }
  
  // Test palindrome
  for( int K = 0, J = ( DigitSet.size() - 1 ); K < J; K++, J-- ){
    if( DigitSet[ K ] != DigitSet[ J ] )
      ReturnCondition = false;
  }

  if( ReturnCondition == false ){
    // Build reverse number
    *R = 0;
    for( int K = 0; K < DigitSet.size(); K++ ){
      *R *= 10;
      *R += DigitSet[ K ];
    }
  }

  return ReturnCondition;
}

void ExceedTimeLimit(){
  while( true );
}
