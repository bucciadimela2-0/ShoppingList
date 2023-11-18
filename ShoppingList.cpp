//
// Created by Martina Buccioni
//


#include "ShoppingList.h"

void ShoppingList::addItem(const Item& item) {
    items.push_back(item);
    notify();
}

void ShoppingList::removeItem(int index) {
    if (index >= 0 && index < items.size()) {
        items.erase(items.begin() + index);
        notify();
    }
}

void ShoppingList::itemPurchased(int index) {
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
    for (auto& observer : observers) {
        observer->update(this->getListName());
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

std::string ShoppingList::getListName() const {
    return name;
}

int ShoppingList::getUnboughtQuantity() const {
    int totalUnboughtQuantity = 0;
    for (const auto& item : items) {
        if (!item.isPurchased()) {
            totalUnboughtQuantity += 1;
        }
    }
    return totalUnboughtQuantity;
}

 std::vector<Observer *> ShoppingList:: getObserver() {
    return observers;
};



