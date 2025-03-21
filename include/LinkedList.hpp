//
//  LinkedList.hpp
//  PracticeC++
//
//  Created by Scott Novak on 7/18/22.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>


class LinkedList
{
    
public:
    
    

    
    typedef struct Node
    {
        int data;
        Node* next;
        
    } Node;
    
private:
    

    
    
    Node* mHead;
    
    
public:
    
    
    LinkedList();
    ~LinkedList();
    

    
    int getLength(const Node* head);
    
    Node* getNthNode(Node* head, int nth);
    

    
    inline Node* getHead() {return mHead;}
    
    void appendData (Node** ref, int data);
    
    int pop (Node* *ref);
    
    void deleteList(Node* *headRef);
    
    void insertAtNth(Node* *headRef, int data, int nth);
    
    
};




#endif /* LinkedList_hpp */
