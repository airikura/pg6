//
//  OListTest.cpp
//  pg6
//
//  Created by Alexander Irikura on 11/10/14.
//  Copyright (c) 2014 Alexander Irikura. All rights reserved.
//

#include <stdio.h>
#include "OList.h"
#include "Card.h"
#include "assert.h"

using std::cout;
using std::endl;

void test1();
void test2();
void test3();

void test1String();
void test2String();
void test3String();

using std::cout;
using std::endl;

int main(void){
    test1();
    test1String();
    test2();
    test2String();
    test3();
    test3String();
}

/* NEED TO GET COPY CONSTRUCTOR AND DESTRUCTOR WORKING
 FIX WEIRD GLITCH WITH GCOVLIST AND COUNT ASSERT IN TEST3 NOT WORKING PROPERLY
 MAKE A TEST FOR COPY CONSTRUCTOR AND DESTRUCTOR
 */
void test1(){
    OList<Card> cardList= OList<Card>();
    
    cardList.addFront(Card(4,3));
    
    cardList.addFront(Card(15,0));
    cardList.addFront(Card(1,1));
    cardList.addFront(Card(9,2));
    cardList.printList();
    assert(cardList.find(Card(9,2)) != NULL);
    
    assert(cardList.size() == 4);
    
    cardList.clearList();
   
    assert(cardList.size() == 0);

    cardList.addTail(Card(4,3));
    cardList.addTail(Card(15,0));
    cardList.addTail(Card(1,1));
    cardList.addTail(Card(9,2));
    cardList.addTail(Card(6,1));
    assert(cardList.size() == 5);
    
    cardList.clearList();
    
    assert(cardList.size() == 0);
}

void test1String(){
    OList<std::string> cardList= OList<std::string>();
    cardList.addFront("hello");
    cardList.addFront("how are you");
    cardList.addFront("Please give me an 100 on this assignment");
    cardList.addFront("Thanks");
    assert(cardList.find("Please give me an 100 on this assignment") != NULL);
    
    assert(cardList.size() == 4);
    
    cardList.clearList();
    
    assert(cardList.size() == 0);
    
    cardList.addTail("hello");
    cardList.addTail("how are you");
    cardList.addTail("Please give me an 100 on this assignment");
    cardList.addTail("Thank you");
    cardList.addTail("Goodbye");
    assert(cardList.size() == 5);
    assert(cardList.find("hello") != NULL);

    cardList.clearList();
    
    assert(cardList.size() == 0);
}

//test insert, find, replace, delete
void test2(){
    OList<Card> cardList=OList<Card>();
    cardList.insert(Card(4,3));
    cardList.insert(Card(15,0));
    cardList.insert(Card(1,1));
    cardList.insert(Card(9,2));
    assert(cardList.size() == 4);
    
    assert(((cardList.find(Card(4,3)))->getData()).getRank()== 49);
    cardList.replace(cardList.find(Card(4,3))->getData(), Card(5,2));
    assert(cardList.find(Card(5,2)) != NULL);
    assert(cardList.find(Card(1,1)) != NULL);
    assert(cardList.find(Card(4,3)) == NULL);
    assert(cardList.find(Card(9,2)) != NULL);
    assert(cardList.find(Card(15,0)) != NULL);

    assert(cardList.size() == 4);
    
    
    cardList.deleteNode(Card(5,2));
    cardList.deleteNode(Card(15,0));
    
    assert(cardList.size() == 2);
    assert(cardList.find(Card(5,2)) == NULL);
    assert(cardList.find(Card(15,0)) == NULL);
    
    cardList.clearList();
    
    assert(cardList.size() == 0);
    
}

void test2String(){
    OList<std::string> cardList= OList<std::string>();
    cardList.insert("hello");
    cardList.insert("why am I up at 5am");
    cardList.insert("Please give me an 100 on this assignment");
    cardList.insert("thanks");
    
    assert(cardList.size() == 4);
    
    cardList.replace(cardList.find("hello")->getData(), "goodbye");
    assert(cardList.find("goodbye") != NULL);
    assert(cardList.find("Please give me an 100 on this assignment") != NULL);
    assert(cardList.find("hellO") == NULL);
    assert(cardList.find("why am I up at 5am") != NULL);
    assert(cardList.find("thanks") != NULL);
    
    assert(cardList.size() == 4);
    
    
    cardList.deleteNode("goodbye");
    cardList.deleteNode("thanks");
    
    assert(cardList.size() == 2);
    assert(cardList.find("goodbye") == NULL);
    assert(cardList.find("thanks") == NULL);
    
    cardList.clearList();
    
    assert(cardList.size() == 0);


}

void test3String(){
    OList<std::string> cardList=OList<std::string>();
    cardList.insert("good morning sir");
    cardList.insert("what shall I put in this list");
    cardList.insert("tototot");
    cardList.insert("good morning sir");
    cardList.addFront("good morning sir");
    cardList.addFront("tototot");
    cardList.addFront("final item");
    std::cout << cardList.count("good morning sir") << std::endl;
    assert(cardList.count("good morning sir") == 2);
    assert(cardList.count("tototot") == 2);
    assert(cardList.count("final item") == 1);
    assert(cardList.count("what shall I put in this list") == 1);
    
    cardList.uniquify();
    
    assert(cardList.count("tototot") == 1);
    assert(cardList.count("good morning sir") == 1);
    
    cardList.clearList();
    assert(cardList.count("good morning sir") == 0);
    cardList.uniquify(); //to make sure no errors when list is null
    
    
}

//test count, uniquify, destructor, copy constructor, 
void test3(){
    OList<Card> cardList=OList<Card>();
    cardList.insert(Card(4,3));
    cardList.insert(Card(15,0));
    cardList.insert(Card(1,1));
    cardList.insert(Card(9,2));
    cardList.addFront(Card(4,3));
    cardList.addFront(Card(4,3));
    cardList.addFront(Card(9,2));
    assert(cardList.count(Card(4,3)) == 3);
    assert(cardList.count(Card(9,2)) == 2);
    assert(cardList.count(Card(1,1)) == 1);
    assert(cardList.count(Card(0,0)) == 0);
    
    cardList.uniquify();
    
    cout << cardList.count(Card(4,3)) << endl;
    assert(cardList.count(Card(4,3)) == 1);
    assert(cardList.count(Card(9,2)) == 1);
    
    OList<Card> *cardList2 = new OList<Card>(cardList);
    
    assert(cardList2->count(Card(4,3)) == 1);
    assert(cardList2->count(Card(9,2)) == 1);
    delete cardList2;
    cout << cardList2 << endl;
    cardList.clearList();
    assert(cardList.count(Card(4,3)) == 0);
    cardList.uniquify();
    
    
    
    
    
    
}