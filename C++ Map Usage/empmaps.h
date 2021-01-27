// Tim Inzitari

#ifndef EMPMAPS_H_INCLUDED
#define EMPMAPS_H_INCLUDED
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "Employee.h"

using std::vector;
using std::map;
using std::cin;
using std::cout;
using std::stringstream;
using std::string;
using std::ifstream;
using std::unordered_map;
vector<Employee> employees();

map<int,vector<Employee>> mapEmpDept(vector<Employee> & emp);
map<int,vector<Employee>> mapSalRange(vector<Employee> & emp);
void printSalRange(map<int,vector<Employee>> & salRange);

unordered_map<int,vector<Employee>> umapEmpDept(vector<Employee> & emp);
unordered_map<int, vector<Employee>> umapSalRange(vector<Employee> & emp);
void uprintSalRange(unordered_map<int,vector<Employee>> & salRange);




#endif // EMPMAPS_H_INCLUDED
