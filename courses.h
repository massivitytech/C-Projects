#include "cgpa.cpp"


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
};
