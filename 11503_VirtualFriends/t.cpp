#include<iostream>
#include<map>
#include<vector>
using namespace std;

map <string, int> PeopleID;
vector <int> Parent;
vector <int> GroupSize;

int FindRootParent( int Person ){
  if( Parent[ Person ] != Person ){
    Parent[ Person ] = FindRootParent( Parent[ Person ] );
  }
  return Parent[ Person ];      
}


int main(){

  int TotalCases = 0;
  cin >> TotalCases;
  //cout << "CASES: " << TotalCases << endl;
  
  for( int CC = 0; CC < TotalCases; CC++ ){

    PeopleID.clear();
    Parent.clear();
    GroupSize.clear();
    int IDcount = 0;
    
    int TotalInteractions = 0;
    cin >> TotalInteractions;
    //cout << "INTERACTIONS: " << TotalInteractions << endl;
    for( int II = 0; II < TotalInteractions; II++ ){

      //cout << "===========" << endl;
      //cout << "IT " << II <<endl;
	
      string Friend_0, Friend_1;
      cin >> Friend_0 >> Friend_1;
      //cout << "FRIENDS: " << Friend_0 << " " << Friend_1 << endl;

      
      if( PeopleID.count( Friend_0 ) == 0 ){
	//cout << "ADDED: " << Friend_0 << endl;
	PeopleID[ Friend_0 ] = IDcount;
	Parent.push_back( IDcount );
	GroupSize.push_back( 1 );
	IDcount++;
      }
      if( PeopleID.count( Friend_1 ) == 0 ){
	//cout << "ADDED: " << Friend_1 << endl;
	PeopleID[ Friend_1 ] = IDcount;
	Parent.push_back( IDcount );
	GroupSize.push_back( 1 );
	IDcount++;
      }

      int ID_0 = PeopleID[ Friend_0 ];
      int ID_1 = PeopleID[ Friend_1 ];
      //cout << Friend_0 << "=" << ID_0 << "  " << Friend_1 <<"=" << ID_1 << endl;

      int Parent_0 = FindRootParent( ID_0 );
      int Parent_1 = FindRootParent( ID_1 );
      //cout << "pp0=" << Parent_0 << " pp1=" << Parent_1 << endl;
      if( Parent_0 != Parent_1 ){
	//cout << "MERGED" << endl;
	GroupSize[ Parent_0 ] += GroupSize[ Parent_1 ];
	Parent[ Parent_1 ] = Parent_0;
      }

      //cout << "Parent_0 = " << Parent[ ID_0 ] << "  Parent_1 = " << Parent[ ID_1 ] << endl;
      //cout << "P_0 = " << Parent[ Parent_0 ] << "  P_1 = " << Parent[ Parent_1 ]<< endl;
      //cout << "Size_0 = " << GroupSize[ Parent_0 ] << "  Size_1 = " << GroupSize[ Parent_1 ] << endl;

      cout << GroupSize[ Parent_0 ] << endl;
      
    }
  }
}
