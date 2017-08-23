#include<stdio.h>
using namespace std;

char FirstNotRepeatChar(const char* pString)
{
	if(pString==NULL)
		return '\0';

	const int tableSize=256;
	unsigned int hashTable[tableSize];
	for(unsigned int i=0;i<tableSize;++i)
		hashTable[i]=0;
	
	const char* pHashKey=pString;
	while(*(pHashKey)!='\0')
		hashTable[*(pHashKey++)]++;

	pHashKey=pString;
	while(*pHashKey!='\0')
	{
		if(hashTable[*pHashKey]==1)
			return *pHashKey;
		pHashKey++;
	}
	return '\0';
}

// ====================测试代码====================
void Test(const char* pString, char expected)
{
    if(FirstNotRepeatChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    // 常规输入测试，存在只出现一次的字符
    Test("google", 'l');

    // 常规输入测试，不存在只出现一次的字符
    Test("aabccdbd", '\0');

    // 常规输入测试，所有字符都只出现一次
    Test("abcdefg", 'a');

    // 鲁棒性测试，输入nullptr
    Test(NULL, '\0');

    return 0;
}

