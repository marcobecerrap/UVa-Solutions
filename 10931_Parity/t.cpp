// UVA-ID: 10931
// "Parity"
// (cl) by mabp, January-2015.
#include <iostream>
#include <vector>
using namespace std;

int main( int argc, char *argv[] ){

  long Number;
  while( cin >> Number ){
    
    if( Number == 0 )
      break;
    
    // Binary conversion & bitcount.
    int BitCount = 0;
    vector <int> BinaryNumber;
    while( Number != 0 ){
      BinaryNumber.push_back( Number % 2 );
      BitCount += Number % 2;
      Number /= 2;
    }
    
    // Print output
    cout << "The parity of ";
    for( int K = BinaryNumber.size() - 1; K >= 0; K-- )
      cout << BinaryNumber.at( K );
    cout << " is " << BitCount << " (mod 2)." << endl;
        
  }

  return 0;
}
