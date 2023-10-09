//
// Created by Martina Buccioni on 22/07/23.
//

#ifndef UNTITLED2_USER_H
#define UNTITLED2_USER_H


#include <string>
#include <iostream>
#include "ShoppingList.h"

class User : public Observer {
private:
    ShoppingList* lista;
    std::string name;

public:
    User(ShoppingList* lista, const std::string& name);
    ~User();

    void update() override;

    void displayList() const;
    void markItemAsPurchased(int index);
    void addItems(ShoppingList& lista,const Item& item);
    void removeItem(ShoppingList& lista, int index);
    void createList(ShoppingList& lista, const std::vector<Item>& elementi);

    std::string getName();
};




#endif //UNTITLED2_USER_H
