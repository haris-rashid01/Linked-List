#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node* next;
};
struct node* list = NULL;

void insertonAtStart(int x){
struct node* p;
if (list == NULL)
{
    p = (struct node*)malloc(sizeof(struct node));
    p ->info = x;
    p ->next = NULL;
    list = p;
}
else{
    p = (struct node*)malloc(sizeof(struct node));
    p ->info = x;
    p-> next = list;
    list = p;
}

}
void insertonAtEnd(int x){
struct node* p;
struct node* q;
if (list == NULL)
{
    p = (struct node*)malloc(sizeof(struct node));
    p ->info = x;
    p ->next = NULL;
    list = p;
}
else{
    q = list;
    while (q->next != NULL)
    {
        q = q->next;
    }
    
    p = (struct node*)malloc(sizeof(struct node));
    p ->info = x;
    p-> next = NULL;
    q->next = p;
}

}

void deletionAtStart(){
struct node* p;
struct node* q;
if (list == NULL)
{
    printf("No node to delete\n");
}
else{
    p = list;
    list = p->next;
    free(p);
}


}

void deletionAtEnd(){
struct node* p;
struct node* q;
if (list == NULL)
{
    printf("No node to delete\n");
}
else{
    p = list;
    if (p->next == NULL)
    {
       free(p);
       list = NULL;
    }
    else{
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    free(p);
    }
}
}
void insertAtSpecifiedPosition(int value, int x){
    struct node* p;
    struct node* q;
if (list == NULL)
{
    p = (struct node*)malloc(sizeof(struct node));
    p ->info = x;
    p ->next = NULL;
    list = p;
}
p = list;
while (p->next != NULL)
{
    if (p->info == x)
    {
        q = (struct node*)malloc(sizeof(struct node));
        q->info = x;
        q -> next = p->next;
        p-> next = q;
    }
    p = p->next;
}
}

void deleteAtSpecifiedPosition(int position){
    struct node* p;
    struct node* q;
if (list == NULL)
{
   printf("No node found\n");
}
p = list;
while (p->next != NULL)
{
    if (p->info == position)
    {
       q->next = p->next;
       free(p);
    }
    q = p;
    p = p->next;
}
}

void display(){
struct node* p;
p = list;
if (list == NULL)
{
    printf("No node to show\n");
}
printf("Displaying NODES:\n");
while (p != NULL)
{
    printf("%d\n", p->info);
    p = p -> next;
}
}
void sorting(){
    struct node* p;
    struct node* q;
    int temp = 0;
p = list;
    while (p -> next != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
                if (p->info > q->info)
                {
                    temp = p->info;
                    p->info = q->info;
                    q->info = temp;
                }
            q = q -> next;       
        }
        p = p->next;        
    }
    printf("Sorted Linked list is:\n");
    p = list;
    while (p != NULL)
    {
        printf("%d\n", p->info);
        p = p-> next;
    }
    
}
void maxInteger(){
    struct node* p;
    struct node* q;
    if (list == NULL)
    {
        printf("No node found\n");
    }
    p = list;
    int max = p->info;
    while (p != NULL)
    {
    if (p->info > max)
    {
        max = p -> info;
    }
    p = p -> next;
    }
    printf("Maximum Integer is: %d\n", max);
} 
void deleteDuplicateNodes(){
struct node* p = list;

while (p != NULL)
{
    struct node* q = p->next;
    struct node* r = p;
    while (q !=NULL)
    {
        if (p->info == q->info)
        {
            r -> next = q -> next;
            free(q);
            q = r -> next;
        }
        else{
        r = q;
        q = q->next;
        }
    }
    p = p->next;    
}
}
int main(){
 int opt, x, value;
 do
 {
    printf("Press 1 for insertion at start\n2 insertion at end\n3 for deletion at start\n4 for deletion at end\n5 for insertion at specified position\n6 for deletion at specified position\n7 to display\n8 for sorting\n9 for max integer\n10 to delete Duplcate nodes\n-1 to terminate\n");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
    printf("Enter value to insert\n");
    scanf("%d", &x);
    insertonAtStart(x);
    break;
    case 2:
    printf("Enter value to insert\n");
    scanf("%d", &x);
    insertonAtEnd(x);
    break;
    case 3:
    deletionAtStart();    
    break;  
    case 4:
    deletionAtEnd();
    break; 
    case 5:
    printf("Enter at which value you want to insert\n");
    scanf("%d", &value);
    printf("Enter value to insert\n");
    scanf("%d", &x);
    insertAtSpecifiedPosition(value, x); 
    break;
    case 6:
    printf("Enter at which value you want to insert\n");
    scanf("%d", &value);
    deleteAtSpecifiedPosition(value);
    break;    
    case 7:
    display();
    break;
    case 8:
    sorting();
    break;  
    case 9:
    maxInteger();
    break; 
    case 10:
    deleteDuplicateNodes();
    break;
    case -1:
    printf("Program  Ended!\n");
    break;
    default:
    printf("Invald key!\n");
        break;
    }

 } while (opt != -1);
 
}