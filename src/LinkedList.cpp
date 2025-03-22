//
//  LinkedList.cpp
//  PracticeC++
//
//  Created by Scott Novak on 7/18/22.
//

#include "LinkedList.hpp"
#include <stdlib.h>

LinkedList::LinkedList() : mHead(nullptr) {}

LinkedList::~LinkedList() {}

int LinkedList::getLength(const Node* head) {
    int length = 0;

    if (head != nullptr) {
        while (head != nullptr) {
            length++;
            head = head->next;
        }
    }

    return length;
}

LinkedList::Node* LinkedList::getNthNode(Node* head, int nth) {
    int count = 0;
    while (head != nullptr) {
        if (count == nth) {
            return head;
        }

        count++;
        head = head->next;
    }

    return nullptr;
}

void LinkedList::appendData(Node** ref, int data) {
    if (*ref == nullptr) // then there is no head
    {
        Node* ptr = (Node*)malloc(sizeof(Node));
        ptr->data = data;
        ptr->next = nullptr;
        *ref = ptr; // set ref to point to new head
    } else {
        while ((*ref)->next != nullptr) {
            *ref = (*ref)->next;
        }

        Node* ptr = (Node*)malloc(sizeof(Node));
        ptr->data = data;
        ptr->next = nullptr;
        (*ref)->next = ptr; // set ref to point to new head
    }
}

int LinkedList::pop(Node** ref) {
    if (ref == nullptr || *ref == nullptr) {
        return 0;
    }

    Node* newHead = (*ref)->next;
    int data = (*ref)->data;
    free(*ref);
    *ref = newHead;
    return data;
}

void LinkedList::deleteList(Node** headRef) {
    if (headRef == nullptr || *headRef == nullptr) {
        return;
    }

    Node* head = *headRef;
    while (head != nullptr) {
        Node* next = head->next;
        head->next = nullptr;
        free(head);
        head = next;
    }
}

void LinkedList::insertAtNth(Node** headRef, int data, int nth) {
    if (headRef == nullptr) {
        return;
    }

    if (*headRef == nullptr && nth > 0) {
        return;
    }

    Node* head = *headRef;

    // handle the case of an empty list and we're adding to the 0th position
    if (*headRef == nullptr && nth == 0) {
        Node* ptr = (Node*)malloc(sizeof(Node));
        ptr->data = data;
        ptr->next = nullptr;
        *headRef = ptr;
    }

    Node* previous = nullptr;
    int count = 0;
    while (head != nullptr) {
        if (count == nth) {
            Node* ptr = (Node*)malloc(sizeof(Node));
            ptr->data = data;
            ptr->next = head;
            previous->next = ptr;

            //(*ref)->next = ptr; // set ref to point to new head
        }
        previous = head;
        head = head->next;
        count++;
    }
}
