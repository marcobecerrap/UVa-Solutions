// UVA-ID: #10038
// "Jolly Jumpers"
// (cl) by mabp, sep-2013.
#include <iostream>
#include <sstream>
#include <bitset>
#include <vector>
using namespace std;


int main( int argc, char *argv[] ){
  
  bitset <3000> BitList;
  string InputString;
  
  while( getline( cin, InputString ) ){ // Get each input string

    istringstream InputStream( InputString ); // String 2 Stream
    
    vector <int> Sequence;    
    int i_aux;
    InputStream >> i_aux; // We ignore the first number... (size of sequence)
    if( i_aux == 1 ){
      cout << "Jolly" << endl;
      continue;
    }

    while( InputStream >> i_aux ) // Read the sequence
      Sequence.push_back( i_aux );
    

    // Set the BitList
    BitList.reset();
    for( int K = 0; K < ( Sequence.size() - 1 ); K++ ) // Turning ON first 'n-1 = [0,n-2]' bits
      BitList.set( K );
    
    int diff;
    for( int K = 0; K < ( Sequence.size() - 1 ); K++ ){
      diff = ( Sequence[ K ] > Sequence[ K + 1 ] ) ? ( Sequence[ K ] - Sequence[ K + 1 ] ) : ( Sequence[ K + 1 ] - Sequence[ K ] );
      if( diff > 0  && diff < 3000 )
	BitList.reset( diff - 1 );
    }
    
    if( BitList.any() )
      cout << "Not jolly" << endl;
    else
      cout << "Jolly" << endl;
  }
  
  return 0;
}

