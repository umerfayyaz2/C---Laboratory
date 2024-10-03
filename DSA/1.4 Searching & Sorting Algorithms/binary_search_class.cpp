#include "arrayListType.h"
#include "searchSortAlgorithms.h"

template <class elemType>
class orderedArrayListType : public arrayListType<elemType>
{
public:
    void insertAt(int location, const elemType &insertItem);
    void insertEnd(const elemType &insertItem);
    void replaceAt(int location, const elemType &repItem);
    int seqSearch(const elemType &searchItem) const;
    void insert(const elemType &insertItem);
    void remove(const elemType &removeItem);
    int binSearch(const elemType &removeItem); // Binary Search Declaration
    orderedArrayListType(int size = 100);      // Constructor
};

// Definition of binSearch member function
template <class elemType>
int orderedArrayListType<elemType>::binSearch(const elemType &item) const
{
    return binarySearch(list, length, item); // Call to binary search function
}
