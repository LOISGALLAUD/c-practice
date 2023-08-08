/*
Linked List
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node *malloc_list(int *array)
{
    struct Node *head = NULL;
    struct Node *current = NULL;
    struct Node *previous = NULL;

    for (size_t i = 0; array[i] != -1; ++i)
    {
        current = malloc(sizeof(struct Node));
        current->val = array[i];
        current->next = NULL;

        if (head == NULL)
        {
            head = current;
        }
        else
        {
            previous->next = current;
        }

        previous = current;
    }

    return head;
}

void free_list(struct Node *head)
{
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

void print_list(struct Node *head)
{
    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

struct Node *invert_list(struct Node *head)
{
    struct Node *current = head;
    struct Node *next = NULL;
    struct Node *prev = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

struct Node *copy_list(struct Node *head)
{
    struct Node *current = head;
    struct Node *new_head = NULL;
    struct Node *new_current = NULL;
    struct Node *new_previous = NULL;

    while (current != NULL)
    {
        new_current = malloc(sizeof(struct Node));
        new_current->val = current->val;
        new_current->next = NULL;

        if (new_head == NULL)
        {
            new_head = new_current;
        }
        else
        {
            new_previous->next = new_current;
        }

        new_previous = new_current;
        current = current->next;
    }

    return new_head;
}

struct Node *generate_random_list(size_t size)
{
    struct Node *head = NULL;
    struct Node *current = NULL;
    struct Node *previous = NULL;

    for (size_t i = 0; i < size; ++i)
    {
        current = malloc(sizeof(struct Node));
        current->val = rand() % 100;
        current->next = NULL;

        if (head == NULL)
        {
            head = current;
        }
        else
        {
            previous->next = current;
        }

        previous = current;
    }

    return head;
}

int main(void)
{
    srand(time(NULL));
    struct Node *head = generate_random_list(1e4);
    print_list(head);
    head = invert_list(head);
    print_list(head);
    free_list(head);
    return 0;
}