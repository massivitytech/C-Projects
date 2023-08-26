#include <vector>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <utility>
#include <cctype>
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
    vector<string>Opt;
    double totalcredits;
    void extractNumber(string m, char symbol);
    void InsertNumber(char symbol);
    string removeSpaces(string &input);
    double weight(double credits);
   // double GetCredits(int index);
    void InsertModules();
    void Numbers(string filename); //Add to vector opt a line as it is
    pair<double,char>Fill(int index , char symbol);
};
