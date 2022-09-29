#include "Header.h"

/*
        Programmer - Caden Guffin
        Class - CPTS 122
        Assignment - Programing Assignment 3
        Due Date - 9/28/2022

        Recived Help From Matt Wolfe, on function Parse data

*/




int main(void)
{
   
    FILE* infile = fopen("list.csv","r+");

    char lines[200][50] = { "" };
    int temp = 0;
    int lines_number = 0;
    Record newRecord = { "",-1 };
    List pList = { NULL };
    List** list = &pList;
   
    Node *pNode = { NULL };
    int success = 0;

    if (infile != NULL)
    {
        int choice = 0;
        do {
            
            main_menu();
            printf("Enter your choice of action: ");
            scanf(" %d", &choice);
            
            switch (choice)
            {
            case 1:
                


                while (fgets(lines[temp],200, infile) != NULL)
                {

                    parseData(lines, &newRecord, temp);
                    insert_at_front(&pList, newRecord);

                   
                   
                }
                 
               
                break;

            case 2:
                store(&pList, infile);
                
                break;

            case 3:
                
                display(&pList);
               
                break;

            case 4:
                insert(list, newRecord);

                
                break;

            case 5:
                delete(&pList);

                
                break;

            case 6:
                edit(&pList);
                
                break;

            case 7:
                
                sort(&pList);
                
                break;

            case 8:
                rate(&pList);
               
                break;

            case 9:
                play(&pList);
                
                break;

            case 10:
                
                shuffle(&pList);
                break;

            case 11:
                store(&pList, infile);
                exit(0);
                break;
            }
        } while (choice != 11);
    }
    else
    {
        printf("File can not be opened");
    }




    
    return 0;
}