// UVA-ID: 11636
// "Hello World!"
// (cl) by mabp, January-2015.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){

  int Input;
  int CaseCount = 1;
  while( cin >> Input ){

    if( Input < 0 )
      break;
    

    int Count = 0;
    int Copies = 1;
    while( Copies < Input ){
      Copies *= 2;
      Count++;
    }
    
    cout << "Case " << CaseCount << ": " << Count << endl;
    CaseCount++;
  }
  
  return 0;
}
