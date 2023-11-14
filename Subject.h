//
// Created by Martina Buccioni on 21/07/23.
//

#ifndef UNTITLED2_SUBJECT_H
#define UNTITLED2_SUBJECT_H


#include "Observer.h"
#include "Item.h"

class Subject {
public:
    virtual void attach(std::shared_ptr<Observer> observer) = 0;
    virtual void detach(std::shared_ptr<Observer> observer) = 0;
    virtual void notify() = 0;
    virtual ~Subject() = default;

};


#endif //UNTITLED2_SUBJECT_H
