// UVA-ID: 12646
// "Zero Or One"
// (cl) by mabp, January-2015.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){

  int Hand[ 3 ];
  while( cin >> Hand[ 0 ] >> Hand[ 1 ] >> Hand[ 2 ] ){
    int Sum = Hand[ 0 ] + Hand[ 1 ] + Hand[ 2 ];
    if( Sum == 0 || Sum == 3 )
      cout << "*" << endl;
    else if( Sum == 2 ){
      if( Hand[ 0 ] == 0 )
	cout << "A" << endl;
      else if( Hand[ 1 ] == 0 )
	cout << "B" << endl;
      else
	cout << "C" << endl;
    }
    else{
      if( Hand[ 0 ] == 1 )
	cout << "A" << endl;
      else if( Hand[ 1 ] == 1 )
	cout << "B" << endl;
      else
	cout << "C" << endl;
    }
  }

  return 0;
}
