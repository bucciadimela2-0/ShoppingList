//
// Created by Martina Buccioni on 22/07/23.
//

#ifndef UNTITLED2_USER_H
#define UNTITLED2_USER_H


#include <string>
#include <iostream>
#include "ShoppingList.h"

class User : public Observer, public std::enable_shared_from_this<User>{
private:
    std::vector<ShoppingList*> liste;
    std::string name;

public:
    User(const std::string& name);
    ~User();

    void update(std::string listName) override;

    void displayList(const ShoppingList* lista) const;
    void itemPurchased(ShoppingList* lista, int index);
    static void addItems(ShoppingList* lista,const Item& item);
    void removeItem(ShoppingList* lista, int index);
    void createList(ShoppingList* lista, const std::vector<Item>& elementi);
    void addNewList(ShoppingList* lista);
    void removeList(ShoppingList* lista);
    int getNumShoppingList(){return liste.size();}
    void getAllShoppingList();
    std::string getUserName(){return name;}



};



#endif //UNTITLED2_USER_H
