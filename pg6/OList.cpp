//
//  OList.cpp
//  pg6
//
//  Created by Alexander Irikura on 11/1/14.
//  Copyright (c) 2014 Alexander Irikura. All rights reserved.
//

/* #include "OList.h"

long OList::size(){
    long size = 0;
    while (head){
        size++;
        head = head->next;
    }
    return size;
}

void OList::printList(){
    while (head!= NULL){
        std::cout << head->data;
        head = head->next;
    }
}

void OList::printRec(){
    printRecHelper(head);
}

void OList::printRecHelper(Node * head){
    if (head){
        std::cout << head->data;
        printRecHelper(head->next);
    }
}

void OList::printReverse(){
    printReverseHelper(head);
}

void OList::printReverseHelper(Node * head){
    if (head){
        printReverseHelper(head->next);
    }
    std::cout << head->data;
}

void OList::addFront(Node **lptr, std::string val){
    Node *np = new Node(*lptr, val);
    * lptr = np;
}


void OList::addTailR(std::string val){
    addTailRHelper(&head, val);
}

void OList::addTailRHelper(Node **lptr, std::string val){
    if (*lptr == NULL){
        Node * np = new Node(NULL, val);
        *lptr = np;
    }
    else {
        addTailRHelper(&((*lptr)->next), val);
    }
}

void OList::addTail(Node **lptr, std::string val){
    Node *np = new Node(NULL, val);
    if (*lptr == NULL){
        *lptr = np;
    }
    else {
        Node *head = *lptr;
        while (head->next != NULL){
            head = head->next;
        }
        head->setNext(np);
    }
}

int OList::deleteNode(Node **lptr, std::string val){
    Node * curr = *lptr;
    Node * prev = NULL;
    while (curr && curr->getData() != val){
        prev = curr;
        curr = curr->getNext();
    }
    if (!curr){
        return 0;
    }
    else if (prev == NULL){
        *lptr = curr->getNext();
    }
    else {
        prev->setNext(curr->getNext());
    }
    curr->setNext(NULL);
    free(curr);
    return 1;
}

int OList::deleteR(Node **lptr, std::string val){
    if (*lptr == NULL){
        return 0;
    }
    else if ((*lptr)->getData() == val){
        Node * curr = *lptr;
        *lptr = (*lptr)->getNext();
        free(curr);
        return 1;
    }
    else {
        return deleteR(&((*lptr)->next), val);
    }
}

void OList::clearList(Node **lptr){
    if (*lptr != NULL){
        clearList(&(*lptr)->next);
    }
    free(*lptr);
    *lptr = NULL;
}

OList::Node* OList::find(Node * head, std::string val){
    while (head && head-> getData()!= val){
        head = head->getNext();
    }
    return head;
}

int OList::replace(Node * head, std::string oldVal, std::string newVal){
    Node * found = find(head, oldVal);
    if (found){
        found->setData(newVal);
        return 1;
    }
    else {
        return 0;
    }
}

OList::Node * OList::insert(Node **lptr, std::string val){
    if (*lptr == NULL){
        *lptr = new Node(NULL, val);
        return *lptr;
    }
    else if ((*lptr)->getData() == val){
        return NULL;
    }
    else if ((*lptr)->getData() > val){
        Node * np = new Node(*lptr, val);
        *lptr = np;
        return np;
    }
    else {
        return insert(&((*lptr)->next), val);
    }
    
    
}
 */
