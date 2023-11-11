//
// Created by Martina Buccioni
//

#ifndef UNTITLED2_ITEM_H
#define UNTITLED2_ITEM_H



#include <string>

class Item {
public:
    enum class Gruppo {
        VERDURE,
        CARNE,
        FRUTTA,
        PESCE,
        CANCELLERIA,
        ROSTICCERIA,
        FORNO,
        LEGUMI,
        BEVANDE,
        DOLCI,
        ALTRO
    };

    Item(const std::string name, Gruppo group, int quantity, bool purchased = false)
            : name(name), group(group), quantity(quantity), purchased(purchased) {}

    const std::string getName() const { return name; }
    Gruppo getGroup() const { return group; }
    bool isPurchased() const { return purchased; }
    void setPurchased(bool isPurchased) { purchased = isPurchased; }
    int getQuantity() const { return quantity; }


private:
    std::string name;
    Gruppo group;
    bool purchased;
    int quantity;
};







#endif //UNTITLED2_ITEM_H
