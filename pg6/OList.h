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

class OList{
    
private: class Node{
    Node *next;
    std::string data;
    public:
    int size(Node *head){
        int size = 1;
        while (head->next != NULL){
            size++;
            head = head->next;
        }
        return size;
    }
    
    
    
    
    
    
    
    };
    
    
    
};

#endif /* defined(__pg6__OList__) */
