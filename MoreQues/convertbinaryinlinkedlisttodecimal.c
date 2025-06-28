#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}node;
void insert(node**head,int value){
    node*temp;
    node*newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=NULL;
    if(*head==NULL){
        *head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}
void display(node*head){
    while(head!=NULL){
        printf("%d\t",head->data);
        head=head->next;
    }
    printf("\n");
}
int getdecimalvalue(node*head){
    node*prev=NULL;
    node*next=NULL;
    node*curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    int decimal=0;
    int base=1;
    while(head!=NULL){
        decimal+=head->data*base;
        base=base*2;
        head=head->next;
    }
    return decimal;
}
int main(){
    node*head=NULL;
    insert(&head,1);
    insert(&head,0);
    insert(&head,0);
    insert(&head,1);
    int d=getdecimalvalue(head);
    printf("%d",d);
}