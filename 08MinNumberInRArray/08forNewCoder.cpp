//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int nLength=rotateArray.size();
        if(nLength==0){
            return 0;
        }
        int nLeft=0;
        int nRight=nLength-1;
        while(nLeft!=nRight-1){//最后左指针指向前面子数组最大值，右指针指向后面子数组最小值
            int nMid=(nLeft+nRight)>>1;
            if(rotateArray[nMid]<=rotateArray[nRight])
                nRight=nMid;
            else if(rotateArray[nMid]>=rotateArray[nLeft])
                nLeft=nMid;
        }
        return rotateArray[nRight];
    }
};
