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

node*reverselist(node*head){
    node*prev=NULL;
    node*curr=head;
    node*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

node*doubleit(node*head){
    head=reverselist(head);
    node*curr=head;
    node*prev=NULL;
    int carry=0;
    while(curr!=NULL){
        int newvalue=curr->data*2+carry;
        curr->data=newvalue%10;
        if(newvalue>=10){
            carry=1;
        }
        else{
            carry=0;
        }
        prev=curr;
        curr=curr->next;
    }
    if(carry!=0){
        node*newnode=(node*)malloc(sizeof(node));
        newnode->data=carry;
        prev->next=newnode;
    }
    return reverselist(head);
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
    insert(&head,8);
    insert(&head,9);
    display(head);
    head=doubleit(head);
    display(head);
    return 0;
}