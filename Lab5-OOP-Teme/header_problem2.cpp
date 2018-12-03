#include "header_problem2.h"
#include <iostream>
#include <string>

using namespace std;

string Form::getName(){
    return this->name;
}

void Form::setName(string name){
	this->name = name;
}

string Form::getColor(){
        return this->color;
    }

void Form::setColor(string color){
        this->color = color;
        }

void Rectangle::setWidth(int width){
        this->width = width;
    }

int Rectangle::getWidth(){
        return this->width;
    }

void Rectangle::setHeight(int height){
        this->height = height;
    }

int Rectangle::getHeight(){
        return this->height;
    }

string Rectangle::getColor2(){
        return this->getColor();
    }

void Rectangle::setColor2(string color){
        setColor(color);
    }
