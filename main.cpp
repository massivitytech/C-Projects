#include "cgpa.cpp"
//#include <SDL2/SDL.h>


int main(int argc, char* argv[]){
  Courses one("Mathematics");
  one.InsertModules();
  one.PrintModules();
  one.InsertNumber('A');
  GCPA Main(one.major,one);
  cout<<one.Nummodules()<<endl;//next now change the gpa for many modules
  cout<<Main.GPA()<<endl;
}