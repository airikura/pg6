//
//  CardTest.cpp
//  pg6
//
//  Created by Alexander Irikura on 11/10/14.
//  Copyright (c) 2014 Alexander Irikura. All rights reserved.
//

#include <stdio.h>
#include "Card.h"
#include <vector>
#include <assert.h>
#include <iostream>
#include <string>

/* get rank: test for multiple values, including invalid cards */
/* less than operator should be valid because it's given to us, test a little anyway*/
/* test getStringSuit */
/* test set face with multiple values, including invalid cards */
/* same with set suit */

using std::cout;
using std::vector;
using std::endl;
using std::string;

void testGetRank();
void testIsValidCard();
void testPrint();
void testLessThan();
void testCopyConstructor();

int main(void){
    testGetRank();
    testIsValidCard();
    testPrint();
    testLessThan();
    testCopyConstructor();
    return 0;
}

void testLessThan(){
    vector<Card> Deck;
    for (int j = 0; j < 4; j++){
        for (int i =1; i < 16; i++){
            Deck.push_back(Card(i,j));
        }
    }
    Card largest = Card(15, 3); //largest possible valid card
    Card smallest = Card (1,0); //smallest possible valid card
    // go through deck except for first and last card, make sure largest is always greater than and
    //smallest is always less than every card
    for (vector<Card>::iterator it = Deck.begin() + 1; it != Deck.end() - 1; it++){
        assert((largest<(*it)) == false);
        assert((smallest<(*it)) == true);
    }
}

/*also tests '==' operator*/
void testCopyConstructor(){
    Card validCard = Card(1,0);
    Card validCard1 = Card(2,1);
    Card validCard2 = Card(10,2);
    Card validCard3 = Card(15, 3);
    Card newCard = Card(validCard);
    assert(newCard == validCard);
    
    newCard = Card(validCard1);
    assert(newCard == validCard1);
    
    newCard = Card(validCard2);
    assert(newCard == validCard2);
    
    newCard = Card(validCard3);
    assert(newCard == validCard3);
    
    
}

void testPrint(){
    Card validCard = Card(1,0);
    Card validCard1 = Card(2, 1);
    Card validCard2 = Card(10,2);
    Card validCard3 = Card(15, 3);
    Card invalidCard = Card(-1, 3);
    Card invalidCard1 = Card(-1, -1);
    Card invalidCard2 = Card(16, 4);
    
    string fillerLine = string(10, '*');
    cout << "Next line of input should be: '1 of Circles'"<< endl;
    validCard.print();
    cout << fillerLine << endl;
    cout << "Next line of input should be: '2 of Diamonds'"<< endl;
    validCard1.print();
    cout << fillerLine << endl;
    cout << "Next line of input should be: '10 of Squares'"<< endl;
    validCard2.print();
    cout << fillerLine << endl;
    cout << "Next line of input should be: '15 of Triangles'"<< endl;
    validCard3.print();
    cout << fillerLine << endl;
    
    cout << "Next line of input should be: '0 of Triangles'"<< endl;
    invalidCard.print();
    cout << fillerLine << endl;
    cout << "Next line of input should be: '0 of invalidsuit'"<< endl;
    invalidCard1.print();
    cout << fillerLine << endl;
    cout << "Next line of input should be: '0 of invalidsuit'"<< endl;
    invalidCard2.print();
    cout << fillerLine << endl;
    
}
/*tests isValidCard, also tests constructor / set methods because they are called by constructor*/
void testIsValidCard(){
    Card validCard = Card(1, 3);
    assert(validCard.isValidCard() == true);
    Card invalidCard = Card(-1, 3);
    Card invalidCard1 = Card(-1, -1);
    Card invalidCard2 = Card(16, 4);
    assert(invalidCard.isValidCard() == false);
    assert(invalidCard1.isValidCard() == false);
    assert(invalidCard2.isValidCard() == false);
   
    Card validStringCard = Card(1, "Triangles");
    assert(validStringCard.isValidCard() == true);
    Card invalidStringCard = Card(-1, "Triangles");
    Card invalidStringCard1 = Card(-1, "Hello");
    Card invalidStringCard2 = Card(16, "invalid");
    assert(invalidStringCard.isValidCard() == false);
    assert(invalidStringCard1.isValidCard() == false);
    assert(invalidStringCard2.isValidCard() == false);
    Card validStringCard3 = Card(1, "Triangles");
    Card validStringCard4 = Card(1, "Squares");
    Card validStringCard5 = Card(1, "Diamonds");
    Card validStringCard6 = Card(1, "Circles");
    assert(validStringCard3.isValidCard() == true);
    assert(validStringCard4.isValidCard() == true);
    assert(validStringCard5.isValidCard() == true);
    assert(validStringCard6.isValidCard() == true);
    
    
    
}

void testGetRank(){
    vector<Card> Deck;
    for (int j = 0; j < 4; j++){
        for (int i =1; i < 16; i++){
              Deck.push_back(Card(i,j));
        }
    }
    int counter = 1;
    // go through a deck of 60 cards and make sure each card has the right rank
    for (vector<Card>::iterator it = Deck.begin(); it != Deck.end(); it++){
        assert(it->getRank() == counter);
        counter++;
    }
    //test if constructor works correctly, which tests if setCard(int) and setFace(int) work correctly
    //also tests if getRank gets the correct rank for these
    Card invalidCard = Card(-10, 4);
    Card invalidCard1 = Card(16, -1);
    assert(invalidCard.getRank() == -1);
    assert(invalidCard1.getRank() == -1);
    invalidCard.print();
}



