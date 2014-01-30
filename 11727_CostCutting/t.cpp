// UVA-ID: #11727
// "Cost Cutting"
// (cl) by mabp, sep-2013.
#include <iostream>
using namespace std;

void SwapNumbers( int *A, int *B );

int main( int argc, char *argv[] ){
  int nCases;
  int iCases = 0;
  cin >> nCases;
  
  int SalaryA, SalaryB, SalaryC;
  
  while( cin >> SalaryA >> SalaryB >> SalaryC ){
    iCases++;

    if( SalaryA > SalaryB )
      SwapNumbers( &SalaryA, &SalaryB );
    if( SalaryB > SalaryC )
      SwapNumbers( &SalaryB, &SalaryC );
    if( SalaryA > SalaryB )
      SwapNumbers( &SalaryA, &SalaryB );
    
    cout << "Case " << iCases << ": " << SalaryB << endl;
    

    // End of program condition
    if( iCases == nCases )
      break;
  }


  return 0;
}

void SwapNumbers( int *A, int *B ){
  int T;
  T = *A;
  *A = *B;
  *B = T;
}
