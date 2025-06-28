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
node* reversebetween(node*head,int left,int right){
    int count=1;
    node*current=head;
    node*prev=NULL;
    while(count!=left){
        prev=current;  // previous will point to the node previous to the left pointer this will allow us to access the list before left
        current=current->next; // current points to head and at the end of loop it points to left position
        count++;
    }
    node*start=current; // the start pointer is pointing the left position
    while(count!=right){
        current=current->next; // now the current is pointing to the right position 
        count++;
    }
    node*rest=current->next; // this creates a linked list rest which stores the list after the right (current) pointer
    current->next=NULL;
    node*prevrev=NULL;
    node*next=NULL;
    while(start!=NULL){
        next=start->next;
        start->next=prevrev;
        prevrev=start;
        start=next;
    }
    node*newhead=prevrev;
    if(prev!=NULL){
        prev->next=newhead;
    }
    current=newhead;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=rest;
    if(left==1){
        return newhead;
    }
    else{
        return head;
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