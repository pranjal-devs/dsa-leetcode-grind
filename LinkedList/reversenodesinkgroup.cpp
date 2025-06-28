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
    ListNode*reverseList(ListNode*head){
        ListNode*curr=head;
        ListNode*prev=nullptr;
        ListNode*next=nullptr;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode*getkthNode(ListNode*head,int k){
        k-=1;
        while(k>0&&head!=nullptr){
            k--;
            head=head->next;
        }
        return head;
    }
    ListNode*reversenodesinkgroup(ListNode*head,int k){
        ListNode*temp=head;
        ListNode*prevLast=nullptr;
        while(temp!=nullptr){
            ListNode*kthnode=getkthNode(temp,k);
            if(kthnode==nullptr){
                if(prevLast){
                    prevLast->next=temp;
                    break;
                }
            }
            ListNode*nextNode=kthnode->next;
            kthnode->next=nullptr;
            reverseList(temp);
            if(temp==head){
                head=kthnode;
            }
            else{
                prevLast->next=kthnode;
            }
            prevLast=temp;
            temp=nextNode;
        }
        return head;
    }
};

int main() {
    Solution solution;
    ListNode* head = nullptr;
    solution.append(head, 1);
    solution.append(head, 2);
    solution.append(head, 3);
    solution.append(head, 4);
    solution.append(head, 5);
    solution.append(head, 6);
    solution.append(head, 7);
    solution.append(head, 8);
    solution.append(head, 9);
    solution.append(head, 10);
    solution.display(head);
    head=solution.reversenodesinkgroup(head,3);
    solution.display(head);
    return 0;
}
