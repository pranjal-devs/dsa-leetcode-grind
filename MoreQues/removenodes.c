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

node*removenodes(node*head){
    node*dummy=(node*)malloc(sizeof(node));
    dummy->next=head;
    node*prev=dummy;
    node*current=head;
    while(current!=NULL){
        node*check=current->next;
        while(check!=NULL){
            if(check->data>current->data){
                prev->next=current->next;
                current=prev->next;
            }
            check=check->next;
        }
        prev=current;
        current=current->next;
    }
    return dummy->next;
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
    insert(&head,5);
    insert(&head,2);
    insert(&head,13);
    insert(&head,3);
    insert(&head,8);
    display(head);
    head=removenodes(head);
    display(head);
    return 0;
}