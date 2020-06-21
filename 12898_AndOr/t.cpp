// UVA-ID: 12898
// "And Or"
// (cl) by mabp, January-2015.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){
  
  int Size;
  cin >> Size;
  
  for( int K = 0; K < Size; K++ ){
    unsigned long long NumberA, NumberB, AnswerOR, AnswerAND, Diff;
    cin >> NumberA >> NumberB;
    Diff = NumberB - NumberA;
    
    AnswerOR = NumberA;
    AnswerAND = NumberA;
    
    unsigned long long LastZero = 0, LastOne = 0;
    unsigned long long P;
    for(  P = 1; P <= Diff; P = P*2 ){
      AnswerOR  |= P;
      AnswerAND &= ~( P );
      NumberB = ( NumberB >> 1 );
      NumberA = ( NumberA >> 1 );
    }
    while( NumberA != NumberB ){
      AnswerOR  |= P;
      AnswerAND &= ~( P );
      NumberB = ( NumberB >> 1 );
      NumberA = ( NumberA >> 1 );
      P *= 2;
    }


    cout << "Case " << ( K + 1 ) << ": " << AnswerOR << " " << AnswerAND << endl;

  }

  return 0;
}
