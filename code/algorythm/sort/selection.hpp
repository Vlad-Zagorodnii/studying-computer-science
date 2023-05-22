#ifndef SELECTION
#define SELECTION

#include <vector>

namespace CS::Algorythm
{

    template <class T>
    void SelectionSort(std::vector<T> &Data)
    {
        for (int i = 0; i < Data.size() - 1; ++i)
        {
            int Index = i;
            T Smaller = Data[i];
            for (int j = i + 1; j < Data.size(); ++j)
            {
                if (Smaller > Data[j])
                {
                    Index = j;
                    Smaller = Data[j];
                }
            }

            for (int j = Index - 1; j >= i; --j)
            {
                Data[j + 1] = Data[j];
            }

            Data[i] = Smaller;
        }
    }

    template <class T>
    void OptimizedSelectionSort(std::vector<T> &Data)
    {
        for (int i = 0; i < Data.size() - 1; ++i)
        {
            int Index = i;
            T Smaller = Data[i];
            for (int j = i + 1; j < Data.size(); ++j)
            {
                if (Smaller > Data[j])
                {
                    Index = j;
                    Smaller = Data[j];
                }
            }

            T Temp = Data[Index];
            Data[Index] = Data[i];
            Data[i] = Temp;
        }
    }
}

#endif