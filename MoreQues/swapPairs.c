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
node*swapPairs(node*head){
    if(head==NULL&&head->next==NULL){
        return head;
    }
    node*curr=head;
    node*newhead=head->next;
    while(curr!=NULL&&curr->next!=NULL){
        node*next=curr->next;
        node*ptr=next->next;
        next->next=curr;
        curr->next=(ptr!=NULL&&ptr->next!=NULL) ? ptr->next : ptr;
        curr=ptr;
    }
    return newhead;
}
int main(){
    node*head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    display(head);
    head=swapPairs(head);
    display(head);
}