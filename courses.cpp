#include "courses.h"
#include <stdexcept>
#include <fstream>
#include <iostream>

using namespace std; // Added to resolve identifiers like 'cerr' and 'endl'

Courses::Courses(string one) {
    major = one;
    yos = 1;
    totalcredits = 144;
    nummodules = 5;
    averageGPA = 3.5;
    instructor = "Dr. Smith";
}

string Courses::Modules(string major) {
    string moduleList = "";
    string filenames = removeSpaces(major);
    filenames += ".txt";
    Numbers(filenames);
    ifstream inputFile(filenames);

    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        throw invalid_argument("Error opening file.");
    }

    string line; // Changed to string from std::string
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

void Courses::InsertModules() {
    string one = Modules(major); // Used 'major' instead of 'course'
    string two = "";
    for (char m : one) {
        if (m != ',') {
            two += m;
        } else {
            Mod.push_back(two);
            two = "";
        }
    }
}

void Courses::Numbers(string filename)
{
    ifstream inputFile(filename);
    
    if (!inputFile.is_open()) {
        cerr << "Cannot Open File" << endl;
        throw invalid_argument("Cannot Open File");
    }

    string line;
    while (getline(inputFile, line)) {
        Opt.push_back(line);
        line = "";
    }

    inputFile.close();
}

void Courses::PrintModules() {
    for(string m:Mod){
      cout<<m<<endl;
    }
}

double Courses::weight(double credits) {
    return credits / totalcredits;
}

/*double Courses::GetCredits(int index) { //extract number works we wont need you
    size_t hyphenPos = Mod[index].find('-');
    
    if (hyphenPos != string::npos) {
        string creditsSubstring = Mod[index].substr(hyphenPos + 1);
        double Credits = stod(creditsSubstring);
        return Credits;
    }
    
    return 0.0;
}*/

//Fills my vector
/*pair<double, char> Courses::Fill(int index, char symbol) {
    Alls.push_back({extractnumber(index), symbol});
    return {GetCredits(index), symbol};
}*/

//Enables me get the name of the file which I have so I use a stream to open
string Courses::removeSpaces(string &input) { 
    string result;

    for (char c : input) {
        if (!isspace(c)) {
            result += c;
        }
    }
    return result;
}
void Courses::extractNumber(string m , char symbol) { //Extracts a number from a given string and returns it
    size_t hyphenPos = m.find('-'); // Find the position of the hyphen
    size_t commaPos = m.find(',', hyphenPos); // Find the position of the comma after the hyphen

    if (hyphenPos != std::string::npos && commaPos != std::string::npos) {
        std::string numberStr = m.substr(hyphenPos + 1, commaPos - hyphenPos - 1); // Extract the number substring
        std::stringstream ss(numberStr);
        double number;
        if (ss >> number) {
             Alls.push_back({number,symbol}); // Successfully parsed the number
        }
    }
    
}

void Courses::InsertNumber(char symbol)
{
    for(string m:Opt){
        extractNumber(m,symbol);
    }
}