//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode *pLastNode=NULL;
        ConvertNode(pRootOfTree,&pLastNode);//转换完后，指针指向最后

        TreeNode *pHeadNode=pLastNode;
        while(pHeadNode!=NULL&&pHeadNode->left!=NULL)//返回头指针
            pHeadNode=pHeadNode->left;
        return pHeadNode;
    }
    void ConvertNode(TreeNode* pNode,TreeNode** pLastNode)
    {
        if(pNode==NULL)
            return;
        TreeNode *pCurrent=pNode;
        if(pCurrent->left!=NULL)
            ConvertNode(pCurrent->left,pLastNode);//递归转换左子树
        pCurrent->left=*pLastNode;//当前节点的左子针指向最后一个节点
        if(*pLastNode!=NULL)
            (*pLastNode)->right=pCurrent;//最后一个节点的右子针指向当前节点
        *pLastNode=pCurrent;//更新最后一个节点为当前节点
        if(pCurrent->right!=NULL)
            ConvertNode(pCurrent->right,pLastNode);//递归转换右子树
    }
};
