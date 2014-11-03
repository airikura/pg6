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
    int suit;//triangles 3, squares 2, diamonds 1, circles 0
    
Card();
Card(int, int);

~Card();

int getFace() const {return face;}

int getSuit() const {return suit;}

int getRank() const;

bool operator< (const Card & other) const;
std::string getStringSuit();
void printCard();
void setFace(int face);
void setSuit(int suit);

};
#endif /* defined(__pg6__Card__) */
