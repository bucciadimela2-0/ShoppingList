
#include "CreatorList.h"
#include "ShoppingList.h"
#include "User.cpp"
#include "CreatorList.cpp"
#include "ShoppingList.cpp"
#include "User.h"
#include <iostream>
#include <vector>
#include <memory>

int main(int argc, char *argv[]) {

    //CreatorList creator;
    std::unique_ptr<ShoppingList> shoppingList = std::make_unique<ShoppingList>() ;

    std::string userName = "John";
    std::string userName2 = "Dalia";



    std::unique_ptr<User> user = std::make_unique<User>(shoppingList.get(), userName);
    std::unique_ptr<User> user2 = std::make_unique<User>(shoppingList.get(), userName2);

    shoppingList->addItem("Carote", Item::Gruppo::VERDURE,1);
    shoppingList->addItem("Patate", Item::Gruppo::VERDURE, 10);
    shoppingList->addItem("Cipolle", Item::Gruppo::VERDURE, 3);
    shoppingList->addItem("Insalata", Item::Gruppo::VERDURE,1);
    shoppingList->addItem("Pomodori",Item::Gruppo::VERDURE,10);

    Item item1("Latte", Item::Gruppo::BEVANDE, 2);
    Item item2("Pane", Item::Gruppo::FORNO, 1);
    Item item3("Biscotti", Item::Gruppo::FORNO, 3);

    user->addItems(*shoppingList,item1);
    user->addItems(*shoppingList,item2);
    user->addItems(*shoppingList,item3);
    // Mostra la lista della spesa prima e dopo aver segnato gli elementi come acquistati
    std::cout << "Lista della spesa iniziale:" << std::endl;
    user->displayList();

    // Segnamo come acquistati alcuni elementi della lista
    user->markItemAsPurchased(0); // Segna come acquistato il primo elemento
    user->markItemAsPurchased(2); // Segna come acquistato il terzo elemento

    std::cout << "Lista della spesa dopo gli acquisti:" << std::endl;
    user->displayList();




}




