#include <stdio.h>


typedef void(*funk)(int, char);

void cross(int, char);
void filledDiamond(int, char);
void hollowDiamond(int, char);
void figure(int, funk*);

int main()
{
	funk mass[3] = { cross, filledDiamond, hollowDiamond };

	int key;
	bool stop = true;

	while (stop)
	{
		printf("1-cross \n");
		printf("2-hollow diamond \n");
		printf("3-filled diamond \n");
		printf("4-exit \n");

		scanf_s("%d", &key);
		switch (key)
		{
		case 1:
			figure(key, mass);
			break;
		case 2:
			figure(key, mass);
			break;
		case 3:
			figure(key, mass);
			break;
		case 4:
			stop = false;
			break;

		default:
			printf("Error! \n");
			break;
		}
	}

	return 0;
}

void figure(int key, funk *mass)
{
	int size;
	char ch;
	printf("size of a figure ");
	scanf_s(" %d", &size);
	printf("symbol ");
	scanf_s(" %c", &ch);
	mass[key - 1](size, ch);
}


void hollowDiamond(int n, char ch)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == n / 2 + i || ((n % 2 == 0) ? j == n / 2 - i - 1 : j == n / 2 - i))
				printf("%c", ch);
			else if (j == n / 2 + n - i - 1 || j == i - n / 2)
				printf("%c", ch);
			else printf(" ");
		}
		printf("\n");
	}
}

void cross(int n, char ch)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				printf("%c", ch);
			else if ((i + j == n - 1) && (i != j))
				printf("%c", ch);
			else printf(" ");
		}
		printf("\n");
	}
}

void filledDiamond(int n, char ch)
{
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j <= n / 2 + i && ((n % 2 == 0) ? j >= n / 2 - i - 1 : j >= n / 2 - i))
				printf("%c", ch);
			else printf(" ");
		}
		printf("\n");
	}

	for (int i = n / 2; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j <= n / 2 + n - i - 1 && j >= i - n / 2)
				printf("%c", ch);
			else printf(" ");
		}
		printf("\n");
	}
}