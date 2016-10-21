/**
 * Student List 
 * 
 * A vector-based database of students that keeps track of their first names, 
 * last names, IDs, and GPAs.
 * 
 * e.g. [Harish] [Palani] [355131] [4.0] -> "Harish Palani, 355131, 4.0"
 * 
 * @author Harish Palani
 * @version 1.0
 */


#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>

using namespace std;

struct student {
  char first[80];
  char last[80];
  int id;
  float gpa;
};

void add_student(vector<student> &students, char first[80], char last[80], int id, float gpa);
void remove_student(vector<student> &students, int id);
void print_all(vector<student> &students);
vector<student> students;

int main() {
  
  char input[80];
  cout << "Enter a command [ADD, PRINT, or DELETE]: ";
  cin >> input;

  if(strcmp(input, "ADD") == 0) {
     
    char first[80];
    char last[80];
    int id;
    float gpa;
     
     cout << "First name: ";
     cin >> first;

     cout << "Last name: ";
     cin >> last;

     cout << "ID: ";
     cin >> id;

     cout << "GPA: ";
     cin >> gpa;

     add_student(students, first, last, id, gpa);
     main();
     
   } 
   
   if (strcmp(input, "PRINT") == 0) {
     print_all(students);
     main();
   }
  
  if (strcmp(input, "DELETE") == 0) {
    
    int id;
     cout << "Enter ID of student you'd like to remove: ";
     cin >> id;
     
    remove_student(students, id);
    main();
  }
}

void add_student(vector<student> &students, char first[80], char last[80], int id, float gpa) {
  students.push_back(student());
  
  int i = students.size() - 1;
  
  strcpy(students[i].first, first);
  strcpy(students[i].last, last);
  students[i].id = id;
  students[i].gpa = gpa;
}

void remove_student(vector<student> &students, int id) {
  for(int i = 0; i < students.size(); i++) {
    if(students[i].id == id) {
      students.erase(students.begin() + i);
    }
  }
}

void print_all(vector<student> &students) {
  for(int i = 0; i < students.size(); i++) {
    cout << fixed << students[i].first << " " << students[i].last << ", " << students[i].id << ", " << setprecision(2) << students[i].gpa << endl;
  }
}
