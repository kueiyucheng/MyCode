#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
struct DataItem
{
    int data;
    int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* item;
struct DataItem* dummyItem;

int hashCode(int key)
{
    return key % SIZE;
}

void insert(int key, int data)
{
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->key = key;
    item->data = data;
    int hashIndex = hashCode(item->key);
    while(hashArray[hashIndex]!=NULL && hashArray[hashIndex]->key!=-1)
    {
        hashIndex++;
        hashIndex %= SIZE;
    }

    hashArray[hashIndex] = item;
}

struct DataItem *search(int key)
{
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex]!=NULL)
    {
        if(hashArray[hashIndex]->key==key)
        {
            return hashArray[hashIndex];
        }
        hashIndex++;
        hashIndex %= SIZE;
    }
    return NULL;
}

void deleteItem(int key)
{
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex]!=NULL)
    {
        if(hashArray[hashIndex]->key==key)
        {
            hashArray[hashIndex]->key = -1;
            hashArray[hashIndex]->data = -1;


        }
        hashIndex++;
        hashIndex %= SIZE;
    }

}

void display()
{
    int i = 0;
    for(i=0;i<SIZE;i++)
    {
        if(hashArray[i]!=NULL && hashArray[i]->key!=-1)
        {
            printf("(%d, %d)", hashArray[i]->key, hashArray[i]->data);
        }
        else
        {
            printf(" (NULL) ");
        }
    }
}

int main()
{


    insert(1, 20);
    insert(2, 20);
    insert(3, 20);
    //insert(4, 20);
    insert(5, 20);
    insert(6, 20);
    insert(25, 100);
    insert(14, 20);
    display();
    deleteItem(25);
    display();
    item = search(25);
    if(item!=NULL)
    {
        printf("Element found: %d\n",item->data);
    }
    else
    {
        printf("Element not found!\n");
    }
    return 0;
}
