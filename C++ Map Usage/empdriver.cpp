// Tim Inzitari
#include <iostream>
#include <fstream>
#include <ctime>
#include "Employee.h"
#include <unordered_map>
#include <ctime>
#include "empmaps.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::map;
using std::unordered_map;
using std::ifstream;
using std::ofstream;
using std::endl;



using namespace std;

int main()
{
    vector<Employee> emp = employees();
    cout << "Number of Employees: " << emp.size() << endl;

    clock_t start,stop;

    start = clock();
    map<int, vector<Employee>> myEmpMap = mapEmpDept(emp);
    stop = clock();
    cout << "ORDERED Map creation with department as key clock ticks: " << double(stop-start) << endl;
    cout << "ORDERED Map number of departments: " << myEmpMap.size() << endl;

    start = clock();
    map<int, vector<Employee>> mySalMap = mapSalRange(emp);
    stop = clock();
    cout << "ORDERED Map creation with salary as key clock ticks: " << double(stop-start) << endl;
    cout << "ORDERED Map number of salaries: " << mySalMap.size() << endl;

    printSalRange(mySalMap);

    cout << "\n";

    start = clock();
    unordered_map<int, vector<Employee>> myEmpUMap = umapEmpDept(emp);
    stop = clock();
    cout << "UNORDERED Map creation with department as key clock ticks: " << double(stop-start) << endl;
    cout << "UNORDERED Map number of departments: " << myEmpUMap.size() << endl;

    start = clock();
    unordered_map<int, vector<Employee>> mySalUMap = umapSalRange(emp);
    stop = clock();
    cout << "UNORDERED Map creation with Salary as key clock ticks: " << double(stop-start) << endl;
    cout << "UNORDERED Map number of salaries: " << mySalUMap.size() << endl;

    uprintSalRange(mySalUMap);

    cout << "\n";


    return 0;
}
