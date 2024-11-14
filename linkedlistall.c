#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    char name[10];
    struct Node *next;
};
struct Node *insertAtFirst(struct Node *head,int data, char *name){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    strcpy(ptr->name,name);
    ptr->next = head;
    head = ptr;
    return head;
}
void traverse(struct Node *head){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr = head;
    while(ptr!=NULL){
        printf("number = %d\n",ptr->data);
        puts(ptr->name);
        ptr = ptr->next;
    }
}
struct Node *insertAtEnd(struct Node *head,int data,char *name){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    p = head;
    ptr->data = data;
    strcpy(ptr->name,name);
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}
struct Node *insertAtIndex(struct Node *head,int data,char *name,int index){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    p = head;
    ptr->data = data;
    strcpy(ptr->name,name);
    int i=0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
}
struct Node *deleteFirst(struct Node *head){      /*struct node* delfirst(struct node*head)
                                                      struct node*ptr=head;
                                                      head=head->next
                                                      free(ptr);
                                                      return head;  */
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    
    return head;
}
struct Node *deleteEnd(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q!=NULL){
        p = p->next;
        q = q->next;
    }
    free(q);
    p->next = NULL;

    return head;
}
struct Node *deleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = head->next;
    int i=0;
    while(i!=index-1){
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);

    return head;
}
struct Node *deleteAValue(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}
int main(){
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *) malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *) malloc(sizeof(struct Node));
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    head->data =1;
    second->data =2;
    third->data =3;
    fourth->data =4;
    fifth->data =5;
    
    strcpy(head->name,"anando");
    strcpy(second->name,"miraj");
    strcpy(third->name,"noshin");
    strcpy(fourth->name,"mursalin");
    strcpy(fifth->name,"mahfuj");

    printf("linked list before operation\n");
    traverse(head);

    int newData=6;
    char newName[10]="farhana";
    head = deleteAValue(head,2);

    printf("linked list after operation\n");
    traverse(head);    
} 