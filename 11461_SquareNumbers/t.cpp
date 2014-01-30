// UVA-ID: #11461
// "Square Numbers"
// (cl) by mabp, oct-2013.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ULONG;

vector <int> SquareVector;

void InitSquareVector();


int main( int argc, char *argv[] ){

  InitSquareVector();

  int Num1, Num2;
  
  while( cin >> Num1 >> Num2 ){
    // Exit condition
    if( Num1 == 0 && Num2 == 0 )
      break;
    
    // Sorting
    if( Num1 > Num2 ){
      int T = Num1;
      Num1 = Num2;
      Num2 = T;
    }
    
    cout << ( ( upper_bound( SquareVector.begin(), SquareVector.end(), Num2 ) ) - ( lower_bound( SquareVector.begin(), SquareVector.end(), Num1 ) ) ) << endl;
      
  }

  
  //// Generator of Square Numbers
  // for( int K = 0; K < 1000; K++ ){
  //   cout << "SquareVector.push_back( " << ( K * K ) << " );" << endl;
  //   if ( ( K * K ) >= 100000 )
  //     break;
  // }

  return 0;
}

void InitSquareVector(){
  SquareVector.push_back( 0 );
  SquareVector.push_back( 1 );
  SquareVector.push_back( 4 );
  SquareVector.push_back( 9 );
  SquareVector.push_back( 16 );
  SquareVector.push_back( 25 );
  SquareVector.push_back( 36 );
  SquareVector.push_back( 49 );
  SquareVector.push_back( 64 );
  SquareVector.push_back( 81 );
  SquareVector.push_back( 100 );
  SquareVector.push_back( 121 );
  SquareVector.push_back( 144 );
  SquareVector.push_back( 169 );
  SquareVector.push_back( 196 );
  SquareVector.push_back( 225 );
  SquareVector.push_back( 256 );
  SquareVector.push_back( 289 );
  SquareVector.push_back( 324 );
  SquareVector.push_back( 361 );
  SquareVector.push_back( 400 );
  SquareVector.push_back( 441 );
  SquareVector.push_back( 484 );
  SquareVector.push_back( 529 );
  SquareVector.push_back( 576 );
  SquareVector.push_back( 625 );
  SquareVector.push_back( 676 );
  SquareVector.push_back( 729 );
  SquareVector.push_back( 784 );
  SquareVector.push_back( 841 );
  SquareVector.push_back( 900 );
  SquareVector.push_back( 961 );
  SquareVector.push_back( 1024 );
  SquareVector.push_back( 1089 );
  SquareVector.push_back( 1156 );
  SquareVector.push_back( 1225 );
  SquareVector.push_back( 1296 );
  SquareVector.push_back( 1369 );
  SquareVector.push_back( 1444 );
  SquareVector.push_back( 1521 );
  SquareVector.push_back( 1600 );
  SquareVector.push_back( 1681 );
  SquareVector.push_back( 1764 );
  SquareVector.push_back( 1849 );
  SquareVector.push_back( 1936 );
  SquareVector.push_back( 2025 );
  SquareVector.push_back( 2116 );
  SquareVector.push_back( 2209 );
  SquareVector.push_back( 2304 );
  SquareVector.push_back( 2401 );
  SquareVector.push_back( 2500 );
  SquareVector.push_back( 2601 );
  SquareVector.push_back( 2704 );
  SquareVector.push_back( 2809 );
  SquareVector.push_back( 2916 );
  SquareVector.push_back( 3025 );
  SquareVector.push_back( 3136 );
  SquareVector.push_back( 3249 );
  SquareVector.push_back( 3364 );
  SquareVector.push_back( 3481 );
  SquareVector.push_back( 3600 );
  SquareVector.push_back( 3721 );
  SquareVector.push_back( 3844 );
  SquareVector.push_back( 3969 );
  SquareVector.push_back( 4096 );
  SquareVector.push_back( 4225 );
  SquareVector.push_back( 4356 );
  SquareVector.push_back( 4489 );
  SquareVector.push_back( 4624 );
  SquareVector.push_back( 4761 );
  SquareVector.push_back( 4900 );
  SquareVector.push_back( 5041 );
  SquareVector.push_back( 5184 );
  SquareVector.push_back( 5329 );
  SquareVector.push_back( 5476 );
  SquareVector.push_back( 5625 );
  SquareVector.push_back( 5776 );
  SquareVector.push_back( 5929 );
  SquareVector.push_back( 6084 );
  SquareVector.push_back( 6241 );
  SquareVector.push_back( 6400 );
  SquareVector.push_back( 6561 );
  SquareVector.push_back( 6724 );
  SquareVector.push_back( 6889 );
  SquareVector.push_back( 7056 );
  SquareVector.push_back( 7225 );
  SquareVector.push_back( 7396 );
  SquareVector.push_back( 7569 );
  SquareVector.push_back( 7744 );
  SquareVector.push_back( 7921 );
  SquareVector.push_back( 8100 );
  SquareVector.push_back( 8281 );
  SquareVector.push_back( 8464 );
  SquareVector.push_back( 8649 );
  SquareVector.push_back( 8836 );
  SquareVector.push_back( 9025 );
  SquareVector.push_back( 9216 );
  SquareVector.push_back( 9409 );
  SquareVector.push_back( 9604 );
  SquareVector.push_back( 9801 );
  SquareVector.push_back( 10000 );
  SquareVector.push_back( 10201 );
  SquareVector.push_back( 10404 );
  SquareVector.push_back( 10609 );
  SquareVector.push_back( 10816 );
  SquareVector.push_back( 11025 );
  SquareVector.push_back( 11236 );
  SquareVector.push_back( 11449 );
  SquareVector.push_back( 11664 );
  SquareVector.push_back( 11881 );
  SquareVector.push_back( 12100 );
  SquareVector.push_back( 12321 );
  SquareVector.push_back( 12544 );
  SquareVector.push_back( 12769 );
  SquareVector.push_back( 12996 );
  SquareVector.push_back( 13225 );
  SquareVector.push_back( 13456 );
  SquareVector.push_back( 13689 );
  SquareVector.push_back( 13924 );
  SquareVector.push_back( 14161 );
  SquareVector.push_back( 14400 );
  SquareVector.push_back( 14641 );
  SquareVector.push_back( 14884 );
  SquareVector.push_back( 15129 );
  SquareVector.push_back( 15376 );
  SquareVector.push_back( 15625 );
  SquareVector.push_back( 15876 );
  SquareVector.push_back( 16129 );
  SquareVector.push_back( 16384 );
  SquareVector.push_back( 16641 );
  SquareVector.push_back( 16900 );
  SquareVector.push_back( 17161 );
  SquareVector.push_back( 17424 );
  SquareVector.push_back( 17689 );
  SquareVector.push_back( 17956 );
  SquareVector.push_back( 18225 );
  SquareVector.push_back( 18496 );
  SquareVector.push_back( 18769 );
  SquareVector.push_back( 19044 );
  SquareVector.push_back( 19321 );
  SquareVector.push_back( 19600 );
  SquareVector.push_back( 19881 );
  SquareVector.push_back( 20164 );
  SquareVector.push_back( 20449 );
  SquareVector.push_back( 20736 );
  SquareVector.push_back( 21025 );
  SquareVector.push_back( 21316 );
  SquareVector.push_back( 21609 );
  SquareVector.push_back( 21904 );
  SquareVector.push_back( 22201 );
  SquareVector.push_back( 22500 );
  SquareVector.push_back( 22801 );
  SquareVector.push_back( 23104 );
  SquareVector.push_back( 23409 );
  SquareVector.push_back( 23716 );
  SquareVector.push_back( 24025 );
  SquareVector.push_back( 24336 );
  SquareVector.push_back( 24649 );
  SquareVector.push_back( 24964 );
  SquareVector.push_back( 25281 );
  SquareVector.push_back( 25600 );
  SquareVector.push_back( 25921 );
  SquareVector.push_back( 26244 );
  SquareVector.push_back( 26569 );
  SquareVector.push_back( 26896 );
  SquareVector.push_back( 27225 );
  SquareVector.push_back( 27556 );
  SquareVector.push_back( 27889 );
  SquareVector.push_back( 28224 );
  SquareVector.push_back( 28561 );
  SquareVector.push_back( 28900 );
  SquareVector.push_back( 29241 );
  SquareVector.push_back( 29584 );
  SquareVector.push_back( 29929 );
  SquareVector.push_back( 30276 );
  SquareVector.push_back( 30625 );
  SquareVector.push_back( 30976 );
  SquareVector.push_back( 31329 );
  SquareVector.push_back( 31684 );
  SquareVector.push_back( 32041 );
  SquareVector.push_back( 32400 );
  SquareVector.push_back( 32761 );
  SquareVector.push_back( 33124 );
  SquareVector.push_back( 33489 );
  SquareVector.push_back( 33856 );
  SquareVector.push_back( 34225 );
  SquareVector.push_back( 34596 );
  SquareVector.push_back( 34969 );
  SquareVector.push_back( 35344 );
  SquareVector.push_back( 35721 );
  SquareVector.push_back( 36100 );
  SquareVector.push_back( 36481 );
  SquareVector.push_back( 36864 );
  SquareVector.push_back( 37249 );
  SquareVector.push_back( 37636 );
  SquareVector.push_back( 38025 );
  SquareVector.push_back( 38416 );
  SquareVector.push_back( 38809 );
  SquareVector.push_back( 39204 );
  SquareVector.push_back( 39601 );
  SquareVector.push_back( 40000 );
  SquareVector.push_back( 40401 );
  SquareVector.push_back( 40804 );
  SquareVector.push_back( 41209 );
  SquareVector.push_back( 41616 );
  SquareVector.push_back( 42025 );
  SquareVector.push_back( 42436 );
  SquareVector.push_back( 42849 );
  SquareVector.push_back( 43264 );
  SquareVector.push_back( 43681 );
  SquareVector.push_back( 44100 );
  SquareVector.push_back( 44521 );
  SquareVector.push_back( 44944 );
  SquareVector.push_back( 45369 );
  SquareVector.push_back( 45796 );
  SquareVector.push_back( 46225 );
  SquareVector.push_back( 46656 );
  SquareVector.push_back( 47089 );
  SquareVector.push_back( 47524 );
  SquareVector.push_back( 47961 );
  SquareVector.push_back( 48400 );
  SquareVector.push_back( 48841 );
  SquareVector.push_back( 49284 );
  SquareVector.push_back( 49729 );
  SquareVector.push_back( 50176 );
  SquareVector.push_back( 50625 );
  SquareVector.push_back( 51076 );
  SquareVector.push_back( 51529 );
  SquareVector.push_back( 51984 );
  SquareVector.push_back( 52441 );
  SquareVector.push_back( 52900 );
  SquareVector.push_back( 53361 );
  SquareVector.push_back( 53824 );
  SquareVector.push_back( 54289 );
  SquareVector.push_back( 54756 );
  SquareVector.push_back( 55225 );
  SquareVector.push_back( 55696 );
  SquareVector.push_back( 56169 );
  SquareVector.push_back( 56644 );
  SquareVector.push_back( 57121 );
  SquareVector.push_back( 57600 );
  SquareVector.push_back( 58081 );
  SquareVector.push_back( 58564 );
  SquareVector.push_back( 59049 );
  SquareVector.push_back( 59536 );
  SquareVector.push_back( 60025 );
  SquareVector.push_back( 60516 );
  SquareVector.push_back( 61009 );
  SquareVector.push_back( 61504 );
  SquareVector.push_back( 62001 );
  SquareVector.push_back( 62500 );
  SquareVector.push_back( 63001 );
  SquareVector.push_back( 63504 );
  SquareVector.push_back( 64009 );
  SquareVector.push_back( 64516 );
  SquareVector.push_back( 65025 );
  SquareVector.push_back( 65536 );
  SquareVector.push_back( 66049 );
  SquareVector.push_back( 66564 );
  SquareVector.push_back( 67081 );
  SquareVector.push_back( 67600 );
  SquareVector.push_back( 68121 );
  SquareVector.push_back( 68644 );
  SquareVector.push_back( 69169 );
  SquareVector.push_back( 69696 );
  SquareVector.push_back( 70225 );
  SquareVector.push_back( 70756 );
  SquareVector.push_back( 71289 );
  SquareVector.push_back( 71824 );
  SquareVector.push_back( 72361 );
  SquareVector.push_back( 72900 );
  SquareVector.push_back( 73441 );
  SquareVector.push_back( 73984 );
  SquareVector.push_back( 74529 );
  SquareVector.push_back( 75076 );
  SquareVector.push_back( 75625 );
  SquareVector.push_back( 76176 );
  SquareVector.push_back( 76729 );
  SquareVector.push_back( 77284 );
  SquareVector.push_back( 77841 );
  SquareVector.push_back( 78400 );
  SquareVector.push_back( 78961 );
  SquareVector.push_back( 79524 );
  SquareVector.push_back( 80089 );
  SquareVector.push_back( 80656 );
  SquareVector.push_back( 81225 );
  SquareVector.push_back( 81796 );
  SquareVector.push_back( 82369 );
  SquareVector.push_back( 82944 );
  SquareVector.push_back( 83521 );
  SquareVector.push_back( 84100 );
  SquareVector.push_back( 84681 );
  SquareVector.push_back( 85264 );
  SquareVector.push_back( 85849 );
  SquareVector.push_back( 86436 );
  SquareVector.push_back( 87025 );
  SquareVector.push_back( 87616 );
  SquareVector.push_back( 88209 );
  SquareVector.push_back( 88804 );
  SquareVector.push_back( 89401 );
  SquareVector.push_back( 90000 );
  SquareVector.push_back( 90601 );
  SquareVector.push_back( 91204 );
  SquareVector.push_back( 91809 );
  SquareVector.push_back( 92416 );
  SquareVector.push_back( 93025 );
  SquareVector.push_back( 93636 );
  SquareVector.push_back( 94249 );
  SquareVector.push_back( 94864 );
  SquareVector.push_back( 95481 );
  SquareVector.push_back( 96100 );
  SquareVector.push_back( 96721 );
  SquareVector.push_back( 97344 );
  SquareVector.push_back( 97969 );
  SquareVector.push_back( 98596 );
  SquareVector.push_back( 99225 );
  SquareVector.push_back( 99856 );
  SquareVector.push_back( 100489 );
}

