#include<stdio.h>
using namespace std;

bool IsUgly(int number)
{
	while(number%2==0)
		number=number/2;
	while(number%3==0)
		number=number/3;
	while(number%5==0)
		number=number/5;
	
	return (number==1)? true : false;
}

int GetUglyNumber_Solution1(int index)
{
	if(index<=0)
		return 0;
	
	int count=0;
	int number=0;
	while(count<index)
	{
		++number;
		if(IsUgly(number))
			++count;
	}
	printf("%d",number);
	return number;
}

int Min(int num1,int num2,int num3)
{
	int min=(num1<num2)?num1:num2;
	return (min<num3)?min:num3;
}

int GetUglyNumber_Solution2(int index)
{
	if(index<=0)
		return 0;
	
	int *pUglyNumbers=new int[index];
	pUglyNumbers[0]=1;
	int nextUglyIndex=1;

	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	while(nextUglyIndex<index)
	{
		int min=Min(*pMultiply2*2,*pMultiply3*3,*pMultiply5*5);
		pUglyNumbers[nextUglyIndex]=min;

		while(*pMultiply2*2<=pUglyNumbers[nextUglyIndex])
			++pMultiply2;
		while(*pMultiply3*3<=pUglyNumbers[nextUglyIndex])
			++pMultiply3;
		while(*pMultiply5*5<=pUglyNumbers[nextUglyIndex])
			++pMultiply5;

		++nextUglyIndex;
	}
	int ugly=pUglyNumbers[nextUglyIndex-1];
	delete[] pUglyNumbers;
	printf("%d",ugly);
	return ugly;
}

// ====================测试代码====================
void Test(int index, int expected)
{
    if(GetUglyNumber_Solution1(index) == expected)
        printf("solution1 passed\n");
    else
        printf("solution1 failed\n");

    if(GetUglyNumber_Solution2(index) == expected)
        printf("solution2 passed\n");
    else
        printf("solution2 failed\n");
}

int main(int argc, char* argv[])
{
    Test(1, 1);

    Test(2, 2);
    Test(3, 3);
    Test(4, 4);
    Test(5, 5);
    Test(6, 6);
    Test(7, 8);
    Test(8, 9);
    Test(9, 10);
    Test(10, 12);
    Test(11, 15);

    Test(1500, 859963392);

    Test(0, 0);

    return 0;
}
