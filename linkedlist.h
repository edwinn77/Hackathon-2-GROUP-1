#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList {
public:
	struct ListNode {
        T value;              // Node value of type T
        ListNode* next;    // Pointer to the next node
    };
    ListNode* head;
    
    // Constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    // Linked list operations
    void appendNode(T);
    void displayList() const;
};

//#include "linkedlist.cpp"  // Include the source file

#endif  // LINKEDLIST_H

