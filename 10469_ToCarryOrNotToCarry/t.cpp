// UVA-ID: 10469
// "ToCarry Or Not To Carry"
// (cl) by mabp, January-2015.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){

  long InputNumber1, InputNumber2;
  
  while( cin >> InputNumber1 >> InputNumber2 )
    cout << ( InputNumber1 ^ InputNumber2 ) << endl;

  return 0;
}
