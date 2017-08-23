#include<stdio.h>
#include<stdexcept>
using namespace std;

int MinInOrder(int* Nums,int start,int end)
{
	int result=Nums[start];
	for(int i=start;i<=end;++i)
	{
		if(Nums[i]<result)
			result=Nums[i];
	}
	return result;
}

int Min(int* Nums,int length)
{
	if(Nums==NULL || length<=0)
		throw std::runtime_error("Nums is NULL");
	int start=0;
	int end=length-1;
	int mid=start;//当数组未旋转时，直接返回start
	while(Nums[mid]>=Nums[end])
	{
		if(end-start==1)
		{
			mid=end;
			break;
		}
		mid=(start+end)/2;

		if(Nums[start]==Nums[mid]&&Nums[end]==Nums[mid])
			return MinInOrder(Nums,start,end);

		if(Nums[mid]>=Nums[start])
		{
			start=mid;
		}
		else if(Nums[mid]<=Nums[end])
		{
			end=mid;
		}
	}
	return Nums[mid];
}

// ====================测试代码====================
void Test(int* numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = Min(numbers, length);

        for(int i = 0; i < length; ++i)
            printf("%d ", numbers[i]);

        if(result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed\n");
    }
    catch (...)
    {
        if(numbers == NULL)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
}

int main(int argc, char* argv[])
{
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = { 3, 4, 5, 1, 2 };
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 0, 1, 1, 1 };
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // 数组中只有一个数字
    int array6[] = { 2 };
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // 输入nullptr
    Test(NULL, 0, 0);

    return 0;
}
