#include "gradepoints.cpp"

class Credithours{
    public:
          Credithours();
          string course;
          vector<pair<double,char>>Alls;
          vector<string>Mod;
          double totalcredits;
          double weight(double credits);
          double GetCredits(int index);
          void Credits(char symbol);
          pair<double,char>Fill(int index , char symbol);
};
