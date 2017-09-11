#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;
void insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp2 = head;
    temp->data = x;
    if(head == NULL)
    {
        temp->next = head;
        head = temp;
        return;
    }
    while(temp2->next!=NULL)
    {
        temp2 = temp2->next;
    }
        temp->next = temp2->next;
        temp2->next = temp;
}

    void print()
    {
        struct Node* temp = head;
        printf("print the list!\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
void Delete(int n)
{
    struct Node* temp1 = head;
    if(n==1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
        int i;
        for(i=0;i<(n-2);i++)
        {
            temp1 = temp1->next;
        }
        struct Node* temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
}
int main()
{
    head = NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    int n;
    printf("enter a position!\n");
    scanf("%d",&n);
    Delete(n);
    print();
    return 0;
}
