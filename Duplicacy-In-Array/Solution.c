#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

int partition(int nums[],int left,int right){
	int pivot = right;
	int i = left-1;
	int j = left;
	int tmp;
	for (; j <= right - 1; j++){
		if (nums[j] <= nums[pivot]){
			if (nums[j] == nums[pivot])
				return -1;
			i++;
			tmp = nums[j];
			nums[j] = nums[i];
			nums[i] = tmp;
		}
	}
	tmp = nums[i + 1];
	nums[i + 1] = nums[pivot];
	nums[pivot] = tmp;
	return i + 1;
}

bool containsDuplicate(int nums[], int begin, int end){
	if (begin<end){
		int p = partition(nums,begin,end);
		if (p == -1)
			return true;
		else{
			containsDuplicate(nums, begin, p - 1);
			containsDuplicate(nums, p + 1, end);
		}
	}
	return false;
}


int main(){
	int nums[] = { 2, 8, 1,6,5,6};
	if (containsDuplicate(nums,0,(sizeof(nums)/sizeof(int))-1)){
		printf("\nIt has duplicates");
	}
	else{
		printf("\nHas no duplicates");
	}
	return 0;
}
