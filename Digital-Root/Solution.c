int main()
{
	int n = 0;
	printf("\nEnter n: ");
	scanf("%d", &n);
	printf("\nDigital Root: %d", (1 + ((n - 1) % 9)));
	return 0;
}
