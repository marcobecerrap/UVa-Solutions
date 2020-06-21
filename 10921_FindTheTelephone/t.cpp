// UVA-ID: 10921
// "Find The Telephone"
// (cl) by mabp, January-2015.
#include <iostream>
#include <string>
using namespace std;

int main( int argc, char *argv[] ){

  string InputString;
  while( cin >> InputString ){
    string Telephone = "";
    
    for( int K = 0; K < InputString.size(); K++ ){
      switch( InputString[ K ] ){
      case 'A': 
      case 'B': 
      case 'C':
	Telephone.push_back( '2' );
	break;
      case 'D':
      case 'E':
      case 'F':
	Telephone.push_back( '3' );
	break;
      case 'G':
      case 'H':
      case 'I':
	Telephone.push_back( '4' );
	break;
      case 'J':
      case 'K':
      case 'L':
	Telephone.push_back( '5' );
	break;
      case 'M':
      case 'N':
      case 'O':
	Telephone.push_back( '6' );
	break;
      case 'P':
      case 'Q':
      case 'R':
      case 'S':
 	Telephone.push_back( '7' );
	break;
      case 'T':
      case 'U':
      case 'V':
	Telephone.push_back( '8' );
	break;
      case 'W':
      case 'X':
      case 'Y':
      case 'Z':
	Telephone.push_back( '9' );
	break;
      default:
	Telephone.push_back( InputString[ K ] );
	break;
      }
    }
    
    cout << Telephone << endl;

  }

  return 0;
}
