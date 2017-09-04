//输入一个链表，反转链表后，输出链表的所有元素。

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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL)
            return NULL;
        stack<ListNode*> Nodes;
        ListNode* tempNode=pHead;
        while(tempNode->next!=NULL){
            Nodes.push(tempNode);
            tempNode=tempNode->next;
        }
        ListNode* resultNode=tempNode;
        while(!Nodes.empty()){
            tempNode->next=Nodes.top();
            tempNode=tempNode->next;
            Nodes.pop();
        }
        tempNode->next=NULL;
        return resultNode;
        /*if(pHead==NULL)
            return NULL;
        ListNode* left=NULL;
        ListNode* mid=pHead;
        ListNode* right=NULL;
        while(mid!=NULL){
            right=mid->next;
            mid->next=left;
            if(right==NULL)
                break;
            left=mid;
            mid=right;
        }
        return mid;*/
    }
};
