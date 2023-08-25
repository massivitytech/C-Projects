#include "cgpa.cpp"
#include <vector>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Course{
  public:
        string major;
        int yos;
        int nummodules;
        double averageGPA;
        string instructor;
};

class Courses : public Course{
  public:
    Courses(string major);
    vector<string> Majors = {"Computer Science And Applied Mathematics","Astrophysics","Actuarial Science","Physical Sciences","Geology","Mathematics"};
    string Modules(string major);
    void PrintModules();
    int Nummodules();
    string course;
    vector<pair<double,char>>Alls;
    vector<string>Mod;
    double totalcredits;
    double weight(double credits);
    double GetCredits(int index);
    void Credits(char symbol);
    pair<double,char>Fill(int index , char symbol);
};
