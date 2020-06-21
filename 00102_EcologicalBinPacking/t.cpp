// UVA-ID: #102
// "Ecological Bin Packing"
// (cl) by mabp, sep-2013.
#include <iostream>
#include <algorithm>
using namespace std;

void Copy1DArray( int *A, int *B, int size );

int main( int argc, char *argv[] ){

  const int BIN_SIZE = 3;
  const int COLOR_SIZE = 3;
  long Bin[ BIN_SIZE ][ COLOR_SIZE ];
  char BottleType[] = { 'B', 'G', 'C', 'Z' };
  
  while( cin >> Bin[0][0] >> Bin[0][1] >> Bin[0][2] >> Bin[1][0] >> Bin[1][1] >> Bin[1][2] >> Bin[2][0] >> Bin[2][1] >> Bin[2][2] ){

    // Counting bottles
    long TotalBottleCount = 0;
    for( int K = 0; K < 3; K++ )
      for( int M = 0; M < 3; M++ )
	TotalBottleCount += Bin[ K ][ M ];

    //We have 3 different permutations with 3 elements. We're going to build it all & save the max amount of bottles of different color in different boxes. This represents the maximum amount o non-moved bottles... so the minimum amount of moved bottles.
    int p_color[] = { 0, 1, 2 };
    
    int MaxCount = 0;
    int p_color_MAX[] = { 3, 3, 3 };
    int Count;
    for( int K = 0; K < 6; K++ ){
      Count = Bin[ 0 ][ p_color[ 0 ] ] + Bin[ 1 ][ p_color[ 1 ] ] + Bin[ 2 ][ p_color[ 2 ] ];
      if( Count > MaxCount ){
	MaxCount = Count;
	 Copy1DArray( p_color, p_color_MAX, 3 );
      }
      else if( Count == MaxCount ){ // Choose the first alphabetical occurence...
      	if( BottleType[ p_color[ 0 ] ] < BottleType[ p_color_MAX[ 0 ] ] )
      	  Copy1DArray( p_color, p_color_MAX, 3 );
      	else if( BottleType[ p_color[ 1 ] ] < BottleType[ p_color_MAX[ 1 ] ] && BottleType[ p_color[ 0 ] ] == BottleType[ p_color_MAX[ 0 ] ] )
      	  Copy1DArray( p_color, p_color_MAX, 3 );
      }
      next_permutation( p_color, p_color + 3 );
    }
    
    cout << BottleType[ p_color_MAX[ 0 ] ] << BottleType[ p_color_MAX[ 1 ] ] << BottleType[ p_color_MAX[ 2 ] ] << " " << ( TotalBottleCount - MaxCount ) << endl;    

  }

  return 0;
}

void Copy1DArray( int *A, int *B, int size ){
  for( int K = 0; K < size; K++ )
    *( B + K ) = *( A + K );
}
