#include <iostream>
#include <vector>

template <class T, class D>
struct pair
{
public:
    T First;
    D Second;
};

template <class T>
bool exUnion(pair<int, int> P_Q, std::vector<T> *Data)
{
    bool isUnion = true;
    T searchValue = (*Data)[P_Q.First];
    for (int i = 0; i < Data->size(); ++i)
    {
        if ((*Data)[i] == searchValue)
        {
            if ((*Data)[i] != (*Data)[P_Q.Second])
            {
                (*Data)[i] = (*Data)[P_Q.Second];
                isUnion = false;
            }
        }
    }
    return isUnion;
}

int main()
{
    pair<int, int> P_Q[] = {{3, 4}, {4, 9}, {8, 0}, {2, 3}, {5, 6}, {2, 9}, {5, 9}, {7, 3}, {4, 8}, {5, 6}, {0, 2}, {6, 1}};
    std::vector<int> Data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 12; ++i)
    {
        std::cout << (P_Q + i)->First << ' ' << (P_Q + i)->Second << '\t';
        std::cout << exUnion(P_Q[i], &Data) << '\t';
        for (int j = 0; j < Data.size(); ++j)
        {
            std::cout << Data[j] << ' ';
        }
        std::cout << '\n';
    }
}