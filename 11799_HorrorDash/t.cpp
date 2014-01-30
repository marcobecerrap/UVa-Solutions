// UVA-ID: #11799
// "Horror Dash"
// (cl) by mabp, oct-2013.
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main( int argc, char *argv[] ){
  
  int NCases;
  int CaseCount = 0;
  string InputString;

  cin >> NCases;
  getline( cin, InputString ); // To erase the '\n'
  

  while( getline( cin, InputString ) ){
    CaseCount++; 
    
    istringstream InputStream( InputString );

    int NRunners;
    vector <int> Runner;
    InputStream >> NRunners;
    
    // Read runners' speeds
    int Runner_aux;
    for( int K = 0; K < NRunners; K++ ){
      InputStream >> Runner_aux;
      Runner.push_back( Runner_aux );
    }
    
    // Get the greatest runner speed
    for( int K = 0; K < NRunners; K++ ){
      if( Runner[ K ] > Runner_aux )
    	Runner_aux = Runner[ K ];
    }
    
    cout << "Case " << CaseCount << ": " << Runner_aux << endl;
    
    // End of program condition
    if( CaseCount == NCases )
      break;    
  }

  return 0;
}
