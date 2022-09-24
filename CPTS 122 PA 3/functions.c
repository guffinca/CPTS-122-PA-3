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

struct Node* make_node(FILE* infile)
{
    
    Node* node = malloc(sizeof(Node));
    Record* pMem = malloc(sizeof(Record));
    char* i = NULL;
    char temp[100];
    

    
    fgets(temp, 100, infile);

    i = strtok(temp, ",");
    if (i != NULL)
    {
        strcpy(pMem->Artist, i);
    }


    i = strtok(temp, ",");
    if (i != NULL)
    {
        strcpy(pMem->Album, i);
    }
   
    i = strtok(temp, ",");
    if (i != NULL)
    {
        strcpy(pMem->Song, i);
    }
   
    i = strtok(temp, ",");
    if (i != NULL)
    {
        strcpy(pMem->Genre, i);
    }
    
    i = strtok(temp, ",");
    char* length = i;
    
    if (i != NULL)
    {
        pMem->times_played = atoi(i);
    }


    i = strtok(temp, ",");
  
    if (i != NULL)
    {
        pMem->Rating = atoi(i);
    }
    
    char* min_or_sec = NULL;
    min_or_sec = strtok(length, ":");
    if (min_or_sec != NULL)
    {
        pMem->Length.minutes = atoi(min_or_sec);
        min_or_sec = strtok(NULL, ":");
        pMem->Length.seconds = atoi(min_or_sec);
    }

   
    node->pPrev = NULL;
    node->pNext = NULL;

    return node;
}
void insert_at_front(Node *pHead, FILE *infile)
{
    Node* temp = NULL, * next = NULL;

    if (pHead == NULL)
    {
        pHead = make_node(infile);
        next = pHead;
    }
    else
    {
    temp = pHead;
    pHead = make_node(infile);
    pHead->pNext = temp;
 }

    
}

void load(FILE* infile)
{
    Node* node = malloc(sizeof(Node));
    char* i = NULL;
    char temp[100];

    if (infile != NULL)
    {
        while (fgets(temp, 100, infile) != NULL)
        {
            make_node(infile);
            insert_at_front(node, infile);
        }
    }
}

void display(Node** pList)
{
    int i = 0;

    do
    {
        printf("Enter 1 to see all songs");
        printf("Enter 2 to see songs by one artist");
        scanf("%d", &i);

    } while ((i != 1) && (i != 2));

    Record* current_song = pList;
    
    if (i == 1)
    {
        while (current_song != NULL)
        {
            printf("Song: %s\n", current_song->Song);
            printf("Artist: %s\n", current_song->Artist);
            printf("Album: %s\n", current_song->Album);
            printf("Genre: %s\n", current_song->Genre);
            printf("TIME: %d:%d", current_song->Length.minutes, current_song->Length.seconds);
            printf("Times Played: %d\n", current_song->times_played);
            printf("RATING: %d\n\n", current_song->Rating);

            current_song = current_song->pNext;

        }
      
    }
    else if(i == 2)
    {
        while (current_song != NULL)
        {
            printf("Song: %s\n", current_song->Song);
            printf("Artist: %s\n", current_song->Artist);
            printf("Album: %s\n", current_song->Album);
            printf("Genre: %s\n", current_song->Genre);
            printf("TIME: %d:%d", current_song->Length.minutes, current_song->Length.seconds);
            printf("Times Played: %d\n", current_song->times_played);
            printf("RATING: %d\n\n", current_song->Rating);

            current_song = current_song->pNext;

        }
    }
}

void store(struct node** pHead, FILE* infile)
{
    struct record* current = pHead;

    while (current->pNext != NULL)
    {
        current = current->pNext;
    }

    while (current->pNext != NULL)
    {
        fprintf(infile, "%s,%s,%s,%s,%d:%d,%d,%d", current->Artist, current->Album, current->Song, current->Genre, current->Length.minutes, current->Length.seconds, current->times_played, current->Rating);

        current = current->pPrev;
    }
}

void edit(struct record* head)
{
    struct record* current = head;
    int choice = 0;
    char search[50];
    char edit[50];
    int temp = 0;
    printf("Enter the artist to search: ");
    
    fgets(search, 50, stdin);
    // Allows input of Artist wanted to edit
    
    while (current != NULL & choice == 0)
    {

        if (strcmp(search, current->Artist) == 0)
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
                getchar();
                fgets(edit, 50, stdin);
                strcpy(current->Artist, edit);

                printf("The new artist is %s\n", current->Artist);
                break;
            case 2:
                //Allows edit of Album title and copys edit into the Struct
                printf("Enter the new album: ");
                getchar();
                fgets(edit, 50, stdin);
                strcpy(current->Album, edit);
                printf("The new album is %s\n", current->Album);
                break;
            case 3:
                //Allows edit of song title and copys edit into struct
                printf("Enter the new Song title: ");
                getchar();
                fgets(edit, 50, stdin);
                strcpy(current->Song, edit);
                printf("The new Song is %s\n", current->Song);
                break;
            case 4:
                //Allows edit of genre and copys edit into struct
                printf("Enter the new genre: ");
                getchar();
                fgets(edit, 50, stdin);
                strcpy(current->Genre, edit);
                printf("The new genre is %s\n", current->Genre);
                break;
            case 5:
                //Allows edit of song time in minutes and seconds and copys edit into struct
                printf("Enter the new number of minutes: ");
                scanf("%d", &temp);
                current->Length.minutes = temp;
                printf("Enter the new number of seconds: ");
                scanf("%d", &temp);
                current->Length.seconds = temp;
                break;
            case 6:
                //Allows user to input amount of times song has been played
                printf("Enter the new number of plays: ");
                scanf("%d", &temp);
                current->times_played = temp;
                break;

            }

        }
        current = current->pNext;
        choice = 0;
    }
}

void rate(struct record* head)
{
    struct record* cur = head;
   
    char search_artist[50];

    printf("Enter Artist to Rate");
    fgets(search_artist, 50, stdin);

    while ((cur != NULL))
    {
        if (strcmp(search_artist, cur->Artist) == 0)
        {
            int new_rating = 0;
              do 
              {   
                    printf("Enter Your rating for the Song between 1 and 5:");
                    scanf("%d", &new_rating);
              } while ((new_rating >= 1) & (new_rating <= 5));

                cur->Rating = new_rating;
                printf("The New rating is now: %d", cur->Rating);
                return;
            
        }
        cur = cur->pNext;
       
    }

}


void play(struct record* pHead)
{
    struct record* pCur = pHead;
    char choice[50];
    int play = 0;

    //Gets song choice
    printf("Enter a song to start with: ");
    getchar();
    fgets(choice, 50, stdin);
    choice[strlen(choice) - 1] = '\0';


    while (pCur != NULL)
    {

        if (strcmp(choice, pCur->Song) == 0)
        {
           
            
                printf("Artist %s", pCur->Artist);
                printf("Album %s", pCur->Album);
                printf("Song %s", pCur->Song);
                printf("Genre %s", pCur->Genre);
                printf("Duration %d:%d", pCur->Length.minutes, pCur->Length.seconds);
                printf("Times Player %d", pCur->times_played);
                printf("Rating %d", pCur->Rating);
                
                //Sleep function will run for 5 seconds
                //Deleted Count function as i relised it was not needed
                Sleep(5000);
                
           
            system("clear");
        }
        pCur = pCur->pNext;
        
    }

}



void shuffle(struct Record* pHead)
{
    int songs = 0;
    Record *pCur = pHead;
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

        printf("Artist %s", pCur->Artist);
        printf("Album %s", pCur->Album);
        printf("Song %s", pCur->Song);
        printf("Genre %s", pCur->Genre);
        printf("Duration %d:%d", pCur->Length.minutes, pCur->Length.seconds);
        printf("Times Player %d", pCur->times_played);
        printf("Rating %d", pCur->Rating);

        //Sleep function will run for 5 seconds then go into the next count
        Sleep(5000);
        

    system("clear");


}




int insert(Record** pHead, FILE* infile)
{
    Record* newSong = malloc(sizeof(Record));

   

    char temp[100];
    printf("Please enter the new artist");
    fgets(temp, 100, stdin);
    strcpy(newSong->Artist, temp);


    printf("Please enter the New Album");
    fgets(temp, 100, stdin);
    strcpy(newSong->Album, temp);


    printf("Please enter the New Song Title");
    fgets(temp, 100, stdin);
    strcpy(newSong->Song, temp);


    printf("Please enter the New Genre");
    fgets(temp, 100, stdin);
    strcpy(newSong->Genre, temp);


    int min = 0, sec = 0;
    printf("Please Enter the Amount of Minutes");
    scanf("%d", &min);
    newSong->Length.minutes = min;
    printf("Please Enter the Amount of Seconds");
    scanf("%d", &min);
    newSong->Length.seconds = sec;

    int timesPlayed = 0;
    printf("Please enter how many times you have played the song");
    scanf("%d", &timesPlayed);
    newSong->times_played = timesPlayed;

    int rating = 0;
    printf("Please enter your intial rating");
    scanf("%d", &rating);
    newSong->Rating = rating;

    insert_at_front(newSong, infile);

    return 0;
}

void delete(Record** pHead)
{
    char temp[100];

    printf("Enter Artist to Delete");
    getchar();
    fgets(temp, 100, stdin);

    if (strcmp(temp, (*pHead)->Song) == 0)
    {
       Record *temp = *pHead;
       *pHead = (*pHead)->pNext;
       free(temp);

    }
    else
    {
        printf("Song not Found");
    }


}

void exit_function(struct node* pHead, FILE* infile)
{

    struct record* current = pHead;

    while (current->pNext != NULL)
    {
        current = current->pNext;
    }

    while (current->pNext != NULL)
    {
        fprintf(infile, "%s,%s,%s,%s,%d:%d,%d,%d", current->Artist, current->Album, current->Song, current->Genre, current->Length.minutes, current->Length.seconds, current->times_played, current->Rating);

        current = current->pPrev;
    }
    exit(0);
}

void sort(struct Record** pHead)
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


        break;
    case 4:
        // Times played sort
        break;

    }
}

