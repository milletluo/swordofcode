//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
        ListNode* Result;
        ListNode* Node1;
        ListNode* Node2;
        Node1=pHead1;
        Node2=pHead2;
        if(Node1->val<=Node2->val){
            Result=Node1;
            Result->next=Merge(Node1->next,Node2);
        }
        else{
            Result=Node2;
            Result->next=Merge(Node1,Node2->next);
        }
        return Result;
    }
};
