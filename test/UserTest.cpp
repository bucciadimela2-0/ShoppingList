//
// Created by Martina Buccioni on 13/11/23.
//
#include <gtest/gtest.h>

#include "User.cpp"


// Test fixture per la classe User
class UserTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Inizializzazione comune per i test, crea una nuova ShoppingList e User per ogni test

        ShoppingList shoppingList(std::string("lista1"));
        User user("dalia");
        user.addNewList(&shoppingList);
    }

    ShoppingList shoppingList = ShoppingList(std::string("lista1"));
    User user = User("dalia");

};

// Test per User::update()
TEST_F(UserTest, UpdateTest) {
    Item item1("Latte", Item::Gruppo::BEVANDE, 2);
    Item item2("Pane", Item::Gruppo::FORNO, 1);
    user.addNewList(&shoppingList);
    // Aggiungi alcuni elementi alla ShoppingList
    shoppingList.addItem(item1);
    shoppingList.addItem(item2);

    // Cattura l'output della funzione update()
    ::testing::internal::CaptureStdout();

    // Richiama la funzione update() di User
    user.update(shoppingList.getListName());

    // Ottieni l'output catturato
    std::string output = ::testing::internal::GetCapturedStdout();

// Output atteso (aggiorna con il nuovo formato della tua implementazione di displayList())
std::string expectedOutput = "Lista aggiornata lista1 per lo user dalia:\nElementi dalla lista lista1 mancanti da comprare: 2\n0. Latte - Quantit\xC3\xA0: 2 \n1. Pane - Quantit\xC3\xA0: 1 \n\n";

// Assert che l'output sia uguale all'output atteso
EXPECT_EQ(output, expectedOutput);
}



TEST_F(UserTest, UnboughtProductTest){

    Item item1("Latte", Item::Gruppo::BEVANDE, 2);
    Item item2("Pane", Item::Gruppo::FORNO, 1);
    user.addNewList(&shoppingList);
// Aggiungi alcuni elementi alla ShoppingList
    shoppingList.addItem(item1);
    shoppingList.addItem(item2);
    ASSERT_EQ(shoppingList.getUnboughtQuantity(), 2);

    // Segna l'elemento con indice 0 come acquistato
    user.itemPurchased(&shoppingList, 0);
    ASSERT_EQ(shoppingList.getUnboughtQuantity(), 1);



};

// Test per User::itemPurchased()
TEST_F(UserTest, MarkItemAsPurchasedTest) {

    Item item1("Latte", Item::Gruppo::BEVANDE, 2);
    Item item2("Pane", Item::Gruppo::FORNO, 1);
    user.addNewList(&shoppingList);
// Aggiungi alcuni elementi alla ShoppingList
shoppingList.addItem(item1);
shoppingList.addItem(item2);

// Segna l'elemento con indice 0 come acquistato
user.itemPurchased(&shoppingList, 0);

// Assert che l'elemento sia stato segnato come acquistato correttamente
ASSERT_TRUE(shoppingList.getItem(0).isPurchased());
}

// Test per User::addItems()
TEST_F(UserTest, AddItemsTest) {

    Item item1("Latte", Item::Gruppo::BEVANDE, 2);
    Item item2("Pane", Item::Gruppo::FORNO, 1);
    user.addNewList(&shoppingList);
// Aggiungi alcuni elementi alla ShoppingList
shoppingList.addItem(item1);
shoppingList.addItem(item2);

// Aggiungi un nuovo elemento alla ShoppingList utilizzando User::addItems()
Item newItem("Biscotti", Item::Gruppo::DOLCI, 3);
user.addItems(&shoppingList, newItem);

// Assert che il nuovo elemento sia stato aggiunto correttamente alla lista
ASSERT_EQ(shoppingList.getSize(), 3);
}

// Test per User::removeItem()
TEST_F(UserTest, RemoveItemTest) {
// Aggiungi alcuni elementi alla ShoppingList
    Item item1("Latte", Item::Gruppo::BEVANDE, 2);
    Item item2("Pane", Item::Gruppo::FORNO, 1);
    user.addNewList(&shoppingList);
    shoppingList.addItem(item1);
    shoppingList.addItem(item2);

// Rimuovi l'elemento con indice 1 dalla ShoppingList utilizzando User::removeItem()
user.removeItem(&shoppingList, 1);

// Assert che l'elemento sia stato rimosso correttamente dalla lista
ASSERT_EQ(shoppingList.getSize(), 1);
}


// Test per User::removeItem()
TEST_F(UserTest, RemoveAndAddListTest) {
// Aggiungi alcuni elementi alla ShoppingList
    Item item1("Latte", Item::Gruppo::BEVANDE, 2);
    Item item2("Pane", Item::Gruppo::FORNO, 1);
    user.addNewList(&shoppingList);
    shoppingList.addItem(item1);
    shoppingList.addItem(item2);

    ShoppingList shoppingList2(std::string("lista2"));
    user.addNewList(&shoppingList2);
    shoppingList2.addItem(item1);
    shoppingList2.addItem(item2);

    ASSERT_EQ( user.getNumShoppingList(),2);

// Rimuovi l'elemento con indice 1 dalla ShoppingList utilizzando User::removeItem()
    user.removeList(&shoppingList2);

// Assert che l'elemento sia stato rimosso correttamente dalla lista
    ASSERT_EQ(user.getNumShoppingList(), 1);
}