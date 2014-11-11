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




int Card::getRank() const{
    if (isValidCard()){
    return (15 * suit) + face;
    }
    return -1;
}
bool Card::operator< (const Card & other) const{
    return this->getRank() < other.getRank();
}

bool Card::operator==(const Card & other) const{
    return this->getRank() == other.getRank();
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
            //std::cout << "Invalid Suit" << std::endl;
            return "invalidsuit";
    }
}
bool Card::isValidCard() const{
    if ((suit == -1) || (face == 0)){
        return false;
    }
        return true;
}
void Card::printCard(){
    std::cout << getFace() << " of " << getStringSuit() << std::endl;
}
void Card::setFace(int newFace){
    if (newFace >=1  && newFace <= 15){
        this->face = newFace;
    }
    else {
        this->face = 0;
        std::cout << "Face " << newFace << " not valid" << std::endl;
    }
}
void Card::setSuit(int newSuit){
    if (newSuit >= 0 && newSuit < 4){
        this->suit = newSuit;
    }
    else {
        this->suit = -1;
        std::cout << "Suit " << newSuit << " not valid" << std::endl;
    }
}

    
    

    
    
    
    
    
    
    
    
