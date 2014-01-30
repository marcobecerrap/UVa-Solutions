// UVA-ID: #10970
// "Big Chocolate"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){
  
  int N, M;
  int Test1, Test2;
  while( cin >> N >> M ){
    if( N > 1 && M > 1 ){
      Test1 = (N - 1) + ( N * ( M - 1 ) );
      Test2 = (M - 1) + ( M * ( N - 1 ) );
    }
    else{
      Test1 = ( M > 1 ) ? ( M -1 ) : ( N - 1 );
      Test2 = Test1;
    }
    if( Test1 < Test2 )
      cout << Test1 << endl;
    else
      cout << Test2 << endl;
  }

  return 0;
}
