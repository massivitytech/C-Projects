#include "courses.h"
#include <stdexcept>
#include <fstream>


Courses::Courses(string one) {
    major = one;
    yos = 1;
    nummodules = 5;
    averageGPA = 3.5;
    instructor = "Dr. Smith";
}

string Courses::Modules(string major) {
    string moduleList = "";
    major += ".txt";
    ifstream inputFile(major); // Corrected the ifstream constructor

    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        throw invalid_argument("Error opening file."); 
    }

    std::string line;
    while (getline(inputFile, line)) {
        moduleList += line;
    }
    return moduleList;
}

int Courses::Nummodules() {
    string one = Modules(major);
    int counter = 0;
    for (char m : one) {
        if (m == '-') {
            counter++;
        }
    }
    return counter;
}

void Courses:: PrintModules()
{
  string traverse = Modules(major);
  string modula = "";
  for (char m : traverse) {
        if (m != ',') {
            modula += m;
        }
        else{
            cout<<modula<<endl;
            modula = "";
          }
    }
}
