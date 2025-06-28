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
node*deleteduplicates(node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node*dummy=(node*)malloc(sizeof(node));
    dummy->next=head;
    node*prev=dummy;
    node*current=head;
    while(current!=NULL){
        if(current->data==current->next->data){
            while(current->next!=NULL&&current->data==current->next->data){
                current=current->next;
            }
            prev->next=current->next;
        }
        else{
            prev=current;
        }
        current=current->next;
    }
    return dummy->next;
}
int main(){
    node*head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,3);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    insert(&head,5);
    display(head);
    head=deleteduplicates(head);
    display(head);
}