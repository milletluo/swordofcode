//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

class Solution {
public:
     int  NumberOf1(int n) {
         int flag=1;
         int count=0;
         while(flag){
             if(n&flag)
                 count++;
             flag=flag<<1;//1左移一位，右边补零，溢出后为0，退出while
         }
         return count;
     }
};

class Solution {
public:
     int  NumberOf1(int n) {
         int count=0;
         while(n){
             count++;
             n=(n-1)&n;//把该整数最右边一个1变成0，左边的保持不变。有多少个1就可以做多少次这种操作，直到最后与完的结果为0
         }
         return count;
     }
};
