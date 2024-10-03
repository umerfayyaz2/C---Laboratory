template <class elemType>
int binarySearch(const elemType list[], int length, const elemType &item)
{
    int first = 0;
    int last = length - 1;
    int mid;
    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;
        if (list[mid] == item)
        {
            found = true;
        }
        else if (list[mid] > item)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }

    if (found)
    {
        return mid;
    }
    else
    {
        return -1;
    }
}
