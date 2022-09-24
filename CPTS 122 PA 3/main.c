#include "Header.h"

int main(void)
{
    
    Record* pHead = NULL;
    Record* pCur = pHead;
    FILE* infile = NULL;
    infile = fopen("list.csv", "r+");

    if (infile != NULL)
    {
        
        main_menu();

        int choice = 0;
        do {
            printf("Enter your choice of action: ");
            scanf(" %d", &choice);
        } while ((choice < 1) && (choice > 10));

        switch (choice)
        {
        case 1:
            load(infile);
            system("clear");
            break;

        case 2:
            store(pHead, infile);
            system("clear");
            break;

        case 3:
            display(pHead);
            system("clear");
            break;

        case 4:


            system("clear");
            break;

        case 5:


            system("clear");
            break;

        case 6:
            edit(pHead);
            system("clear");
            break;

        case 7:


            system("clear");
            break;

        case 8:
            rate(pHead);
            system("clear");
            break;

        case 9:
            play(pHead);
            system("clear");
            break;

        case 10:
            shuffle(pHead);
            system("clear");
            break;

        case 11:
            
            
            break;
        }
        
    }
    else
    {
        printf("File can not be opened");
    }




    
    return 0;
}