//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        //int nSize=array.size();
        vector<int> vOdd;
        for(vector<int>::iterator it=array.begin(); it!=array.end();){
            if(*it%2==1){
                vOdd.push_back(*it);
                it=array.erase(it);
            }
            else
                it++;
        }
        for(vector<int>::iterator it=array.begin(); it!=array.end();++it){
            vOdd.push_back(*it);
        }
        array=vOdd;
    }
};

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int nSize=array.size();
        vector<int> vOdd;
        for(int i=0;i<nSize;++i){
            if(array[i]%2==1)
                vOdd.push_back(array[i]);
        }
        for(int i=0;i<nSize;++i){
            if(array[i]%2==0)
                vOdd.push_back(array[i]);
        }
        array=vOdd;
    }
};
