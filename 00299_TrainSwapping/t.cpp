// UVA-ID: #299
// "Train Swapping"
// (cl) by mabp, oct-2013.
#include <iostream>
#include <vector>
using namespace std;

int main( int argc, char *argv[] ){
  int NCases;
  cin >> NCases;
  
  int NCarriages;
  for( int K = 0; K < NCases; K++ ){
    cin >> NCarriages;

    vector <int> Carriage;
    int i_aux;
    for( int L = 0; L < NCarriages; L++ ){
      cin >> i_aux;
      Carriage.push_back( i_aux );
    }
    
    // Bubblesorting
    int SwapCount = 0;
    for( int I = 1; I < NCarriages; I++ )
      for( int J = 1; J < NCarriages; J++ )
	if( Carriage[ J - 1 ] > Carriage[ J ] ){
	  i_aux = Carriage[ J ];
	  Carriage[ J ] = Carriage[ J - 1];
	  Carriage[ J - 1 ] = i_aux;
	  SwapCount++;
	}
      
    cout << "Optimal train swapping takes " << SwapCount << " swaps." << endl;    
  }

  return 0;
}
