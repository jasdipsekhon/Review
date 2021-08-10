#ifndef __LINKEDLIST__H__
#define __LINKEDLIST__H__
#include <iostream>
using namespace std;

struct Node
{
    int data; // each node consists of data
    Node *next; // each ndoe consists of a pointer to next Node of type Node
    Node()
    {
        data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    public:
    Node *insertAtHead(Node *head, int data);
    Node *insertAtTail(Node *head, int data);
    Node *insertAtNthPosition(Node *head, int data, int position);
    void deleteAtNthPosition(Node *head, int position);
    Node *reverseLinkedList(Node *head);
    void Print(Node *head);
};
#endif  //!__LINKEDLIST__H__