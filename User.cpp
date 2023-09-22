//
// Created by Martina Buccioni
#include "User.h"

User::User(ShoppingList* lista, const std::string& name) {
    this->lista = lista;
    this->name = name;
    lista->attach(this);
}

User::~User() {
    lista->detach(this);
}

void User::update() {
    // Display updated list
    std::cout << "Lista aggiornata per lo user " << name << ":" << std::endl;
    displayList();
}

void User::displayList() const {
    std::cout << "Lista per lo user " << name << ":" << std::endl;
    int i = 0;

    const std::vector<Item>& items = lista->getItems();

    for (const Item& item : items) {
        std::cout << i << ". " << item.getName() << " - Quantità: " << item.getQuantity()<<" ";
        if(item.isPurchased())
            std::cout<<" x " << std::endl;
        else
            std::cout<<std::endl;
        i++;
    }
    std::cout << std::endl;
}

void User::markItemAsPurchased(int index) {
    std::cout << "Elemento acquistato: " << std::endl;
    lista->markItemAsPurchased(index);
}

void User::createList(ShoppingList& lista, const std::vector<Item>& elementi) {
    lista.attach(this);
    for (const Item& elem : elementi) {
        lista.addItem(elem.getName(), elem.getGroup(), elem.getQuantity());
    }
}

void User::addItems(ShoppingList& lista, const Item& elem) {
    lista.addItem(elem.getName(), elem.getGroup(), elem.getQuantity());
    std::cout << "Elemento aggiunto alla lista della spesa" << std::endl;
}

void User::removeItem(ShoppingList &lista, int index) {

    lista.removeItem(index);
    std::cout << "Elemento rimosso dalla lista della spesa" << std::endl;
}
std::string User::getName(){
    return name;
}


