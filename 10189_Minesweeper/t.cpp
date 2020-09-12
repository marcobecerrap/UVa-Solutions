// UVA-ID: 10189
// "Minesweeper"
// (cl) by mabp, sep-2011.
#include <iostream>
using namespace std;

const char cZERO  = '0';
const int  iZERO  =  0 ;
const int MINEDFIELD_SZ = 102;
char MinedField[ MINEDFIELD_SZ ][ MINEDFIELD_SZ ]; // Mined field
int SolvedField[ MINEDFIELD_SZ ][ MINEDFIELD_SZ ]; // Solved mined field


int main( int argc, char *argv[] ){

  int r_sz, c_sz; // Mined field size vars
  int count = 0;

 
  while ( cin >> r_sz >> c_sz ){
    // Finish condition
    if( r_sz == 0 && c_sz == 0 )
      break;
    
    if( count > 0 )  // Break-line between two entries
      cout << endl;
    
    // Clean Arrays
    for( int K = 0 ; K <= ( r_sz + 1) ; K++ )
      for( int M = 0 ; M <= ( c_sz + 1) ; M++ ){
	MinedField[  K ][ M ] = cZERO;
	SolvedField[ K ][ M ] = iZERO;
      }

    // Get Mined Field from STDIN
    for( int K = 1 ; K <= r_sz ; K++ )
      for( int M = 1 ; M <= c_sz ; M++ )	
	while( MinedField[ K ][ M ] != '.' &&  MinedField[ K ][ M ] != '*' )
	  cin >> MinedField[ K ][ M ];

    // Solve Mined Field
    for( int K = 1 ; K <= r_sz ; K++ )
      for( int M = 1 ; M <= c_sz ; M++ )
	if( MinedField[ K ][ M ] == '*' ){
	  SolvedField[ K-1 ][ M-1 ]++;
	  SolvedField[ K-1 ][ M   ]++;
	  SolvedField[ K-1 ][ M+1 ]++;
	  SolvedField[ K   ][ M-1 ]++;
	  SolvedField[ K   ][ M+1 ]++;
	  SolvedField[ K+1 ][ M-1 ]++;
	  SolvedField[ K+1 ][ M   ]++;
	  SolvedField[ K+1 ][ M+1 ]++;
	}
    
    // Print Results
    count++;
    cout << "Field #" << count << ":" << endl;
    for( int K = 1 ; K <= r_sz ; K++ ){
      for( int M = 1 ; M <= c_sz ; M++ ){
	if( MinedField[ K ][ M ] == '*' )
	  cout << '*';
	else
	  cout << SolvedField[ K ][ M ];
      }
      cout << endl;
    }    
  }


  return 0;
}

