//
//  Card.cpp
//  pg6
//
//  Created by Alexander Irikura on 10/31/14.
//  Copyright (c) 2014 Alexander Irikura. All rights reserved.
//

#include "Card.h"
#include <string>
#include <iostream>

    int face;
    int suit;//triangles 3, squares 2, diamonds 1, circles 0

Card::Card(){
    face = 0;
    suit = 1;
}
Card::Card(int face, int suit){
    this->face = face;
    this->suit = suit;
}

    
int Card::getRank() const{
    return (15 * suit) + face;
}
    
bool Card::operator< (const Card & other) const{
    return this->getRank() < other.getRank();
}
std::string Card::getStringSuit(){
    switch (suit){
        case 0:
            return "Circles";
        case 1:
            return "Diamonds";
        case 2:
            return "Squares";
        case 3:
            return "Triangles";
        default:
            std::cout << "Suit doesn't exist." << std::endl;
            return "";
    }
}
void Card::printCard(){
    std::cout << getFace() << " of" << getStringSuit() << std::endl;
}
void Card::setFace(int face){
    if (face >=1  && face <= 15){
        this->face = face;
    }
    else {
        std::cout << "Face " << face << " not valid" << std::endl;
    }
}
void Card::setSuit(int suit){
    if (suit >= 0 && suit < 4){
        this->suit = suit;
    }
    else {
        std::cout << "Suit " << suit << " not valid" << std::endl;
    }
}

    
    

    
    
    
    
    
    
    
    
