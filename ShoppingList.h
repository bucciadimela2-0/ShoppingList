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
        std::string name;

    public:
        ShoppingList(const std::string& name) : name(name) {};

        void addItem(const Item& item);
        void removeItem(int index);
        void itemPurchased(int index);
        void attach(Observer* observer) override;
        void detach(Observer* observer) override;
        void notify() override;
        const std::vector<Item>& getItems() const;
        int getSize() const;
        std::string getListName() const;
        int getUnboughtQuantity() const;
        const Item& getItem(int index) const;
        std::vector<Observer *> getObserver();

};




#endif //UNTITLED2_SHOPPINGLIST_H
