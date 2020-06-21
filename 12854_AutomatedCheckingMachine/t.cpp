// UVA-ID: 12854
// "Automated Checking Machine"
// (cl) by mabp, January-2015.
#include <iostream>
using namespace std;

int main( int argc, char *argv[] ){

  int ConnectorA[ 5 ], ConnectorB[ 5 ];
  
  while( cin >> ConnectorA[ 0 ] >> ConnectorA[ 1 ] >> ConnectorA[ 2 ] >> ConnectorA[ 3 ] >> ConnectorA[ 4 ] ){
    cin >> ConnectorB[ 0 ] >> ConnectorB[ 1 ] >> ConnectorB[ 2 ] >> ConnectorB[ 3 ] >> ConnectorB[ 4 ];
    int Flag = 0;
    for( int K = 0; K < 5; K++ ){
      if( ConnectorA[ K ] == ConnectorB[ K ] ){
	Flag = 1;
	break;
      }
    }
    if( Flag == 0 )
      cout << "Y" << endl;
    else
      cout << "N" << endl;
  }
  
  return 0;
}
