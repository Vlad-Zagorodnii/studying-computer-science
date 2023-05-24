#ifndef INSERTION
#define INSERTION

#include <vector>

namespace CS::Algorythm
{

    template <class T>
    void InsertionSort(std::vector<T> &Data)
    {
        for (int i = 1; i < Data.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (Data[i] < Data[j])
                {
                    T Value = Data[i];
                    for (int k = i - 1; k >= j; --k)
                    {
                        Data[k + 1] = Data[k];
                    }
                    Data[j] = Value;
                    break;
                }
            }
        }
    }
}

#endif