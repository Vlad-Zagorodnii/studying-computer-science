#ifndef EXMPLLINK
#define EXMPLLINK

#include "subfunction.hpp"

namespace CS
{

    template <class T>
    class exmplLink
    {
    private:
        CS::subF::pair<T, T> *chainPTR = nullptr;
        int size = 0;

    public:
        ~exmplLink();
        void addChain(CS::subF::pair<T, T> chain);
        std::vector<T> findLink(CS::subF::pair<T, T> endNodes);
    };

    template <class T>
    void exmplLink<T>::addChain(CS::subF::pair<T, T> chain)
    {
        CS::subF::pair<T, T> *newChainPtr = new CS::subF::pair<T, T>[size + 1];
        for (int i = 0; i < size; ++i)
        {
            newChainPtr[i] = chainPTR[i];
        }
        newChainPtr[size] = chain;
        ++size;
        delete[] chainPTR;
        chainPTR = newChainPtr;
    }

    // return final and intermediate nodes<dataArrayPtr, size>
    template <class T>
    std::vector<T> exmplLink<T>::findLink(CS::subF::pair<T, T> endNodes)
    {
        std::vector<T> PassedNode;
        std::vector<std::vector<T>> Path;
        Path.push_back({endNodes.First});
        while (Path.size() > 0)
        {
            for (int i = 0; i < Path.size(); ++i)
            {
                subF::pair<T *, int> Node = subF::link({chainPTR, size}, Path[i][Path[i].size() - 1], 5);
                PassedNode.push_back(Path[i][Path[i].size() - 1]);
                subF::DelPassNode(&Node, &PassedNode);

                if (Node.Second > 1)
                {
                    for (int j = 0; j < Node.Second; ++j)
                    {
                        Path.push_back(Path[i]);
                        Path[Path.size() - 1].push_back(Node.First[j]);
                        if (Path[Path.size() - 1][Path[Path.size() - 1].size() - 1] == endNodes.Second)
                        {
                            return Path[Path.size() - 1];
                        }
                    }
                }
                else if (Node.Second == 1)
                {
                    Path[i].push_back(*Node.First);
                    if (Path[Path.size() - 1][Path[Path.size() - 1].size() - 1] == endNodes.Second)
                    {
                        return Path[Path.size() - 1];
                    }
                }
                else
                {
                    if (Path[Path.size() - 1][Path[Path.size() - 1].size() - 1] != endNodes.Second)
                    {

                        Path.pop_back();
                    }
                }
                delete[] Node.First;
            }
        }
        return {endNodes.First};
    }

    template <class T>
    exmplLink<T>::~exmplLink()
    {
        delete[] chainPTR;
    }
};

#endif