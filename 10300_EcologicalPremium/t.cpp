// UVA-ID: #10300
// "Ecological Premium"
// (cl) by mabp, oct-2013.
#include <iostream>
using namespace std;

typedef unsigned long long ULONG;

int main( int argc, char *argv[] ){

  int NCases;
  cin >> NCases;

  int NFarmers;
  int SizeFarm, NumberAnimals, EnvironmentFriend;
  double Payment;
  double TotalPayment;
  for( int K = 0; K < NCases; K++ ){
    cin >> NFarmers;
    TotalPayment = 0;
    for( int L = 0; L < NFarmers; L++ ){
      cin >> SizeFarm >> NumberAnimals >> EnvironmentFriend;
      Payment = ( ( ( (double) SizeFarm ) / ( (double) NumberAnimals ) ) * EnvironmentFriend ) * NumberAnimals;
      TotalPayment += Payment;
    }
    
    cout << (int) TotalPayment << endl;
  }
  
  return 0;
}
