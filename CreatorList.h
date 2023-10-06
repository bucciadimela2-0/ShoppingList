//
// Created by Martina Buccioni on 22/07/23.
//

#ifndef UNTITLED2_CREATORLIST_H
#define UNTITLED2_CREATORLIST_H


#include <memory>
#include <string>
#include "ShoppingList.h"
#include "User.h"


class CreatorList {
public:
    std::unique_ptr<ShoppingList> createList();
    std::unique_ptr<User> createUser(ShoppingList* lista, const std::string& name);
};


#endif //UNTITLED2_CREATORLIST_H
