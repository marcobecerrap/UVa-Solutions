// UVA-ID: #10370
// "Above The Average"
// (cl) by mabp, sep-2013.
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

int main( int argc, char *argv[] ){
  int nCases;
  string InputString;

  cin >> nCases; // Getting the number of cases to test
  getline( cin, InputString ); // Erase the""\n"
  
  for( int K = 0; K < nCases; K++ ){
    int nStudents;    
    cin >> nStudents; // getting the number of students in a class

    vector <int> vStudentGrade; // Students' grades
    int i_aux;
    double GradeSum = 0;
    double AverageGrade;
    int AboveAverageStudentCount = 0;
    for( int M = 0; M < nStudents; M++ ){
      cin >> i_aux;
      vStudentGrade.push_back( i_aux );
      GradeSum += (double) i_aux;
    }
    
    
    AverageGrade = GradeSum / ( (double) nStudents );

    for( int M = 0; M < nStudents; M++ )
      if( vStudentGrade[ M ] > AverageGrade )
	AboveAverageStudentCount++;     
    
    double Percentage;
    Percentage = ( ( double ) AboveAverageStudentCount ) / ( ( double ) nStudents );

    // Rounding
    Percentage *= 100000;
    Percentage = round( Percentage );

    cout.precision(3);
    cout.setf( std::ios::fixed, std:: ios::floatfield ); // floatfield set to fixed
    cout << Percentage/1000 << "%" << endl;
  }

  return 0;
}
