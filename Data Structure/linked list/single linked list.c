#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node *head;
struct node *temp;

struct node *createnode(int ele){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = ele;
    p->next =  NULL;
    return p;
}

// void display(){
//     if(head == NULL)
//         printf("empty list");
//     else{
//         struct node *q;
//         q = head;
//         while(q != NULL){
//             printf("%d  ", q->info);
//             q = q->next;
//         }
//     printf("\n");
//     }
// }

// q = head;
void display(struct node *q){
if(q->next == NULL){
    printf("%d ", q->info);
    return ;
}
else{
    printf("%d ", q->info);
    display(q->next);
}
}

void insertfront(int ele){
    struct node *p;
    p = createnode(ele);

    if (head == NULL)
        head = p;
    else {
        p->next = head;
        head = p;
    }
    // display();
}

void deletefront(){
    if(head == NULL)
        printf("underflow");
    else if(head->next == NULL){
        free(head);
        head = NULL;
        // display();
    }
    else{
        struct node *q;
        q = head;
        head = head->next;
        free(q);
        // display();
    }
}

void insertend(int ele){
    struct node *p;
    p = createnode(ele);
    if(head == NULL)
        head = p;
    else{
        struct node *q;
        q = head;

        while(q->next != NULL)
            q = q->next;
        q->next = p;
    }
    // display();
}

void deleteend(){
    if(head == NULL)
        printf("underflow");
    else if(head->next == NULL){
        free(head);
        head = NULL;
        // display();
    }
    else{
        struct node *q, *p;
        q = head;
        while((q->next)->next != NULL)
            q = q->next;
        p = q->next;
        q->next = NULL;
        free(p);
        // display();
    }
}

int main(){
    int ch, ele;
    head = NULL;

    while(1){
        printf("\n1.insertfront 2.display 3.deletefront 4.insertend 5.deleteend\n");
        scanf("%d", &ch);

        switch(ch){
            case 1: printf("enter elen: ");
                    scanf("%d", &ele);
                    insertfront(ele);
                    break;
            case 2:
                    temp = head;
                    display(temp);
                    break;
            case 3: deletefront();
                    break;
            case 4: printf("enter elen: ");
                    scanf("%d", &ele);
                    insertend(ele);
                    break;
            case 5: deleteend();
                    break;
            default: return 0;
        }
    }
    return 0;
}

