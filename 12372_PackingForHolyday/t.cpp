// UVA-ID: 12372
// "Packing For Holyday"
// (cl) by mabp, January-2015.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main( int argc, char *argv[] ){
  
  int Size;
  cin >> Size;
  
  for( int K = 0; K < Size; K++ ){
    vector<int> MyBox;
    int aux_x, aux_y, aux_z;
    cin >> aux_x >> aux_y >> aux_z;
    MyBox.push_back( aux_x );
    MyBox.push_back( aux_y );
    MyBox.push_back( aux_z );
    sort( MyBox.begin(), MyBox.end() );
    
    cout << "Case " << ( K + 1 ) << ": ";
    if( MyBox[ 2 ]  <=  20 ){
      cout << "good" << endl;
      continue;
    }
    cout << "bad" << endl;
  }
  
  return 0;
}
