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
    public:
    
    Node(Node * next,  std::string data){
        Node * np;
        np->next = next;
        np->data = data;
    }
    long size(Node *head){
        long size = 0;
        while (head){
            size++;
            head = head->next;
        }
        return size;
    }
    
    void printList(Node * head){
        while (head!= NULL){
            std::cout << head->data;
            head = head ->next;
        }
    }
    
    void printRec(Node * head){
        if (head){
            std::cout << head->data;
            printRec(head->next);
        }
    }
    
    void addFront(Node **lptr, std::string val){
        Node *np = new Node(*lptr, val);
        * lptr = np;
    }
    
    void addTailR(Node **lptr, std::string val){
        if (*lptr == NULL){
            Node * np = new Node(NULL, val);
            *lptr = np;
        }
        else {
            addTailR(&((*lptr)->next), val);
        }
    }
    
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
            head-> next = np;
        }
    }
    
    int deleteNode(Node **lptr, std::string val){
        Node * curr = *lptr;
        Node * prev = NULL;
        while (curr && curr->data != val){
            prev = curr;
            curr = curr->next;
        }
        if (!curr){
            return 0;
        }
        else if (prev == NULL){
            *lptr = curr->next;
        }
        else {
            prev->next = curr->next;
        }
        curr->next = NULL;
        free(curr);
        return 1;
    }
    
    int deleteR(Node **lptr, std::string val){
        if (*lptr == NULL){
            return 0;
        }
        else if ((*lptr)->data == val){
            Node * curr = *lptr;
            *lptr = (*lptr)->next;
            free(curr);
            return 1;
        }
        else {
            return deleteR(&((*lptr)->next), val);
        }
    }
    
    void clearList(Node **lptr){
        if (*lptr != NULL){
            clearList(&(*lptr)->next);
        }
        free(*lptr);
        *lptr = NULL;
    }
    
    Node * find(Node * head, std::string val){
        while (head && head-> data!= val){
            head = head->next;
        }
        return head;
    }
    
    int replace(Node * head, std::string oldVal, std::string newVal){
        Node * found = find(head, oldVal);
        if (found){
            found->data = newVal;
            return 1;
        }
        else {
            return 0;
        }
    }
    
    Node * insert(Node **lptr, std::string val){
        if (*lptr == NULL){
            *lptr = new Node(NULL, val);
            return *lptr;
        }
        else if (*lptr-> data == val){
            
        }
    }
    
    
    };
    
    
    
};

#endif /* defined(__pg6__OList__) */
