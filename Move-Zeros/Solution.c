#include "stdafx.h"
#include "stdlib.h"

int main()
{
	int nums[] = { 0, 1, 0, 3,0,5,0,4,8,0,9, 12,0 };
	int i = 0, j = 0;
	for (; i < (sizeof(nums) / sizeof(nums[0])); i++){
		if (nums[i] == 0){
			j = i;
			while (nums[j] == 0)
				j++;
			if (j < (sizeof(nums) / sizeof(nums[0]))){
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
	system("cls");
	for (i = 0; i < (sizeof(nums) / sizeof(nums[0])); i++)
		printf("%d\t", nums[i]);
	return 0;
}
