#include<stdio.h>
using namespace std;

void printNumber(int num)
{
	printf("%d\t",num);
}

void PrintMatrixCircle(int** numbers,int columns,int rows,int start);

void PrintMatrixClockwisely(int** numbers,int columns,int rows)
{
	if(numbers==NULL || columns<=0 || rows<=0)
		return;
	int start=0;
	while(start*2<rows && start*2<columns)
	{
		PrintMatrixCircle(numbers,columns,rows,start);
		start++;
	}
}

void PrintMatrixCircle(int** numbers,int columns,int rows,int start)
{
	//待打印矩阵右下角坐标
	int endX=columns-1-start;
	int endY=rows-1-start;

	for(int i=start;i<=endX;++i)
	{
		int num=numbers[start][i];
		printNumber(num);
	}

	if(endY>start)
	{
		for(int i=start+1;i<=endY;++i)
		{
			int num=numbers[i][endX];
			printNumber(num);
		}
	}
	if(endX>start&&endY>start)
	{
		for(int i=endX-1;i>=start;--i)
		{
			int num=numbers[endY][i];
			printNumber(num);
		}
	}
	if(endY-1>start&&endX>start)
	{
		for(int i=endY-1;i>start;--i)
		{
			int num=numbers[i][start];
			printNumber(num);
		}
	}
}

// ====================测试代码====================
void Test(int columns, int rows)
{
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if(columns < 1 || rows < 1)
        return;

    int** numbers = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    PrintMatrixClockwisely(numbers, columns, rows);
    printf("\n");

    for(int i = 0; i < rows; ++i)
        delete[] (int*)numbers[i];

    delete[] numbers;
}

int main(int argc, char* argv[])
{
    /*
    1    
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);

    return 0;
}
