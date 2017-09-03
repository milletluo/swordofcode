//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

class Solution {
public:
    double Power(double base, int exponent) {
        double result=1;
        if(exponent==0)
            result=1;
        else if(exponent<0){
            for(int i=0;i<-exponent;i++){
                result=result*base;
            }
            result=1/result;
        }
        else{
            for(int i=0;i<exponent;i++){
                result=result*base;
            }
        }
        return result;
    }
};

class Solution {
public:
    double Power(double base, int exponent) {
        double result=1;
        if((base-0.0>-0.0000001)&&(base-0.0<0.0000001))
            return 0;
        if(exponent==0)
            result=1;
        else if(exponent<0){
            for(int i=0;i<-exponent;i++){
                result=result*base;
            }
            result=1/result;
        }
        else{
            for(int i=0;i<exponent;i++){
                result=result*base;
            }
        }
        return result;
    }
};
