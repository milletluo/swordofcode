//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        //bool result=false;
        int len=sequence.size();
        if(len<=0)
            return false;
        int root=sequence[len-1];
        vector<int> left;
        vector<int> right;
        int i=0;
        for(;i<len-1;++i){
            if(sequence[i]>root)
                break;
            left.push_back(sequence[i]);
        }
        int j=i;
        for(;j<len-1;++j){
            if(sequence[j]<root)
                return false;
            right.push_back(sequence[j]);
        }
        if(j!=len-1)
            return false;
        bool bleft=true;
        if(left.size()>0)
            bleft=VerifySquenceOfBST(left);
        bool bright=true;
        if(right.size()>0)
            bright=VerifySquenceOfBST(right);
        return bleft&&bright;
    }
};
