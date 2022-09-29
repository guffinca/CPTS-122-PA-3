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
    if (pHead->pHead == NULL)
    {
        pHead->pHead = pMem;
    }
    else
    {
        success = 1;

        pMem->pNext = pHead->pHead;
        pMem->pPrev = pHead->pHead;
        pHead->pHead = pMem;
    }

    
}



//Recieved help on the parse Data function from Matt Wolfe

int parseData(char* line, Record *music_record, int Number)
{
    //Checks and sees if artist has "", checks to see if its a full name
    if (line[0] =='\"')
    {
        strcpy(music_record[Number].Artist, strtok(line, ","));
        strcat(music_record[Number].Artist, strtok(NULL, ","));

    }
    else
    {
        strcpy(music_record[Number].Artist, strtok(line, ","));
    }
    //copys record into token
    strcpy(music_record[Number].Album, strtok(NULL, ","));
    strcpy(music_record[Number].Song, strtok(NULL, ","));
    strcpy(music_record[Number].Genre, strtok(NULL, ","));
    music_record[Number].Length.minutes = atoi(strtok(NULL, ":"));
    music_record[Number].Length.seconds = atoi(strtok(NULL, ","));
    music_record[Number].times_played = atoi(strtok(NULL, ","));
    music_record[Number].Rating = atoi(strtok(NULL, "\n"));

   
}
void display(const List* pList)
{
    int i = 0;
    char choice[50];
    //allows input for see all songs or by just one artist
    do
    {
        printf("Enter 1 to see all songs\n");
        printf("Enter 2 to see songs by one artist\n");
        scanf("%d", &i);

    } while ((i != 1) && (i != 2));
    system("cls");
 
    Node* current_song = pList->pHead; //Goes to top of list
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

            current_song = current_song->pNext; //Goes on to next record and prints it to screen

        }
      
    }
    else if(i == 2)
    {
        
        printf("Please enter the Artist you want to see: ");
        getchar();
        fgets(choice, 50, stdin);
        choice[strlen(choice) - 1] = '\n';
        choice[strlen(choice) - 1] = '\0';
        
       


            while (strcmp(choice, current_song->Data.Artist) != 0) //Runs loop until it finds the artist that is being looked for
            {
                current_song = current_song->pNext;
            }

            if (strcmp(choice, current_song->Data.Artist) == 0) //sees artist name within record and prints it to the sc
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

void store( List* pHead, FILE *infile)
{
     Node* current =pHead->pHead;


    while (current != NULL)
    {
        
        fprintf(infile, "%s,%s,%s,%s,%d:%d,%d,%d\n", current->Data.Artist, current->Data.Album, current->Data.Song, current->Data.Genre, current->Data.Length.minutes, current->Data.Length.seconds, current->Data.times_played, current->Data.Rating);
        printf("%s,%s,%s,%s,%d:%d,%d,%d\n", current->Data.Artist, current->Data.Album, current->Data.Song, current->Data.Genre, current->Data.Length.minutes, current->Data.Length.seconds, current->Data.times_played, current->Data.Rating);
        current = current->pNext;
    }
}

void edit( List* head)
{
    struct node* current = head ->pHead;
    
    char edit[50];
    char search[50];
    int temp = 0;
    int choice = 0;
    printf("Enter the artist to search: ");
    
    getchar();
    fgets(search, 50, stdin);
    search[strlen(search) - 1] = '\0';
    // Allows input of Artist wanted to edit
    
    while (current != NULL & choice == 0)
    {
        while (strcmp(search, current->Data.Artist) != 0)
        {
            current = current->pNext;
        }
        if (strcmp(search, current->Data.Artist) == 0)
        {

            printf("Which field do you want to edit?\n");
            printf("1) Artist\n2) Album\n3) Song\n4) Genre\n5) Length\n6) Number of plays\n");
            //Prints out choice for which field they would like to edit
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                //Allows edit of Artist name and copys edit into the struct
                printf("Enter the new artist: ");
                getchar();
                fgets(edit, 50, stdin);
                edit[strlen(edit) - 1] = '\0';
                strcpy(current->Data.Artist, edit);

                printf("The new artist is %s\n", current->Data.Artist);
                break;
            case 2:
                //Allows edit of Album title and copys edit into the Struct
                printf("Enter the new album: ");
                getchar();
                fgets(edit, 50, stdin);
                edit[strlen(edit) - 1] = '\0';
                strcpy(current->Data.Album, edit);
                printf("The new album is %s\n", current->Data.Album);
                break;
            case 3:
                //Allows edit of song title and copys edit into struct
                printf("Enter the new Song title: ");
                getchar();
                fgets(edit, 50, stdin);
                edit[strlen(edit) - 1] = '\0';
                strcpy(current->Data.Song, edit);
               
                printf("The new Song is %s\n", current->Data.Song);
                break;
            case 4:
                //Allows edit of genre and copys edit into struct
                printf("Enter the new genre: ");
                getchar();
                fgets(edit, 50, stdin);
                edit[strlen(edit) - 1] = '\0';
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
                do
                {
                    printf("Enter the new number of plays: ");
                    scanf("%d", &temp);
                    current->Data.times_played = temp;
                } while (temp < 0);
                break;

            }

        }
        
        
    }
}

void rate(List* head)
{
    struct node* cur = head ->pHead;
   
    char search_artist[50];

    printf("Enter Artist to Rate\n");
    getchar();
     fgets(search_artist, 50, stdin);
     search_artist[strlen(search_artist) - 1] = '\n';
     search_artist[strlen(search_artist) - 1] = '\0';
   
    while ((cur != NULL))
    {
        while (strcmp(search_artist, cur->Data.Artist) != 0)
        {
            cur = cur->pNext;
        }
        if (strcmp(search_artist, cur->Data.Artist) == 0)
        {
            int new_rating = 0;
              do 
              {   
                    printf("Enter Your rating for the Song between 1 and 5: ");
                    scanf("%d", &new_rating);
              } while ((new_rating <= 1)&(new_rating >= 5));

                cur->Data.Rating = new_rating;
                printf("The New rating is now: %d\n", cur->Data.Rating);
                return;
            
        }
        cur = cur->pNext;
       
    }

}


void play(List *pHead)
{
    struct node* pCur = pHead ->pHead;
    char choice[200];
    int play = 0;

    //Gets song choice
    printf("Enter a song to start with: ");
    getchar();
    fgets(choice, 50, stdin);
    choice[strlen(choice) - 1] = '\n';
    choice[strlen(choice) - 1] = '\0';
    while (strcmp(choice, pCur->Data.Song) != 0)
    {
        pCur = pCur->pNext;
    }

    while (pCur != NULL)
    {
        
        if (strcmp(choice, pCur->Data.Song) == 0)
        {
           
            while (pCur != NULL)
            {
                printf("Artist: %s\n", pCur->Data.Artist);
                printf("Album: %s\n", pCur->Data.Album);
                printf("Song: %s\n", pCur->Data.Song);
                printf("Genre: %s\n", pCur->Data.Genre);
                printf("Duration: %d:%d\n", pCur->Data.Length.minutes, pCur->Data.Length.seconds);
                printf("Times Player: %d\n", pCur->Data.times_played);
                printf("Rating: %d", pCur->Data.Rating);

                //Sleep function will run for 5 seconds
                //Deleted Count function as i relised it was not needed
                Sleep(5000);

                pCur = pCur->pNext;
                system("cls");
            }
        }
        
        
    }

}



void shuffle(List* pHead)
{
    int i = 0,k=0;
    Node* pCur = pHead->pHead;
    char cur[50] = { NULL };

    
    for (i = 0; i <= 10; i++)
    {
        cur[i] = pCur->Data.Song;
        cur[i] = pCur->pNext;
    }
   
    i = rand() % 10 + 1;

    while (k <= 4)
    {
        i = rand() % 10 + 1;
        printf("Artist %s", cur[i]);
        printf("Album %s", cur[i]);
        printf("Song %s", cur[i]);
        printf("Genre %s", cur[i]);
        printf("Duration %d:%d", cur[i], cur[i]);
        printf("Times Player %d", cur[i]);
        printf("Rating %d", cur[i]);

        //Sleep function will run for 5 seconds then go into the next count
        Sleep(5000);
        k++;
    }

    system("cls");


}




int insert(List** pHead, Record newRecord)
{
    Node* newSong = malloc(sizeof(Node));

   

    char choice[50];
    printf("Please enter the new artist");
    getchar();
    fgets(choice, 50, stdin);
    choice[strlen(choice) - 1] = '\n';
    choice[strlen(choice) - 1] = '\0';
    strcpy(newSong->Data.Artist, choice);


    printf("Please enter the New Album");
    getchar();
    fgets(choice, 50, stdin);
    choice[strlen(choice) - 1] = '\n';
    choice[strlen(choice) - 1] = '\0';
    strcpy(newSong->Data.Album, choice);


    printf("Please enter the New Song Title");
    getchar();
    fgets(choice, 50, stdin);
    choice[strlen(choice) - 1] = '\n';
    choice[strlen(choice) - 1] = '\0';
    strcpy(newSong->Data.Song, choice);


    printf("Please enter the New Genre");
    getchar();
    fgets(choice, 50, stdin);
    choice[strlen(choice) - 1] = '\n';
    choice[strlen(choice) - 1] = '\0';
    strcpy(newSong->Data.Genre, choice);


    int min = 0, sec = 0;
    printf("Please Enter the Amount of Minutes");
    scanf("%d", &min);
    newSong->Data.Length.minutes = min;
    printf("Please Enter the Amount of Seconds");
    scanf("%d", &min);
    newSong->Data.Length.seconds = sec;

    int timesPlayed = 0;
    do
    {
       
        printf("Please enter how many times you have played the song");
        scanf("%d\n", &timesPlayed);
        newSong->Data.times_played = timesPlayed;
        if (timesPlayed < 0)
        {
            printf("Please enter an amount greater then 0\n");
        }
    } while (timesPlayed < 0);

   
    int rating = 0;
    do
    {
        printf("Please enter your intial rating:");
        scanf("%d\n", &rating);
        newSong->Data.Rating = rating;

        if ((rating < 1) & (rating > 5))
        {
            printf("Please enter a rating on the scale 1 through 5\n");
        }
        
    } while ((rating < 1) & (rating > 5));
    
    insert_at_front(newSong, newRecord);
    return 0;
}

void delete(List** plist)
{
    Node** pHead = plist;
    char choice[50];

    printf("Enter Song to Delete");
    getchar();
    fgets(choice, 50, stdin);
    choice[strlen(choice) - 1] = '\n';
    choice[strlen(choice) - 1] = '\0';;

    while (strcmp(choice, (*pHead)->Data.Song) != 0)
    {
        pHead = (*pHead)->pNext;
    };
    if (strcmp(choice, (*pHead)->Data.Song) == 0)
    {
       Node *temp = pHead;
       pHead = (*pHead)->pNext;
       free(temp);

    }
    else
    {
        printf("Song not Found");
    }


}



void sort(List* pHead)
{
    
    int choice = 0;
    printf("Please select which one you would like to Sort by\n");
    printf("1) Artist\n2)Album\n3)Rating\n4)Times Played\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        //Artist sort
        sortbyartist(pHead);
        break;
    case 2:
        //Album Sort
        sortbyalbum(pHead);
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
        ptr1 = pHead->pHead;

        while (ptr1->pNext != lptr)
        {
            if (ptr1->Data.Rating > ptr1->pNext->Data.Rating)
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
    Node *ptr1;
    Node *lptr = NULL;

    if (pHead == NULL)
    {
        return;
    }

    do
    {
        swapped = 0;
        ptr1 = pHead->pHead;

        while (ptr1->pNext != lptr)
        {
            if (ptr1->Data.times_played > ptr1->pNext->Data.times_played)
            {
                swap_timesPlayed(ptr1, ptr1->pNext);
                swapped = 1;
                
            }
            ptr1 = ptr1->pNext;
        }
        lptr = ptr1;
    } while (swapped);

}

int sortbyartist(List* pHead) //Insert in order function, inserting by A-Z
{
   

    
}

int sortbyalbum(List* pHead) //Insert in order function, inserting by A-Z
{
    int k, i;
    Node* ptr1[50]={NULL};
    Node* ptr2[50]={NULL};
    Node *temp[50] = { NULL };
    

    if (pHead == NULL)
    {
        return;
    }
    for (i = 0; i < 10; i++)
    {
        ptr1[0] = pHead->pHead;
    }
    for (i = 0; i < 10; i++)
    {
        for (k = 0; k < 10; k++)
        {
            ptr2[k] = ptr1[i]->pNext;
            if (strcmp(ptr1[i]->Data.Album, ptr2[k]->Data.Album) > 0)
            {
                strcpy(temp, ptr1[i]);
                strcpy(ptr1[i], ptr2[k]);
                strcpy(ptr2[k], temp);

            }
            ptr1[i] = ptr1[i]->pNext;
            k++;
        }
    }
       
        for (i= 0; i < 10; i++)
        {
            puts(ptr1[i]);
        }
    

}
