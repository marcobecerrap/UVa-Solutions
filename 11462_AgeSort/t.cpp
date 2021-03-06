// UVA-ID: 11462
// "Age Sort"
// (cl) by mabp, January-2015.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main( int argc, char *argv[] ){

  int Size = 0;
  while( cin >> Size ){

    if( Size == 0 )
      return 0;
    
    // Store input
    vector <long> InputVector;
    for( int K = 0; K < Size; K++ ){
      int aux;
      cin >> aux;
      InputVector.push_back( aux );
    }
    
    // Sort elements
    std::sort( InputVector.begin(), InputVector.end() );

    // Print output
    for( int K = 0; K < Size-1; K++ )
      cout << InputVector.at( K ) << " ";
    cout << InputVector.at( Size - 1 ) << endl;

  }

  return 0;
}
