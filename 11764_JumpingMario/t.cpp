// UVA-ID: #11764
// "Jumping Mario"
// (cl) by mabp, oct-2013.
#include <iostream>
#include <vector>
using namespace std;

int main( int argc, char *argv[] ){

  int NCases;
  cin >> NCases;

  int HighCount, LowCount;
  int WallCount;
  for( int K = 0; K < NCases; K++ ){
    HighCount = 0;
    LowCount = 0;

    cin >> WallCount;
    
    vector <int> Wall;
    int i_aux;
    for( int L = 0; L < WallCount; L++ ){
      cin >> i_aux;
      Wall.push_back( i_aux );
    }
    
    for( int L = 1; L < Wall.size(); L++ ){
      if( Wall[ L - 1 ] < Wall[ L ] )
	HighCount++;
      if( Wall[ L - 1 ] > Wall[ L ] )
	LowCount++;
    }
    
    cout << "Case " << ( K + 1 ) << ": " << HighCount << " " << LowCount << endl;
  }

  return 0;
}
