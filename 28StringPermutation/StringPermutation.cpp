#include<stdio.h>
using namespace std;
void Permutation(char* pStr,char* pBegin);

void Permutation(char* pStr)
{
	if(pStr==NULL)
		return;
	Permutation(pStr,pStr);
}

void Permutation(char* pStr,char* pBegin)
{
	if(*pBegin=='\0')
		printf("%s\n",pStr);
	else
	{
		for(char* pCh=pBegin;*pCh!='\0';pCh++)
		{
			//将第一个数依次与后续数交换
			char Temp=*pBegin;
			*pBegin=*pCh;
			*pCh=Temp;
			//余下的递归全排列
			Permutation(pStr,pBegin+1);
			//还原序列，以便下一次交换
			Temp=*pBegin;
			*pBegin=*pCh;
			*pCh=Temp;
		}
	}
}

// ====================测试代码====================
void Test(char* pStr)
{
    if(pStr == NULL)
        printf("Test for NULL begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    Permutation(pStr);

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(NULL);

    char string1[] = "";
    Test(string1);

    char string2[] = "a";
    Test(string2);

    char string3[] = "ab";
    Test(string3);

    char string4[] = "abc";
    Test(string4);

    char string5[] = "abcd";
    Test(string5);

    return 0;
}
