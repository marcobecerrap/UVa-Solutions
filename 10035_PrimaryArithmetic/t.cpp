// UVA-ID: #10035
// "Primary Arithmetic"
// (cl) by mabp, sep-2013.
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;
typedef unsigned long long ULONG;

int main( int argc, char *argv[] ){

  ULONG NumA, NumB;
  
  string InputString;
  char c_aux;

  while( getline( cin, InputString ) ){ // Input string
    istringstream InputStream( InputString ); // string 2 stream

    while( InputStream.get( c_aux ) )
      if( c_aux >= '0' && c_aux <= '9' )
	break;
    InputStream.unget();
    InputStream >> NumA;

    while( InputStream.get( c_aux ) )
      if( c_aux >= '0' && c_aux <= '9' )
	break;
    InputStream.unget();
    InputStream >> NumB;

    
    // End og program condition
    if( NumA == 0 && NumB == 0 )
      break;

    int CarryCount = 0;
    int LastCarry = 0;
    int DigitA;
    int DigitB;
    while( NumA != 0 && NumB !=0 ){
      DigitA = NumA % 10;
      DigitB = NumB % 10;
      
      if( ( DigitA + DigitB + LastCarry ) >= 10 ){
	LastCarry = 1;
	CarryCount++;
      }
      else
	LastCarry = 0;
      
      NumA = ( NumA - DigitA ) / 10;
      NumB = ( NumB - DigitB ) / 10;	
    }

    while( NumA != 0 ){
      DigitA = NumA % 10;
      
      if( ( DigitA + LastCarry ) >= 10 ){
	LastCarry = 1;
	CarryCount++;
      }
      else
	LastCarry = 0;
      
      NumA = ( NumA - DigitA ) / 10;

    }

    while( NumB != 0 ){
      DigitB = NumB % 10;
      
      if( ( DigitB + LastCarry ) >= 10 ){
	LastCarry = 1;
	CarryCount++;
      }
      else
	LastCarry = 0;
      
      NumB = ( NumB - DigitB ) / 10;
    }

    // Printing results
    switch( CarryCount ){
    case 0:
      cout << "No carry operation." << endl;
      break;
    case 1:
      cout << "1 carry operation." << endl;
      break;
    default:
      cout << CarryCount << " carry operations." << endl;
      break;    
    }    

  }

  return 0;
}


// WRONG APPROACH!!!
// int main( int argc, char *argv[] ){

//   string InputString;

//   while( getline( cin, InputString ) ){ // Input string
//     istringstream InputStream( InputString ); // string 2 stream
//     stack <char> NumA, NumB;
//     char c_aux;
//     int flag = 0;
//     while( InputStream.get( c_aux ) ){
//       if( c_aux >= '0' && c_aux <= '9' && flag == 0 ){
// 	  flag++;
// 	  do{
// 	    NumA.push( c_aux - '0' );
// 	    InputStream.get( c_aux );
// 	  } while( c_aux >= '0' && c_aux <= '9' );
//       }
//       if( c_aux >= '0' && c_aux <= '9' && flag == 1 ){
// 	  flag++;
// 	  do{
// 	    NumB.push( c_aux - '0' );
// 	    InputStream.get( c_aux );
// 	  } while( c_aux >= '0' && c_aux <= '9' && InputStream.good() );
//       }
//       if( flag == 2 )
// 	break;
//     }

//     // End of program condition...
//     if( ((int) NumA.top()) == 0 && ((int) NumB.top()) == 0 && NumA.size() == 1 && NumB.size() == 1 )
//       break;

//     int CarryCount = 0;
//     int LastCarry = 0;
//     int N_A, N_B;
//     // Count first carries...
//     while( !NumA.empty() && !NumB.empty() ){
//       N_A = NumA.top();
//       N_B = NumB.top();
//       NumA.pop();
//       NumB.pop();
      
//       if( ( N_A + N_B + LastCarry ) >= 10 ){
// 	LastCarry = 1;
// 	CarryCount++;
//       }
//       else
// 	LastCarry = 0;      
//     }

//     // Count last carries
//     while( !NumA.empty() )
//       if( ( NumA.top() + LastCarry ) >= 10 ){
// 	CarryCount++;
// 	LastCarry = 1;
// 	NumA.pop();
//       }
//     while( !NumB.empty() )
//       if( ( NumB.top() + LastCarry ) >= 10 ){
// 	CarryCount++;
// 	LastCarry = 1;
// 	NumB.pop();
//       }

//     // Printing results
//     switch( CarryCount ){
//     case 0:
//       cout << "No carry operation." << endl;
//       break;
//     case 1:
//       cout << "1 carry operation." << endl;
//       break;
//     default:
//       cout << CarryCount << " carry operations." << endl;
//       break;    
//     }    

//   }

//   return 0;
// }
