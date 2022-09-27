#include "Header.h"


void main_menu()
{
   
    printf("Main Menu\n");
    printf("(1) Load songs\n");
    printf("(2) Store songs\n");
    printf("(3) Display songs\n");
    printf("(4) Insert songs\n");
    printf("(5) Delete songs\n");
    printf("(6) Edit songs\n");
    printf("(7) Sort songs\n");
    printf("(8) Rate songs\n");
    printf("(9) Play songs\n");
    printf("(10) Shuffle\n");
    printf("(11) Exit\n");
    
}

Node* make_node(Record newRecord)
{
    
    Node *pMem = malloc(sizeof(Node));
   
    if (pMem != NULL)
    {

        strcpy((*pMem).Data.Artist, newRecord.Artist);
        strcpy((*pMem).Data.Album, newRecord.Album);
        strcpy((*pMem).Data.Song, newRecord.Song);
        strcpy((*pMem).Data.Genre, newRecord.Genre);
        pMem->Data.Length.minutes = newRecord.Length.minutes;
        pMem->Data.Length.seconds = newRecord.Length.seconds;
        pMem->Data.times_played = newRecord.times_played;
        pMem->Data.Rating = newRecord.Rating;
        pMem->pPrev = NULL;
        pMem->pNext = NULL;
    }

    return pMem;
}
void insert_at_front(List *pHead, Record newRecord)
{
    Node* pMem = make_node(newRecord);
    int success = 0;
    if (pMem != NULL)
    {
        success = 1;

        pMem->pNext = pHead->pHead;
        pMem->pPrev = pHead->pHead;
        pHead->pHead = pMem;
    }

    
}



//Worked on Function with Matt Wolfe

int parseData(char* lines, Record *music_record, int lineNumber)
{
    
    if (lines[0] =='\"')
    {
        strcpy(music_record[lineNumber].Artist, strtok(lines, ","));
        strcat(music_record[lineNumber].Artist, strtok(NULL, ","));

    }
    else
    {
        strcpy(music_record[lineNumber].Artist, strtok(lines, ","));
    }
    strcpy(music_record[lineNumber].Album, strtok(NULL, ","));
    strcpy(music_record[lineNumber].Song, strtok(NULL, ","));
    strcpy(music_record[lineNumber].Genre, strtok(NULL, ","));
    music_record[lineNumber].Length.minutes = atoi(strtok(NULL, ":"));
    music_record[lineNumber].Length.seconds = atoi(strtok(NULL, ","));
    music_record[lineNumber].times_played = atoi(strtok(NULL, ","));
    music_record[lineNumber].Rating = atoi(strtok(NULL, "\n"));

   
}
void display(List* pList)
{
    int i = 0;
    char choice[50];
    
    do
    {
        printf("Enter 1 to see all songs\n");
        printf("Enter 2 to see songs by one artist");
        scanf("%d", &i);

    } while ((i != 1) && (i != 2));
    system("cls");
 
    Node* current_song = pList->pHead;
    if (i == 1)
    {
       
        while (current_song != NULL)
        {
            printf("Song: %s\n", current_song->Data.Song);
            printf("Artist: %s\n", current_song->Data.Artist);
            printf("Album: %s\n", current_song->Data.Album);
            printf("Genre: %s\n", current_song->Data.Genre);
            printf("TIME: %d:%d\n", current_song->Data.Length.minutes, current_song->Data.Length.seconds);
            printf("Times Played: %d\n", current_song->Data.times_played);
            printf("RATING: %d\n\n", current_song->Data.Rating);

            current_song = current_song->pNext;

        }
      
    }
    else if(i == 2)
    {
        printf("Please enter the Artist you want to see");
        getchar();
        fgets(choice, 50, stdin);
        choice[strlen(choice) - 1] = '\0';
        if (strcmp(choice, current_song->Data.Artist) == 0)
        {

           
                printf("Song: %s\n", current_song->Data.Song);
                printf("Artist: %s\n", current_song->Data.Artist);
                printf("Album: %s\n", current_song->Data.Album);
                printf("Genre: %s\n", current_song->Data.Genre);
                printf("TIME: %d:%d\n", current_song->Data.Length.minutes, current_song->Data.Length.seconds);
                printf("Times Played: %d\n", current_song->Data.times_played);
                printf("RATING: %d\n\n", current_song->Data.Rating);



        }
    }
}

void store(struct List** pHead, FILE *infile)
{
    struct node* current = pHead;

    while (current->pNext != NULL)
    {
        current = current->pNext;
    }

    while (current->pPrev != NULL)
    {
        fprintf(infile, "%s,%s,%s,%s,%d:%d,%d,%d", current->Data.Artist, current->Data.Album, current->Data.Song, current->Data.Genre, current->Data.Length.minutes, current->Data.Length.seconds, current->Data.times_played, current->Data.Rating);
        printf("%s,%s,%s,%s,%d:%d,%d,%d", current->Data.Artist, current->Data.Album, current->Data.Song, current->Data.Genre, current->Data.Length.minutes, current->Data.Length.seconds, current->Data.times_played, current->Data.Rating);
        current = current->pPrev;
    }
}

void edit(struct List* head)
{
    struct node* current = head;
    
    char edit[25];
    char search[25];
    int temp = 0;
    int choice = 0;
    printf("Enter the artist to search: ");
    
    getchar();
    fgets(search, 25, stdin);
    search[strlen(search) - 1] = '\0';
    // Allows input of Artist wanted to edit
    
    while (current != NULL & choice == 0)
    {

        if (strcmp(search, current->Data.Artist) == 0)
        {

            printf("Which field do you want to edit?\n");
            printf("1) Artist\n2) Album\n3) Song\n4) Genre\n5) Length\n6) Number of plays\n");
            //Prints out choice for which field they would like to edit
            scanf(" %d", &choice);

            switch (choice)
            {
            case 1:
                //Allows edit of Artist name and copys edit into the struct
                printf("Enter the new artist: ");
                while ((getchar()) != "\n");
                fgets(edit, 50, stdin);
                edit[strlen(edit) - 1] = NULL;
                strcpy(current->Data.Artist, edit);

                printf("The new artist is %s\n", current->Data.Artist);
                break;
            case 2:
                //Allows edit of Album title and copys edit into the Struct
                printf("Enter the new album: ");
                while ((getchar()) != "\n");
                fgets(edit, 50, stdin);
                edit[strlen(edit) - 1] = NULL;
                strcpy(current->Data.Album, edit);
                printf("The new album is %s\n", current->Data.Album);
                break;
            case 3:
                //Allows edit of song title and copys edit into struct
                printf("Enter the new Song title: ");
                while ((getchar()) != "\n");
                fgets(edit, 50, stdin);
                edit[strlen(edit) - 1] = NULL;
                strcpy(current->Data.Song, edit);
               
                printf("The new Song is %s\n", current->Data.Song);
                break;
            case 4:
                //Allows edit of genre and copys edit into struct
                printf("Enter the new genre: ");
                while ((getchar()) != "\n");
                fgets(edit, 50, stdin);
                edit[strlen(edit) - 1] = NULL;
                strcpy(current->Data.Genre, edit);
                printf("The new genre is %s\n", current->Data.Genre);
                break;
            case 5:
                //Allows edit of song time in minutes and seconds and copys edit into struct
                printf("Enter the new number of minutes: ");
                scanf("%d", &temp);
                current->Data.Length.minutes = temp;
                printf("Enter the new number of seconds: ");
                scanf("%d", &temp);
                current->Data.Length.seconds = temp;
                break;
            case 6:
                //Allows user to input amount of times song has been played
                printf("Enter the new number of plays: ");
                scanf("%d", &temp);
                current->Data.times_played = temp;
                break;

            }

        }
        current = current->pNext;
        choice = 0;
    }
}

void rate(struct List* head)
{
    struct node* cur = head;
   
    char search_artist[50];

    printf("Enter Artist to Rate");
    getchar();
        fgets(search_artist, 50, stdin);
      
   
    while ((cur != NULL))
    {
        if (strcmp(search_artist, cur->Data.Artist) == 0)
        {
            int new_rating = 0;
              do 
              {   
                    printf("Enter Your rating for the Song between 1 and 5:");
                    scanf("%d", &new_rating);
              } while ((new_rating >= 1) & (new_rating <= 5));

                cur->Data.Rating = new_rating;
                printf("The New rating is now: %d", cur->Data.Rating);
                return;
            
        }
        cur = cur->pNext;
       
    }

}


void play( List *pHead)
{
    struct node* pCur = pHead;
    char choice[50];
    int play = 0;

    //Gets song choice
    printf("Enter a song to start with: ");
    getchar();
    fgets(choice, 50, stdin);
    choice[strlen(choice) - 1] = '\0';


    while (pCur != NULL)
    {

        if (strcmp(choice, pCur->Data.Song) == 0)
        {
           
            
                printf("Artist %s", pCur->Data.Artist);
                printf("Album %s", pCur->Data.Album);
                printf("Song %s", pCur->Data.Song);
                printf("Genre %s", pCur->Data.Genre);
                printf("Duration %d:%d", pCur->Data.Length.minutes, pCur->Data.Length.seconds);
                printf("Times Player %d", pCur->Data.times_played);
                printf("Rating %d", pCur->Data.Rating);
                
                //Sleep function will run for 5 seconds
                //Deleted Count function as i relised it was not needed
                Sleep(5000);
                
           
            system("cls");
        }
        pCur = pCur->pNext;
        
    }

}



void shuffle(List* pHead)
{
    int songs = 0;
    Node*pCur = pHead;
    while (pCur != NULL)
    {
        pCur = pCur->pNext;
        songs++;
    }

    pCur = pHead;
    int *songsPlayed = (int*)malloc(sizeof(int));
    int randomSong,songfound =0;

    randomSong = rand() % songs + 1;

    if (songsPlayed[randomSong] != 0)
    {
        do {
            randomSong = rand() % songs + 1;
            if (songsPlayed[randomSong] == 0)
            {
                songfound = 1;
            }
        } while (songfound != 1);
    }

    int listloop = 1;

    if (listloop != randomSong && pCur->pNext != NULL)
    {
        pCur = pCur->pNext;
        listloop++;
    }

        printf("Artist %s", pCur->Data.Artist);
        printf("Album %s", pCur->Data.Album);
        printf("Song %s", pCur->Data.Song);
        printf("Genre %s", pCur->Data.Genre);
        printf("Duration %d:%d", pCur->Data.Length.minutes, pCur->Data.Length.seconds);
        printf("Times Player %d", pCur->Data.times_played);
        printf("Rating %d", pCur->Data.Rating);

        //Sleep function will run for 5 seconds then go into the next count
        Sleep(5000);
        

    system("cls");


}




int insert(List** pHead, Record newRecord)
{
    Node* newSong = malloc(sizeof(Node));

   

    char temp[50];
    printf("Please enter the new artist");
    while ((getchar()) != "\n");
    fgets(temp, 50, stdin);
    temp[strlen(temp) - 1] = NULL;
    strcpy(newSong->Data.Artist, temp);


    printf("Please enter the New Album");
    while ((getchar()) != "\n");
    fgets(temp, 50, stdin);
    temp[strlen(temp) - 1] = NULL;
    strcpy(newSong->Data.Album, temp);


    printf("Please enter the New Song Title");
    while ((getchar()) != "\n");
    fgets(temp, 50, stdin);
    temp[strlen(temp) - 1] = NULL;
    strcpy(newSong->Data.Song, temp);


    printf("Please enter the New Genre");
    while ((getchar()) != "\n");
    fgets(temp, 50, stdin);
    temp[strlen(temp) - 1] = NULL;
    strcpy(newSong->Data.Genre, temp);


    int *min = 0, *sec = 0;
    printf("Please Enter the Amount of Minutes");
    scanf("%d", min);
    newSong->Data.Length.minutes = min;
    printf("Please Enter the Amount of Seconds");
    scanf("%d", min);
    newSong->Data.Length.seconds = sec;

    int timesPlayed = 0;
    printf("Please enter how many times you have played the song");
    scanf("%d", timesPlayed);
    newSong->Data.times_played = timesPlayed;

    int rating = 0;
    printf("Please enter your intial rating");
    scanf("%d", rating);
    newSong->Data.Rating = rating;

    insert_at_front(newSong,newRecord);

    return 0;
}

void delete(List** plist)
{
    Node** pHead = plist;
    char temp[50];

    printf("Enter Song to Delete");
    while ((getchar()) != "\n");
    fgets(temp, 50, stdin);
    temp[strlen(temp) - 1] = NULL;

    if (strcmp(temp, (*pHead)->Data.Song) == 0)
    {
       Record *temp = pHead;
       pHead = (*pHead)->pNext;
       free(temp);

    }
    else
    {
        printf("Song not Found");
    }


}

void exit_function(struct List** pHead, FILE* infile)
{
    struct node* current = pHead;

    while (current->pNext != NULL)
    {
        current = current->pNext;
    }

    while (current->pNext != NULL)
    {
        fprintf(infile, "%s,%s,%s,%s,%d:%d,%d,%d", current->Data.Artist, current->Data.Album, current->Data.Song, current->Data.Genre, current->Data.Length.minutes, current->Data.Length.seconds, current->Data.times_played, current->Data.Rating);

        current = current->pPrev;
    }
}

void sort(List* pHead)
{
    
    int choice = 0;
    printf("Please select which one you would like to Sort by");
    printf("1) Artist\n2)Album\n3)Rating\n4)Times Played\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        //Artist sort
        break;
    case 2:
        //Album Sort
        break;
    case 3:
        //Rating Sort
        SortByRank(pHead);

        break;
    case 4:
        // Times played sort
        SortByTimesPlayed(pHead);
        break;

    }
}
 

/*Code is from https ://www.geeksforgeeks.org/c-program-bubble-sort-linked-list/ */
void swap_rating(Node* ptr1, Node* ptr2)
{
    int temp = ptr1->Data.Rating;
    ptr1->Data.Rating = ptr2->Data.Rating;
    ptr2->Data.Rating = temp;
}

/*Code is from https ://www.geeksforgeeks.org/c-program-bubble-sort-linked-list/ */
void SortByRank(List* pHead)
{
    int swapped, i;
    Node* ptr1;
    Node *lptr = NULL;

    if (pHead == NULL)
    {
        return;
    }

    do
    {
        swapped = 0;
        ptr1 = pHead;

        while (ptr1->pNext != lptr)
        {
            if (ptr1->Data.Rating > ptr1->pNext->Rating)
            {
                swap_rating(ptr1, ptr1->pNext);
                swapped = 1;
            }
            ptr1 = ptr1->pNext;
        }
        lptr = ptr1;
    } while (swapped);

}

void swap_timesPlayed(Node* ptr1, Node* ptr2)
{
    int temp = ptr1->Data.times_played;
    ptr1->Data.times_played = ptr2->Data.times_played;
    ptr2->Data.times_played = temp;
}

void SortByTimesPlayed(List* pHead)
{
    int swapped, i;
    Node* ptr1;
    Node* lptr = NULL;

    if (pHead == NULL)
    {
        return;
    }

    do
    {
        swapped = 0;
        ptr1 = pHead;

        while (ptr1->pNext != lptr)
        {
            if (ptr1->Data.times_played > ptr1->pNext->times_played)
            {
                swap_timesPlayed(ptr1, ptr1->pNext);
                swapped = 1;
            }
            ptr1 = ptr1->pNext;
        }
        lptr = ptr1;
    } while (swapped);

}

