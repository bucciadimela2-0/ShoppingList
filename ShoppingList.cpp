//
// Created by Martina Buccioni
//


#include "ShoppingList.h"

void ShoppingList::addItem(const std::string& name, Item::Gruppo group, int quantity) {
    items.push_back(Item(name, group, quantity, false));
    notify();
}

void ShoppingList::removeItem(int index) {
    if (index >= 0 && index < items.size()) {
        items.erase(items.begin() + index);
        notify();
    }
}

void ShoppingList::markItemAsPurchased(int index) {
    if (index >= 0 && index < items.size()) {
        items[index].setPurchased(true);
        notify();
    }
}

void ShoppingList::attach(Observer* observer) {
    observers.push_back(observer);
}

void ShoppingList::detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void ShoppingList::notify() {
    for (auto observer : observers) {
        observer->update();
    }
}

const std::vector<Item>& ShoppingList::getItems() const {
    return items;
}

const Item& ShoppingList::getItem(int index) const {
    return items[index];
}

int ShoppingList::getSize() const {
    return items.size();
}

int ShoppingList::getObserverCount()  const {
    return observers.size();
}

