#include "linkedlist.h"
#include "game.h"  // Include the necessary header file(s)

#include <iostream>

using namespace std;

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
    ListNode* nodePtr = head;
    while (nodePtr) {
        ListNode* garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

template <class T>
void LinkedList<T>::appendNode(T newValue) {
    ListNode* newNode = new ListNode;
    newNode->value = newValue;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        ListNode* nodePtr = head;
        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

template <class T>
void LinkedList<T>::displayList() const {
    ListNode* nodePtr = head;
    double totalCredit = 0;
    double totalGPA = 0.0;
    double totalCGPA = 0.0;

    while (nodePtr) {
        nodePtr->value.displayGame();
        cout << endl;

        totalCredit += nodePtr->value.getCredit();
        totalGPA += nodePtr->value.getGPA() * nodePtr->value.getCredit();

        nodePtr = nodePtr->next;
    }
    cout << "Total Credit: " << totalCredit << endl;
    if (totalCredit != 0.0) {
        totalCGPA = totalGPA / totalCredit;
    } else {
        totalCGPA = 0.0; // Handle the case where totalCredit is zero to avoid division by zero
    }
    cout << "Total CGPA: " << totalCGPA << endl
         << endl;
}
