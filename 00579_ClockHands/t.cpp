// UVA-ID: #579
// "ClockHands"
// (cl) by mabp, sep-2013.
#include <iostream>
#include <cmath>
using namespace std;

void SwapNumbers( double *A, double *B );


int main( int argc, char *argv[] ){
  double Hour = 0;
  double Min = 0;
  double H_Advance;
  double Angle;
  char c_aux;
  
  while( cin >> Hour >> c_aux >> Min  ){
    if( c_aux!= ':' ) // Invalid input
      continue;
    
    // End of program condition
    if( Hour == 0 && Min == 0)
      break;

    // Advance of the Hour because of the Mins
    H_Advance = Min / 60.0;

    // 0-360
    Hour =  ( Hour == 12 ) ? 0 : Hour; 
    Hour += H_Advance;
    Hour *= 30;
    Min *= 6;
    
    if( Hour > Min )
      SwapNumbers( &Hour, &Min );
    
    Angle = Min - Hour;
    
    Angle = ( Angle < ( 360 - Angle ) ) ? Angle : ( 360 - Angle );
    // Round to 3 decimals.
    Angle *= 1000;
    Angle = round( Angle );
    Angle /= 1000;

    cout.precision(3);
    cout.setf( std::ios::fixed, std:: ios::floatfield ); // floatfield set to fixed
    cout << Angle << endl;
  }    

  return 0;
}

void SwapNumbers( double *A, double *B ){
  double T;
  T = *A;
  *A = *B;
  *B = T;
}

