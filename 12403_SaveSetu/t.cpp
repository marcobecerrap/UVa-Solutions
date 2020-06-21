// UVA-ID: 12403
// "Save Setu"
// (cl) by mabp, January-2015.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){

  int Size;
  cin >> Size;

  int Money = 0;
  for( int K = 0; K < Size; K++ ){
    string InputString;
    int InputMoney;
    
    cin >> InputString;
    
    if( InputString == "report" ){
      cout << Money << endl;
      continue;
    }
    
    cin >> InputMoney;
    Money += InputMoney;    
  }
  
  return 0;
}
