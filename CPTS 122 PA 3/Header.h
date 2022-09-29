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
	char Artist[50];
	char Album[50];
	char Song[50];
	char Genre[50];
	Duration Length;
	int times_played;
	int Rating;
}Record;

typedef struct node
{
	Record Data;
	struct node* pPrev;
	struct node* pNext;

}Node;

typedef struct list
{
	Node* pHead;
}List;

void main_menu();
Node* make_node(Record newRecord);
void insert_at_front(List* pHead, Record newRecord);
int parseData(char* lines, Record* music_record, int lineNumber);
void display(const List* pList);
void store(List* pHead, FILE* infile);
void edit(struct List* head);
void rate(List* head);
void play(List* pHead);
void shuffle(List* pHead);
int insert(List** pHead, Record newRecord);
void delete(List** plist);
void exit_function(Node** pHead, FILE* infile);
void sort(List* pHead);
void swap_rating(Node* ptr1, Node* ptr2);
void SortByRank(List* pHead);
void swap_timesPlayed(Node* ptr1, Node* ptr2);
void SortByTimesPlayed(List* pHead);
int sortbyartist(List* plist);
int sortbyalbum(List* pHead);








#endif 
