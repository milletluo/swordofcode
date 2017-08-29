//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
//n<=39
//0  1  2  3  4  5  6...
//0  1  1  2  3  5  8...

class Solution {
public:
    int Fibonacci(int n) {
        //int result=0;
        //if(n==0)
        //    result=0;
        //else if(n==1)
        //    result=1;
        //else
        //    result=Fibonacci(n-1)+Fibonacci(n-2);
        //return result;//递归效率太低
        if(n==0)
            return 0;
        else if(n==1)
            return 1;
        else{
            int first=1;
            int second=0;
            int result=0;
            for(int i=2;i<=n;++i){
                result=first+second;
                second=first;
                first=result;
            }
            return result;
        }
    }
};
