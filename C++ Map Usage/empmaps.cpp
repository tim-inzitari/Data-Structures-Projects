// Tim Inzitari
#include "empmaps.h"

vector<Employee> employees()
{
    vector<Employee> emp;
    string fName;
    ifstream inFile;
    cout << "Enter file of employee data to process: ";
    cin >> fName;

    inFile.open(fName);
    if (inFile.fail())
    {
        cout << "File not Found, exiting";
        exit(1);
    }

    int identifier;
    int salary;
    string lastname;
    string getLineStr;

    while (getline(inFile, getLineStr)) // get each line of input
    {
        std::istringstream ss(getLineStr); // make each line a string stream
        ss >> identifier; // get id
        ss >> lastname; // get last name
        ss >> salary; // get salary

        Employee x = Employee(identifier, lastname, salary); // store it in an Employee class

        emp.push_back(x); // add employee to vector

    }
    inFile.close(); // close file
    return emp; // return vector
}

map<int,vector<Employee>> mapEmpDept(vector<Employee> & emp)
{
    map<int, vector<Employee>> myMap;


    int id = 0;

    for (vector<Employee>::iterator myIter = emp.begin(); myIter != emp.end(); myIter++) // for everything in vector
    {
        id = myIter->id() / 100; // cut last 2 digits of id
        myMap[id].push_back(*myIter);  // push back id into map with employee data
    }

    return myMap;
}


map<int,vector<Employee>> mapSalRange(vector<Employee> & emp)
{
     map<int, vector<Employee>> myMap;
     int id = 0;

     for (vector<Employee>::iterator myIter = emp.begin(); myIter != emp.end(); myIter++) // for everything in vector
     {
         id = myIter->sal() / 10000 * 10000; // get 10000 value
         myMap[id].push_back(*myIter);  // push back id into map with employee data
     }
     return myMap;
}


void printSalRange(map<int,vector<Employee>> & salRange)
{
    map<int,vector<Employee>>::iterator maxSizeIter = salRange.begin();

    for (map<int,vector<Employee>>::iterator myIter = salRange.begin(); myIter != salRange.end(); myIter++) // for entire map
    {
        if (maxSizeIter->second.size() < myIter->second.size())
            maxSizeIter = myIter;

        cout << "ORDERED Map Salary Range " << myIter->first << " contains " << myIter->second.size() << " employees." << std::endl;

    }
    cout << "ORDERED Map Salary Range with most employees: " << maxSizeIter->first << " containing " << maxSizeIter->second.size() << " employees." << std::endl;

}

unordered_map<int,vector<Employee>> umapEmpDept(vector<Employee> & emp)
{
    unordered_map<int, vector<Employee>> myMap;


    int id = 0;

    for (vector<Employee>::iterator myIter = emp.begin(); myIter != emp.end(); myIter++) // for everything in vector
    {
        id = myIter->id() / 100; // cut last 2 digits of id
        myMap[id].push_back(*myIter);  // push back id into map with employee data
    }

    return myMap;
}

unordered_map<int,vector<Employee>> umapSalRange(vector<Employee> & emp)
{
     unordered_map<int, vector<Employee>> myMap;
     int id = 0;

     for (vector<Employee>::iterator myIter = emp.begin(); myIter != emp.end(); myIter++) // for everything in vector
     {
         id = myIter->sal() / 10000 * 10000; // get 10000 value
         myMap[id].push_back(*myIter);  // push back id into map with employee data
     }
     return myMap;
}


void uprintSalRange(unordered_map<int,vector<Employee>> & salRange)
{
    unordered_map<int,vector<Employee>>::iterator maxSizeIter = salRange.begin();

    for (unordered_map<int,vector<Employee>>::iterator myIter = salRange.begin(); myIter != salRange.end(); myIter++) // for entire map
    {
        if (maxSizeIter->second.size() < myIter->second.size())
            maxSizeIter = myIter;

        cout << "UNORDERED Map Salary Range " << myIter->first << " contains " << myIter->second.size() << " employees." << std::endl;

    }
    cout << "UNORDERED Map Salary Range with most employees: " << maxSizeIter->first<< " containing " << maxSizeIter->second.size() << " employees." << std::endl;

}
