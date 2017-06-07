#include<iostream>
using namespace std;

void Replace(char* str)
{
    if(str==NULL)
    {
        return;
    }

    int nOrigL=0;
    int nSpaces=0;
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]==' ')
            nSpaces++;
        nOrigL++;
        i++;
    }
    int nNewL=nOrigL+nSpaces*2;

    int nOrigIndex=nOrigL;
    int nNewIndex=nNewL;
    while(nOrigIndex>=0&&nOrigIndex<nNewIndex)
    {
        if(str[nOrigIndex]==' ')
        {
            str[nNewIndex--]='0';
            str[nNewIndex--]='2';
            str[nNewIndex--]='%';
        }
        else
        {
            str[nNewIndex--]=str[nOrigIndex];
        }
        nOrigIndex--;
    }
}

void Test(char str[],char expected[])
{
    Replace(str);
    if(str==NULL&&expected==NULL)
    {
        cout<<"passed!"<<endl;
    }
    else if(str==NULL&&expected!=NULL)
    {
        cout<<"failed!"<<endl;
    }
    else if(strcmp(str,expected) == 0)
    {
        cout<<"passed!"<<endl;
    }
    else
    {
        cout<<"failed!"<<endl;
    }
}

// 空格在句子中间
void Test1()
{
    char str[100] = "hello world";
    Test(str, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    char str[100] = " helloworld";
    Test(str, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    char str[100] = "helloworld ";
    Test(str, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    char str[100] = "hello  world";
    Test(str,  "hello%20%20world");
}

// 传入nullptr
void Test5()
{
    Test( nullptr, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
    char str[100] = "";
    Test(str, "");
}

//传入内容为一个空格的字符串
void Test7()
{

    char str[100] = " ";
    Test(str, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    char str[100] = "helloworld";
    Test( str, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    char str[100] = "   ";
    Test(str,  "%20%20%20");
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
    Test9();
    return 0;
}

