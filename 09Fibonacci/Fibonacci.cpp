#include<stdio.h>
#include<time.h>
using namespace std;

long long Fibonacci(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	long long temp1=1;
	long long temp2=0;
	long long result=0;
	for(int i=2;i<=n;++i)
	{
		result = temp1 + temp2;
		temp2 = temp1;
		temp1 = result;
	}
	return result;
}

long long Fib_Iterate(int n)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	return Fib_Iterate(n-1)+Fib_Iterate(n-2);
}

void Test(int n, int expected)
{
	clock_t start,stop1,stop2;
	start = clock();
    if(Fibonacci(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);
	stop1 = clock();
	printf("Use time:%f\n",(double)(stop1-start)/CLOCKS_PER_SEC);
    if(Fib_Iterate(n) == expected)
        printf("Test for %d in solution2 passed.\n", n);
    else
        printf("Test for %d in solution2 failed.\n", n);
	stop2 = clock();
	printf("Use time:%f\n",(double)(stop2-stop1)/CLOCKS_PER_SEC);
}

int main(int argc, char* argv[])
{
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);

    return 0;
}
