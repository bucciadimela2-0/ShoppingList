//
// Created by Martina Buccioni
//

#include "CreatorList.h"


std::unique_ptr<ShoppingList> CreatorList::createList() {


    auto lista = std::unique_ptr<ShoppingList>(new ShoppingList());
    lista->addItem("Carote", Item::Gruppo::VERDURE,1);
    lista->addItem("Patate", Item::Gruppo::VERDURE, 10);
    lista->addItem("Cipolle", Item::Gruppo::VERDURE, 3);
    lista->addItem("Insalata", Item::Gruppo::VERDURE,1);
    lista->addItem("Pomodori",Item::Gruppo::VERDURE,10);
    return lista;
}

std::unique_ptr<User> CreatorList::createUser(ShoppingList* lista, const std::string& name) {

        auto user = std::unique_ptr<User>(new User(lista, name));
        user->displayList();
        return user;

}

