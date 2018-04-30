#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include <math.h>
#include "Oblast raboty.h"
void createName(char * name, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (i == 0)
			*(name + i) = (char)(65 + rand() % 24);
		else
			*(name + i) = (char)(97 + rand() % 24);
	}
	*(name + len) = '\0';
}

void generateDate(birthDate *date)
{
	date->day = 1 + rand() % 31;
	date->month = 1 + rand() % 12;
	date->year = 1940 + rand() % 60;
}


void printInfoHockey(hockeyPlayer *team, int len)
{
	//printf("--- Èíôîðìàöèÿ î êîìàíäå ---\n");
	for (int i = 0; i < len; i++)
	{
		printf("#%d %s: Фамилия	 %d, Возраст	: %d; Количество игр: %d\n",
			i + 1,
			team[i].fullName,
			team[i].age,
			team[i].countGoal,
			team[i].countGame
		);
	}
}

hockeyPlayer *createTeam(int *count)
{
	hockeyPlayer *team = (hockeyPlayer*)calloc(*count, sizeof(hockeyPlayer));

	if (team != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			createName(team[i].fullName, 10);
			team[i].age = 20 + rand() % 8;
			team[i].countGame = 1 + rand() % 20;
			team[i].countGoal = 1 + rand() % 100;
		}
		printInfoHockey(team, *count);
	}
	else
	{
		printf("Ничего!");
		exit(1);
	}
	return team;
}


void printInfoPrd(goods *article, int len)
{
	//printf("--- Задача о товарах ---\n");
	for (int i = 0; i < len; i++)
	{
		printf("#%d Наименование %s; Производитель %s; Год_выпуска: %d;Количество: %d;Цена: %d\n",
			i + 1,
			article[i].name,	
			article[i].maker,	
			article[i].year,	
			article[i].quantity,
			article[i].price);	
	}
}

goods *createArticle1()
{
	goods *article = (goods*)calloc(10, sizeof(goods));
	if (article != NULL)
	{
		for (int i = 0; i < 10; i++)
		{
			createName(article[i].name, 5);
			createName(article[i].maker, 5);
			article[i].year = 2014 + rand() % 5;
			article[i].quantity = 1 + rand() % 1000;
			article[i].price = 100 + rand() % 5000;
		}
		printInfoPrd(article, 10);
	}
	else
	{
		printf("Ничего!");
		exit(1);
	}
	return article;
}


void printInfoPrd2(goods3 *article, int len)
{
	//printf("--- Èíôîðìàöèÿ î òîâàðå ---\n");
	for (int i = 0; i < len; i++)
	{
		printf("#%d Наименование: %s;Количество: %d;Цена: %d;Производитель: %s;Дата_выпуска: %d.%d.%d\n",
			i + 1,
			article[i].name,
			article[i].quantity,
			article[i].price,
			article[i].maker,
			article[i].crtDate.day,
			article[i].crtDate.month,
			article[i].crtDate.year);
	}
}

goods3 *createArticle2()
{
	goods3 *article = (goods3*)calloc(10, sizeof(goods3));
	if (article != NULL)
	{
		for (int i = 0; i < 10; i++)
		{
			createName(article[i].name, 5);
			article[i].quantity = 100 + rand() % 1000;
			article[i].price = 1000 + rand() % 5000;
			createName(article[i].maker, 5);
			generateDate(&article[i].crtDate);
			/*generateDate(&article[i].crtDate.month);
			generateDate(&article[i].crtDate.year);*/
		}
		printInfoPrd2(article, 10);

	}
	else
	{
		printf("Îøèáêà!");
		exit(1);
	}
	return article;
}


void generatePosition(ocupation * pos)
{
	int rnd = 1 + rand() % 20;
	char srnd[3];
	_itoa(rnd, srnd, 10);
	//strcat(pos, "Äîëæíîñòü #");
	strcpy(pos->ocup, "Äîëæíîñòü #");
	strcat(pos->ocup, srnd);
}

void generateEducation(education *ed)
{
	int rnd = 1 + rand() % 3;
	switch (rnd)
	{
	case 1:
		strcpy(ed->grade, "Íà÷àëüíîå");
		break;

	case 2:
		strcpy(ed->grade, "Ñðåäíåå");
		break;

	case 3:
		strcpy(ed->grade, "Âûñøåå");
		break;
	}
}

void printInfoEmpl(employee *file, int len)
{
	//printf(" --- Информация по работнику --- \n");
	for (int i = 0; i < len; i++)
	{
		printf("#%dФамилия: %s;День рождения: %d.%d.%d; Должность: %s;Зарплата: %d;Образование: %s\n",
			i + 1,
			file[i].lastName,
			file[i].bdt.day,
			file[i].bdt.month,
			file[i].bdt.year,
			file[i].ocp.ocup,
			file[i].salary,
			file[i].ed->grade);
	}
}

employee *createFile()
{
	employee *file = (employee*)calloc(10, sizeof(employee));
	if (file != NULL)
	{
		for (int i = 0; i < 10; i++)
		{
			createName(file[i].lastName, 10);
			generateDate(&file[i].bdt);
			generatePosition(&file[i].ocp);
			file[i].salary = 100000 + rand() % 500000;
			generateEducation(file[i].ed);
		}
		printInfoEmpl(file, 10);
	}
	else
	{
		printf("Ничего!");
		exit(1);
	}
	return file;
}

void generateSubject(subject *sub, int num)
{
	sub->rate = 75 + rand() % 25;

	switch (num)
	{
	case 0:
		strcpy(sub->nameSub, "Ôèçèêà ");
		break;

	case 1:
		strcpy(sub->nameSub, "Ìàòåìàòèêà ");
		break;

	case 2:
		strcpy(sub->nameSub, "Èíôîðìàòèêà ");
		break;
	}
}

void printInfoStd(student * students, int len)
{
	//printf(" ---  --- Информация по студенту ------ \n");
	for (int i = 0; i < len; i++)
	{
		printf("#%d.Фамилия	: %s,Группа	%s, Год рождения: %d.%d.%d\n",
			i + 1,
			students[i].name,
			students[i].groupe,
			students[i].bdt.day,
			students[i].bdt.month,
			students[i].bdt.year);

		for (int j = 0; j < 3; j++)
		{
			printf("-->%s\t%d\n",
				students[i].sub[j].nameSub,
				students[i].sub[j].rate);
		}
		printf("\n");
	}
}

student * createStudent(int *count)
{
	student *st = (student*)malloc(*count * sizeof(student));
	if (st != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			createName(st[i].name, 10);
			createName(st[i].groupe, 3);
			generateDate(&st[i].bdt);
			for (int j = 0; j < 3; j++)
			{
				generateSubject(&st[i].sub[j], j);
			}

		}
		printInfoStd(st, *count);
	}
	else
	{
		printf("Ничего!");
		exit(1);
	}
	return st;
}
