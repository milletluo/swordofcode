//输入一个链表，输出该链表中倒数第k个结点。

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(k<=0||pListHead==NULL)
            return NULL;
        //int nSize=0;
        //while(pListHead->next!=NULL)//没必要先遍历一遍
        //    nSize++;
        //if(k>nSize)
        //    return NULL;
        ListNode* tempNode=pListHead;
        ListNode* resultNode=pListHead;
        for(int i=0;i<k-1;++i)
            if(tempNode->next!=NULL)//相当于判断k是否大于长度
                tempNode=tempNode->next;
            else
                return NULL;
        while(tempNode->next!=NULL){
            resultNode=resultNode->next;
            tempNode=tempNode->next;
        }
        return resultNode;
    }
};
