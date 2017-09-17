//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4

class Solution {
public:
    /*vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if(k<=0||input.size()<k)
            return result;
        sort(input.begin(),input.end());
        for(int i=0;i<k;i++){
            result.push_back(input[i]);
        }
        return result;
    }*/
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if(k<=0||input.size()<k)
            return result;
        int begin=0;
        int end=input.size()-1;
        int index=Partition(input,begin,end);
        while(index!=(k-1)){
            if(index>k-1){
                end=index-1;
                index=Partition(input,begin,end);
            }
            else{
                begin=index+1;
                index=Partition(input,begin,end);
            }
        }
        for(int i=0;i<=index;i++){
            result.push_back(input[i]);
        }
        return result;
    }
    int Partition(vector<int>& data,int begin,int end){
        int low=begin;
        int high=end;
        int pivot=data[low];
        while(low<high){
            while(low<high&&pivot<=data[high])
                high--;
            data[low]=data[high];
            while(low<high&&pivot>=data[low])
                low++;
            data[high]=data[low];
        }
        data[low]=pivot;
        return low;
    }
};
