// UVA-ID: 706
// "LCD Display"
// (cl) by mabp, sep-2011.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned int UINT;

int main( int argc, char *argv[] ){
  UINT LCD_SZ  = 0;
  UINT LCD_Num = 0;
  
  enum { sa = 0, sb, sc, sd, se, sf, sg };
  const int TOT_DIGS = 10; // Total number of digits   [0-9]
  const int TOT_SEGS =  7; // Total number of segments [a-g]
                                           //  a  b  c  d  e  f  g
  const int Segs[ TOT_DIGS ][ TOT_SEGS ] = { { 1, 1, 1, 1, 1, 1, 0},  //0
					     { 0, 1, 1, 0, 0, 0, 0},  //1
					     { 1, 1, 0, 1, 1, 0, 1},  //2
					     { 1, 1, 1, 1, 0, 0, 1},  //3
					     { 0, 1, 1, 0, 0, 1, 1},  //4
					     { 1, 0, 1, 1, 0, 1, 1},  //5
					     { 1, 0, 1, 1, 1, 1, 1},  //6
					     { 1, 1, 1, 0, 0, 0, 0},  //7
					     { 1, 1, 1, 1, 1, 1, 1},  //8
					     { 1, 1, 1, 1, 0, 1, 1}}; //9
  
  vector <int> Digits;  // Will contain the digits to display
  string Output;        // An auxiliar string for output purposes...
  int count = 0;
  
  while ( cin >> LCD_SZ >> LCD_Num ){
    
    // Finish Condition
    if( LCD_SZ == 0 && LCD_Num == 0 )
      break;  
    
    // Obtaining individual digits...
    Digits.erase( Digits.begin(), Digits.end() );    
    if ( LCD_Num > 0 ){
      while( LCD_Num > 0 ){
	Digits.push_back( LCD_Num % 10 );
	LCD_Num /= 10;
      }
      reverse( Digits.begin(), Digits.end() );
    }
    else
      Digits.push_back( 0 );    

    
    // COMPOSING OUTPUT    
    string s_space( LCD_SZ, ' ');
    string s_line(  LCD_SZ, '-');
      

    // 1) First part, segment 'a'
    Output.erase( Output.begin(), Output.end() );
    for( int K = 0; K < Digits.size(); K++ ){    
      // Side space
      Output.push_back( ' ' );
      // Segment a
      if( Segs[ Digits[ K ] ][ sa ] == 1 )	
	Output += s_line;
      else
	Output += s_space;
      // Side space
      Output.push_back( ' ' );      
      // Inter-digit spaces
      if( (K + 1) < Digits.size() )
	Output.push_back( ' ' );      
    }
    cout << Output << endl;


    // 2) Second part, segments 'b' & f
    Output.erase( Output.begin(), Output.end() );
    for( int K = 0; K < Digits.size(); K++ ){    
      // Segment f
      if( Segs[ Digits[ K ] ][ sf ] == 1 )	
	Output.push_back( '|' );
      else
	Output.push_back( ' ' );	
      // Middle spaces
      Output += s_space;
      //  Segment b
      if( Segs[ Digits[ K ] ][ sb ] == 1 )	
	Output.push_back( '|' );
      else
	Output.push_back( ' ' );
      // Inter-digit spaces
      if( (K + 1) < Digits.size() )
	Output.push_back( ' ' );      
    }
    for( int M = 0; M < LCD_SZ; M++ )
      cout << Output << endl;


    // 3) Tirth part, segment 'g'
    Output.erase( Output.begin(), Output.end() );
    for( int K = 0; K < Digits.size(); K++ ){    
      // Side space
      Output.push_back( ' ' );
      // Segment g
      if( Segs[ Digits[ K ] ][ sg ] == 1 )	
	Output += s_line;
      else
	Output += s_space;
      // Side space
      Output.push_back( ' ' );      
      // Inter-digit spaces
      if( (K + 1) < Digits.size() )
	Output.push_back( ' ' );      
    }
    cout << Output << endl;


    // 4) Fourth part, segments 'e' & c
    Output.erase( Output.begin(), Output.end() );
    for( int K = 0; K < Digits.size(); K++ ){    
      // Segment e
      if( Segs[ Digits[ K ] ][ se ] == 1 )	
	Output.push_back( '|' );
      else
	Output.push_back( ' ' );	
      // Middle spaces
      Output += s_space;
      //  Segment c
      if( Segs[ Digits[ K ] ][ sc ] == 1 )	
	Output.push_back( '|' );
      else
	Output.push_back( ' ' );
      // Inter-digit spaces
      if( (K + 1) < Digits.size() )
	Output.push_back( ' ' );      
    }
    for( int M = 0; M < LCD_SZ; M++ )
      cout << Output << endl;


    // 5) Fifth part, segment 'd'
    Output.erase( Output.begin(), Output.end() );
    for( int K = 0; K < Digits.size(); K++ ){    
      // Side space
      Output.push_back( ' ' );
      // Segment d
      if( Segs[ Digits[ K ] ][ sd ] == 1 )	
	Output += s_line;
      else
	Output += s_space;
      // Side space
      Output.push_back( ' ' );      
      // Inter-digit spaces
      if( (K + 1) < Digits.size() )
	Output.push_back( ' ' );      
    }
    cout << Output << endl << endl;


    count ++;
  }   
  
  return 0;
}
