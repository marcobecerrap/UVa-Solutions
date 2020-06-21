// UVA-ID: 11984
// "A Change In Thermal Unit"
// (cl) by mabp, February-2015.
#include <iostream>
#include <cmath>
using namespace std;

int main( int argc, char *argv[] ){

  int Size;
  cin >> Size;
  
  for( int K =0; K < Size; K++ ){
    double Tc_0, Tc_1;
    double Tf_0, Tf_i, Tf_1;

    cin >> Tc_0 >> Tf_i;
    
    Tf_0 = ( 1.8 * Tc_0 ) + 32;
    Tf_1 = Tf_0 + Tf_i;
    
    Tc_1 = ( ( Tf_1 - 32 ) * 500 ) / 9;
    Tc_1 = round( Tc_1 ) / 100;
    
    cout.precision( 2 );
    std::cout.setf( std::ios::fixed, std:: ios::floatfield );
    cout << "Case " << ( K + 1 ) << ": " << Tc_1 << endl;
  }
  
  return 0;
}
