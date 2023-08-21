#include "courses.cpp"
#include <SDL2/SDL.h>


int main(int argc, char* argv[]){
  Courses one("Mathematics");
  one.PrintModules();
  cout<<one.Nummodules()<<endl;//next now change the gpa for many modules
}
