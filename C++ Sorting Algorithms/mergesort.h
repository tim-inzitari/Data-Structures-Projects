#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED
//Tim Inzitari
//pages 306 and 307 of the book
#include <vector>
using std::vector;
/*
  Merge sort Algorthm (driver)
*/
template <typename Comparable>
void mergeSort(vector<Comparable> & a, vector<Comparable> & tmpArray, int left, int right);

template <typename Comparable>
void merge(vector<Comparable> & a, vector<Comparable> & tmpArray,int leftPos, int rightPos, int rightEnd);

template <typename Comparable>
void mergeSort(vector<Comparable> & a);



template <typename Comparable>
void mergeSort(vector<Comparable> & a)
{
    vector<Comparable> tmpArray(a.size());
    mergeSort(a,tmpArray,0,a.size()-1);
}


/*
    Internal method that makes recursive calls
    a is an array of Comparabltemplate <typename Comparable>
void merge(vector<Comparable> & a, vector<Comparable> & tmpArray,int leftPos, int rightPos, int rightEnd)e items
    tmpArray is an array to place the merged result
    left is the left-most index of the subarray
    right is the ritemplate <typename Comparable>ghtmost index of the subarray
*/
template <typename Comparable>
void mergeSort(vector<Comparable> & a, vector<Comparable> & tmpArray, int left, int right)
{
    if(left < right)
    {
        int center = (left + right) /2;
        mergeSort(a,tmpArray,left,center);
        mergeSort(a,tmpArray,center+1,right);
        merge(a,tmpArray,left,center+1,right);
    }
}

/*
    Internal Method that merges two sorted halves of a subarray
    a is an array of Comparable items.
    tmpArray is an array to place the merged result
    leftPos is the left most index of the sub array
    rightPos is hte index at the start of hte second half
    rightEnd is hte right most index of the subarray
*/
template <typename Comparable>
void merge(vector<Comparable> & a, vector<Comparable> & tmpArray,int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos -1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    // Main Loop
    while (leftPos <= leftEnd && rightPos <= rightEnd)
        if (a[leftPos]<= a[rightPos])
            tmpArray[tmpPos++]=std::move(a[leftPos++]);
        else
            tmpArray[tmpPos++] = std::move(a[rightPos++]);

   while(leftPos <= leftEnd) // copy the rest of first half
        tmpArray[tmpPos++] = std::move(a[leftPos++]);

   while(rightPos <= rightEnd) // copy rest of right half
    tmpArray[tmpPos++] = std::move(a[rightPos++]);

   // Copy Tmp Array back
   for (int i =0; i <numElements; ++i,--rightEnd)
    a[rightEnd] = std::move(tmpArray[rightEnd]);

}

#endif // MERGESORT_H_INCLUDED
