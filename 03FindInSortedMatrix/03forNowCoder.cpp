class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool result=false;
        int row = 0;
        int nRow = array.size();
        int nColumn = array[0].size()-1;
        while(row < nRow && nColumn >= 0){
            if(array[row][nColumn] == target){
                result=true;
                break;
            }
            else if(array[row][nColumn]>target)
                nColumn--;
            else
                row++;
        }
        return result;
    }
};
