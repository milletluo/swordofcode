#include<stdio.h>
using namespace std;

int InversePairsCore(int* data,int* copy,int start,int end);

int InversePairs(int* data,int length)
{
	if(data==NULL||length<=0)
		return 0;
	
	int* copy=new int[length];
	for(int i=0;i<length;++i)
		copy[i]=data[i];
	
	int count=InversePairsCore(data,copy,0,length-1);
	delete[] copy;
	return count;
}

int InversePairsCore(int* data,int* copy,int start,int end)
{
	if(start==end)
	{
		copy[start]=data[start];
		return 0;
	}
	int length=(end-start)/2;
	int left=InversePairsCore(copy,data,start,start+length);
	int right=InversePairsCore(copy,data,start+length+1,end);
	//i,j分别指向两个子数组末尾
	int i=start+length;
	int j=end;
	int indexCopy=end;
	int count=0;
	while(i>=start&&j>=start+length+1)
	{
		if(data[i]>data[j])
		{
			copy[indexCopy--]=data[i--];
			count+=j-start-length;//j以前的个数
		}
		else
		{
			copy[indexCopy--]=data[j--];
		}
	}
	for(;i>=start;--i)
		copy[indexCopy--]=data[i];
	for(;j>=start+length+1;--j)
		copy[indexCopy--]=data[j];

	return left+right+count;
}
// ====================测试代码====================
void Test(const char* testName, int* data, int length, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(InversePairs(data, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    int data[] = { 1, 2, 3, 4, 7, 6, 5 };
    int expected = 3;

    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2()
{
    int data[] = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3()
{
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
    int data[] = { 1 };
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
    int data[] = { 1, 2 };
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
    int data[] = { 2, 1 };
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7()
{
    int data[] = { 1, 2, 1, 2, 1 };
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
    int expected = 0;

    Test("Test8", NULL, 0, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();

    return 0;
}
