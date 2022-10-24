#include <iostream>
#include "HashTable.h"
#include <string>

using namespace std;

int main(int, char**){
    HashTable<string> grades(10);
    grades.insert(93,"Data Structure");
    grades.insert(94,"Intro To Computer Science");
    grades.insert(100,"Infi2M");
    grades.insert(95,"Set Theory");
    grades.insert(97,"Modernic Algebra");
    grades.insert(92,"ProbabilityM");
    grades.insert(81,"Test");
    grades.insert(83,"Test");
    grades.insert(84,"Test");
    grades.insert(85,"Test");
    grades.insert(86,"Test");
    grades.insert(87,"Test");
    grades.insert(77,"Test");
    grades.printKeys();

    return 0;
}
