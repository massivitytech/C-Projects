#include "courses.h"


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

double Credithours::weight(double credits) // weighs the credits
{
    return credits/totalcredits;
}

void Courses::Credits(char symbol)  //Adds modules to the vector for us
{
    string one = Modules(major);
    string two = "";
    for (char m : one) {
        if (m != ',') {
            two += m;
        }else
            Mod.push_back(two);
            two = "";
    }
}

double Courses::GetCredits(int index){ // gets the credits for us
    string two = "";
    for(char m : Mod[index]){
        if(m != '-'){
            if(!isspace(m))
                two += m;
        }else
             two = ""; 
    }
    double Credits = stod(two);
}
pair<double,char> Courses::Fill(int index , char symbol){ //fills our vector with credits and symbol
  Alls.push_back({GetCredits(index),symbol});
  return {GetCredits(index),symbol};

}