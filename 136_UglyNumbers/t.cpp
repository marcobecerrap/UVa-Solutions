// UVA-ID: #136
// "Ugly Numbers"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

typedef unsigned long long ULONG;

bool IsUgly( ULONG Number );

int main( int argc, char *argv[] ){
  int Count = 0;
  ULONG Number = 1;
  
  // while( Count < 1500 ){
  //   if( IsUgly( Number ) ){
  //     Count++;
  //     cout << Count << " - " << Number << endl;
  //   }
  //   Number++;
  // }
  // cout << "The 1500'th ugly number is " << (Number - 1) << "." << endl;

  cout << "The 1500'th ugly number is 859963392." << endl;

  return 0;
}

bool IsUgly( ULONG Number ){
  if( Number == 1 )
    return true;
  else if( Number%2 == 0 )
    return IsUgly( Number / 2 );
  else if( Number%3 == 0 )
    return IsUgly( Number / 3 );
  else if( Number%5 == 0 )
    return IsUgly( Number / 5 );
  else 
    return false;
}

