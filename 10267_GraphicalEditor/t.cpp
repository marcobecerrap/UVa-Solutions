// UVA-ID: 10267#
// "Name: Graphical Editor"
// (cl) by mabp, sept-2011.
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void ClearCanvas( vector <string> *Canvas, int R_SZ, int C_SZ );
void RectangleCanvas( vector <string> *Canvas, int X1, int Y1, int X2, int Y2, char Colour );
void PrintCanvas( vector <string> Canvas, int R_SZ, int C_SZ );
void RegionCanvas( vector <string> *Canvas, int X1, int Y1, char Colour );
void Swap(int *a, int *b);


int main( int argc, char *argv[] ){

  char CMD;
  string CommandLine;
  string garbage;
  bool CreatedCanvas = false;
  // arguments
  int C_SZ;           // (M) Columns
  int R_SZ;           // (N) Rows
  int X1, X2, Y1, Y2; // Coords
  char Colour;        // Colour
  string FileName;    // FileName

  const int CANVAS_SZ = 250;
  vector <string> Canvas( CANVAS_SZ + 2 );
  
  // Init Canvas
  R_SZ = CANVAS_SZ;
  C_SZ = CANVAS_SZ;
  for( int K = 0; K < CANVAS_SZ + 2; K++ )
    Canvas[K] = string( CANVAS_SZ + 2, '1' );
  ClearCanvas( &Canvas, R_SZ, C_SZ);      
  
  
  
  while ( true ){

    getline( cin, CommandLine );
    istringstream CMDLine( CommandLine );
    CMDLine >> CMD;
    
    // I M N
    //Creates a new table M×N. All the pixels are colored in white (O). 
    if ( CMD == 'I' ){
      // Getting arguments
      CMDLine >> C_SZ >> R_SZ;      
      // Input validation
      R_SZ = ( R_SZ >= 1 ) ? ( ( R_SZ <= CANVAS_SZ ) ? R_SZ : 0 ) : 0;
      C_SZ = ( C_SZ >= 1 ) ? ( ( C_SZ <= CANVAS_SZ ) ? C_SZ : 0 ) : 0;      
      if( R_SZ > 0 && C_SZ > 0 ){
	ClearCanvas( &Canvas, R_SZ, C_SZ);      
	CreatedCanvas = true;
      }
    }

    // C
    //Clears the table. The size remains the same. All the pixels became white (O).
    else if( CMD == 'C' ){
      if( CreatedCanvas == true )
	ClearCanvas( &Canvas, R_SZ, C_SZ );      
    }

    // L X Y C
    //Colors the pixel with coordinates (X,Y) in colour C.
    else if( CMD == 'L' ){
      // Getting arguments
      CMDLine >> X1 >> Y1 >> Colour;
      // Input validation
      X1 = ( X1 >= 1 ) ? ( ( X1 <= C_SZ ) ? X1 : 0 ) : 0;
      Y1 = ( Y1 >= 1 ) ? ( ( Y1 <= R_SZ ) ? Y1 : 0 ) : 0;
      if( X1 > 0 && Y1 > 0 && CreatedCanvas == true )
	RectangleCanvas( &Canvas, X1, Y1, X1, Y1, Colour );
    }

    // V X Y1 Y2 C
    // Draws the vertical segment in the column X between the rows Y1 and Y2 inclusive in colour C.
    else if( CMD == 'V' ){
      // Getting arguments
      CMDLine >> X1 >> Y1 >> Y2 >> Colour;      
      // Input validation
      X1 = ( X1 >= 1 ) ? ( ( X1 <= C_SZ ) ? X1 : 0 ) : 0;
      Y1 = ( Y1 >= 1 ) ? ( ( Y1 <= R_SZ ) ? Y1 : 0 ) : 0;
      Y2 = ( Y2 >= 1 ) ? ( ( Y2 <= R_SZ ) ? Y2 : 0 ) : 0;
      if( X1 > 0 && Y1 > 0 && Y2 > 0 && CreatedCanvas == true )
	RectangleCanvas( &Canvas, X1, Y1, X1, Y2, Colour );
    }

    // H X1 X2 Y C
    // Draws the horizontal segment in the row Y between the columns X1 and X2 inclusive in colour C.
    else if( CMD == 'H' ){
      // Getting arguments
      CMDLine >> X1 >> X2 >> Y1 >> Colour;
      // Input validation
      X1 = ( X1 >= 1 ) ? ( ( X1 <= C_SZ ) ? X1 : 0 ) : 0;
      X2 = ( X2 >= 1 ) ? ( ( X2 <= C_SZ ) ? X2 : 0 ) : 0;
      Y1 = ( Y1 >= 1 ) ? ( ( Y1 <= R_SZ ) ? Y1 : 0 ) : 0;
      if( X1 > 0 && X2 > 0 && Y1 > 0 && CreatedCanvas == true )
	RectangleCanvas( &Canvas, X1, Y1, X2, Y1, Colour );
    }


    // K X1 Y1 X2 Y2 C
    // Draws the filled rectangle in colour C. (X1,Y1) is the upper left corner, (X2,Y2) is the lower right corner of the rectangle.
    else if( CMD == 'K' ){
      // Getting arguments
      CMDLine >> X1 >> Y1 >> X2 >> Y2 >> Colour;
      // Input validation
      X1 = ( X1 >= 1 ) ? ( ( X1 <= C_SZ ) ? X1 : 0 ) : 0;
      X2 = ( X2 >= 1 ) ? ( ( X2 <= C_SZ ) ? X2 : 0 ) : 0;
      Y1 = ( Y1 >= 1 ) ? ( ( Y1 <= R_SZ ) ? Y1 : 0 ) : 0;
      Y2 = ( Y2 >= 1 ) ? ( ( Y2 <= R_SZ ) ? Y2 : 0 ) : 0;
      if( X1 > 0 && X2 > 0 && Y1 > 0 && Y2 > 0 && CreatedCanvas == true )
	RectangleCanvas( &Canvas, X1, Y1, X2, Y2, Colour );
    }

    // F X Y C
    // Fills the region with the colour C. The region R to be filled is defined as follows. The pixel (X,Y) belongs to this region. The other pixel belongs to the region R if and only if it has the same colour as pixel (X,Y) and a common side with any pixel which belongs to this region.
    else if( CMD == 'F' ){
      // Getting arguments
      CMDLine >> X1 >> Y1 >> Colour;
      // Input validation
      X1 = ( X1 >= 1 ) ? ( ( X1 <= C_SZ ) ? X1 : 0 ) : 0;
      Y1 = ( Y1 >= 1 ) ? ( ( Y1 <= R_SZ ) ? Y1 : 0 ) : 0;
      if( X1 > 0 && Y1 > 0 && CreatedCanvas == true )
	RegionCanvas( &Canvas, X1, Y1, Colour );
    }

    // S Name
    // Writes the picture in the file Name.
    else if( CMD == 'S' ){
      // Getting arguments
      CMDLine >> FileName;      
      cout << FileName << endl;
      if( CreatedCanvas == true )
	PrintCanvas( Canvas, R_SZ, C_SZ );
    }
    // X
    // Terminates the session.
    else if( CMD == 'X' ){      
      break;
    }
    // UNKWON INPUT
    else{
      continue;
    }
  }  

  return 0;
}


void ClearCanvas( vector <string> *Canvas, int R_SZ, int C_SZ ){
  RectangleCanvas( Canvas, 0, 0, C_SZ + 1, R_SZ + 1, '1' );
  RectangleCanvas( Canvas, 1, 1, C_SZ, R_SZ, 'O' );  
}

void RectangleCanvas( vector <string> *Canvas, int X1, int Y1, int X2, int Y2, char Colour ){
  //string s_aux(1, Colour);

  if( X1 > X2 )
    Swap( &X1, &X2 );
  if( Y1 > Y2 )
    Swap( &Y1, &Y2 );
    
  for( int K = Y1; K <= Y2; K++ )
    for( int M = X1; M <= X2; M++ )
      //( *Canvas )[ K ].replace( M, 1, s_aux );      
      ( *Canvas )[ K ][ M ] = Colour;      
}

void PrintCanvas( vector <string> Canvas, int R_SZ, int C_SZ ){
  for( int K = 1; K <= R_SZ; K++ ){
    for( int M = 1; M <= C_SZ; M++ )
      cout << Canvas[ K ].at( M );  
    cout << endl;
  }
}

void RegionCanvas( vector <string> *Canvas, int X1, int Y1, char Colour ){
  char PastColour;
  
  PastColour = ( *Canvas )[ Y1 ].at( X1 );    
  ( *Canvas )[ Y1 ].at( X1 ) = Colour;
  
  if( PastColour != Colour ){
    if( ( *Canvas )[ Y1 +1 ].at( X1 ) == PastColour )
      RegionCanvas( Canvas, X1, Y1 + 1, Colour );
    if( ( *Canvas )[ Y1 ].at( X1 + 1 ) == PastColour )
      RegionCanvas( Canvas, X1 + 1, Y1, Colour );
    if( ( *Canvas )[ Y1 - 1 ].at( X1 ) == PastColour )
      RegionCanvas( Canvas, X1, Y1 - 1, Colour );
    if( ( *Canvas )[ Y1 ].at( X1 - 1 ) == PastColour )
      RegionCanvas( Canvas, X1 - 1, Y1, Colour );    
  }
}

void Swap(int *a, int *b){
  int t;
  t = *a;
  *a = *b;
  *b = t;
}
