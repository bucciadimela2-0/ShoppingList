//
// Created by Martina Buccioni on 13/11/23.
//


#include <gtest/gtest.h>

#include "ShoppingList.cpp"
// Test fixture per la classe ShoppingList
class ShoppingListTest : public ::testing::Test {
protected:
    // Inizializzazione comune per i test
    void SetUp() override {

        //ShoppingList shoppingList(std::string("lista1"));
        Item item1("Latte", Item::Gruppo::BEVANDE, 2);
        Item item2("Pane", Item::Gruppo::FORNO, 1);
        Item item3("Diario", Item::Gruppo::CANCELLERIA, 3);
        shoppingList.addItem(item1);
        shoppingList.addItem(item2);
        shoppingList.addItem(item3);

    }

ShoppingList shoppingList = ShoppingList(std::string("lista1"));

};

// Test per addItem
TEST_F(ShoppingListTest, AddItem) {

    Item item4("Mela", Item::Gruppo::FRUTTA, 5);
    shoppingList.addItem(item4);

    ASSERT_EQ(shoppingList.getSize(), 4);
}

// Test per removeItem
TEST_F(ShoppingListTest, RemoveItem) {
// Rimuovi un elemento esistente
shoppingList.removeItem(1);
ASSERT_EQ(shoppingList.getSize(), 2);

// Rimuovi un elemento non esistente
shoppingList.removeItem(10);
ASSERT_EQ(shoppingList.getSize(), 2);
}

// Test per itemPurchased
TEST_F(ShoppingListTest, MarkItemAsPurchased) {
// Segna un elemento esistente come acquistato
shoppingList.itemPurchased(0);
ASSERT_TRUE(shoppingList.getItems()[0].isPurchased());
}

// Test per attach e detach
TEST_F(ShoppingListTest, AttachAndDetach) {
    // Crea due observer

    User observer1(std::string("greg"));
    User observer2(std::string("dalila"));

    observer1.addNewList(&shoppingList);
    observer2.addNewList(&shoppingList);
    // Verifica che l'observer sia stato aggiunto correttamente
    ASSERT_EQ(shoppingList.getObserver().size(), 2);

    // Detach observer1
    observer1.removeList(&shoppingList);

    // Verifica che l'observer sia stato rimosso correttamente
    ASSERT_EQ(shoppingList.getObserver().size(), 1);
}


// Test per getSize
TEST_F(ShoppingListTest, GetSize) {
// Verifica che la dimensione della lista sia corretta
ASSERT_EQ(shoppingList.getSize(), 3);
}