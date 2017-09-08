//从上往下打印出二叉树的每个节点，同层节点从左至右打印。

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> tempQ;
        if(root==NULL)
            return result;
        TreeNode* tempNode=root;
        tempQ.push(tempNode);
        while(!tempQ.empty()){
            tempNode=tempQ.front();
            tempQ.pop();
            result.push_back(tempNode->val);
            if(tempNode->left!=NULL)
                tempQ.push(tempNode->left);
            if(tempNode->right!=NULL)
                tempQ.push(tempNode->right);
        }
        return result;
    }
};
