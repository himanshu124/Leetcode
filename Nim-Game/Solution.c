#include "stdafx.h"

 bool canWinNim(int n) {
	 if (n == 4)
		 return false;
	 if (n < 4)
		 return true;
	 if (!((n - 1) % 4) || !((n - 2) % 4) || !((n - 3) % 4))
 		 return true;
	 else
		 return false;
}

int main()
{
	int n = 0;
	printf("\nEnter n: ");
	scanf("%d", &n);
	if (canWinNim(n))
		printf("\nYEEE! You can win");
	else
		printf("\nSorry! Better luck next time");
	return 0;
}
