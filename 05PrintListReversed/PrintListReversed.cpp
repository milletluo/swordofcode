#include<iostream>
#include "../Utilities/List.h"
#include<stack>
using namespace std;

void PrintReversed(ListNode *pHead)
{
    stack<ListNode*> nodes;
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    while(!nodes.empty())
    {
        pNode = nodes.top();
        cout<<pNode->m_nValue<<"\t";
        nodes.pop();
    }
}

void PrintReversedRecursively(ListNode* pHead)
{
    if(pHead != NULL)
    {
        if(pHead->m_pNext != NULL)
        {
            PrintReversedRecursively(pHead->m_pNext);
        }
        cout<<pHead->m_nValue<<"\t";
    }
}

void Test(ListNode* pHead)
{
    PrintList(pHead);
    PrintReversed(pHead);
    cout<<endl;
    PrintReversedRecursively(pHead);
}

void Test1()
{
    cout<<"\nTest1 begins.\n"<<endl;

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);

    DestroyList(pNode1);
}

void Test2()
{
    cout<<"\nTest2 begins.\n"<<endl;

    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1);

    DestroyList(pNode1);
}

void Test3()
{
    cout<<"\nTest3 begins.\n"<<endl;

    Test(NULL);
}

int main(int argc,char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
