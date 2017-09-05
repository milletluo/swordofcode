//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

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
    bool isSubtree(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if(pRoot2==NULL)//要先判pRoot2
            return true;
        if(pRoot1==NULL)
            return false;
        if(pRoot1->val!=pRoot2->val)
            return false;
        return isSubtree(pRoot1->left,pRoot2->left)&&isSubtree(pRoot1->right,pRoot2->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool bResult=false;
        if(pRoot1!=NULL&&pRoot2!=NULL){
            if(pRoot1->val==pRoot2->val)
                bResult=isSubtree(pRoot1,pRoot2);
            if(!bResult){
                bResult=HasSubtree(pRoot1->left,pRoot2);
            }
            if(!bResult){
                bResult=HasSubtree(pRoot1->right,pRoot2);
            }
        }
        return bResult;

    }
};
