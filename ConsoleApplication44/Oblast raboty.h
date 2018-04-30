#pragma once
struct hockeyPlayer
{
	char fullName[10];
	int age;
	int countGame;
	int countGoal;
};
struct goods
{
	char name[5];
	char maker[5];
	int year;
	int quantity;
	int price;
};
struct birthDate
{
	int day;
	int month;
	int year;
};

struct goods3
{
	char name[5];
	int quantity;
	int price;
	char maker[5];
	birthDate crtDate;
};
struct education
{
	char grade[10];
};

struct ocupation
{
	char ocup[30];
};

struct employee
{
	char lastName[10];
	birthDate bdt;
	ocupation ocp;
	int salary;
	education ed[10];
};
struct subject
{
	char nameSub[15];
	int rate;
};

struct student
{
	char name[10];
	char groupe[3];
	subject sub[3];
	birthDate bdt;
};
/* variant 1 */
void createName(char *name, int len);
void generateDate(birthDate *date);
void printInfoHockey(hockeyPlayer *team, int len);
hockeyPlayer *createTeam(int *count);

/* variant 2 */
void printInfoPrd(goods *article, int len);
goods *createArticle1();

/* variant 3 */
//void generateDate(birthDate *date);
void printInfoPrd2(goods3 *article, int len);
goods3 *createArticle2();

/* variant 4 */
void generatePosition(ocupation * pos);
void generateEducation(education *ed);
void printInfoEmpl(employee *file, int len);
employee *createFile();

/* variant 5 */
void generateSubject(subject *sub, int num);
void printInfoStd(student * students, int len);
student * createStudent(int *count);
