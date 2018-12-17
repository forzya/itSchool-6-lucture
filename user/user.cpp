#include <stdio.h>
#include <cstdlib>
#include <string.h>

typedef struct User
{
	int id;
	char nickname[51];
	int karma;
} User;


int compareNickname(const void * pa, const void * pb)   
{
	return strcmp(((User*)pa)->nickname, ((User*)pb)->nickname);
}

int compareKarma(const void * pa, const void * pb)
{
	return ((User*)pa)->karma - ((User*)pb)->karma;
}

void printStruct(User *mass)
{
	for (int i = 0; i < 4; i++)
		printf("id %d | nickname %s | karma %d \n", mass[i].id, mass[i].nickname, mass[i].karma);
}


int main()
{
	User mass[] = { { 23, "nicky", 2 },{ 18, "brain", 0 },{ 20, "aleks", 3 }, { 30, "gregg", 7 } };

	qsort(mass, 3, sizeof(User), compareKarma);
	printf("sort Karma\n");
	printStruct(mass);
				

	qsort(mass, 4, sizeof(User), compareNickname);
	printf("sort Nickname\n");
	printStruct(mass);
	
	return 0;
}
