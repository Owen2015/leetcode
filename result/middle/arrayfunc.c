/**
 * * Return an array of arrays of size *returnSize.
 * * Note: The returned array must be malloced, assume caller calls free().
 * */

int cmpfunc(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
	int front, back;
	int i = 0;
	int **result = 0;
	int s = 0;

	qsort(nums, numsSize, sizeof(int), cmpfunc);

	while (i < numsSize)
	{
		int target = -nums[i];
		if (target < 0)
		{
			break;
		}

		front = i + 1;
		back = numsSize - 1;

		while (front < back)
		{
			int sum = nums[front] + nums[back];
			if (sum < target)
			{
				front++;
			}
			else if (sum > target)
			{
				back--;
			}
			else
			{
				s++;
				result = (int **)realloc(result, sizeof(int *)*s);
				int *temp = (int *)malloc(sizeof(int) * 3);
				temp[0] = nums[i];
				temp[1] = nums[front];
				temp[2] = nums[back];
				result[s-1] = temp;

				while (front < back && nums[front] == temp[1])
				{
					front++;
				}
				while (front < back && nums[back] == temp[2])
				{
					back--;
				}
			}
		}
		while ((i + 1) < numsSize && nums[i] == nums[i + 1])
		{
			i++;
		}
		i++;
	}

	//returnSize = (int *)malloc(sizeof(int));
	*returnSize = s;
	return result;
}




void solution(int** matrix, int i, int j, int *row, int*col, int r, int c);//每个元素的操作
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
	int r = matrixRowSize, c = matrixColSize, i, j;
	int*row = (int*)malloc(sizeof(int)*r), *col = (int*)malloc(sizeof(int)*c);//标记某行、某列是否已经已经有过0，用于减枝所用空间O(m+n)，不减枝则所用额外空间为常数级
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			solution(matrix, i, j, row, col, r, c);//
		}
	}
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			matrix[i][j] = matrix[i][j] == -20 ? 0 : matrix[i][j];//更新标记值-20为0
}
void solution(int** matrix, int i, int j, int *row, int*col, int r, int c) {
	if (matrix[i][j] == 0) {//满足操作条件的元素
		if (col[j] != 20) {
			col[j] = 20;//列标记
			for (int q = 0; q < r; q++)
				matrix[q][j] =  matrix[q][j] == 0 ? matrix[q][j] : -20;//该列上0保持不变，其余改为标记值-20
		}
		if (row[i] != 20) {
			row[i] = 20;//行标记
			for (int q = 0; q<c; q++)
				matrix[i][q] = (matrix[i][q] == -20 || matrix[i][q] == 0) ? matrix[i][q] : -20;
		}
	}
}


bool increasingTriplet(int* nums, int numsSize) {
    int i;
    int a, b = INT_MAX;//a为最小，b为倒数第二小
    
    if(numsSize < 3)
    {
        return false;
    }
    a = nums[0];
    for(i = 0; i < numsSize; i++)
    {
       if(nums[i] <= a)
       {
           a = nums[i];
       }
        else if(nums[i] < b)
        {
            b = nums[i];
        }
        else if(nums[i] > b)
        {
            return true;
        }
    }
    return false;
}
