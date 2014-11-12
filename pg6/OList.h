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

template <class T>
class OList{
    /* need to write:
     get
     count
     copy constructor
     destructor
     uniquify
     */
private: class Node{
    Node *next;
    T data;
    friend class OList;
public:
    Node(){
    }
    ~Node(){
       // delete next;
    }
    Node(Node * next,  T data){
        this->next = next;
        this->data = data;
    }
    
    void setNext(Node * next){
        this->next = next;
    }
    
    void setData(T data){
        this->data = data;
    }
    
    Node* getNext(){
        return next;
    }
    
    T getData(){
        return this->data;
    }
    
};
private:
    Node * head;
public:
    /*returns the size of the list*/
    OList<T>(){
        head = NULL;
        
    }
    ~OList<T>(){
        Node * temp = head;
        while (head != NULL){
            temp = head->next;
            delete head;
            head = temp;
        }
    }
    
    OList<T> (const OList<T>&other){
        head = NULL;
        long size = other.size();
        Node * temp = other.head;
        for (int i = 0; i < size; i++){
            this->addFront(temp->getData());
            temp = temp->next;
        }
    }
    
    /*returns the size of the list*/
    long size() const{
        Node * temp = head;
        long size = 0;
        while (temp){
            size++;
            temp = temp->next;
        }
        return size;
    }
    
    /*gets and returns a node at position position*/
    Node * get(int position){
        Node * temp = head;
        while (position > 1){
            temp = temp->next;
            position--;
        }
    }
    
    /*counts and returns the number of occurences of data in the list*/
    int count(T data){
        Node *temp = head;
        int counter = 0;
        while (temp){
            if (temp->getData() == data){
                counter++;
            }
            temp = temp->getNext();
        }
        return counter;
    }
    
    /*clears the list of any duplicates*/
    void uniquify(){
        return uniquifyHelper(head);
    }
    /*helper method for uniquify*/
    void uniquifyHelper(Node * head){
        if (!head){
            return;
        }
        Node * curr = head;
        Node * prev = NULL;
        T data = curr->data;
        while (curr){
            prev = curr;
            curr = curr->getNext();
            if (!curr){
                return uniquifyHelper(head->next);
            }
            if (curr->getData() == data){
                if (prev == NULL){
                  head = curr->getNext();
                }
                else {
                    prev->setNext(curr->getNext());
                }
                curr->setNext(NULL);
                delete curr;
            }
        }
    }
    
    /*prints the list, only works when class T has print() method declared*/
    void printList(){
        Node * temp = head;
        while (temp!= NULL){
                temp->data.print();
                temp = temp->next;
        }
    }
    /*prints the list in reverse, only works when class T has print() method declared*/
    void printReverse(){
        printReverseHelper(head);
    }
    /*helper method for printReverse*/
    void printReverseHelper(Node * head){
        if (head){
            printReverseHelper(head->next);
        }
        head->data.print();
    }
     /*add a node to the front of the list*/
    void addFront(T val){
        if (head){
        Node *np = new Node(head, val);
        head = np;
        }
        else {
            head = new Node(NULL, val);
        }
    }

    void addTail(T val){
        Node *np = new Node(NULL, val);
        if (head == NULL){
            head = np;
        }
        else {
            Node *temp = head;
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->setNext(np); // may be wrong
        }
    }
    /*delete a node with data == val and return its index*/
    int deleteNode(T val){
        Node * curr = head;
        Node * prev = NULL;
        while (curr && curr->getData() != val){
            prev = curr;
            curr = curr->getNext();
        }
        if (!curr){
            return 0;
        }
        else if (prev == NULL){
            head = curr->getNext();
        }
        else {
            prev->setNext(curr->getNext());
        }
        curr->setNext(NULL);
        free(curr);
        return 1;
    }
    /*clear the entire list and free memory*/
    void clearList(){
        clearListHelper(&head);
    }
    /*helper method for clearList()*/
    void clearListHelper(Node ** lptr){
        if (*lptr != NULL){
            clearListHelper(&(*lptr)->next);
        }
        free(*lptr);
        *lptr = NULL;
    }
    /*find the node with data == val and return it*/
    Node * find(T val){
        Node * temp = head;
        while (temp && temp->getData()!= val){
            temp = temp->getNext();
        }
        return temp;
    }
    /*find the node with data oldVal and set data = newVal,
     returns the new Node*/
    int replace(T oldVal, T newVal){
        Node * found = find(oldVal);
        if (found){
            found->setData(newVal);
            return 1;
        }
        else {
            return 0;
        }
    }
    /*inserts the node in order (based on val) assuming the list is order*/
    Node * insert (const T val){
        return insertHelper(&head, val);
    }
    /*helper method for insert*/
    Node * insertHelper(Node **lptr, T val){
        if (*lptr == NULL){
            *lptr = new Node(NULL, val); //if head is null, set head node with val and next = null
            return *lptr;
        }
        else if ((*lptr)->getData() == val){  //else if node with data == val already exists return null
            return NULL;
        }
        else if (val < (*lptr)->getData()){     //if val is less than lptr.data, insert the node
            Node * np = new Node(*lptr, val);
            *lptr = np;
            return np;
        }
        else {
            return insertHelper(&((*lptr)->next), val);
        }
    }
    
    
    
    
    
};

#endif /* defined(__pg6__OList__) */
