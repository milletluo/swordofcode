#include<stdio.h>
using namespace std;

void ReorderOddEven(int *pData,unsigned int length)
{
	if(pData==NULL||length<=0)
		return;
	
	int *pStart=pData;
	int *pEnd=pData+length-1;
	while(pStart<pEnd)
	{
		while((*pStart & 0x01)!=0)
			pStart++;
		while((*pEnd &0x01)==0)
			pEnd--;
		if(pStart<pEnd)
		{
			int xchange=*pStart;
			*pStart=*pEnd;
			*pEnd=xchange;
		}
	}
}


// ====================测试代码====================
void PrintArray(int numbers[], int length)
{
    if(length < 0)
        return;

    for(int i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void Test(char* testName, int numbers[], int length)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
    {
        copy[i] = numbers[i];
    }

    PrintArray(numbers, length);
    ReorderOddEven(numbers, length);
    PrintArray(numbers, length);

    delete[] copy;
}

void Test1()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    Test("Test1", numbers, sizeof(numbers)/sizeof(int));
}

void Test2()
{
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int));
}

void Test3()
{
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int));
}

void Test4()
{
    int numbers[] = {1};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int));
}

void Test5()
{
    int numbers[] = {2};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int));
}

void Test6()
{
    Test("Test6", NULL, 0);
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
