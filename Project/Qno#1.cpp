#include <iostream>
using namespace std;
main() {
int numberOfStudents = 10, studentAges[numberOfStudents];
string studentNames[numberOfStudents]; 
char studentGrades[numberOfStudents];
for (int i = 0; i < numberOfStudents; ++i) {
	cout<<"Enter details for student "<<(i + 1)<<":"<<endl;
	cout<<"Name: "; 
	cin>>studentNames[i];
	cout<<"Age: ";
	cin>>studentAges[i]; 
	cout<<"Grade: "; 
	cin>>studentGrades[i];
	}
cout << "\nStudent List:" << endl;
for (int i = 0; i < numberOfStudents; ++i) {
	cout<<"Student "<<(i + 1)
	<<" - Name: "<<studentNames[i]
	<<", Age: "<<studentAges[i]
	<<", Grade: "<<studentGrades[i]<<endl;
} }