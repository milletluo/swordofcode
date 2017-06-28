#include<stdio.h>
#include"../Utilities/List.h"
using namespace std;

ListNode* ReverseList(ListNode* pHead)
{
	ListNode *pLeft=NULL;
	ListNode *pMid=pHead;
	ListNode *pReversedHead=NULL;
	while(pMid!=NULL)
	{
		ListNode *pRight=pMid->m_pNext;
		if(pRight==NULL)
			pReversedHead=pMid;
		pMid->m_pNext=pLeft;
		pLeft=pMid;
		pMid=pRight;
	}
	return pReversedHead;
}

// ====================测试代码====================
ListNode* Test(ListNode* pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// 输入的链表有多个结点
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入空链表
void Test3()
{
    Test(NULL);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
