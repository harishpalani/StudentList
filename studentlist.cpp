#include <iostream>
#include <vector>

using namespace std;

struct student {
  string first;
  string last;
  int id;
  float gpa;
};

void printAll(vector<student> *students) {

  for(int i = 0; i < students.size(); i++) {
    cout << students[i].first << " / " << students[i].last << " / " << students[i].id << " / " << students[i].gpa << endl;
  }
}

void addStudent(vector<student> *students, string first, string last, int id, float gpa) {
  students.push_back(student());

  int i = students.size();
  students[i].first = first;
  students[i].last = last;
  students[i].id = id;
  students[i].gpa = gpa;  
}

  int main() {
    vector<student> students;

    students.push_back(student());

    students[0].first = "Harish";
    students[0].last = "Palani";
    students[0].id = 355131;
    students[0].gpa = 4.0;

    
    
  }
