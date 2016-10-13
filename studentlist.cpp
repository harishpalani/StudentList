#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct student {
  string first;
  string last;
  int id;
  float gpa;
};

void add_student(vector<student> &students, string first, string last, int id, float gpa);
void remove_student(vector<student> &students, string first, string last, int id, float gpa);
void print_all(vector<student> &students);

int main() {
  vector<student> students;
  
  add_student(students, "Jason", "Galbraith", 487329, 5.00);
  add_student(students, "Harish", "Palani", 876543, 2.00);
  print_all(students);

  remove_student(students, "Harish", "Palani", 876543, 2.00);
  print_all(students);
}

void add_student(vector<student> &students, string first, string last, int id, float gpa) {
  students.push_back(student());
  
  int i = students.size() - 1;
  
  students[i].first = first;
  students[i].last = last;
  students[i].id = id;
  students[i].gpa = gpa;  
}

void remove_student(vector<student> &students, string first, string last, int id, float gpa) {
  for(int i = 0; i < students.size(); i++) {
    if((students[i].first.compare(first) == 0) &&
       (students[i].last.compare(last) == 0) &&
       (students[i].id == id) &&
       (students[i].gpa == gpa)) {
      students.erase(students.begin() + i);
    }
  }
}

void print_all(vector<student> &students) {
  for(int i = 0; i < students.size(); i++) {
    cout << fixed << students[i].first << " " << students[i].last << ", " << students[i].id << ", " << setprecision(2) << students[i].gpa << endl;
  }
}
