// UVA-ID: #10696
// "f91"
// (cl) by mabp, sep-2013.
#include <iostream>
using namespace std;
typedef unsigned long long ULONG;

ULONG f91( ULONG N );

int main( int argc, char *argv[] ){
  ULONG Num;
  
  while( cin >> Num ){
    
    // End of program condition.
    if( Num == 0 )
      break;
    
    cout << "f91(" << Num << ") = " << f91( Num ) << endl;    
  }

  return 0;
}


// MacCarthy's Recursive Function
ULONG f91( ULONG N ){
  if( N >= 101 )
    return N - 10;
  else {
    return f91( f91( N + 11 ) );
  }
}



