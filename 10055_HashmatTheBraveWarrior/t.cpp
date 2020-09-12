// UVA-ID: #10055
// "Hashmat the Brave Warrior"
// (cl) by mabp, sep-2013.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){

  long ArmyHashmat;
  long ArmyEnemy;

  while( cin >> ArmyHashmat >> ArmyEnemy ){
    
    if( ArmyHashmat < ArmyEnemy )
      cout << ( ArmyEnemy - ArmyHashmat ) << endl;
    else
      cout << ( ArmyHashmat - ArmyEnemy ) << endl; // In this case they are swapped      
  }

  return 0;
}
