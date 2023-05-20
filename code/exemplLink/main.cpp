#include <iostream>
#include "exmplLink.hpp"

using namespace std;

int main()
{
    CS::exmplLink<int> tst;
    tst.addChain({3, 4});
    tst.addChain({4, 9});
    tst.addChain({8, 0});
    tst.addChain({2, 3});
    tst.addChain({5, 6});
    vector<int> rez = tst.findLink({2, 9});

    for (int i = 0; i < rez.size(); ++i)
    {
        cout << rez[i] << " ";
    }
    cout << '\n';
}