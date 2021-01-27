// Tim Inzitari
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>

#include "insertsort.h"
#include "heapsort.h"
#include "mergesort.h"
#include "quicksort.h"

using std::vector;
using std::cout;
using std::string;
void displayVect(const vector<int> x);

int main()
{
    vector<int> vectToCopySmall;
    vector<int> vectorToSort = {};
    int nInts = 0;
    std::ifstream sortFile;
    string inFileName;
    int fromFile = 0;

    cout << "Please enter the filename: ";
    std::cin >> inFileName;
    sortFile.open(inFileName);
    while(!(sortFile.is_open())) // get File names while errorchecking
    {
        cout << "\nError: File not Found, Try Again: ";
        std:: cin >> inFileName;// reset vector to nothing
        sortFile.open(inFileName);
    }


    cout << "Enter the number of integers to sort: ";

    while(!(std::cin>>nInts)) // get int values while errorchecking
    {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        cout << "Error: not an Integer, Try Again: ";
    }



    // -------------------------------
    // BEGIN SMALL SORT
    // -------------------------------
// Random Number Gen Stuff
    // get input f
    // -------------------------------
    // BEGIN BIG SORT
    // -------------------------------or small array
    while(sortFile >> fromFile)
        vectToCopySmall.push_back(fromFile);


    // SMALL INSERTION SORT BEGIN
    vectorToSort.clear(); // reset vector to nothing
    for (int i = 0; i < vectToCopySmall.size(); ++i) // populate
        vectorToSort.push_back(vectToCopySmall[i]);

    cout << "\n vector before insertion sort: ";
    displayVect(vectorToSort);

    // do insertionsort
    insertionSort(vectorToSort.begin(), vectorToSort.end());
    cout << "vector after insertion sort: ";
    displayVect(vectorToSort);
    // SMALL INSERTION SORT END


    // SMALL HEAP SORT BEGIN
    vectorToSort.clear(); // reset vector to nothing
    for (int i = 0; i < vectToCopySmall.size(); ++i) // populate
        vectorToSort.push_back(vectToCopySmall[i]);

    cout << "\n vector before heap sort: ";
    displayVect(vectorToSort);

    // do heapsort
    heapsort(vectorToSort);
    cout << "vector after heap sort: ";
    displayVect(vectorToSort);
    // SMALL HEAP SORT END


    // SMALL MERGE SORT BEGIN
    vectorToSort.clear(); // reset vector to nothing
    for (int i = 0; i < vectToCopySmall.size(); ++i) // populate
        vectorToSort.push_back(vectToCopySmall[i]);
    cout << "\n vector before merge sort: ";
    displayVect(vectorToSort);

    // do merge sort
    mergeSort(vectorToSort);
    cout << "vector after merge sort: ";
    displayVect(vectorToSort);
    // SMALL MERGE SORT END


    // SMALL QUICK SORT (no cutoff) BEGINvector<int> vectToCopyBigRandom(nInts, 0); // make a vector of nInt size, all initialized to 0 for Random
    vectorToSort.clear(); // reset vector to nothing
    for (int i = 0; i < vectToCopySmall.size(); ++i) // populate
        vectorToSort.push_back(vectToCopySmall[i]);

    cout << "\n vector before quick sort (no cutoff): ";
    displayVect(vectorToSort);

    // do quick sort
    quicksort(vectorToSort);
    cout << "vector after quick sort (no cutoff): ";
    displayVect(vectorToSort);
    // SMALL QUICK SORT <no cuttoff> SORT END

    // -------------------------------
    // END SMALL SORT
    // -------------------------------


    // -------------------------------
    // BEGIN BIG SORT
    // -------------------------------

    // SET CLOCK VARIABLES
    clock_t start, stop;

    // seed random
    srand(time(NULL));

    // make Vector
    vector<int> vectToCopyBigRandom(nInts, 0); // make a vector of nInt size, all initialized to 0 for Random
    vector<int> vectToCopyBigAscend(nInts, 0); // make a vector of nInt size, all initialized to 0 for Assencd
    vector<int> vectToCopyBigDescend(nInts, 0); // make a vector of nInt size, all initialized to 0 for Descend

    // populate big vector
    // fill vectors with Random numbers from [0, 10000], Presorted increasing, presorted decreasing
    for(int i = 0; i < nInts; ++i)
    {
        vectToCopyBigRandom[i] = rand() % 10000 + 1;
        vectToCopyBigAscend[i] = i;
        vectToCopyBigDescend[i] = nInts - i;
    }

    // FILL PRESORTED ARRAYS


    cout << "\nruntime of algorithms for N = " << nInts << " items." << std::endl;



    // BIG HEAPSORT

        // RANDOM
        vectorToSort.clear(); // reset vector to nothing
        for (int i = 0; i < vectToCopyBigRandom.size(); ++i) // populate
            vectorToSort.push_back(vectToCopyBigRandom[i]);

        start = clock ();
        heapsort(vectorToSort);
        stop = clock ();
        cout << "heapsort random: " << double(stop-start)/double(CLOCKS_PER_SEC);
        cout << std::endl;
        // END RANDOM

        //ASSEND
        vectorToSort.clear(); // reset vector to nothing
        for (int i = 0; i < vectToCopyBigAscend.size(); ++i) // populate
            vectorToSort.push_back(vectToCopyBigAscend[i]);

        start = clock ();
        heapsort(vectorToSort);
        stop = clock ();
        cout << "heapsort ascend: " << double(stop-start)/double(CLOCKS_PER_SEC);
        cout << std::endl;
        // end Ascend

        //DESCEND
        vectorToSort.clear(); // reset vector to nothing
        for (int i = 0; i < vectToCopyBigDescend.size(); ++i) // populate
            vectorToSort.push_back(vectToCopyBigDescend[i]);

        start = clock ();
        heapsort(vectorToSort);
        stop = clock ();
        cout << "heapsort descend: " << double(stop-start)/double(CLOCKS_PER_SEC);
        cout << std::endl;
        // end Descend


    // END BIG HEAP



        // BIG MERGESORT

        // RANDOM
        vectorToSort.clear(); // reset vector to nothing
        for (int i = 0; i < vectToCopyBigRandom.size(); ++i) // populate
            vectorToSort.push_back(vectToCopyBigRandom[i]);

        start = clock ();
        mergeSort(vectorToSort);
        stop = clock ();
        cout << "merge sort random: " << double(stop-start)/double(CLOCKS_PER_SEC);
        cout << std::endl;
        // END RANDOM

        //ASSEND
        vectorToSort.clear(); // reset vector to nothing
        for (int i = 0; i < vectToCopyBigAscend.size(); ++i) // populate
            vectorToSort.push_back(vectToCopyBigAscend[i]);

        start = clock ();
        mergeSort(vectorToSort);
        stop = clock ();
        cout << "merge sort ascend: " << double(stop-start)/double(CLOCKS_PER_SEC);
        cout << std::endl;
        // end Descend;
        // end Ascend

        //DESCEND
        vectorToSort.clear(); // reset vector to nothing
        for (int i = 0; i < vectToCopyBigDescend.size(); ++i) // populate
            vectorToSort.push_back(vectToCopyBigDescend[i]);

        start = clock ();
        mergeSort(vectorToSort);
        stop = clock ();
        cout << "merge sort descend: " << double(stop-start)/double(CLOCKS_PER_SEC);
        cout << std::endl;
        // end Descend


    // END BIG MergeSort




        // BIG QUICK SORT

        // RANDOM
        vectorToSort.clear(); // reset vector to nothing
        for (int i = 0; i < vectToCopyBigRandom.size(); ++i) // populate
            vectorToSort.push_back(vectToCopyBigRandom[i]);

        start = clock ();
        quicksort(vectorToSort);
        stop = clock ();
        cout << "quick sort (no cutoff) random: " << double(stop-start)/double(CLOCKS_PER_SEC);
        cout << std::endl;
        // END RANDOM

        //ASSEND
        vectorToSort.clear(); // reset vector to nothing
        for (int i = 0; i < vectToCopyBigAscend.size(); ++i) // populate
            vectorToSort.push_back(vectToCopyBigAscend[i]);

        start = clock ();
        quicksort(vectorToSort);
        stop = clock ();
        cout << "quick sort (no cutoff) ascend: " << double(stop-start)/double(CLOCKS_PER_SEC);
        cout << std::endl;
        // end Descend;
        // end Ascend

        //DESCEND
        vectorToSort.clear(); // reset vector to nothing
        for (int i = 0; i < vectToCopyBigDescend.size(); ++i) // populate
            vectorToSort.push_back(vectToCopyBigDescend[i]);

        start = clock ();
        quicksort(vectorToSort);
        stop = clock ();
        cout << "quick sort (no cutoff) descend: " << double(stop-start)/double(CLOCKS_PER_SEC);
        cout << std::endl;
        // end Descend


    // END BIG Quick Sort

        // BIG Insert SORT

        // RANDOM
        vectorToSort.clear(); // reset vector to nothing
        for (int i = 0; i < vectToCopyBigRandom.size(); ++i) // populate
            vectorToSort.push_back(vectToCopyBigRandom[i]);

        start = clock ();
        insertionSort(vectToCopyBigRandom.begin(), vectToCopyBigRandom.end());
        stop = clock ();
        cout << "insertion sort random: " << double(stop-start)/double(CLOCKS_PER_SEC);
        cout << std::endl;
        // END RANDOM

        //ASSEND
        vectorToSort.clear(); // reset vector to nothing
        for (int i = 0; i < vectToCopyBigAscend.size(); ++i) // populate
            vectorToSort.push_back(vectToCopyBigAscend[i]);

        start = clock ();
        insertionSort(vectToCopyBigAscend.begin(), vectToCopyBigAscend.end());
        stop = clock ();
        cout << "insertion sort ascend: " << double(stop-start)/double(CLOCKS_PER_SEC);
        cout << std::endl;
        // end Ascend

        //DESCEND
        vectorToSort.clear(); // reset vector to nothing
        for (int i = 0; i < vectToCopyBigDescend.size(); ++i) // populate
            vectorToSort.push_back(vectToCopyBigDescend[i]);

        start = clock ();
        insertionSort(vectToCopyBigDescend.begin(),vectToCopyBigDescend.end());
        stop = clock ();
        cout << "insertion sort descend: " << double(stop-start)/double(CLOCKS_PER_SEC);
        cout << std::endl;
        // end Descend


    // END BIG Insert Sort
    return 0;

}

void displayVect( const vector<int> x)
{
    for(int i = 0; i < x.size(); ++i)
        cout << " " << x[i];
    cout << std::endl;
}

