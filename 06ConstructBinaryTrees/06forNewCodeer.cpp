/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int lenPre=pre.size();
        int lenIn=vin.size();
        if(lenPre==0||lenIn==0){
            return NULL;
        }
        TreeNode* treeNode = new TreeNode(pre[0]);
        int lenleft=0;
        while(vin[lenleft]!=pre[0]){
            lenleft++;
        }
        vector<int> preL,preR,inL,inR;
        for(int i=0;i<lenleft;i++){
            preL.push_back(pre[i+1]);
            inL.push_back(vin[i]);
        }
        for(int j=lenleft+1;j<lenPre;j++){
            preR.push_back(pre[j]);
            inR.push_back(vin[j]);
        }
        treeNode->left=reConstructBinaryTree(preL,inL);
        treeNode->right=reConstructBinaryTree(preR,inR);
        return treeNode;

    }
};
