#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char quiz;
void login();
void registration();
void homePage();
void beginner();
void intermediate();
void advance();
bool comparePrograms(const string& userProgramPath);
void retake();

int main() {
    int c;
	cout<<"\t\t\t_____________________________________________________\n\n\n";
	cout<<"\t\t\t            Welcome to the Login Page                \n\n\n";
	cout<<"\t\t\t________________     MENU   _________________________\n\n\n";
	cout<<"                                                             \n\n";
	cout<<"\t| Press 1 to LOGIN        |\n";
	cout<<"\t| Press 2 to REGISTER     |\n";
	cout<<"\t| Press 3 to EXIT         |\n";
	cout<<"\n\t\t\t Please Enter your Choice : ";
	cin>>c;
	cout<<endl;
	
	switch(c){
		case 1: {
			login();
			break;
		}
		case 2: {
			registration();
			break;
		}
		case 3: {
			system("cls");
			cout<<"\t\t\t   THANK YOU! \n\n ";
			break;
		}
		default: {
			system("cls");
			cout<<"\t\t\t Please select Option from Below: \n\n";
			main();
		}
	}
    return 0;
}
void login(){
	int Count=0;
	string userID,password,id,pass;
	system("cls");
	cout<<"\t\t\t USERNAME: ";
	cin>>userID;
	cout<<"\t\t\t PASSWORD: ";
	cin>>password;
	
	ifstream input("records.txt");
	
	while(input>>id>>pass){
		if(userID==id && password==pass){
			Count=1;
			system("cls");
		}
	}
	input.close();
	if(Count==1) {
		cout<<"\t\t\t Sucessfully Login! \n\n";
		homePage();
	} else {
		cout<<"\t\t\t INVALID USERNAME OR PASSWORD! \n\n";
		main();
	}
}
void registration(){
	int Count=0;
	string ruserID,rpassword;
	system("cls");
	cout<<"\t\t\t USERNAME: ";
	cin>>ruserID;
	cout<<"\t\t\t PASSWORD: ";
	cin>>rpassword;
	
	ofstream f1("records.txt", ios::app);
	f1<<ruserID<<' '<<rpassword;
	system("cls");
	cout<<"\t\t\t Sucessfully Register!\n";
	homePage();
}
void homePage(){
	cout<<"\t| Press B for Beginner     level |\n";
	cout<<"\t| Press I for Intermediate level |\n";
	cout<<"\t| Press A for Advanced     level |\n";
	cout<<"\t\t\t Enter Your Choice : ";
	cin>>quiz;
	
	switch(quiz){
		case 'B' :{
			beginner();
			break;
		}
		case 'I' :{
			intermediate();
			break;
		}
		case 'A' :{
			advance();
			break;
		}
		default:{
			system("cls");
			cout<<"\t\t\t Please select Option from Below: \n\n";
			homePage();
		}
	}
}
void beginner() {
    string ans;
    cout<<"\t\t\t Welcome to C++ Beginner QUIZZZZZ " << endl;
    cout<<"Question NO 1:" << endl;
    cout<<"How many Types of Programming Language are there.............?" << endl;
    cin >> ans;
    if (ans == "Two") {
    	system("cls");
        cout<<"Question NO 2" << endl;
        cout<<"Name any one..." << endl;
        cin >> ans;
        if (ans == "High_level" || ans == "Low_level") {
            system("cls");
			cout<<"Question No 3" << endl;
            cout<<"C++ is Developed by........?" << endl;
            cin >> ans;
            if (ans == "Bjarne") {
                system("cls");
				cout<<"Question No 4" << endl;
                cout<<"C++ is Developed at........?" << endl;
                cin >> ans;
                if (ans == "Bell_lab") {
                    system("cls");
					cout<<"Question No 5" << endl;
                    cout<<"C++ is Developed in.........?" << endl;
                    cin >> ans;
                    if (ans == "1980") {
                    	system("cls");
                        cout << "\n\n \t\t\t!!!!!Congratulations!!!!! \n\n";
                        intermediate();
                    } else {
                        retake();
                    }
                } else {
                    retake();
                }
            } else {
                retake();
            }
        } else {
            retake();
        }
    } else {
        retake();
    }
}
void retake() {
    char ch;
    cout<<"\t\t\t  ohhhhhhhh Wrong Answer !!!\n\n";
    cout<<"\t| Press R for Retake Quiz        |\n";
	cout<<"\t| Press L for Learning Path      |\n";
    cin >> ch;
    if (ch == 'R') {
        if (quiz == 'B') {
            beginner();
        } else if (quiz == 'I') {
            intermediate();
        } else {
            advance();
        }
    } else {
        cout << "https://www.w3schools.com/cpp/";
    }
}
void intermediate() {
    string ans;
    cout << "\t\t\t Welcome to C++ Intermediate  QUIZZZZZ " << endl;
    cout << "Question NO 1:" << endl;
    cout << "How to declare a variable in C++...........?" << endl;
    cin >> ans;
    if (ans == "datatype_variablename_=_value;") {
    	system("cls");
        cout << "Question NO 2" << endl;
        cout << "In How many ways can we initialize Variable in C++......" << endl;
        cin >> ans;
        if (ans == "Two") {
            cout << "Question No 3" << endl;
            cout << "Increments Type" << endl;
            cin >> ans;
            if (ans == "Two") {
                cout << "\n\n \t\t!!!!!Congratulations!!!!!\n\n";
                advance();
            } else {
                retake();
            }
        } else {
            retake();
        }
    } else {
        retake();
    }
}
void advance() {
    string userProgramPath;
    cout << "\t\t\t Welcome to C++ Advanced  QUIZZZ" << endl;
    cout<<"Question No 1: \n A C++ program that gathers a list of student information,with each student having attributes like name, age, and grade, using different arrays, and then displays the list with all these details. \n\n";
    cout << "Enter the path to the user's program file: ";
    cin.ignore(); 
    getline(cin, userProgramPath);

  

    ifstream yourFile("Qno#1.cpp");
    ifstream userFile(userProgramPath);

    if (!yourFile.is_open()) {
        cout << "\t\t\t Error opening your program file." << endl;
        return;
    }
    if (!userFile.is_open()) {
        cout << "\t\t\t Error opening the user's program file." << endl;
        return;
    }

    if (!comparePrograms(userProgramPath)) {       
		retake();
    } else {
        cout<<"\n\n \t\t!!!!!Congratulations!!!!!\n\n";
        cout<<"\t\t\t Your program is correct."<<endl;
    }
    yourFile.close();
    userFile.close();
}

bool comparePrograms(const string& userProgramPath) {
    ifstream userFile(userProgramPath);
    ifstream yourFile("Qno#1.cpp");

    if (!userFile.is_open() || !yourFile.is_open()) {
        cout << "\t\t\t Error opening files." << endl;
        return false;
    }

    string userLine, yourLine;
    while (getline(userFile, userLine) && getline(yourFile, yourLine)) {
        if (userLine != yourLine) {
            return false; // Programs don't match
        }
    }

    // If reached here, all lines match, so programs are identical
    return true;
}

