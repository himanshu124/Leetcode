#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

void findMajority(int nums[],int size){
	int candidate;
	int count = 0;
	int i;
	for (i = 0; i<size; i++){
		if (count == 0){
			candidate = nums[i];
			count++;
		}
		else{
			if (candidate == nums[i])
				count++;
			else
				count--;
		}
	}
	if (count == 0){
		printf("\n No Majority Element");
		return;
	}
	count = 0;
	for (i = 0; i <size; i++){
		if (candidate == nums[i])
			count++;
	}
	if (count >(size / 2))
		printf("\nMajority element is%d", candidate);
	return;
}

int main(){
	int nums[] = { 1, 2, 6, 2, 2, 6, 2, 2, 8, 2 };
	findMajority(nums, (sizeof(nums) / sizeof(int)));
}
