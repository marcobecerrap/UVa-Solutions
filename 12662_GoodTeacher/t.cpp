// UVA-ID: 12662
// "Good Teacher"
// (cl) by mabp, January-2015.
#include <iostream>
#include <string>
using namespace std;

int main( int argc, char *argv[] ){

  int ClassSize;
  cin >> ClassSize;
  
  string Student[ ClassSize ];
  for( int K = 0; K < ClassSize; K++ ){
    cin >> Student[ K ];
  }

  int QuerySize;
  cin >> QuerySize;
  for( int K = 0; K < QuerySize; K++ ){

    int Query;
    cin >> Query;
    Query--;
    
    if( Student[ Query ] != "?" ){
      cout << Student[ Query ] << endl;
      continue;
    }

    int left = Query, right = Query;
    while( right < ClassSize ){
      if( Student[ right ] == "?" )
	right++;
      else
	break;
    }
    while( left >= 0 ){
      if( Student[ left ] == "?" )
	left--;
      else
	break;
    }

    if( left == -1 ){
      for( int P = 0; P < ( right - Query ); P++ )
	cout << "left of ";
      cout << Student[ right ] << endl;
      continue;
    }
    else if( right == ClassSize ){
      for( int P = 0; P < ( Query - left ); P++ )
    	cout << "right of ";
      cout << Student[ left ] << endl;
      continue;
    }
    else if( ( Query - left ) == ( right - Query ) ){
      cout << "middle of " << Student[ left ] << " and " << Student[ right ] << endl;
      continue;
    }
    else if( ( Query - left ) < ( right - Query ) ){
      for( int P = 0; P < ( Query - left ); P++ )
    	cout << "right of ";
      cout << Student[ left ] << endl;
      continue;
    }
    else if( ( Query - left ) > ( right - Query ) ){
      for( int P = 0; P < ( right - Query ); P++ )
    	cout << "left of ";
      cout << Student[ right ] << endl;
      continue;
    }    
  }

  return 0;
}
