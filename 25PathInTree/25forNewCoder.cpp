//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        //if(root==NULL)
            //return NULL;
        vector<vector<int> > resultV;
        vector<int> path;
        int sum=0;
        findPath(root,expectNumber,resultV,path,sum);
        return resultV;
    }
    void findPath(TreeNode* root,int expectNumber,vector<vector<int> >& resultV,vector<int>& path,int& sum){
        if(root==NULL)
            return;
        sum+=root->val;
        path.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
            if(sum==expectNumber)
                resultV.push_back(path);
        }
        if(root->left!=NULL)
            findPath(root->left,expectNumber,resultV,path,sum);
        if(root->right!=NULL)
            findPath(root->right,expectNumber,resultV,path,sum);
        sum=sum-root->val;
        path.pop_back();
    }
};
