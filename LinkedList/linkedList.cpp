#include "linkedList.h"
#include <iostream>
using namespace std;

Node* LinkedList::insertAtHead(Node *head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

Node* LinkedList::insertAtTail(Node *head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    return head;
}

Node* LinkedList::insertAtNthPosition(Node *head, int data, int position)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    Node *temp = head;
    int count = 0;
    while(count < position - 2)
    {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void LinkedList::deleteAtNthPosition(Node *head, int position)
{
    Node *temp1;
    Node *temp2;
    temp1 = head;
    temp2 = temp1->next;
    int count = 0;
    while(count < position - 2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        count++;
    }
    temp1->next = temp2->next;
    temp2->next = NULL;
    delete temp2; // value or memory block pointed by pointer is destroyed; results in dangling pointer (bad)
}

Node* LinkedList::reverseLinkedList(Node *head)
{
    Node *curr;
    Node *prev;
    Node *next;
    curr = head;
    prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

void LinkedList::Print(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}