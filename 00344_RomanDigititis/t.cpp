// UVA-ID: 344
// "Roman Digititis"
// (cl) by mabp, January-2015.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){


  string Units[ 10 ]  = { "", "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix" };
  string Decens[ 10 ] = { "", "x", "xx", "xxx", "xl", "l", "lx", "lxx", "lxxx", "xc" };
  string Centens[ 2 ] = { "", "c" };

  int i_Units[ 10 ]  = { 0, 1, 2, 3, 1, 0, 1, 2, 3, 1 };
  int v_Units[ 10 ]  = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 0 };
  int x_Units[ 10 ]  = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
  int x_Decens[ 10 ] = { 0, 1, 2, 3, 1, 0, 1, 2, 3, 1 };
  int l_Decens[ 10 ] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 0 };
  int c_Decens[ 10 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
  int c_Centens[ 2 ] = { 0, 1 };
  
  int i_Count[ 101 ];
  int v_Count[ 101 ];
  int x_Count[ 101 ];
  int l_Count[ 101 ];
  int c_Count[ 101 ];

  i_Count[ 0 ] = 0;
  v_Count[ 0 ] = 0;
  x_Count[ 0 ] = 0;
  l_Count[ 0 ] = 0;
  c_Count[ 0 ] = 0;
  for( int K = 1; K <= 100; K++ ){
    int n_units   = K % 10;
    int n_centens = K / 100;
    int n_decens  =  ( K - (n_centens * 100 ) - n_units ) / 10;
    
    i_Count[ K ] = i_Count[ K - 1 ] + i_Units[ n_units ];
    v_Count[ K ] = v_Count[ K - 1 ] + v_Units[ n_units ];
    x_Count[ K ] = x_Count[ K - 1 ] + x_Units[ n_units ] + x_Decens[ n_decens ];
    l_Count[ K ] = l_Count[ K - 1 ] + l_Decens[ n_decens ];
    c_Count[ K ] = c_Count[ K - 1 ] + c_Decens[ n_decens ] + c_Centens[ n_centens];
    
    //cout << K << ") i" << i_Count[K] << " v" << v_Count[K] << " x" << x_Count[K] << " l" << l_Count[K] << " " << c_Count[K] << endl;
    
  }


  int InputNumber;
  while( cin >> InputNumber ){
    
    if( InputNumber == 0 )
      break;
    
    int K = InputNumber;
    cout << K << ": " << i_Count[K] << " i, " << v_Count[K] << " v, " << x_Count[K] << " x, " << l_Count[K] << " l, " << c_Count[K] << " c" << endl;
    
  }

  return 0;
}
