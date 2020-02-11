#ifndef __LIST__H__
#define __LIST__H__

#include <iostream>

using namespace std;

typedef struct NODE{
    int value;
    NODE *next;
    NODE *previous;
}s_NODE;

class list{
    public:
        list();
        ~list();
        void appendValue(int valueToAdd);
        void deleteList(void);
        bool findValue(int valueToFind);
        void printList(void);
        void removeValue(int);
        void sortList(void);

    private:
        int p_IsSorted;
        int p_NumberOfNodes;
        s_NODE *p_Head;
        s_NODE *p_Tail;

        s_NODE* p_CreateNode(int newValue);
        void p_DeleteList(void);
        void p_DeleteNode(int);
        void p_InsertNode(int);

};

#endif