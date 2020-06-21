// UVA-ID: 11292
// "Dragon Of Loowater"
// (cl) by mabp, February-2015.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main( int argc, char *argv[] ){
  
  int HeadsSize, KnightsSize;
  
  while( cin >> HeadsSize >> KnightsSize ){
    
    if( HeadsSize == 0 && KnightsSize == 0 )
      break;    
    
    vector <int> Heads;
    vector <int> Knights;

    int aux;
    for( int K = 0; K < HeadsSize; K++ ){
      cin >> aux;
      Heads.push_back( aux );
    }    
    sort( Heads.begin(), Heads.end() );

    for( int K = 0; K < KnightsSize; K++ ){
      cin >> aux;
      Knights.push_back( aux );
    }
    sort( Knights.begin(), Knights.end() );
    
    int Payment = 0;
    int S = 0;
    bool Doomed = false;
    for( int K = 0; K < Heads.size(); K++ ){
      if( S >= Knights.size() ){ // No more knights left
	Doomed =  true;
	break;
      }
      while( ( Knights[ S ] < Heads[ K ] ) && ( S < Knights.size() ) )
	S++;
      if( S >= Knights.size() ){ // No more knights left
	Doomed =  true;
	break;
      }
      else{
	Payment += Knights[ S ];
	S++;
      }	
    }
    if( Doomed == false )
      cout << Payment << endl;
    else
      cout << "Loowater is doomed!" << endl;      
  }

  return 0;
}
