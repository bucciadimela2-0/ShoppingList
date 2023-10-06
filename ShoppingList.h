//
// Created by Martina Buccioni on 22/07/23.
//

#ifndef UNTITLED2_SHOPPINGLIST_H
#define UNTITLED2_SHOPPINGLIST_H


#include <vector>
#include <iostream>
#include "Observer.h"
#include "Subject.h"

class ShoppingList : public Subject {


private:
    std::vector<Item> items;
    std::vector<Observer*> observers;

public:
    void addItem(const std::string& name, Item::Gruppo group, int quantity);
    void removeItem(int index);
    void markItemAsPurchased(int index);
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify();
    const std::vector<Item>& getItems() const;
    int getSize() const;
    int getObserverCount() const;

    const Item &getItem(int index) const;
};



#endif //UNTITLED2_SHOPPINGLIST_H
