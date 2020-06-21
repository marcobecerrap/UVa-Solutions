// UVA-ID: 01644
// "Prime Gap"
// (cl) by mabp, February-2015.
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ULONG;

int main( int argc, char *argv[] ){

  //%%%%%%%%% BUILDING PRIMES
  const ULONG SizeLimit = 1299710;
  vector<ULONG> Prime;
  vector<ULONG> Prime_IDX;
  vector<bool> IsPrime;
  
  for( ULONG K = 0; K < SizeLimit; K++ )
    IsPrime.push_back( true );
  
  int IDX = -1;
  Prime_IDX.push_back( -1 ); // 0
  Prime_IDX.push_back( -1 ); // 1
  for( ULONG K = 2; K < SizeLimit; K++ ){
    Prime_IDX.push_back( IDX );
    if( IsPrime[ K ] == false )
      continue;
    else{
      IDX++; 
      Prime_IDX[ K ] = IDX;
      Prime.push_back( K );
      for( ULONG S = 2 * K; S < SizeLimit; S += K )
  	IsPrime[ S ] = false;
    }    
  }
  //%%%%%%%%%

  ULONG InputNumber;
  while( cin >> InputNumber){

    if( InputNumber == 0 )
      break;

    if( Prime[ Prime_IDX[ InputNumber ] ] == InputNumber ){
      cout << 0 << endl;
      continue;
    }
    else{
      cout << Prime[ Prime_IDX[ InputNumber ] + 1 ] - Prime[ Prime_IDX[ InputNumber ] ] << endl;
    }
  }  

  return 0;
}
