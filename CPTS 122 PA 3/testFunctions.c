#include "test.h"

void testinsert(void)
{
    List** pList = NULL;
    Record Record = { "Perry, Katy","Witness","Chained to the Rhythm","pop","4:46",-1,6 };
    insert(&pList, Record);

    if (pList != NULL)
    {
        printf("List has been update");
        if ((*pList)->pHead->Data.Artist == "Perry, Katy")
        {
            printf("Artist Added");
        }
        if ((*pList)->pHead->Data.Album == "Witness")
        {
            printf("Album Added");
        }
        if ((*pList)->pHead->Data.Song == "Chained to the Rhythm")
        {
            printf("Song Added");
        }
        if ((*pList)->pHead->Data.Genre == "pop")
        {
            printf("Genre Added");
        }
        if ((*pList)->pHead->Data.Duration == "4:46")
        {
            printf("Duration Added");
        }
        if ((*pList)->pHead->Data.times_played != -1)
        {
            printf("Successfully did not allow you to add -1");
        }
        if ((*pList)->pHead->Data.Rating != 6)
        {
            printf("Successfully did not allow to to rate it as 6");
        }
    }
}

void testdelete(void)
{
    List** pList = NULL;
    Record Record = { "Perry, Katy","Witness","Chained to the Rhythm","pop","4:46",3,5 };
    delete(&pList);

    if (pList == NULL)
    {
        printf("Deleted list from function");
    }

}