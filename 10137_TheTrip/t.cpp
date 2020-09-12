// UVA-ID: 10137
// "The Trip"
// (cl) by mabp, sept-2011
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef unsigned int UINT;

int main( int argc , char *argv[] ){
  const int STUDENTS_MAX = 1001;
  double Students_SZ; // Number of students
  double Cents[ STUDENTS_MAX ]; // Expenses of students (cents)
  double Mean;     // Mean Expenses of each student (cents)
  double Residual; // Residual cents after the mean value (cents)
  double Total;    // Total Expences (cents)
  double Change;   // Money moving of hand (cents)


  while( cin >> Students_SZ ){
    // Finish condition
    if( Students_SZ == 0 ) 
      break;
    
    // Read expences of students
    Total = 0;
    for(int K = 0 ; K < Students_SZ ; K++ ){
      cin >> Cents[ K ];
      Cents[ K ] *= 100;
      Total += Cents[ K ];
    }

    // Obtaining MeanVal & Residual Cents
    Residual = fmod( Total , Students_SZ );
    Mean     = ( Total - Residual) / Students_SZ;

    // Obtaining the money moving of hand
    Change = 0;
    for(int K = 0 ; K < Students_SZ ; K++ ){
      if( Cents[ K ] > Mean ){
	Change += ( Cents[ K ] - Mean );
	if( Residual > 0 ){
	  Change   -= 1;
	  Residual -= 1;
	}
      }
    }
        
    // Write routine
    cout << fixed;
    cout << "$" << setprecision( 2 ) << ( Change / 100 ) << endl; 
  }

  return 0;
}
