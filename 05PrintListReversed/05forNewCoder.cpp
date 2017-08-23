/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* tempNode=head;
        stack<int> sNodes;
        while(tempNode!=NULL){
            sNodes.push(tempNode->val);
            tempNode=tempNode->next;
        }
        vector<int> result;
        while(sNodes.size()!=0){
            result.push_back(sNodes.top());
            sNodes.pop();
        }
        return result;
    }
};
