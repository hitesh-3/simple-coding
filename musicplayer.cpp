// Implementation of a music player using Data Structures

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int itemCount = 0;

struct node
{
    char song[100];
    struct node *next;
    struct node *prev;
} * top, *temp, *top1;

void tofile(char a[])
{
    fstream f1;
    f1.open("playlist.txt", ios::out | ios::app);
    f1 << a << endl;
    f1.close();
}

// To add a song
void add_node(struct node *first)
{
    itemCount += 1;
    char a[100];
    while (first->next != NULL)
    {
        first = first->next;
    }
    first->next = (struct node *)malloc(sizeof(struct node));
    first->prev = first;
    first = first->next;
    cout << "\n\a\a\a\aName of the song-  ";
    scanf("%s", &a);
    strcpy(first->song, a);
    tofile(a);
    first->next = NULL;
}

void add_node_file(struct node *first, string a)
{
    while (first->next != NULL)
    {
        first = first->next;
    }
    first->next = (struct node *)malloc(sizeof(struct node));
    first->prev = first;
    first = first->next;
    strcpy(first->song, a.c_str());
    first->next = NULL;
    itemCount += 1;
}

void delete_file(char a[])
{
    fstream f1, f2;
    string line;
    int x = 0;
    f1.open("playlist.txt", ios::in | ios::out);
    f2.open("temp.txt", ios::in | ios::out);
    while (!f1.eof())
    {
        getline(f1, line);
        if (strcmp(a, line.c_str()) != 0)
            f2 << line << endl;
        else if (strcmp(a, line.c_str()) == 0)
            x = 1;
    }
    f1.close();
    f2.close();
    remove("playlist.txt");
    rename("temp.txt", "playlist.txt");
    if (x == 0)
    {
        cout << "Song not found." << endl;
    }
    else
    {
        cout << "=>Song has been deleted." << endl;
        itemCount -= 1;
    }
}

void del_node(struct node *first)
{
    while ((first->next)->next != NULL)
    {
        first = first->next;
    }
    struct node *temp;
    temp = (first->next)->next;
    first->next = NULL;
    free(temp);
    cout << "Deleted" << endl;
    itemCount -= 1;
}

void printlist(struct node *first)
{
    cout << "\nPlaylist Name- ";
    while (first->next != NULL)
    {
        cout << first->song << endl;
        first = first->next;
    }
    cout << first->song << endl;
}

// To view the total number of songs
void count_nodes(struct node *first)
{
    cout << "\nTotal songs-  " << itemCount << endl;
}

struct node *del_pos(struct node *pointer, int pos)
{

    struct node *n1, *prev1, *temp;
    prev1 = (struct node *)malloc(sizeof(node));
    temp = (struct node *)malloc(sizeof(node));
    int i = 0;

    if (pos == 1)
    {
        temp = pointer;
        delete_file(temp->song);
        pointer = pointer->next;
        free(temp);
        printf("\n=>Playlist has been updated\n Check it out!\n");
        return pointer;
        itemCount -= 1;
    }
    while (i < pos - 1)
    {
        prev1 = pointer;
        pointer = pointer->next;
        i++;
    }

    if (pointer->next == NULL)
    {

        temp = pointer;
        delete_file(temp->song);

        prev1->next->prev = NULL;
        prev1->next = NULL;

        free(temp);
        printf("\n=>Playlist updated\n Check it out!\n");
        itemCount -= 1;
    }

    else
    {
        temp = pointer;
        delete_file(temp->song);

        prev1->next = temp->next;
        temp->next->prev = prev1;
        free(temp);
        printf("\n=>Playlist updated\n Check it out!\n");
        itemCount -= 1;
    }
}

// To search a song
void search1(struct node *first)
{
    char song[100];
    cout << "\n\a\a\a\aSearch a song- ";
    scanf("%s", &song);
    int flag = 0;

    while (first != NULL)
    {
        if (strcmp(first->song, song) == 0)
        {
            cout << "\n\a\a\a\aYayy! we found the song" << endl;
            flag++;
            break;
        }
        else
        {
            first = first->next;
        }
    }
    if (flag == 0)
    {
        cout << "\n\a\a\a\aUh oh! Song not found!" << endl;
    }
}

void create()
{
    top = NULL;
}

// Push operation
void push(char data[])
{
    if (top == NULL)
    {
        top = (struct node *)malloc(sizeof(struct node));
        top->next = NULL;
        strcpy(top->song, data);
    }
    else if (strcmp(top->song, data) != 0)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->next = top;
        strcpy(temp->song, data);
        top = temp;
    }
}

// To display recently played tracks
void display()
{
    top1 = top;
    if (top1 == NULL)
    {
        printf("\n\a\a\a\a=>NO recently played tracks.\n");
        return;
    }
    printf("\n\a\a\a\aRecently played tracks-\n");
    while (top1 != NULL)
    {
        printf("%s", top1->song);
        printf("\n");
        top1 = top1->next;
    }
}

// To play a song
void play(struct node *first)
{
    char song[100];
    printlist(first);
    cout << "\n\a\a\a\aPlay a song- ";
    scanf("%s", song);
    int flag = 0;

    while (first != NULL)
    {
        if (strcmp(first->song, song) == 0)
        {
            cout << "\n\a\a\a\a=>Now Playing......" << song << endl;
            flag++;
            push(song);
            break;
        }
        else
        {
            first = first->next;
        }
    }
    if (flag == 0)
    {
        cout << "\n\a\a\a\aUh oh! Song not found!" << endl;
    }
}

void recent()
{
    display();
}

// To view recently played song
void topelement()
{
    top1 = top;
    if (top1 == NULL)
    {
        printf("\n\a\a\a\aNO last played tracks.\n");
        return;
    }
    cout << "\n=>Recently Played Song - " << top->song << endl;
}

// To add a playlist
void addplaylist(struct node *start)
{
    fstream f1;
    string line;
    f1.open("playlist.txt", ios::in);
    while (!f1.eof())
    {
        getline(f1, line);
        add_node_file(start, line);
    }
    cout << "=>Playlist Added" << endl;
    f1.close();
}

// To delete a song by search
void del_search(struct node *start)
{
    char song[100];
    printlist(start);
    cout << "\n\a\a\a\aDelete a song- ";
    scanf("%s", song);
    int flag = 0;
    while (start != NULL)
    {
        if (strcmp(start->song, song) == 0)
        {
            cout << "\n\a\a\a\aSong Found" << endl;
            struct node *temp;
            temp = (struct node *)malloc(sizeof(node));
            temp = start;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete_file(temp->song);
            free(temp);
            itemCount -= 1;
            flag++;
            break;
        }
        else
        {
            start = start->next;
        }
    }
    if (flag == 0)
    {
        cout << "\n\a\a\a\aSong Not found" << endl;
    }
}

// Options for deleting songs
void deletemenu(struct node *start)
{
    int c;
    cout << "Wanna delete a song?\n1.By Search\n2.By Position" << endl;
    cout << "\a\a\a\aEnter your choice-";
    cin >> c;
    switch (c)
    {
    case 1:
        del_search(start);
        break;
    case 2:
        int pos;
        printf("\n\a\a\a\aEnter the song number: ");
        scanf("%d", &pos);
        del_pos(start, pos - 1);
        break;
    }
}

main()
{
    int choice, loc;
    char song[100];
    struct node *start, *hold;
    start = (struct node *)malloc(sizeof(struct node));
    cout << "\n\n\a\a\a\aEnter your playlist name-  ";
    cin.getline(start->song, 100);
    start->next = NULL;
    hold = start;
    create();

    do
    {
        cout << "\n1.Add New Song\n2.Delete Song\n3.Display Entered Playlist\n4.Total Songs\n5.Search Song\n6.Play Song\n7.Recently Played List\n8.Last Played\n9. Add From File\n10.Exit" << endl;
        cout << ("\n\a\a\a\aEnter your choice- ");
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_node(start);
            break;
        case 2:
            deletemenu(start);
            break;
        case 3:
            printlist(start);
            break;
        case 4:
            count_nodes(hold);
            break;
        case 5:
            search1(start);
            break;
        case 6:
            play(start);
            break;
        case 7:
            recent();
            break;
        case 8:
            topelement();
            break;
        case 9:
            addplaylist(start);
            break;
        case 10:
            exit(0);
        }
    } while (choice < 11);
}