//
//  Card.h
//  pg6
//
//  Created by Alexander Irikura on 10/31/14.
//  Copyright (c) 2014 Alexander Irikura. All rights reserved.
//

#ifndef __pg6__Card__
#define __pg6__Card__

#include <stdio.h>
#include <string>

class Card{
    int face;
    int suit; /*triangles 3, squares 2, diamonds 1, circles 0*/
public:
Card():face(0),suit(-1){}; /*creates a new card with default values of face = 0 and suit = -1*/
Card(int newFace, int newSuit){setFace(newFace); setSuit(newSuit);}  /*creates a new card with values face = newface and suit = 
                                                                      newsuit*/
Card(int newFace, std::string newSuit){setFace(newFace); setSuit(newSuit);}
Card(const Card &other):face(other.face),suit(other.suit){}; /*copy constructor*/

//~Card();    /*destructor, no new memory allocated / pointers to manually destruct so nothing changed*/

int getFace() const {return face;}  /*returns the face*/

int getIntSuit() const {return suit;}  /*returns the suit (as int)*/

int getRank() const;    /*returns the rank out of 60, i.e. 1 <= rank <= 60, 60 being highest, returns -1 if card isn't valid*/

bool operator< (const Card & other) const;  /*overloaded '<' operator*, returns true when getRank() < other.getRank()*/
bool operator==(const Card & other) const; /*overloaded '==' operator, returns true when getRank() == other.getRank())*/
bool operator!=(const Card & other) const; /*overloaded '!' operator, returns true when getRank() != other.getRank()*/

std::string getSuit();    /*returns the suit as a string i.e. "Diamonds"*/
void print();
void makeLowerCase(std::string*&);
bool isValidCard() const;   //returns true if suit and num are valid
    
/*prints the card i.e. "4 of Circles"*/
private:

void setFace(int face);     /*sets the face to face assuming face is valid (1<= face <= 15)*/
void setSuit(int suit);     /*sets the suit to suit assuming suit is valid (0<= suit <= 3)*/
void setSuit(std::string suit);

};
#endif /* defined(__pg6__Card__) */
