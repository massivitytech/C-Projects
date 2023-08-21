#include "gradepoints.h"

Gradepoints::Gradepoints()
{
    Symbol[0] = 'A';
    Symbol[1] = 'B'; 
    Symbol[2] = 'C';
    Symbol[3] = 'D';
    Symbol[4] = 'F';
    points[0] = 4;
    points[1] = 3;
    points[2] = 2;
    points[3] = 1;
}

int Gradepoints::num_points(char m){
    int indexofsymbol = -1; 
    for(int index = 0 ; index < 5; index++){ 
    
        if(m == Symbol[index]){
            indexofsymbol = index;
            break;
        }
    }
    if (indexofsymbol != -1) { 
        return points[indexofsymbol];
    }
    return -1; 
}
