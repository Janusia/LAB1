// LAB3(2013).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{
	FILE *pF, *pG;
	bool pr;
	char name1[50] = "File1.txt";
	char name2[50] = "File2.txt";
	char s1[256], s2[256];
	fopen_s(&pF, name1, "rt");
	if (pF== NULL)  // Открываем файл для чтения в текстовом режиме
	{
		printf("Error open file");
		_getch(); 
		return 1;
	}
	fopen_s(&pG, name2, "rt");
	if (pG == NULL)  // Открываем файл для чтения в текстовом режиме
	{
		printf("Error open file"); 
		_getch(); 
		return 1;
	}
	while (!feof(pF))
	{
		fgets(s1, 256, pF);
		pr = true;
		while (!feof(pG))
		{
			fgets(s2, 256, pG);
			if (strcmp(s1, s2) == 0) pr = false;
		}
		if (pr) printf("%s : %s\n", name1, s1);
		rewind(pG);
	}
	rewind(pF);
	rewind(pG);
	printf("\n");
	while (!feof(pG))
	{
		fgets(s1, 256, pG);
		pr = true;
		while (!feof(pF))
		{
			fgets(s2, 256, pF);
			if (strcmp(s1, s2) == 0) pr = false;
		}
		if (pr) printf("%s : %s\n", name2, s1);
		rewind(pF);
	}
	fclose(pF);
	fclose(pG);
	_getch();
	printf("\nfor exit press any key ");
	return 0;
}



