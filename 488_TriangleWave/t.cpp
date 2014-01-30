// UVA-ID: #488
// "Triangle Wave"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

void PrintWave( int Amplitude );

int main( int argc, char *argv[] ){
  
  int NCases;  
  cin >> NCases;

  int Frequency;
  int Amplitude;

  for( int K = 0; K < NCases; K++ ){
    cin >> Amplitude;
    cin >> Frequency;
    
    for( int M = 0; M < Frequency; M++ ){
      PrintWave( Amplitude );
      if( M < ( Frequency - 1 ) )
      	cout << endl;
    }

    if( K < ( NCases - 1 ) )
      cout << endl;    
  }

  return 0;
}

void PrintWave( int Amplitude ){
  for( int K = 1; K <= Amplitude; K++){
    for( int M = 0; M < K; M++ )
      cout << K;
    cout << endl;
  }
  for( int K = ( Amplitude - 1 ); K > 0; K--){
    for( int M = 0; M < K; M++ )
      cout << K;
    cout << endl;
  }
}
