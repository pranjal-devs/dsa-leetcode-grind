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

node*partitionnode(node*head,int x){
    node*List1=(node*)malloc(sizeof(node));
    node*List2=(node*)malloc(sizeof(node));
    node*l1=List1;
    node*l2=List2;
    while(head){
        if(head->data<x){
            l1->next=head;
            l1=l1->next;
        }
        else{
            l2->next=head;
            l2=l2->next;
        }
        head=head->next;
    }
    l1->next=List2->next;
    l2->next=NULL;
    return List1->next;
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
    insert(&head,1);
    insert(&head,4);
    insert(&head,3);
    insert(&head,2);
    insert(&head,5);
    insert(&head,2);
    display(head);
    head=partitionnode(head,3);
    display(head);
    return 0;
}