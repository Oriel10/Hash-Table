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
    grades.printKeys();

    return 0;
}
