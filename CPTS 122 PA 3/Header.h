#pragma once

#ifndef Header_h
#define Header_h

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<Windows.h>
//Got windows.h and Sleep function from Stack overflow



typedef struct duration
{
	unsigned int minutes;
	unsigned int seconds;
}Duration;

typedef struct record
{
	char Artist[25];
	char Album[25];
	char Song[25];
	char Genre[25];
	Duration Length;
	int times_played;
	int Rating;
	struct record* pPrev;
	struct record* pNext;

}Record;

typedef struct node
{
	Record Data;
	struct record* pPrev;
	struct record* pNext;

}Node;

void main_menu();
struct Node* make_node(FILE* infile);
void insert_at_front(struct Node* pHead, FILE* infile);
void load(FILE* infile);
void display(struct record* list);
void store(struct node** pHead, FILE* infile);
void edit(struct record* head);
void rate(struct record* head);
void play(struct record* pHead);
void shuffle(struct record* pHead);
int insert(Record** pHead, FILE* infile);
void delete(Record** pHead);
void exit_function(struct node* pHead, FILE* infile);









#endif 
