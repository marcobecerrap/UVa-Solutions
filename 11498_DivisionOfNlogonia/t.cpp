// UVA-ID: #11498
// "Division of Nlogonia"
// (cl) by mabp, sep-2013.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){
  int nCases;
  int DivX, DivY;
  int HomeX, HomeY;

  while( cin >> nCases ){
    
    // End of program condition
    if( nCases == 0 )
      break;

    cin >> DivX >> DivY;
    
    for( int K = 0; K < nCases; K++ ){
      cin >> HomeX >> HomeY;
      
      if( HomeX == DivX || HomeY == DivY )
	cout << "divisa" << endl;
      else{
	if( HomeY > DivY )
	  cout << "N";
	else
	  cout << "S";
	if( HomeX > DivX )
	  cout << "E";
	else
	  cout << "O";
	cout << endl;
      }
    }    
  }    

  return 0;
}
