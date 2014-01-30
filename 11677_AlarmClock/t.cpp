// UVA-ID: #11677
// "Alarm Clock"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){
  
  int H1, M1, H2, M2;
  
  while( cin >> H1 >> M1 >> H2 >> M2 ){
    // Exit condition
    if( H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0 )
      break;
    
    int MinuteCount = 0;
    
    while( H1 != H2 || M1 != M2 ){
      if( M1 == 59 )
	H1 = ( H1 + 1 ) % 24;
      M1 = ( M1 + 1 ) % 60;
      MinuteCount++;
    }
    
    cout << MinuteCount << endl;
  }
  
  return 0;
}
