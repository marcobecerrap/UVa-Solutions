// UVA-ID: 10033
// "Interpreter"
// (cl) by mabp, sept-2011.
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void AssignMemory( vector <int> *Memory );

int main( int argc, char *argv[] ){
  int nCases;
  string garbage;
  bool HaltCondition = false;
  int ProgramCounter;
  int InstructionRegister;  
  int InstructionCounter;
  // CMD = [Inst][Arg1][Arg2]
  int Inst;
  int Arg1;
  int Arg2;

  cin >> nCases;
  getline( cin, garbage );
  getline( cin, garbage );


  while( nCases > 0 ){    
    // Resets registers & RAM memory
    vector <int> Register( 10, 0 );
    vector <int> Memory( 1000, 0 );

    // Assign RAM memory
    AssignMemory( &Memory );

    InstructionCounter = 0;
    ProgramCounter = 0;
    HaltCondition = false;
    while( HaltCondition == false ){
      // FETCH
      InstructionRegister = Memory[ ProgramCounter ];      
      
      // DECODE
      Arg2 = InstructionRegister % 10;
      InstructionRegister -= Arg2;
      InstructionRegister /= 10;
      Arg1 = InstructionRegister % 10;
      InstructionRegister -= Arg1;
      InstructionRegister /= 10;
      Inst = InstructionRegister;
      
      // EXECUTE
      switch( Inst ){
      case 0:
	if( Register[ Arg2 ] == 0 )
	  ProgramCounter++;
	else
	  ProgramCounter = Register[ Arg1 ];	  
	break;
      case 1:	
	HaltCondition = true;
	break;
      case 2:
	Register[ Arg1 ] = Arg2;
	ProgramCounter++;
	break;
      case 3:
	Register[ Arg1 ] += Arg2;
	Register[ Arg1 ] %= 1000;
	ProgramCounter++;
	break;
      case 4:
	Register[ Arg1 ] *= Arg2;
	Register[ Arg1 ] %= 1000;
	ProgramCounter++;
	break;
      case 5:
	Register[ Arg1 ] = Register[ Arg2 ];
	ProgramCounter++;
	break;
      case 6:
	Register[ Arg1 ] += Register[ Arg2 ];
	Register[ Arg1 ] %= 1000;
	ProgramCounter++;
	break;
      case 7:
	Register[ Arg1 ] *= Register[ Arg2 ];
	Register[ Arg1 ] %= 1000;
	ProgramCounter++;
	break;
      case 8:
	Register[ Arg1 ] = Memory[ Register[ Arg2 ] ];
	ProgramCounter++;
	break;
      case 9:
	Memory[ Register[ Arg2 ] ] = Register[ Arg1 ];
	ProgramCounter++;
	break;
      }      
      InstructionCounter++;
    }
    cout << InstructionCounter << endl;;
   
    nCases--;
    
    if( nCases > 0 )
      cout << endl;
  }

  return 0;
}

void AssignMemory( vector <int> *Memory ){
  string sInput;
  int K = 0;
  while( true ){
    // Read string
    getline( cin, sInput );
    if( sInput.empty() == true )
      break;
    istringstream Input( sInput );
    // Asign data to memory
    Input >> (*Memory)[ K ];
    (*Memory)[ K ] %= 1000;
    K++;
  }
}

