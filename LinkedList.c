//
// Created by user on 27.08.2019.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;

    struct Node* previous;
} Node;
typedef struct MyList
{
    Node* head;
    Node* tail;
    size_t size;
} MyList;

MyList create_list();

void ListPush_back(MyList *lst, int value);

void ListPush_front(MyList *lst, int value);

void ListPop_back(MyList *lst);

void ListPop_front(MyList *lst);

void ListInsert(MyList* lst, size_t position, int element);

int ListBack(MyList* lst);

int ListAt(MyList* lst, size_t position);

int ListFront(MyList* lst);

void ListClear(MyList *lst);

int ListEmpty(MyList* lst);

void ListErase(MyList *lst, size_t position);

size_t list_size(MyList* lst);

void list_swap(MyList* lst, MyList* other);

void list_print(MyList* lst);




MyList create_list()
{
    MyList* new_list = (MyList*)malloc(sizeof(MyList));
    new_list->head = new_list->tail = 0;
    new_list->size = 0;
    return *new_list;
}



void ListPush_back(MyList *lst, int value)
{
    lst->size++;
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = new_node->previous = 0;
    if(lst->tail == 0)
    {
        lst->tail = lst->head = new_node;
        return;
    }
    new_node->previous = lst->tail;
    lst->tail->next = new_node;
    lst->tail = lst->tail->next;
}

void ListPush_front(MyList *lst, int value)
{
    lst->size++;
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = new_node->previous = 0;
    if(lst->head == 0)
    {
        lst->tail = lst->head = new_node;
        return;
    }
    Node* new_head = lst->head;
    new_node->next = new_head;
    new_node->next->previous = new_node;
    lst->head = new_node;
}

void ListPop_back(MyList *lst)
{
    Node* new_node = lst->tail->previous;
    new_node->next = 0;
    free(lst->tail);
    lst->tail = new_node;
    --lst->size;
}

void ListPop_front(MyList *lst)
{
    Node* new_node = lst->head->next;
    new_node->previous = 0;
    free(lst->head);
    lst->head = new_node;
    --lst->size;
}

int ListAt(MyList* lst, size_t position)
{
    if(position < list_size(lst) / 2)
    {
        Node* new_head = lst->head;
        while(position--)
        {
            new_head = new_head->next;
        }
        return new_head->data;
    }
    else
    {
        Node* new_tail = lst->tail;
        position = list_size(lst) - position;
        while(--position)
        {
            new_tail = new_tail->previous;
        }
        return new_tail->data;
    }
}

int ListFront(MyList* lst) { return lst->head->data; }

int ListBack(MyList* lst) { return lst->tail->data; }

int ListEmpty(MyList* lst)  { return lst->size == 0; }

void ListInsert(MyList* lst, size_t position, int element)
{
    if(position == 0)
    {
        ListPush_front(lst, element);
    }
    if(position == list_size(lst))
    {
        ListPush_back(lst, element);
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = element;
    if(position >=  list_size(lst) / 2)
    {
        Node* new_tail = lst->tail;
        position = list_size(lst) - position;
        while(--position)
        {
            new_tail = new_tail->previous;
        }
        new_node->next = new_tail;
        new_node->previous = new_tail->previous;
        new_tail->previous->next = new_node;
        new_tail->previous = new_node;
        ++lst->size;


    }
    else
    {
        Node* new_head = lst->head;
        while(position--)
        {
            new_head = new_head->next;
        }
        new_node->next = new_head;
        new_node->previous = new_head->previous;
        new_head->previous->next = new_node;
        new_head->previous = new_node;
        ++lst->size;
    }
}

void ListClear(MyList *lst)
{
    lst->size = 0;
    while(lst->head != 0)
    {
        free(lst->head->previous);
        lst->head = lst->head->next;

    }
}

void ListErase(MyList *lst, size_t position)
{
    if(position == 0)
    {
        ListPop_front(lst);
        return;
    }
    if(position == lst->size - 1)
    {
        ListPop_back(lst);
        return;
    }
    if(position >=  list_size(lst) / 2)
    {
        Node* new_tail = lst->tail;
        position = list_size(lst) - position;
        while(--position)
        {
            new_tail = new_tail->previous;
        }
        new_tail->previous->next = new_tail->next;
        new_tail->next->previous = new_tail->previous;

        --lst->size;
    }
    else
    {
        Node* new_head = lst->head;
        while(position--)
        {
            new_head = new_head->next;
        }
        new_head->previous->next = new_head->next;
        new_head->next->previous = new_head->previous;
        --lst->size;
    }
}

size_t list_size(MyList* lst) { return lst->size; }

void list_swap(MyList* lst, MyList* other)
{
    Node* new_head = lst->head;
    Node* old_head = other->head;
    Node* new_tail = lst->tail;
    Node* old_tail = other->tail;
    size_t new_size = lst->size;
    size_t old_size = other->size;
    lst->head = old_head;
    other->head = new_head;
    lst->tail = old_tail;
    other->tail = new_tail;
    lst->size = old_size;
    other->size = new_size;
}


void list_print(MyList* lst)
{
    Node* head = lst->head;
    while(head != 0)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

