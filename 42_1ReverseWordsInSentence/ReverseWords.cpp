#include<stdio.h>
#include<string.h>
using namespace std;

void Reverse(char* pBegin,char* pEnd)
{
	if(pBegin==NULL||pEnd==NULL)
		return;
	while(pBegin<pEnd)
	{
		char temp;
		temp=*pEnd;
		*pEnd=*pBegin;
		*pBegin=temp;

		pBegin++;
		pEnd--;
	}
}

char* ReverseSentence(char* pData)
{
	if(pData==NULL)
		return NULL;
	
	char *pBegin=pData;
	char *pEnd=pData;
	while(*pEnd!='\0')
		pEnd++;
	pEnd--;

	Reverse(pBegin,pEnd);

	pBegin=pEnd=pData;
	while(*pBegin!='\0')
	{
		if(*pBegin==' ')
		{
			pBegin++;
			pEnd++;
		}
		else if(*pEnd==' '||*pEnd=='\0')
		{
			Reverse(pBegin,--pEnd);
			pBegin=++pEnd;
		}
		else
		{
			pEnd++;
		}
	}
	return pData;
}

// ====================测试代码====================
void Test(const char* testName, char* input, char* expectedResult)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    ReverseSentence(input);

    if((input == NULL && expectedResult == NULL)
        || (input != NULL && strcmp(input, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试，句子中有多个单词
void Test1()
{
    char input[] = "I am a student.";
    char expected[] = "student. a am I";

    Test("Test1", input, expected);
}

// 功能测试，句子中只有一个单词
void Test2()
{
    char input[] = "Wonderful";
    char expected[] = "Wonderful";

    Test("Test2", input, expected);
}

// 鲁棒性测试
void Test3()
{
    Test("Test3", NULL, NULL);
}

// 边界值测试，测试空字符串
void Test4()
{
	char input[] = "";
	char expected[] = "";
    Test("Test4", input, expected);
}

// 边界值测试，字符串中只有空格
void Test5()
{
    char input[] = "   ";
    char expected[] = "   ";
    Test("Test5", input, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
