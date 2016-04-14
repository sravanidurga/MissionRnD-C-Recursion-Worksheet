/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
int *spiral_1(int rows, int columns, int **input_array, int *arr,int T,int B,int L, int R,int dir,int ind)
{
	int i;
	if (T <= B && L <= R)
	{
		if (dir == 0)
		{
			for (i = L; i <= R; i++)
				*(arr + (ind++)) = *(*(input_array + T) + i);
			T++;
			dir = 1;
		}
		else if (dir == 1)
		{
			for (i = T; i <= B; i++)
				*(arr + (ind++)) = *(*(input_array + i) + R);
			R--;
			dir = 2;
		}
		else if (dir == 2)
		{
			for (i = R; i >= L; i--)
				*(arr + (ind++)) = *(*(input_array + B) + i);
			B--;
			dir = 3;

		}
		else if (dir == 3)
		{
			for (i = B; i >= T; i--)
				*(arr + (ind++)) = *(*(input_array + i) + L);
			L++;
			dir = 0;
		}
		arr=spiral_1(rows, columns, input_array, arr, T, B, L, R, dir, ind);;

	}
	return arr;
}
int *spiral(int rows, int columns, int **input_array)
{
	
	int *arr;
	int T = 0, B = rows - 1, L = 0, R = columns - 1,dir=0,ind=0;
	if (input_array == NULL || rows<=0 || columns <=0)
		return NULL;
	arr  = (int *)malloc(sizeof(int)*(rows*columns));
	return spiral_1(rows, columns, input_array, arr, T, B, L, R, dir, ind);

}
