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
void display(node*head){
    while(head!=NULL){
        printf("%d\t",head->data);
        head=head->next;
    }
    printf("\n");
}
node*removeelements(node*head,int value){
    while(head!=NULL&&head->data==value){
        node*del=head;
        head=head->next;
        free(del);
    }
    node*temp=head;
    while(temp!=NULL&&temp->next!=NULL){
        if(temp->next->data==value){
            node*todel=temp->next;
            temp->next=temp->next->next;
            free(todel);
        }
        else{
            temp=temp->next;
        }
    }
    return head;
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
    head=removeelements(head,30);
    display(head);
    return 0;
}