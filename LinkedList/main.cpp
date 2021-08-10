#include "linkedList.h"
#include <iostream>
using namespace std;

int main()
{
    Node *head = NULL;
    LinkedList *list = new LinkedList();
    list->insertAtNthPosition(head, 5, 1);
    return 0;
}