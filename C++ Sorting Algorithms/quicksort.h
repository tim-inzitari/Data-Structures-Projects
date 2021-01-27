#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED
// Tim Inzitari
// pages 316 and 317
#include <vector>
using std::vector;
/*
    Quicksort Algorithm (driver)
*/
template <typename Comparable>
void quicksort(vector<Comparable> & a);

template <typename Comparable>
const Comparable & median3(vector<Comparable> & a, int left, int right);

template <typename Comparable>
void quicksort(vector<Comparable> & a, int left, int right);



template <typename Comparable>
void quicksort(vector<Comparable> & a)
{
    quicksort(a,0,a.size()-1);
}

/*
    Return median of Left,center and right
    Order these and hide the pivot
*/
template <typename Comparable>
const Comparable & median3(vector<Comparable> & a, int left, int right)
{
    int center = (left + right) /2;

    if(a[center]<a[left])
        std::swap(a[left],a[center]);
    if(a[right]< a[left])
        std::swap(a[left], a[right]);
    if(a[right] < a[center])
        std::swap(a[center], a[right]);

    // place pivot at position right -1
    std::swap(a[center],a[right-1]);
    return a[right-1];
}

/*
    Internal quicksort method that makes recursive calls
    uses median of three partitioning
    a is an array of Comparable Items
    left is the left-most index of the subarray
    right is the right-most index of the subarray
*/
template <typename Comparable>
void quicksort(vector<Comparable> & a, int left, int right)
{
    if (left + 2 <= right) // if 3 or more elements
    {
        const Comparable &pivot = median3(a,left,right);

        // begin partitioning
        int i = left, j = right-1;
        for (;;)
        {
            while(a[++i]<pivot){}
            while(pivot < a[--j]){}
            if (i<j)
                std::swap(a[i],a[j]);
            else
                break;
        }

        std::swap(a[i],a[right-1]); // restore pivot

        quicksort(a,left,i-1); // sort small elements
        quicksort(a, i+1,right);// sort large elements
    }
    else if(left+1 == right) //BASE CASE  if 2 elements
    {
        // simply compare the two elements
        if (a[left] > a[right])
            std::swap(a[left], a[right]);
    }
    else//BASE CASE: one element
    {
        // do nothing, we only have 1 element
    }
}

#endif // QUICKSORT_H_INCLUDED
