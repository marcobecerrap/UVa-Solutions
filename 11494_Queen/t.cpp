// UVA-ID: 11494
// "Queen"
// (cl) by mabp, January-2014.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){

  int Px_0, Py_0, Px_1, Py_1;

  while( cin >> Px_0 >> Py_0 >> Px_1 >> Py_1 ){

    if( Px_0 == 0 )
      break;
    
    if( Px_0 == Px_1 && Py_0 == Py_1){
      cout << 0 << endl;
      continue;
    }
    
    Px_0--;
    Py_0--;
    Px_1--;
    Py_1--;

    int Px_aux, Py_aux;
    int Moves = 0;

    Px_aux = Px_0; Py_aux = Py_0;    
    for( int Kx = 0; Px_aux < 8 && Px_aux >= 0 && Kx < 8 && Moves == 0 ; Kx++ ){
      for( int Ky = 0; Py_aux < 8 && Py_aux >= 0 && Ky < 8 && Moves == 0; Ky++ ){
	Px_aux++;
	Py_aux++;
	if( Px_aux == Px_1 && Py_aux == Py_1 )
	  Moves =1;
      }
    }

    Px_aux = Px_0; Py_aux = Py_0;    
    for( int Kx = 0; Px_aux < 8 && Px_aux >= 0 && Kx < 8 && Moves == 0 ; Kx++ ){
      for( int Ky = 0; Py_aux < 8 && Py_aux >= 0 && Ky < 8 && Moves == 0; Ky++ ){
	Px_aux++;
	Py_aux--;
	if( Px_aux == Px_1 && Py_aux == Py_1 )
	  Moves =1;
      }
    }

    Px_aux = Px_0; Py_aux = Py_0;    
    for( int Kx = 0; Px_aux < 8 && Px_aux >= 0 && Kx < 8 && Moves == 0 ; Kx++ ){
      for( int Ky = 0; Py_aux < 8 && Py_aux >= 0 && Ky < 8 && Moves == 0; Ky++ ){
	Px_aux--;
	Py_aux++;
	if( Px_aux == Px_1 && Py_aux == Py_1 )
	  Moves =1;
      }
    }

    Px_aux = Px_0; Py_aux = Py_0;    
    for( int Kx = 0; Px_aux < 8 && Px_aux >= 0 && Kx < 8 && Moves == 0 ; Kx++ ){
      for( int Ky = 0; Py_aux < 8 && Py_aux >= 0 && Ky < 8 && Moves == 0; Ky++ ){
	Px_aux--;
	Py_aux--;
	if( Px_aux == Px_1 && Py_aux == Py_1 )
	  Moves =1;
      }
    }

    Px_aux = Px_0; Py_aux = Py_0;    
    for( int Kx = 0; Px_aux < 8 && Px_aux >= 0 && Kx < 8 && Moves == 0 ; Kx++ ){
      for( int Ky = 0; Py_aux < 8 && Py_aux >= 0 && Ky < 8 && Moves == 0; Ky++ ){
	Px_aux++;
	if( Px_aux == Px_1 && Py_aux == Py_1 )
	  Moves =1;
      }
    }

    Px_aux = Px_0; Py_aux = Py_0;    
    for( int Kx = 0; Px_aux < 8 && Px_aux >= 0 && Kx < 8 && Moves == 0 ; Kx++ ){
      for( int Ky = 0; Py_aux < 8 && Py_aux >= 0 && Ky < 8 && Moves == 0; Ky++ ){
	Px_aux--;
	if( Px_aux == Px_1 && Py_aux == Py_1 )
	  Moves =1;
      }
    }

    Px_aux = Px_0; Py_aux = Py_0;    
    for( int Kx = 0; Px_aux < 8 && Px_aux >= 0 && Kx < 8 && Moves == 0 ; Kx++ ){
      for( int Ky = 0; Py_aux < 8 && Py_aux >= 0 && Ky < 8 && Moves == 0; Ky++ ){
	Py_aux++;
	if( Px_aux == Px_1 && Py_aux == Py_1 )
	  Moves =1;
      }
    }

    Px_aux = Px_0; Py_aux = Py_0;    
    for( int Kx = 0; Px_aux < 8 && Px_aux >= 0 && Kx < 8 && Moves == 0 ; Kx++ ){
      for( int Ky = 0; Py_aux < 8 && Py_aux >= 0 && Ky < 8 && Moves == 0; Ky++ ){
	Py_aux--;
	if( Px_aux == Px_1 && Py_aux == Py_1 )
	  Moves =1;
      }
    }
    
    if( Moves == 1 )
      cout << 1 << endl;
    else
      cout << 2 << endl;

  }

  return 0;
}
