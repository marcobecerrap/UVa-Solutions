// UVA-ID: #
// "Flip Sort"
// (cl) by mabp, Jan-2014.
#include <iostream>
#include <vector>
using namespace std;

int main( int argc, char *argv[] ){

  int InputSize;
  while( cin >> InputSize ){

    vector <int> InputVector;

    // Reading input data set
    int InputNumber;
    for( int K = 0; K < InputSize; K++ ){
      cin >> InputNumber;
      InputVector.push_back( InputNumber );
    }
    
    int FlipCount = 0;
    for( int K = 1; K < InputSize; K++ )
      for( int M = 1; M < InputSize; M++ ){
	if( InputVector[ M - 1 ] > InputVector[ M ] ){
	  int aux = InputVector[ M - 1 ];
	  InputVector[ M - 1 ] = InputVector[ M ];
	  InputVector[ M ] = aux;
	  FlipCount++;
	}
      }
    
    // Program output
    cout << "Minimum exchange operations : " << FlipCount << endl;

  }

  return 0;
}
