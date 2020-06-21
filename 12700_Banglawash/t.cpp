// UVA-ID: 12700
// "Banglawash"
// (cl) by mabp, January-2015.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){
  
  int Size;
  cin >> Size;
  for( int K = 0; K < Size; K++ ){
    
    int Matches;
    string Results;
    cin >> Matches;
    cin >> Results;
    
    int B_Count = 0, W_Count = 0, T_Count = 0, A_Count = 0; 
    for( int P = 0; P < Matches; P++ ){      
      switch( Results[ P ] ){
      case 'B':	
     	B_Count++;
    	break;
      case 'W':	
    	W_Count++;
    	break;
      case 'T':	
    	T_Count++;
    	break;
      case 'A':	
    	A_Count++;
    	break;
      }
    }

    cout << "Case " << ( K + 1 ) << ": ";
    if( A_Count == Matches ){
      cout << "ABANDONED\n";
      continue;
    }
    else if( ( B_Count + A_Count ) == Matches ){
      cout << "BANGLAWASH\n";
      continue;
    }
    else if( ( W_Count + A_Count ) == Matches ){
      cout << "WHITEWASH\n";
      continue;
    }
    else if( B_Count == W_Count ){
      cout << "DRAW " << W_Count << " " << T_Count << "\n";
      continue;
    }
    else if( B_Count > W_Count ){
      cout << "BANGLADESH " << B_Count << " - " << W_Count << "\n";
      continue;
    }
    else if( W_Count > B_Count ){
      cout << "WWW " << W_Count << " - " << B_Count << "\n";
      continue;
    }
  }
  
  return 0;
}
