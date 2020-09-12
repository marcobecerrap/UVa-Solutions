// UVA-ID: #11875
// "Brick Game"
// (cl) by mabp, oct-2013.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main( int argc, char *argv[] ){

  int NCases;
  cin >> NCases;
  
  for( int K = 0; K < NCases; K++ ){
    int NPlayers;
    cin >> NPlayers;

    vector <int> Player;

    int i_aux;
    for( int L = 0; L < NPlayers; L++ ){
      cin >> i_aux;
      Player.push_back( i_aux );
    }
    
    sort( Player.begin(), Player.end() );
    
    cout << "Case " << ( K + 1 ) << ": " << Player[ ( Player.size() / 2 ) ] << endl;
    
  }
  
  return 0;
}
