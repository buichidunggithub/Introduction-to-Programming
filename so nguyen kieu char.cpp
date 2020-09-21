//Nhap so nguyen kieu char
#include<stdio.h>			
#include<math.h>
#include<stdlib.h>

int main()
{
	int input;
	printf("Set input: ");
	scanf("%d", &input);
	int n = log2(input);
	char* p = (char*)calloc(n + 1, sizeof(char));
	int i = 0;
	while (input != 0)
	{
		if (input % 2 == 0)
		{
			p[i] = '0';
		}
		else
		{
			p[i] = '1';
		}
		i++;
		input /= 2;
	}
	i--;
	while (i >= 0)
	{
		printf("%c", p[i]);
		i--;
	}
	printf("\n");
	system("pause");
	return 0;
}
