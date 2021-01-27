#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED
// taken from pg 302
#include <vector>
using std::vector;

template <typename Comparable>
void percDown(vector<Comparable> & a, int i, int n);
inline int leftChild(int i);
// standard heap sort
template <typename Comparable>
void heapsort(vector<Comparable> & a)
{
    for (int i = a.size()/2 -1; i>=0; --i) //build heap
        percDown(a,i,a.size());
    for (int j= a.size()-1;j>0;--j) // delete max
    {
        std::swap(a[0],a[j]);
        percDown(a,0,j);
    }
}

/*
  Internal method for Heapsort
  i is hte index of an item in the heap
  Retrurns the Index of the Left Child
*/
inline int leftChild(int i)
{
    return 2 * i +1;
}


/*
    Internal method for heapsort that is used in dleete max and build heap
    i is the position from which to percolate
    n is the logical size of the binary heap
*/
template <typename Comparable>
void percDown(vector<Comparable> & a, int i, int n)
{
    int child;
    Comparable tmp;

    for (tmp = std::move(a[i]); leftChild(i)<n; i=child)
    {
        child = leftChild(i);
        if (child != n-1 && a[child]< a[child+1])
            ++child;
        if (tmp <a[child])
            a[i] = std::move(a[child]);
        else
            break;
    }
    a[i] = std::move(tmp);
}


#endif // HEAPSORT_H_INCLUDED
