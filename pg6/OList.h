//
//  OList.h
//  pg6
//
//  Created by Alexander Irikura on 11/1/14.
//  Copyright (c) 2014 Alexander Irikura. All rights reserved.
//

#ifndef __pg6__OList__
#define __pg6__OList__

#include <stdio.h>
#include <string>
#include <iostream>

class OList{
    
    
private: class Node{
    Node *next;
    std::string data;
    friend class OList;
public:
    
    Node(Node * next,  std::string data){
        this->next = next;
        this->data = data;
    }
    
    void setNext(Node * next){
        this->next = next;
    }
    
    void setData(std::string data){
        this->data = data;
    }
    
    Node* getNext(){
        return next;
    }
    
    std::string getData(){
        return this->data;
    }
    
};
private:
    Node * head;
    std::string data;
    
    /*returns the size of the list*/
    long size(){
        long size = 0;
        while (head){
            size++;
            head = head->next;
        }
        return size;
    }
    /*prints the list*/
    void printList(){
        while (head!= NULL){
                std::cout << head->data;
                head = head->next;
        }
    }
    /*prints the list recursively by calling printRecHelper*/
    void printRec(){
        printRecHelper(head);
    }
    /*helper method for printRec*/
    void printRecHelper(Node * head){
        if (head){
            std::cout << head->data;
            printRecHelper(head->next);
        }
    }
    /*prints the list in reverse*/
    void printReverse(){
        printReverseHelper(head);
    }
    /*helper method for printReverse*/
    void printReverseHelper(Node * head){
        if (head){
            printReverseHelper(head->next);
        }
        std::cout << head->data;
    }
     /*add a node to the front of the list*/
    void addFront(Node **lptr, std::string val){
        Node *np = new Node(*lptr, val);
        * lptr = np;
    }
    /*add a node recursively to the tail of the list*/
    void addTailR(std::string val){
        addTailRHelper(&head, val);
    }
    /*helper function for addTailR*/
    void addTailRHelper(Node **lptr, std::string val){
        if (*lptr == NULL){
            Node * np = new Node(NULL, val);
            *lptr = np;
        }
        else {
            addTailRHelper(&((*lptr)->next), val);
        }
    }
    /*add a node to the tail of the list*/

    void addTail(Node **lptr, std::string val){
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
    /*delete a node with data == val and return its index*/
    int deleteNode(Node **lptr, std::string val){
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
     /*recursively delete a node with data == val and return its index*/
    int deleteR(Node **lptr, std::string val){
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
    /*clear the entire list and free memory*/
    void clearList(Node **lptr){
        if (*lptr != NULL){
            clearList(&(*lptr)->next);
        }
        free(*lptr);
        *lptr = NULL;
    }
    /*find the node with data == val and return it*/
    Node * find(Node * head, std::string val){
        while (head && head-> getData()!= val){
            head = head->getNext();
        }
        return head;
    }
    /*find the node with data oldVal and set data = newVal,
     returns the new Node*/
    int replace(Node * head, std::string oldVal, std::string newVal){
        Node * found = find(head, oldVal);
        if (found){
            found->setData(newVal);
            return 1;
        }
        else {
            return 0;
        }
    }
    /*inserts the node in order (based on val) assuming the list is order*/
    Node * insert(Node **lptr, std::string val){
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
    
    
    
    
    
    
};

#endif /* defined(__pg6__OList__) */
