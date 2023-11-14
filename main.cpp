
#include "ShoppingList.h"
#include "User.cpp"
#include "ShoppingList.cpp"
#include "User.h"
#include <iostream>
#include <vector>
#include <memory>

int main(int argc, char *argv[]) {

    //CreatorList creator;


    std::shared_ptr<ShoppingList> shoppingList = std::make_shared<ShoppingList>(std::string("lista1"));
    std::shared_ptr<ShoppingList> shoppingList2 = std::make_shared<ShoppingList>(std::string("lista2"));

    std::string userName = "John";
    std::string userName2 = "Dalia";

    std::shared_ptr<User> user = std::make_shared<User>(userName);
    std::shared_ptr<User> user2 = std::make_shared<User>(userName2);

    Item item1("Carote", Item::Gruppo::VERDURE, 1);
    Item item2("Patate", Item::Gruppo::VERDURE, 10);
    Item item3("Cipolle", Item::Gruppo::VERDURE, 3);
    Item item4("Insalata", Item::Gruppo::VERDURE, 1);
    Item item5("Pomodori", Item::Gruppo::VERDURE, 10);
    shoppingList->addItem(item1);
    shoppingList->addItem(item2);
    shoppingList->addItem(item3);
    shoppingList->addItem(item4);
    shoppingList->addItem(item5);

    // Mostra la lista della spesa prima e dopo aver segnato gli elementi come acquistati
    std::cout << "Lista della spesa iniziale:" << std::endl;
    user->displayList(shoppingList);

    shoppingList2->addItem(item1);

    user->addNewList(shoppingList);
    user2->addNewList(shoppingList);

    user->addNewList(shoppingList2);

    Item item6("Latte", Item::Gruppo::BEVANDE, 2);
    Item item7("Pane", Item::Gruppo::FORNO, 1);
    Item item8("Biscotti", Item::Gruppo::FORNO, 3);


    user->addItems(shoppingList, item1);
    user->addItems(shoppingList, item2);
    user->addItems(shoppingList, item3);

    user->addItems(shoppingList2, item1);


// Segnamo come acquistati alcuni elementi della lista
    user->itemPurchased(shoppingList, 0); // Segna come acquistato il primo elemento
    user->itemPurchased(shoppingList, 2); // Segna come acquistato il terzo elemento

    user->itemPurchased(shoppingList2, 0);
    std::cout << "Lista della spesa dopo gli acquisti:" << std::endl;
    user->displayList(shoppingList);




}




