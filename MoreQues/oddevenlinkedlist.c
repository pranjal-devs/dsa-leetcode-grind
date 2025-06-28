#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}node;
void insert(node**head,int data){
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    node*temp;
    if(*head==NULL){
        *head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}
node*oddevenlist(node*head){
    node*tempeven=head;
    node*tempodd=head->next;
    node*oddhead=tempodd;
    while(tempeven!=NULL&&tempeven->next!=NULL&&tempodd!=NULL&&tempodd->next!=NULL){
        tempeven->next=tempeven->next->next;
        tempeven=tempeven->next;

        tempodd->next=tempodd->next->next;
        tempodd=tempodd->next;
    }
    tempeven->next=oddhead;
    return head;
}
void display(node*head){
    while(head!=NULL){
        printf("%d\t",head->data);
        head=head->next;
    }
    printf("\n");
}
int main(){
    node*head=NULL;
    insert(&head,10);
    insert(&head,20);
    insert(&head,30);
    insert(&head,40);
    insert(&head,50);
    insert(&head,60);
    display(head);
    head=oddevenlist(head);
    display(head);
    return 0;
}