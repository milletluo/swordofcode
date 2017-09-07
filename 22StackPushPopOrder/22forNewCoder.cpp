//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
//例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        bool result=false;
        int pushLen=pushV.size();
        int popLen=popV.size();
        if(pushLen!=popLen)
            return result;
        stack<int> tempS;
        int popIndex=0;
        int pushIndex=0;
        while(popIndex<popLen){
            while(tempS.empty()||tempS.top()!=popV[popIndex]){//如果栈顶不等于下一个出列数
                if(pushIndex==pushLen)
                    break;
                tempS.push(pushV[pushIndex++]);//压栈直到全部压入，或者压入的栈顶等于下一个出列数
            }
            if(tempS.top()!=popV[popIndex])//如果栈顶不等于下一个出列数且无数可再压入
                break;
            else{
                tempS.pop();
                popIndex++;
            }
        }
        if(tempS.empty()&&popIndex==popLen)
            result=true;
        return result;
    }
};
