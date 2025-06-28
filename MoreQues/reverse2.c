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
node*reversebetween(node*head,int left,int right){
    node*curr=head;
    node*null=head;
    node*prev=NULL;
    node*next=NULL;
    node*temp=head;
    int i=1,j=1;
    while(i<=left-1){
        curr=curr->next;
        i++;
    }
    while(j<=right-1){
        null=null->next;
        j++;
    }
    while(curr!=null){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
}

int main(){
    node*head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    head=reversebetween(head,2,4);
    display(head);
}