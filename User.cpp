//
// Created by Martina Buccioni


#include "User.h"

User::User(const std::string& name) : name(name) {}

User::~User() {

        for (auto &lista: liste) {
            lista->detach(this);

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

void User::displayList(const ShoppingList* lista) const {

    int i = 0;

    int remaining = lista->getUnboughtQuantity();
    std::cout << "Elementi dalla lista " << lista->getListName() << " mancanti da comprare: " << remaining << std::endl;
    const std::vector<Item> items = lista->getItems();

    for (const auto& itemPtr : items) {
        const Item& item = itemPtr;
        std::cout << i << ". " << item.getName() << " - Quantità: " << item.getQuantity() << " ";
        if (item.isPurchased())
            std::cout << " x " << std::endl;
        else
            std::cout << std::endl;
        i++;
    }
    std::cout << std::endl;
}

void User::itemPurchased(ShoppingList* lista, int index) {
    std::cout << "Elemento acquistato: " << std::endl;
    lista->itemPurchased(index);
}

void User::createList(ShoppingList* lista, const std::vector<Item>& elementi) {
    lista->attach(this);
    liste.push_back(lista);
    for (const Item& elem : elementi) {
        lista->addItem(elem);
    }
}

void User::addItems(ShoppingList* lista,const Item& elem) {
    lista->addItem(elem);
    std::cout << "Elemento aggiunto alla lista della spesa " << lista->getListName()<< " "<< std::endl;
}

void User::removeItem(ShoppingList* lista, int index) {
    lista->removeItem(index);
    std::cout << "Elemento rimosso dalla lista della spesa" << std::endl;
}

void User::addNewList(ShoppingList* lista) {
    liste.push_back(lista);
    lista->attach(this);
}

void User::removeList(ShoppingList* lista) {
        liste.erase(std::remove(liste.begin(), liste.end(), lista), liste.end());
        lista->detach(this);
    }

    void User ::getAllShoppingList() {

        std::cout<<"Liste per user "<<this->getUserName()<<"- "<<this->getNumShoppingList()<<std::endl;
        for (const auto& lista : liste) {
            std::cout << " - " << lista->getListName() << ": " << lista->getUnboughtQuantity() << " prodotti mancanti\n";
            }

}








