#ifndef SUBFUNCTION
#define SUBFUNCTION

#include <vector>

namespace CS::subF
{

    // Definetions

    template <class T, class D>
    struct pair;

    template <class T>
    pair<T *, int> link(pair<pair<T, T> *, int> Chains, T ActiveNode, int ArrExp);

    template <class T>
    void incArray(pair<T *, int> *Ptr, int Size);

    template <class T>
    void DelPassNode(pair<T *, int> *Node, std::vector<T> *PassedNode);

    // Class realisation

    template <class T, class D>
    struct pair
    {
    public:
        T First;
        D Second;
    };

    // function realisation

    // link(ArrChains<ChainsPtr*,Size>, ActiveNode, Array Expansion(default = 10))
    // return linked node<NodePtr, Count>
    template <class T>
    pair<T *, int> link(pair<pair<T, T> *, int> Chains, T ActiveNode, int ArrExp)
    {
        int size = ArrExp;
        pair<T *, int> LinkedNode = {new T[ArrExp], 0};
        for (int i = 0; i < Chains.Second; ++i)
        {
            if (Chains.First[i].First == ActiveNode)
            {
                if (size > LinkedNode.Second)
                {
                    LinkedNode.First[LinkedNode.Second] = Chains.First[i].Second;
                    ++LinkedNode.Second;
                }
                else
                {
                    incArray(&LinkedNode, ArrExp);
                    size += ArrExp;
                    LinkedNode.First[LinkedNode.Second] = Chains.First[i].Second;
                    ++LinkedNode.Second;
                }
            }
        }

        for (int i = 0; i < Chains.Second; ++i)
        {
            if (Chains.First[i].Second == ActiveNode)
            {
                if (size > LinkedNode.Second)
                {
                    LinkedNode.First[LinkedNode.Second] = Chains.First[i].First;
                    ++LinkedNode.Second;
                }
                else
                {
                    incArray(&LinkedNode, ArrExp);
                    size += ArrExp;
                    LinkedNode.First[LinkedNode.Second] = Chains.First[i].First;
                    ++LinkedNode.Second;
                }
            }
        }

        T *tmpPtr = new T[LinkedNode.Second];
        for (int i = 0; i < LinkedNode.Second; ++i)
        {
            tmpPtr[i] = LinkedNode.First[i];
        }
        delete[] LinkedNode.First;
        LinkedNode.First = tmpPtr;
        return LinkedNode;
    }

    template <class T>
    void incArray(pair<T *, int> *Ptr, int Size)
    {
        T *tmpPtr = new T[Ptr->Second + Size];
        for (int i = 0; i < Ptr->Second; ++i)
        {
            tmpPtr[i] = Ptr->First[i];
        }
        delete[] Ptr->First;
        Ptr->First = tmpPtr;
    }

    template <class T>
    void DelPassNode(pair<T *, int> *Node, std::vector<T> *PassedNode)
    {
        pair<T *, int> *newNode = new pair<T *, int>;
        newNode->First = new T[Node->Second];
        newNode->Second = 0;
        for (int i = 0; i < Node->Second; ++i)
        {
            bool isPassed = false;
            for (int j = 0; j < PassedNode->size(); ++j)
            {
                if (Node->First[i] == PassedNode[0][j])
                    isPassed = true;
            }
            if (!isPassed)
            {
                newNode->First[newNode->Second] = Node->First[i];
                ++newNode->Second;
            }
        }
        delete[] Node->First;
        Node->First = newNode->First;
        Node->Second = newNode->Second;
    }
}

#endif