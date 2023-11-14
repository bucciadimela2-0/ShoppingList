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
    std::vector<std::shared_ptr<ShoppingList>> liste;
    std::string name;

public:
    User(const std::string& name);
    ~User();

    void update(std::string listName) override;

    void displayList(std::shared_ptr<ShoppingList> lista) const;
    void itemPurchased(std::shared_ptr<ShoppingList> lista, int index);
    static void addItems(std::shared_ptr<ShoppingList> lista,const Item& item);
    void removeItem(std::shared_ptr<ShoppingList> lista, int index);
    void createList(std::shared_ptr<ShoppingList> lista, const std::vector<Item>& elementi);
    void addNewList(std::shared_ptr<ShoppingList> lista);
    void removeList(std::shared_ptr<ShoppingList> lista);




};



#endif //UNTITLED2_USER_H
