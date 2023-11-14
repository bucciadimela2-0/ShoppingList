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
        std::vector<std::shared_ptr<Item>> items;
        std::vector<std::shared_ptr<Observer>> observers;
        std::string name;

    public:
        ShoppingList(const std::string& name) : name(name) {};

        void addItem(const Item& item);
        void removeItem(int index);
        void itemPurchased(int index);
        void attach(std::shared_ptr<Observer> observer) override;
        void detach(std::shared_ptr<Observer> observer) override;
        void notify() override;
        const std::vector<std::shared_ptr<Item>>& getItems() const;
        int getSize() const;
        std::string getListName() const;
        int getUnboughtQuantity() const;
        const std::shared_ptr<Item>& getItem(int index) const;
        std::vector<std::shared_ptr<Observer>> getObserver();
};




#endif //UNTITLED2_SHOPPINGLIST_H
