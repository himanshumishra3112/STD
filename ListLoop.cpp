#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

void push(struct node** head_ref, int new_data)
{
    printf("---------------------------\n");
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);
    printf("head_ref: %d\n",*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
    printf("head_ref: %d\n",*head_ref);
    printf("new_node: %d\n",new_node);
}

int detectloop(struct node *list)
{
    struct node  *slow_p = list, *fast_p = list;

    while(slow_p && fast_p &&
            fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
            printf("Found Loop\n");
            return 1;
        }
    }
    return 0;
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    printf("head->next: %d\n",head->next);
    printf("head: %d\n",head);


    struct node* head1=head;
    while(head1 != NULL)
    {
        printf("head1->data: %d\n",head1->data);
        head1=head1->next;
    }
    /* Create a loop for testing */
    head->next->next->next->next = head;
    detectloop(head);
}
