//
// Created by Martina Buccioni on 21/07/23.
//

#ifndef UNTITLED2_OBSERVER_H
#define UNTITLED2_OBSERVER_H


#include "ShoppingList.h"

class Observer {
    public:
        virtual void update(std::string name) = 0;
        virtual ~Observer() = default;
};



#endif //UNTITLED2_OBSERVER_H
