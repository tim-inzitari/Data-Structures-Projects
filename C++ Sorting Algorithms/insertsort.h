#ifndef INSERTSORT_H_INCLUDED
#define INSERTSORT_H_INCLUDED
// From pg 294 of the Book
#include <vector>
using std::vector;
/*template <typename Comparable>
void insertionSort (vector<Comparable> & a )
{
    for (int p =1; p<a.size(); ++p)
    {
        Comparable tmp = std::move (a[p]);

        int j;
        for (int j = p; j>0 && tmp < a[j-1]; --j)
            a[j]=std::move(a[j-1]);
        a[j] = std::move(tmp);
    }
}
*/
template<typename Iterator, typename Comparator>
void insertionSort(const Iterator &begin, const Iterator &end, Comparator lessThan);
template <typename Iterator>
void insertionSort(const Iterator & begin, const Iterator & end)
{
    insertionSort(begin,end,std::less<decltype(*begin)>{});
}

template<typename Iterator, typename Comparator>
void insertionSort(const Iterator &begin, const Iterator &end, Comparator lessThan)
{
    if (begin == end)
        return;

    Iterator j;

    for (Iterator p = begin+1; p != end; ++p)
    {
        auto tmp = std::move(*p);
        for(j=p; j!=begin && lessThan(tmp,*(j-1));--j)
            *j = std::move(*(j-1));
        *j = std::move(tmp);
    }
}


#endif // INSERTSORT_H_INCLUDED
