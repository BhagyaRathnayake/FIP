#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include<Windows.h>

using namespace std;

// Function prototype declareation

bool checkLogin(const string& username, const string& password, bool isAdmin);
bool repeatAction();
bool exitMainMenu();
void addCourseDetails();
void viewCourseDetails();
void addStaffDetails();
void viewStaffDetails();
void addStudentDetails();
void viewStudentDetails();
void searchStudentDetails();
void viewCompanyDetails();
int showLoginMenu();
int showAdminMenu();
int showStaffMenu();
bool processLogin();

// Structure to store student details
struct Student {
    string name;
    string idNo;
    string birth;
    string program;
    int contactNum;
};


const int maxStudents = 100;
Student studentList[maxStudents];
int studentCount = 0;

// Structure to store staff details
struct staff {
    string name;
    string idNo;
    string birth;
    string department;
    int contactNum;
};

const int maxStaff = 100;
staff staffList[maxStaff];
int staffCount = 0;


// Main function
int main() {
	
	system("color 9");//Background color and letters
    bool continueProcessing = true;
    while (continueProcessing) {
        continueProcessing = processLogin();
    }
    return 0;
}

// Function to check login credentials
bool checkLogin(const string& username, const string& password, bool isAdmin) {
    if (isAdmin) {
        return ((username == "Admin" || username == "admin") && password == "1234");
    } else {
        return ((username == "Staff" || username == "staff") && password == "123");
    }
}

// Function to prompt user if they want to repeat an action
bool repeatAction() {
    char choice;
    cout<< "\n";
    cout << "\tTo repeat the action press (R) or to exit to main menu press (E) : ";
    cin >> choice;
    return (choice == 'R' || choice == 'r');
}

// Function to prompt user if they want to exit to the main menu
bool exitMainMenu() {
    char choice;
    cout<< "\n";
    cout << "\tTo exit to the main menu press (M): ";
    cin >> choice;
    return (choice == 'k' || choice == 'k');

}

// Function to add course details to a file
void addCourseDetails() {

    do {system("cls");
        fstream file("courses.txt", ios::app); // Open file in append mode
        string courseName, duration, courseFee;
        
        cout<< "\n"<<"\n"<<"\n";
        cout << "\tEnter the course name: ";
        cin.ignore();// Ignore any remaining characters in the input buffer
        getline(cin, courseName); // Read a full line of input, including whitespaces
        
        cout << "\tEnter the course duration: ";
        getline(cin, duration);
        
        cout << "\tEnter the course fee : ";
        getline(cin, courseFee);
        
        file << courseName << "|" << duration << "|" << courseFee << endl; // Write course details to the file
        cout<<endl;
        
        file.close();
        
        system("cls");
        cout<< "\n";
        Sleep(1200);
        cout << "\t***********************************" << endl;
        cout << "\t Course details added successfully " << endl;
        cout << "\t***********************************" << endl;
    } while (repeatAction());
}

// Function to view course details from a file
void viewCourseDetails() {
system("cls");
    do {
        ifstream file("courses.txt"); // Open file for reading
        string line;
        int count = 0;
        
    cout<< "\n"<<"\n"<<"\n";
	cout << "\t**************************" << endl;
    cout << "\t***** Course Details *****" << endl;
    cout << "\t**************************" << endl;
    cout<< "\n";
        while (getline(file, line)) { // Read each line from the file
            count++;
            stringstream ss(line); // Create a stringstream to process the line 
            string courseName, duration, courseFee;
            getline(ss, courseName, '|'); // Extract course details using '|' as delimiter
            getline(ss, duration, '|');
            getline(ss, courseFee, '|');
            cout << "\tCourse " << count << ":" << endl;
            cout << "\tCourse name: " << courseName << endl;
            cout << "\tCourse duration: " << duration << endl;
            cout << "\tCourse fee: " << courseFee << endl;
            cout << endl;
        }
        file.close(); // Close the file 
    } while (exitMainMenu());

} 

// Function to add staff details
void addStaffDetails() {
	
    do {
    	system("cls");
    	cout<< "\n"<<"\n"<<"\n";
        cout << "\tEnter the full name : ";
        cin.ignore(); // Ignore any remaining characters in the input buffer
        getline(cin, staffList[staffCount].name); // Read staff name
        
        cout << "\tEnter the ID number : ";
        cin >> staffList[staffCount].idNo; // Read staff ID number
        
        cout << "\tEnter the date of birth : ";
        cin >> staffList[staffCount].birth; // Read staff date of birth 
        
        cout << "\tEnter the department : ";	
        cin >> staffList[staffCount].department; // Read staff department
        
        cout << "\tEnter the Contact number : ";
        cin >> staffList[staffCount].contactNum; // Read staff contact number
        
        staffCount++; // Increment staff count
        
        system("cls");
        Sleep(1200);
        cout<<"\n";
        cout << "\t*********************************" << endl;
        cout << "\t Staff details added successfully " << endl;
        cout << "\t*********************************" << endl;
    } while (repeatAction());
}
	
// Function to view staff details
void viewStaffDetails() {
system("cls");
    do {
    	cout<< "\n"<<"\n"<<"\n";
    	cout << "\t***************" << endl;
        cout << "\t Staff details " << endl;
        cout << "\t***************" << endl;
        cout <<endl;
        for (int i = 0; i < staffCount; i++) {
            cout << "\tName: " << staffList[i].name << endl;
            cout << "\tID number : " << staffList[i].idNo << endl;
            cout << "\tDate of birth : " << staffList[i].birth << endl;
            cout << "\tDepartmernt : " << staffList[i].department << endl;
            cout << "\tContact number : "<< staffList[i].contactNum << endl;
            cout<<endl;
        }
    } while (exitMainMenu());
}

// Function to add student details
void addStudentDetails() {
	
    do {
    	system("cls");
    	cout<< "\n"<<"\n"<<"\n";
        cout << "\tEnter student name : ";
        cin.ignore(); // Ignore any remaining characters in the input buffer
        getline(cin, studentList[studentCount].name); // Read student name
        
        cout << "\tEnter student ID number : ";
        cin >> studentList[studentCount].idNo;
        
        cout << "\tEnter student date of birth : ";
        cin >> studentList[studentCount].birth;
        
        cout << "\tEnter students program : ";
        cin >> studentList[studentCount].program;
        
        cout << "\tEnter students Contact number : ";
        cin >> studentList[studentCount].contactNum;
        
        studentCount++; // Increment student count
        
        system("cls");
        cout<<endl;
        Sleep(1200);
        cout << "\t************************************" << endl;
        cout << "\t Student details added successfully " << endl;
        cout << "\t************************************" << endl;
    } while (repeatAction());
}	

// Function to view student details
void viewStudentDetails() {
system("cls");
    do {
    	cout<< "\n"<<"\n"<<"\n";
    	cout << "\t******************" << endl;
        cout << "\t Student details " << endl;
        cout << "\t******************" << endl;
        cout <<endl;
        for (int i = 0; i < studentCount; i++) {
            cout << "\tStudnet Name: " << studentList[i].name << endl;
            cout << "\tStudent ID number : " << studentList[i].idNo << endl;
            cout << "\tDate of birth : " << studentList[i].birth << endl;
            cout << "\tRegisterd program : " << studentList[i].program << endl;
            cout << "\tContact number : "<< studentList[i].contactNum << endl;
            cout<<endl;
        }
    } while (exitMainMenu());
}

// Function to search for student details
void searchStudentDetails() {
   
    do {
    	system("cls"); 
        string searchTerm;
        cout<< "\n"<<"\n"<<"\n";
        cout << "Enter the ID number of the student you want to search for: ";
        cin >> searchTerm; // Read the ID number to search
        bool found = false;
        for (int i = 0; i < studentCount; i++) {
            if (studentList[i].idNo == searchTerm) {
                found = true;
                cout << "\tStudent name: " << studentList[i].name << endl;
                cout << "\tID number: " << studentList[i].idNo << endl;
                cout << "\tDate of birth : " << studentList[i].birth << endl;
                cout << "\tProgram: " << studentList[i].program << endl;
                cout << "\tContact number : "<< studentList[i].contactNum << endl; 
                break;
               
            }
        }
        if (!found) {
            cout << "\tNo student found with the given ID number." << endl;
        }
    } 
	while (repeatAction());
     
}

// Function to view company details
void viewCompanyDetails()
{
system("cls");
	do
	{
	cout<< "\n"<<"\n"<<"\n";
	cout<<"\tMaster Mind institute Pvt Ltd.  "<<endl;
	cout<<"\t320/1 High level road "<<endl;
	cout<<"\tMaharagama"<<endl;
	cout<<"\t10101"<<endl;
	cout<<"\tSri Lanka"<<endl;
	}
	while (exitMainMenu());
	
}

// Function to show the login menu and return the user's choice
int showLoginMenu() {
system("cls");
    int choice;
    cout<< "\n"<<"\n"<<"\n";
    cout<<"\t***********************************************"<<endl;
	cout<<"\t***    Welcome To Master Mind institute     ***"<<endl;
	cout<<"\t***           Log In Portal                 ***"<<endl;
	cout<<"\t***********************************************"<<endl;
	cout<<"\t											 "<<endl;
	cout<<"\t(1) Admin                                    "<<endl;
	cout<<"\t(2) Staff                                    "<< endl;
	cout<<"\t											 "<< endl;
	cout<<"\t***********************************************"<<endl;
	cout<< "\tChoose (1) to login as admin or (2) for staff login"; 
	cout<< "\n";
	cout<< "\n";
	cout<<"\tEnter your choice : ";
    cin >> choice;
    system("cls");
    return choice;
}

// Function to show the admin menu and return the user's choice
int showAdminMenu() {
system("cls");
	int choice;
	cout<< "\n"<<"\n"<<"\n";
	cout << "\t**********************" << endl;
    cout << "\t***** Admin Menu *****" << endl;
    cout << "\t**********************" << endl;
    cout<< "\n";
    cout << "\t1. Add Course Details" << endl;
    cout << "\t2. View Course Details" << endl;
    cout << "\t3. Add Staff Details" << endl;
    cout << "\t4. View Staff Details" << endl;
    cout << "\t5. Logout" << endl;
    cout<< "\n";
    cout << "\tEnter your choice: ";
    cin >> choice;
    return choice;
}

// Function to show the staff menu and return the user's choice
int showStaffMenu() {
int choice;	
system("cls");	
	cout<< "\n"<<"\n"<<"\n";
	cout << "\t**********************" << endl;
    cout << "\t***** Staff Menu *****" << endl;
    cout << "\t**********************" << endl;
    cout<< "\n";
    cout << "\t1. Add student Details" << endl;
    cout << "\t2. View Student Details" << endl;
    cout << "\t3. Search Student Details" << endl;
    cout << "\t4. View Course Details" << endl;
    cout << "\t5. View Company Details" << endl;
    cout << "\t6. Logout" << endl;
    cout << "\tEnter your choice: ";
    cin >> choice;
    return choice;
}

// Function to process the login
bool processLogin() {
	
    int choice = showLoginMenu(); // Show the login menu and get the user's choice
    bool isAdmin = (choice == 1); // Check if the user is an admin
    if (choice != 1 && choice != 2) {
    	cout<< "\n"<<"\n"<<"\n";
        cout << "\tInvalid choice Please input a valid choice " << endl;
        Sleep(1200);
        return true;// Return true to indicate an invalid choice
        }
        
    
//system("cls");

    for (int attempts = 0; attempts < 3; attempts++) {
        string username, password;
        
        cout<< "\n"<<"\n"<<"\n";
        cout << "\tEnter username: ";
        cin >> username;      // Read the username
        
        cout << "\tEnter password: ";
        cin >> password;		// Read the password
        
system("cls");

        if (checkLogin(username, password, isAdmin)) {
        	cout<< "\n"<<"\n"<<"\n";
        	cout<<"\t************************"<<endl;
        	cout<<"\t Logged in successfully  "<<endl;
        	cout<<"\t************************"<<endl;
        	Sleep(1200);
        	system("cls");
        	
            if (isAdmin) {
                bool adminActive = true;
                while (adminActive) {
                    int adminChoice = showAdminMenu();
                    switch (adminChoice) {
                        case 1:
                            addCourseDetails();
                            break;
                        case 2:
                            viewCourseDetails();
                            break;
                        case 3:
                            addStaffDetails();
                            break;
                        case 4:
                            viewStaffDetails();
                            break;
                        case 5:
                        	adminActive = false;
                            break;
                        default:
                            cout <<endl <<"\tInvalid choice Please enter valid choice " << endl;
                            Sleep(1200);

                    }
                }
                return true;
            } else {
            	cout<< "\n"<<"\n"<<"\n";
        			cout<<"\t************************"<<endl;
        			cout<<"\t Logged in successfully  "<<endl;
        			cout<<"\t************************"<<endl;
        			Sleep(1200);
        			system("cls");
                bool staffActive = true;
                while (staffActive) {
                    int staffChoice = showStaffMenu();
                    switch (staffChoice) {
                        case 1:
                            addStudentDetails();
                            break;
                        case 2:
                            viewStudentDetails();
                            break;
                        case 3:
                            searchStudentDetails();
                            break;
                        case 4:
                            viewCourseDetails();
                            break;
                        case 5:
                            viewCompanyDetails();
                            break;
                        case 6:
                        	staffActive = false;
                            break;
                        default:
                            cout <<endl <<"\tInvalid choice Please enter valid choice " << endl;
                            Sleep(1200);
                          
                    }
                }
                break;
            }
        } else if (attempts == 2) {
        	cout<< "\n"<<"\n"<<"\n";
        	cout << "\t***********************************************." << endl;
            cout << "\tAccount is locked. Please contact support staff." << endl;
            cout << "\t***********************************************." << endl;
        } else {
        	cout<< "\n"<<"\n"<<"\n";
        	cout << "\t***********************************************." << endl;
            cout << "\tInvalid username or password. Please try again." << endl;
            cout << "\t***********************************************." << endl;
        }
    }
    return false; // Return false to indicate login failure
}

