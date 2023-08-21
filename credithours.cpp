#include "credithours.h"

Credithours::Credithours()
{
      totalcredits = 144;
}

double Credithours::weight(double credits) // weighs the credits
{
    return credits/totalcredits;
}

void Credithours::Credits()  //Adds modules to the vector for us
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

double CreditHours::GetCredits(int index){ // gets the credits for us
    string two = "";
    for(char m : Mod[index]){
        if(m != '-'){
            if(!isspace(m))
                two += m;
        }else
             two = ""; 
    }
    double Credits = double(two);
}
pair<double,char> CreditHours::Fill(int index , char symbol){ //fills our vector with credits and symbol
  Alls.push_back({GetCredits(index),symbol});
  return {GetCredits(index),symbol};
}
