// UVA-ID: #438
// "The Circumference Of The Circle"
// (cl) by mabp, oct-2013.
#include <iostream>
#include <cmath>
using namespace std;

double EuclideanDistance( double X1, double Y1, double X2, double Y2 );

void SwapNumbers( double *A, double *B );

double const PI = 3.14159265359; 

int main( int argc, char *argv[] ){
  
  double X1, Y1, X2, Y2, X3, Y3;
  double M12, M23, M31;
  double X12, X23, X31;
  double Y12, Y23, Y31;
  double A1, B1, A2, B2;
  double X_Center, Y_Center;
  double Radius;
  
  while( cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3 ){

    if( ( Y2 - Y1 ) == 0 ){
      SwapNumbers( &X2, &X3  );
      SwapNumbers( &Y2, &Y3  );
    }
    else if( ( Y3 - Y2 ) == 0 ){
      SwapNumbers( &X2, &X1  );
      SwapNumbers( &Y2, &Y1  );
    }

    M12 = ( X2 - X1 ) / ( Y2 - Y1 );
    M23 = ( X3 - X2 ) / ( Y3 - Y2 );

    X12 = ( X1 + X2 ) / 2;
    Y12 = ( Y1 + Y2 ) / 2;
    X23 = ( X2 + X3 ) / 2;
    Y23 = ( Y2 + Y3 ) / 2;
    X31 = ( X1 + X3 ) / 2;
    Y31 = ( Y1 + Y3 ) / 2;

    A1 = -1 * M23;
    B1 = M23*X23 + Y23;
    A2 = -1 * M12;
    B2 = M12*X12 + Y12;

    X_Center = ( B2 - B1 ) / ( A1 - A2 );
    Y_Center = A1*X_Center + B1;

    Radius = EuclideanDistance( X1, Y1, X_Center, Y_Center );
    
    cout.precision( 2 );
    cout << fixed << ( round( 2 * Radius * PI * 100 ) / 100 ) << endl;
  }

  return 0;
}


double EuclideanDistance( double X1, double Y1, double X2, double Y2 ){
  return sqrt( ( X2 - X1 )*( X2 - X1 ) + ( Y2 - Y1 )*( Y2 - Y1 ) ); 
}


void SwapNumbers( double *A, double *B ){
  double T = *A;
  *A = *B;
  *B = T;  
}
