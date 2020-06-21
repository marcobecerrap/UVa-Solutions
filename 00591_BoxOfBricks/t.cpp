// UVA-ID: #591
// "Box of Bricks"
// (cl) by mabp, sep-2013.
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main( int argc, char *argv[] ){
  
  int nCases = 0;
  int nStacks;
  int TotalBlocks;
  int MeanBlocks;
  int BlockMoves;
  string InputString;
  
  while( cin >> nStacks ){
    
    // End of program condition
    if( nStacks == 0 ) 
      break;
    
    getline( cin, InputString ); // Input string
    getline( cin, InputString ); // Input string
    istringstream InputStream( InputString );
    vector <int> BlockStack;

    int i_aux;
    TotalBlocks = 0;
    while( InputStream >> i_aux ){
      TotalBlocks += i_aux;
      BlockStack.push_back( i_aux );
    }

    MeanBlocks = TotalBlocks / nStacks;
    
    BlockMoves = 0;
    for( int K = 0; K < BlockStack.size(); K++ )
      if( BlockStack[ K ] > MeanBlocks )
	BlockMoves += BlockStack[ K ] - MeanBlocks;
    
    nCases++;
    cout << "Set #" << nCases << endl;
    cout << "The minimum number of moves is " << BlockMoves << "." << endl << endl;
  }

  return 0;
}
