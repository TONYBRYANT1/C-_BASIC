#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 20
#define MAX_TELE 20
#define MAX_ADDR 20
//枚举可以提高代码的可读性:
enum Option
{
	EXIT,
	ADD,
	DELETE,
	MODIFY,
	SEARCH,
	SHOW,
	SORT
};
struct PeoInFo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
struct Contact
{
	struct PeoInFo data[MAX];
	int size;
};
void InitContact(struct Contact* p);
void AddContact(struct Contact* p);
void ShowContact(const struct Contact* p);
void DeleteContact(struct Contact* p);
void SesrchContact(const struct Contact* p);
void ModifyContact(struct Contact* p);
void SortContact(struct Contact* p);