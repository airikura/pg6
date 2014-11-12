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
    bool Card:: operator< (const Card & other) const {
        return this->getRank() < other.getRank();
    }


bool Card::operator==(const Card & other) const{
    return this->getRank() == other.getRank();
}

bool Card::operator!=(const Card & other) const{
    return !(this->getRank() == other.getRank());
}
std::string Card::getSuit(){
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



void makeLowerCase(std::string upper){
    for (std::string::iterator it = upper.begin(); it < upper.end(); it++){
        tolower(*it);
    }
}


void Card::print(){
    std::cout << getFace() << " of " << getSuit() << std::endl;
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

void Card::setSuit(std::string newSuit){
    bool first = true;
    for (std::string::iterator it = newSuit.begin(); it < newSuit.end(); it++){
        if (first){
            toupper(*it);
            first = false;
        }
        else {
            tolower(*it);
        }
    }
    if (newSuit == "Circles"){
        suit = 0;
    }
    else if (newSuit == "Diamonds"){
        suit = 1;
    }
    else if (newSuit == "Squares"){
        suit = 2;
    }
    else if (newSuit == "Triangles"){
        suit = 3;
    }
    else{
        suit = -1;
    }
}


    
    

    
    
    
    
    
    
    
    
