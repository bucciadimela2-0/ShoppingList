//
// Created by Martina Buccioni


#include "User.h"

User::User(const std::string& name) : name(name) {}

User::~User() {

        for (auto &lista: liste) {
            lista->detach(shared_from_this());

    }
}

void User::update(const std::string listName) {
    for (const auto& shoppingList : liste) {
        if (shoppingList->getListName() == listName) {
            std::cout << "Lista aggiornata " << listName << " per lo user " << name << ":" << std::endl;
            displayList(shoppingList);
            return;
        }
    }
}

void User::displayList(std::shared_ptr<ShoppingList> lista) const {

    int i = 0;

    int remaining = lista->getUnboughtQuantity();
    std::cout << "Elementi dalla lista " << lista->getListName() << " mancanti da comprare: " << remaining << std::endl;
    const std::vector<std::shared_ptr<Item>> items = lista->getItems();

    for (const auto& itemPtr : items) {
        const Item& item = *itemPtr;
        std::cout << i << ". " << item.getName() << " - Quantità: " << item.getQuantity() << " ";
        if (item.isPurchased())
            std::cout << " x " << std::endl;
        else
            std::cout << std::endl;
        i++;
    }
    std::cout << std::endl;
}

void User::itemPurchased(std::shared_ptr<ShoppingList> lista, int index) {
    std::cout << "Elemento acquistato: " << std::endl;
    lista->itemPurchased(index);
}

void User::createList(std::shared_ptr<ShoppingList> lista, const std::vector<Item>& elementi) {
    lista->attach(shared_from_this());
    liste.push_back(lista);
    for (const Item& elem : elementi) {
        lista->addItem(elem);
    }
}

void User::addItems(std::shared_ptr<ShoppingList> lista,const Item& elem) {
    lista->addItem(elem);
    std::cout << "Elemento aggiunto alla lista della spesa " << lista->getListName()<< " "<< std::endl;
}

void User::removeItem(std::shared_ptr<ShoppingList> lista, int index) {
    lista->removeItem(index);
    std::cout << "Elemento rimosso dalla lista della spesa" << std::endl;
}

void User::addNewList(std::shared_ptr<ShoppingList> lista) {
    liste.push_back(lista);
    lista->attach(shared_from_this());
}

void User::removeList(std::shared_ptr<ShoppingList> lista) {
    liste.erase(std::remove(liste.begin(), liste.end(), lista), liste.end());
    lista->detach(shared_from_this());
}
