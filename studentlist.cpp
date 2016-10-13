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
void initialize(vector<student> &students, char input[80]);

int main() {
  vector<student> students;

  char input[80];
  cout << "Enter a command [ADD, PRINT, or DELETE]: ";
  cin >> input;

  initialize(students, input);
}

void initialize(vector<student> &students, char input[80]) {

   char first[80];
   char last[80];
   int id;
   float gpa;

   if(strcmp(input, "ADD") == 0) {
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
   } else if (strcmp(input, "PRINT") == 0) {
     print_all(students);
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
