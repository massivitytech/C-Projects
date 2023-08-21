#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <cctype>
#include <string>

using namespace std;

class Gradepoints{
  public:
        Gradepoints();
        char Symbol[5];
        int  points[4];
        int num_points(char b);
};
