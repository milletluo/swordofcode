#include<stdio.h>
#include"../Utilities/Array.h"
using namespace std;
bool g_bInputInvalid=false;

bool CheckInvalidArray(int* numbers,int length)
{
	g_bInputInvalid=false;
	if(numbers==NULL || length<=0)
		g_bInputInvalid=true;

	return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers,int length,int number)
{
	int times=0;
	for(int i=0;i<length;++i)
	{
		if(numbers[i]==number)
			times++;
	}
	bool isMoreThanHalf=true;
	if(times*2<=length)
	{
		g_bInputInvalid=true;
		isMoreThanHalf=false;
	}
	return isMoreThanHalf;
}

int MoreThanHalfNum_Solution1(int* numbers,int length)
{
	if(CheckInvalidArray(numbers,length))
		return 0;
	int middle=length>>1;
	int start=0;
	int end=length-1;
	//Partition在Array中定义
	int index=Partition(numbers,length,start,end);
	while(index!=middle)
	{
		if(index<middle)
			start=index+1;
		else
			end=index-1;
		index=Partition(numbers,length,start,end);
	}
	int result=numbers[middle];
	if(!CheckMoreThanHalf(numbers,length,result))
		result=0;
	return result;
}


// ====================方法2====================
int MoreThanHalfNum_Solution2(int* numbers, int length)
{
    if(CheckInvalidArray(numbers, length))
        return 0;
 
    int result = numbers[0];
    int times = 1;
    for(int i = 1; i < length; ++i)
    {
        if(times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if(numbers[i] == result)
            times++;
        else
            times--;
    }
 
    if(!CheckMoreThanHalf(numbers, length, result))
        result = 0;
 
    return result;
}

// ====================测试代码====================
void Test(const char* testName, int* numbers, int length, int expectedValue, bool expectedFlag)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
        copy[i] = numbers[i];

    printf("Test for solution1: ");
    int result = MoreThanHalfNum_Solution1(numbers, length);
    if(result == expectedValue && g_bInputInvalid == expectedFlag)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Test for solution2: ");
    result = MoreThanHalfNum_Solution2(copy, length);
    if(result == expectedValue && g_bInputInvalid == expectedFlag)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    delete[] copy;
}

// 存在出现次数超过数组长度一半的数字
void Test1()
{
    int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 不存在出现次数超过数组长度一半的数字
void Test2()
{
    int numbers[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), 0, true);
}

// 出现次数超过数组长度一半的数字都出现在数组的前半部分
void Test3()
{
    int numbers[] = {2, 2, 2, 2, 2, 1, 3, 4, 5};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 出现次数超过数组长度一半的数字都出现在数组的后半部分
void Test4()
{
    int numbers[] = {1, 3, 4, 5, 2, 2, 2, 2, 2};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 输入空指针
void Test5()
{
   int numbers[] = {1};
   Test("Test5", numbers, 1, 1, false);
}

// 输入空指针
void Test6()
{
    Test("Test6", NULL, 0, 0, true);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
