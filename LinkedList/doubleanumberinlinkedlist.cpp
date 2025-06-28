#include <iostream>
using namespace std;

// ListNode class representing each node in the linked list
class ListNode {
public:
    int val;      // Data value to store
    ListNode* next; // Pointer to the next node

    // Constructor to initialize node
    ListNode(int value) {
        val = value;
        next = nullptr;
    }
};

// Solution class to handle the linked list operations
class Solution {
public:
    // Function to add a new node at the end of the linked list
    void append(ListNode*& head, int value) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to display all elements in the linked list
    void display(ListNode* head) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ListNode*reverselist(ListNode*head){
        ListNode*curr=head;
        ListNode*next=NULL;
        ListNode*prev=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode*doubleIt(ListNode*head){
        head=reverselist(head);
        ListNode*prev=NULL;
        ListNode*curr=head;
        int carry=0;
        while(curr!=NULL){
            int newval=(curr->val*2)+carry;
            curr->val=newval%10;
            carry=newval/10;
            prev=curr;
            curr=curr->next;
        }
        if(carry!=0){
            ListNode*newnode=new ListNode(carry);
            newnode->next=NULL;
            prev->next=newnode;
        }
        return reverselist(head);
        
    }
};

int main() {
    Solution solution;
    ListNode* head = nullptr;
    solution.append(head, 2);
    solution.append(head, 4);
    solution.append(head, 3);
    solution.display(head);
    head=solution.doubleIt(head);
    solution.display(head);
    return 0;
}
