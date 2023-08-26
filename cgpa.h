#include "gradepoints.cpp"

class GCPA{
  public:
          GCPA(string major , Courses m) : major(major), b(major) {
          All.clear();
          b = m;
          for (const auto& element : m.Alls) {
          All.push_back(element);
        }
    }

    string major;
    double GPA();
    vector<pair<double, char>> All;
    int Points = 0;
    double Hours = 0;
    Gradepoints a;
    Courses b;
};