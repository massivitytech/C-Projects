#include "cgpa.h"

double GCPA::GPA()
{
  double sum = 0.0;
  double ho = 0.0;
  for(pair<double,char> m : All){
      Points = a.num_points(m.second);
      Hours = b.weight(m.first);
      ho += Hours;
      sum += Points*Hours;
  }
  return (sum)/ho;
}
