#include<stdio.h>
#include<string.h>
#include<memory>
using namespace std;
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

bool Increment(char* number)
{
	int nLength = strlen(number);
	int nTakeOver = 0;
	bool isOverflow = false;
	
	for(int i=nLength-1;i>=0;--i)
	{
		int nSum = number[i]-'0'+nTakeOver;
		if(i == nLength-1)//如果是个位
		{
			nSum++;
		}
		if(nSum>=10)
		{
			if(i==0)//如果是最高位进位，溢出
			{
				isOverflow = true;
			}
			else
			{
				nTakeOver = 1;
				nSum-=10;
				number[i]='0'+nSum;
			}
		}
		else
		{			
			number[i]='0'+nSum;
			break;
		}
	}
	return isOverflow;
}

void PrintNumber(char* number)
{
	bool bReady=false;
	int nLen=strlen(number);
	for(int i=0;i<nLen;++i)
	{
		if(!bReady && number[i]!='0')
			bReady=true;
		if(bReady)
			printf("%c",number[i]);
	}
	printf("\t");
}
void Print1ToMaxOfNDigits_1(int n)
{
	if(n<=0)
		return;
	
	char* number = new char[n+1];
	memset(number,'0',n);
	number[n] = '\0';
	while(!Increment(number))
		PrintNumber(number);

	delete []number;
}


// ====================方法二====================
void Print1ToMaxOfNDigits_2(int n)
{
    if(n <= 0)
        return;
 
    char* number = new char[n + 1];
    number[n] = '\0';
 
    for(int i = 0; i < 10; ++i)
    {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }
 
    delete[] number;
}
 
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    if(index == length - 1)
    {
        PrintNumber(number);
        return;
    }
 
    for(int i = 0; i < 10; ++i)
    {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}

// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    Print1ToMaxOfNDigits_1(n);
    Print1ToMaxOfNDigits_2(n);

    printf("Test for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}

