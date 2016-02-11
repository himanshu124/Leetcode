#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

int titleToNumber(char *str){
	int n = strlen(str);
	int i = 0,j=0;
	int num = 0;
	for (i=n-1; i >=0; i--){
		num = num + ((int(*(str + i)) - 64)*(pow(26.0,j)));
		j++;
	}
	return num;
}

int main(){
	char s[10];
	printf("\nEnter column title");
	scanf_s("%s", s);
	int num = titleToNumber(s);
	printf("\n%s\n", num);
	return 0;
}
