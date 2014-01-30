// (cl) by MABP, jul-2013.
// UVA-ID: 10196
// "Check the check"
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

bool EndOfProgramConditionCheck( string Input );
void PrintBoard( string board );
void PrintBoard( bitset <64> board );

const int C_WHITE = 2;
const int C_BLACK = 3;

class ChessPiece{
public:
  ChessPiece( char piece, int r_pos, int c_pos );
  void Print();
  void Set_bbPosition( bitset <64> bb_white, bitset <64> bb_black, bitset <64> bb_board );
  bitset <64> Get_bbPosition();
  bitset <64> Get_bbAttack();
  void BuildAttack();
private:
  char chess_piece;
  int r_position;
  int c_position;
  int piece_color;
  bitset <64> bb_Position;
  bitset <64> bb_Attack;
  bitset <64> bb_WhitePosition;
  bitset <64> bb_BlackPosition;
  bitset <64> bb_BoardPosition;
  bitset <64> bb_ENEMY;
  bitset <64> bb_FRIEND;
  void BuildKing();
  void BuildQueen();
  void BuildRock();
  void BuildBishop();
  void BuildKnight();
  void BuildPawn();
  bool IsValidPosition( int r, int c );
};


int main( int argc, char *argv[] ){
  string InputString; // Reading buffer from stdin
  string BoardString; // Chess board string configuration
  int GameCount = 0;

  while( cin >> InputString ){

    BoardString = InputString;

    // Read the rest of the chess board.
    for( int K = 0; K < 7; K++ ){
      cin >> InputString;
      BoardString += InputString;
    }
      
    // Ends program when finds an empty board.
    if( EndOfProgramConditionCheck( BoardString ) == true )
      break;

    // Reconfigure pieces correctly in the board-string
    string str_aux = BoardString;
    for( int J = 0; J < 8; J++ )
      for( int K = 0; K < 8; K++ )
	BoardString[ ( 7 - J )*8 + K ] = str_aux[ J*8 + K ];
  
    // Empty data structures to use
    vector <ChessPiece> WhitePieces;
    vector <ChessPiece> BlackPieces;
    bitset <64> bb_WhitePosition;  bb_WhitePosition.reset();
    bitset <64> bb_BlackPosition;  bb_BlackPosition.reset();
    bitset <64> bb_BoardPosition;  bb_BoardPosition.reset();
    bitset <64> bb_WhiteAttack;    bb_WhiteAttack.reset();
    bitset <64> bb_BlackAttack;    bb_BlackAttack.reset();
    bitset <64> bb_WhiteChecks;    bb_WhiteChecks.reset();
    bitset <64> bb_BlackChecks;    bb_BlackChecks.reset();    
    int id_WhiteKing;
    int id_BlackKing;

    // Creating & sorting by color chesspieces
    for( int J = 0; J < 8; J++ )
      for( int K = 0; K < 8; K++ )
	if( BoardString[ J*8 + K ] != '.' ){
	  if( BoardString[ J*8 + K ] >= 'A' && BoardString[ J*8 + K ] <= 'Z' ){
	    WhitePieces.push_back( ChessPiece( BoardString[ J*8 + K ], J, K ) );
	    bb_WhitePosition.set( J*8 + K );
	    
	    // Saving White King Position
	    if( BoardString[ J*8 + K ] == 'K' )
	      id_WhiteKing = WhitePieces.size() - 1;
	  }	  
	  else{
	    BlackPieces.push_back( ChessPiece( BoardString[ J*8 + K ], J, K ) );
	    bb_BlackPosition.set( J*8 + K );

	    // Saving Black King Position
	    if( BoardString[ J*8 + K ] == 'k' )
	      id_BlackKing = BlackPieces.size() - 1;
	  }
	}

    // Passing board position bbs
    bb_BoardPosition = bb_WhitePosition | bb_BlackPosition;
    for( int K = 0; K < WhitePieces.size(); K++ )
      WhitePieces[ K ].Set_bbPosition( bb_WhitePosition, bb_BlackPosition, bb_BoardPosition );    
    for( int K = 0; K < BlackPieces.size(); K++ )
      BlackPieces[ K ].Set_bbPosition( bb_WhitePosition, bb_BlackPosition, bb_BoardPosition );
    
    // Building attack bbs
    for( int K = 0; K < WhitePieces.size(); K++ ){
      WhitePieces[ K ].BuildAttack();
      bb_WhiteAttack |= WhitePieces[ K ].Get_bbAttack();
    }
    for( int K = 0; K < BlackPieces.size(); K++ ){
      BlackPieces[ K ].BuildAttack();
      bb_BlackAttack |= BlackPieces[ K ].Get_bbAttack();
    }

    // Inspection for checks
    bb_WhiteChecks = bb_WhiteAttack & ( BlackPieces[ id_BlackKing ].Get_bbPosition() );
    bb_BlackChecks = bb_BlackAttack & ( WhitePieces[ id_WhiteKing ].Get_bbPosition() );

    //Printing Output
    GameCount++;
    cout << "Game #" << GameCount << ": ";
    if( bb_WhiteChecks.any() )
      cout << "black king is in check." << endl;
    else if( bb_BlackChecks.any() )
      cout << "white king is in check." << endl;
    else
      cout << "no king is in check." << endl;

    // DEBUG
    // Print( BoardString );
    // cout << "----------------\n";    
  }

  return 0;
}


bitset <64> ChessPiece :: Get_bbPosition(){
  return bb_Position;
}


bitset <64> ChessPiece :: Get_bbAttack(){
  return bb_Attack;
}


void ChessPiece :: BuildAttack(){
  // We retire the present piece from the board (it's not an obstacle)
  bb_BoardPosition ^= bb_Position;

  if ( piece_color == C_WHITE ){
    bb_ENEMY  = bb_BlackPosition;
    bb_FRIEND = bb_WhitePosition;
  }
  else{
    bb_FRIEND = bb_BlackPosition;
    bb_ENEMY  = bb_WhitePosition;
  }

  switch( chess_piece ){
  case 'K':  case 'k':
    BuildKing();   
    break;
  case 'Q':  case 'q':
    BuildQueen();  
    break;
  case 'R':  case 'r':
    BuildRock();   
    break;
  case 'B':  case 'b':
    BuildBishop(); 
    break;
  case 'N':  case 'n':
    BuildKnight(); 
    break;
  case 'P':  case 'p':
    BuildPawn();   
    break;
  }

  bb_Attack &=  ~bb_FRIEND;

  // We put the present piece back in the board
  bb_BoardPosition |= bb_Position;
}


void ChessPiece :: BuildKing(){
  int r = r_position;
  int c = c_position;
  if( IsValidPosition( r-1, c-1 ) ) bb_Attack.set( ( r-1 )*8 + ( c-1 ) );
  if( IsValidPosition( r-1, c   ) ) bb_Attack.set( ( r-1 )*8 + ( c ) );
  if( IsValidPosition( r-1, c+1 ) ) bb_Attack.set( ( r-1 )*8 + ( c+1 ) );
  if( IsValidPosition( r, c-1   ) ) bb_Attack.set( ( r )*8   + ( c-1 ) );
  if( IsValidPosition( r, c+1   ) ) bb_Attack.set( ( r )*8   + ( c+1 ) );
  if( IsValidPosition( r+1, c-1 ) ) bb_Attack.set( ( r+1 )*8 + ( c-1 ) );
  if( IsValidPosition( r+1, c   ) ) bb_Attack.set( ( r+1 )*8 + ( c ) );
  if( IsValidPosition( r+1, c+1 ) ) bb_Attack.set( ( r+1 )*8 + ( c+1 ) );
}


void ChessPiece :: BuildPawn(){
  int r = r_position;
  int c = c_position;
  if ( piece_color == C_WHITE ){
    if( IsValidPosition( r+1, c-1 ) )  bb_Attack.set( ( r+1 )*8 + ( c-1 ) );
    if( IsValidPosition( r+1, c+1 ) )  bb_Attack.set( ( r+1 )*8 + ( c+1 ) );
  }
  else{
    if( IsValidPosition( r-1, c-1 ) )  bb_Attack.set( ( r-1 )*8 + ( c-1 ) );
    if( IsValidPosition( r-1, c+1 ) )  bb_Attack.set( ( r-1 )*8 + ( c+1 ) );
  }
}


void ChessPiece :: BuildKnight(){
  int r = r_position;
  int c = c_position;
  if( IsValidPosition( r-1, c+2 ) )  bb_Attack.set( ( r-1 )*8 + ( c+2 ) );
  if( IsValidPosition( r+1, c+2 ) )  bb_Attack.set( ( r+1 )*8 + ( c+2 ) );
  if( IsValidPosition( r-1, c-2 ) )  bb_Attack.set( ( r-1 )*8 + ( c-2 ) );
  if( IsValidPosition( r+1, c-2 ) )  bb_Attack.set( ( r+1 )*8 + ( c-2 ) );
  if( IsValidPosition( r+2, c-1 ) )  bb_Attack.set( ( r+2 )*8 + ( c-1 ) );
  if( IsValidPosition( r+2, c+1 ) )  bb_Attack.set( ( r+2 )*8 + ( c+1 ) );
  if( IsValidPosition( r-2, c-1 ) )  bb_Attack.set( ( r-2 )*8 + ( c-1 ) );
  if( IsValidPosition( r-2, c+1 ) )  bb_Attack.set( ( r-2 )*8 + ( c+1 ) );
}


void ChessPiece :: BuildQueen(){
  int r = r_position;
  int c = c_position;
  BuildRock();
  BuildBishop();
}


void ChessPiece :: BuildRock(){
  int r = r_position;
  int c = c_position;
  int ra, ca;
  
  ra = r;  ca = c;
  while ( IsValidPosition( ra, ca ) ){
    bb_Attack.set( ra*8 + ca );    
    if( bb_BoardPosition[ ra*8 + ca ] == 1 )
      break;
    ra++;
  }

  ra = r;  ca = c;
  while ( IsValidPosition( ra, ca ) ){
    bb_Attack.set( ra*8 + ca );    
    if( bb_BoardPosition[ ra*8 + ca ] == 1 )
      break;
    ra--;
  }

  ra = r;  ca = c;
  while ( IsValidPosition( ra, ca ) ){
    bb_Attack.set( ra*8 + ca );    
    if( bb_BoardPosition[ ra*8 + ca ] == 1 )
      break;
    ca++;
  }

  ra = r;  ca = c;
  while ( IsValidPosition( ra, ca ) ){
    bb_Attack.set( ra*8 + ca );    
    if( bb_BoardPosition[ ra*8 + ca ] == 1 )
      break;
    ca--;
  }
}


void ChessPiece :: BuildBishop(){
  int r = r_position;
  int c = c_position;
  int ra, ca;
  
  ra = r;  ca = c;
  while ( IsValidPosition( ra, ca ) ){
    bb_Attack.set( ra*8 + ca );    
    if( bb_BoardPosition[ ra*8 + ca ] == 1 )
      break;
    ra++;  ca++;
  }

  ra = r;  ca = c;
  while ( IsValidPosition( ra, ca ) ){
    bb_Attack.set( ra*8 + ca );    
    if( bb_BoardPosition[ ra*8 + ca ] == 1 )
      break;
    ra++;  ca--;
  }

  ra = r;  ca = c;
  while ( IsValidPosition( ra, ca ) ){
    bb_Attack.set( ra*8 + ca );    
    if( bb_BoardPosition[ ra*8 + ca ] == 1 )
      break;
    ra--;  ca++;
  }

  ra = r;  ca = c;
  while ( IsValidPosition( ra, ca ) ){
    bb_Attack.set( ra*8 + ca );    
    if( bb_BoardPosition[ ra*8 + ca ] == 1 )
      break;
    ra--;  ca--;
  }
}


bool ChessPiece :: IsValidPosition( int r, int c ){
  if( r >= 0 && r < 8 && c >= 0 && c < 8 )
    return true;
  else
    return false;
}


ChessPiece :: ChessPiece( char piece, int r_pos, int c_pos ){
  chess_piece = piece;
  r_position = r_pos;
  c_position = c_pos;

  bb_Position.reset();
  bb_Attack.reset();
  bb_WhitePosition.reset();
  bb_BlackPosition.reset();
  bb_BoardPosition.reset();

  // Sets position in the local bitboard
  bb_Position.set( r_position*8 + c_position );
  
  // Assigns color to the piece
  if( chess_piece >= 'A' && chess_piece <= 'Z' )
    piece_color = C_WHITE;
  else
    piece_color = C_BLACK;
}


void ChessPiece :: Set_bbPosition( bitset <64> bb_white, bitset <64> bb_black, bitset <64> bb_board ){
  bb_WhitePosition = bb_white;
  bb_BlackPosition = bb_black;
  bb_BoardPosition = bb_board;
}


void ChessPiece :: Print(){
  cout << "Piece-" << chess_piece << " Pos-<" << r_position << "," << c_position << ">"; 
  if( piece_color == C_WHITE )
    cout << " c-WHITE";
  else
    cout << " c-BLACK";
  cout << endl;
  PrintBoard( bb_Attack );
}


void PrintBoard( string Board ){
  for( int J = 0; J < 8; J++ ){
    for( int K = 0; K < 8; K++ )
      cout << Board[ ( 7 - J )*8 + K ] << " ";
    cout << endl;
  }
}


void PrintBoard( bitset <64> board ){
  string str_aux = "";
  for( int K = 0; K < 64; K++ )
    if( board[ K ] == 1 )
      str_aux += "+";
    else
      str_aux += ".";
  PrintBoard( str_aux );
}


// Checks the End-Of-Program conditions
bool EndOfProgramConditionCheck( string BoardString ){
  int pos = BoardString.find( 'k' );

  if ( pos >= 0 && pos <= 63 )
    return false;
  else
    return true;
}
