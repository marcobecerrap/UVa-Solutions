// UVA-ID: #272
// "TEX Quotes"
// (cl) by mabp, sep-2013.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){
  char s;
  int count = 0;
  
  while ( cin.get( s ) ){
    if( s == '"' ){
      cout << ( (count == 0) ? "``" : "''" );
      count ^= 1;
    }
    else 
      cout << s;
  }

  return 0;
}
