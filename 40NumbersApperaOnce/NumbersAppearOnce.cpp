#include<stdio.h>
using namespace std;

unsigned int FindRight1(int number)
{
	int index=0;
	while(((number&1)==0)&&(index<8*sizeof(int)))
	{
		number=number>>1;
		index++;
	}
	return index;
}

bool IsBit1(int num,unsigned int indexBit)
{
	num=num>>indexBit;
	return num&1;
}

void FindNumsAppearOnce(int data[],int length,int* num1,int* num2)
{
	if(data==NULL||length<2)
		return;
	int ResultOR=0;
	for(int i=0;i<length;++i)
		ResultOR^=data[i];
	
	unsigned int IndexOf1=FindRight1(ResultOR);
	*num1=*num2=0;
	for(int j=0;j<length;++j)
	{
		if(IsBit1(data[j],IndexOf1))
			*num1^=data[j];
		else
			*num2^=data[j];
	}
}

// ====================测试代码====================
void Test(const char* testName, int data[], int length, int expected1, int expected2)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    int result1, result2;
    FindNumsAppearOnce(data, length, &result1, &result2);

    if((expected1 == result1 && expected2 == result2) ||
        (expected2 == result1 && expected1 == result2))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

void Test1()
{
    int data[] = {2, 4, 3, 6, 3, 2, 5, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test2()
{
    int data[] = {4, 6};
    Test("Test2", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test3()
{
    int data[] = {4, 6, 1, 1, 1, 1};
    Test("Test3", data, sizeof(data) / sizeof(int), 4, 6);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
