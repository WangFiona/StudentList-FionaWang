#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
using namespace std;

/* Author: Fiona Wang
   Date: Oct. 15, 2021
   This program allows the user to input the names, IDs, and GPAs of students. They have the option to add, print, or delete students.
 */

//A struct that includes the names, IDs, and GPAs
struct Student {
  char fname[15];
  char lname[15];
  int id;
  float gpa;
};

//Initialize the methods
void add(vector<Student> &list, int &number);
void print(vector<Student> &list);
void delet(vector<Student> &list, int &number);

int main() {
  //Initialize the variables
  vector<Student> list;
  int number = 0;
  bool running = true;
  char command[7];
  char ADD[] = {'A', 'D', 'D', '\0'};
  char PRINT[] = {'P', 'R', 'I', 'N', 'T', '\0'};
  char DELETE[] = {'D', 'E', 'L', 'E', 'T', 'E', '\0'};
  char QUIT[] = {'Q', 'U', 'I', 'T', '\0'};

  //Ask the user for a command
  cout << "Enter a command (ADD, PRINT, DELETE, or QUIT):" << endl;

  while (running == true) {
    cin.get(command,7);
    cin.get();

    //Allow both upper and lower case
    for(int i=0; i < strlen(command); i++) {
      command[i] = toupper(command[i]);
    }

    //Determine which command the user input
    if (strcmp(command, ADD)==false) {
      add(list, number);
      cout << "Enter a command (ADD, PRINT, DELETE, or QUIT):" << endl;
    } else if (strcmp(command, PRINT)==false) {
      print(list);
      cout << "Enter a command (ADD, PRINT, DELETE, or QUIT):" << endl;
    } else if (strcmp(command, DELETE)==false) {
      delet(list, number);
      cout << "Enter a command (ADD, PRINT, DELETE, or QUIT):" << endl;
    } else if (strcmp(command, QUIT)==false) {
      running = false;
    } else {
      cout << "Please enter a valid command:" << endl;
    }
  }
  return 0;
}

//Method for adding students
void add(vector<Student> &list, int &number) {
  //Add a new Student struct
  list.push_back(Student());

  //Ask the user for the first name and add it to the vector
  char first[15];
  cout << "Please enter a first name" << endl;
  cin.get(first, 15);
  cin.get();
  int i=0;
  for (i=0; i<strlen(first); i++) {
    list[number].fname[i]=first[i];
  }
  list[number].fname[i]='\0';

  //Ask the user for the last name and add it to the vector
  char last[15];
  cout << "Please enter a last name" << endl;
  cin.get(last, 15);
  cin.get();
  for (i=0; i<strlen(last); i++) {
    list[number].lname[i]=last[i];
  }
  list[number].lname[i]='\0';

  //Ask the user for the ID and add it to the vector
  int id=0;
  cout << "Please enter an ID:" << endl;
  cin >> id;
  cin.get();
  //Make sure that the ID is not currently in use
  for (int i=0; i<list.size(); i++) {
    while (id == list[i].id) {
      cout << "Please enter a unique ID number:" << endl;
      cin >> id;
      cin.get();
    }
  }
  list[number].id=id;

  //Ask the user for the GPA and add it to the vector
  float gpa=0;
  cout << "Please enter a GPA:" << endl;
  cin >> gpa; 
  cin.get();
  list[number].gpa=gpa;
  
  number++;
}

//Method for printing the students
void print(vector<Student> &list) {
  //Check if there are any students
  if (list.size() == 0) {
    cout << "There are zero students in the database" << endl;
  }

  //Print out the name, ID, and GPA of each student
  for (int i=0; i<list.size(); i++) {
    for (int k=0; k<strlen(list[i].fname); k++) {
      cout << list[i].fname[k];
    }
    cout << " ";
    for (int k=0; k<strlen(list[i].lname); k++) {
      cout << list[i].lname[k];
    }
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << ", " << list[i].id << ", " << list[i].gpa << endl;
  }
}

//Method for deleting students
void delet(vector<Student> &list, int &number) {
  int dnumber = 0;
  int student;
  bool exist = false;

  //Ask the user for the ID of the student
  cout << "Enter the ID of the student that you would like to delete:" << endl;
  cin >> dnumber;
  cin.get();

  //Look for the student that corresponds with the ID
  for (int i=0; i<list.size(); i++) {
    if (dnumber == list[i].id) {
      student=i;
      exist = true;
      number--;
    }
  }

  //Delete the student if they exist
  if (exist == true) {
    list.erase(list.begin()+student);
    cout << "The student has been deleted" << endl;
  } else {
    cout << "That student does not exist" << endl;
  }
}
