//
// Created by Martina Buccioni on 23/07/23.
//
#include <gtest/gtest.h>

#include "../ShoppingList.h"
#include "../User.h"
#include "../CreatorList.h"
#include "../User.cpp"
#include "../CreatorList.cpp"
#include "../ShoppingList.cpp"
// Test fixture per la classe ShoppingList
class ShoppingListTest : public ::testing::Test {
protected:
    // Inizializzazione comune per i test
    void SetUp() override {
        shoppingList.addItem("Latte", Item::Gruppo::BEVANDE, 1);
        shoppingList.addItem("Pane", Item::Gruppo::FORNO, 2);
        shoppingList.addItem("Diario", Item::Gruppo::CANCELLERIA, 3);
    }
    ShoppingList shoppingList;
};

// Test per addItem
TEST_F(ShoppingListTest, AddItem) {

    shoppingList.addItem("Mela", Item::Gruppo::FRUTTA, 5);
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

// Test per markItemAsPurchased
TEST_F(ShoppingListTest, MarkItemAsPurchased) {
// Segna un elemento esistente come acquistato
    shoppingList.markItemAsPurchased(0);
    ASSERT_TRUE(shoppingList.getItems()[0].isPurchased());
}

// Test per attach e detach
TEST_F(ShoppingListTest, AttachAndDetach) {
// Crea due observer
    User observer1(&shoppingList, "greg");
    User observer2(&shoppingList, "dalila");


    ASSERT_EQ(shoppingList.getObserverCount(), 2);

// Detach observer1
    shoppingList.detach(&observer1);
    ASSERT_EQ(shoppingList.getObserverCount(), 1);


}

// Test per getSize
TEST_F(ShoppingListTest, GetSize) {
// Verifica che la dimensione della lista sia corretta
    ASSERT_EQ(shoppingList.getSize(), 3);
}

// Test per Item
TEST(ItemTest, ItemMethods) {
// Creazione di un oggetto Item e verifica dei suoi metodi
    Item item("Lapis", Item::Gruppo::CANCELLERIA, 1, false);

    ASSERT_EQ(item.getName(), "Lapis");
    ASSERT_EQ(item.getGroup(), Item::Gruppo::CANCELLERIA);
    ASSERT_EQ(item.getQuantity(), 1);
    ASSERT_FALSE(item.isPurchased());

// Mark as purchased e verifica
    item.setPurchased(true);
    ASSERT_TRUE(item.isPurchased());
}



// Test fixture per la classe User
class UserTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Inizializzazione comune per i test, crea una nuova ShoppingList e User per ogni test
        shoppingList = std::make_unique<ShoppingList>();
        user = std::make_unique<User>(shoppingList.get(), "John");
    }

    std::unique_ptr<ShoppingList> shoppingList;
    std::unique_ptr<User> user;
};

// Test per User::update()
TEST_F(UserTest, UpdateTest) {
    // Aggiungi alcuni elementi alla ShoppingList
    shoppingList->addItem("Latte", Item::Gruppo::BEVANDE, 2);
    shoppingList->addItem("Pane", Item::Gruppo::FORNO, 1);

    // Cattura l'output della funzione update()
    ::testing::internal::CaptureStdout();

    // Richiama la funzione update() di User
    user->update();

    // Ottieni l'output catturato
    std::string output = ::testing::internal::GetCapturedStdout();

    // Output atteso (aggiorna con il nuovo formato della tua implementazione di displayList())
    std::string expectedOutput ="Lista aggiornata per lo user John:\nLista per lo user John:\n0. Latte - Quantit\xC3\xA0: 2 \n1. Pane - Quantit\xC3\xA0: 1 \n\n";

    // Assert che l'output sia uguale all'output atteso
    EXPECT_EQ(output, expectedOutput);
}



// Test per User::markItemAsPurchased()
TEST_F(UserTest, MarkItemAsPurchasedTest) {
    // Aggiungi alcuni elementi alla ShoppingList
    shoppingList->addItem("Latte", Item::Gruppo::BEVANDE, 2);
    shoppingList->addItem("Pane", Item::Gruppo::FORNO, 1);

    // Segna l'elemento con indice 0 come acquistato
    user->markItemAsPurchased(0);

    // Assert che l'elemento sia stato segnato come acquistato correttamente
     ASSERT_TRUE(shoppingList->getItem(0).isPurchased());
}

// Test per User::addItems()
TEST_F(UserTest, AddItemsTest) {
    // Aggiungi alcuni elementi alla ShoppingList
    shoppingList->addItem("Latte", Item::Gruppo::BEVANDE, 2);
    shoppingList->addItem("Pane", Item::Gruppo::FORNO, 1);

    // Aggiungi un nuovo elemento alla ShoppingList utilizzando User::addItems()
    Item newItem("Biscotti", Item::Gruppo::DOLCI, 3);
    user->addItems(*shoppingList, newItem);

    // Assert che il nuovo elemento sia stato aggiunto correttamente alla lista
     ASSERT_EQ(shoppingList->getSize(), 3);
}

// Test per User::removeItem()
TEST_F(UserTest, RemoveItemTest) {
    // Aggiungi alcuni elementi alla ShoppingList
    shoppingList->addItem("Latte", Item::Gruppo::BEVANDE, 2);
    shoppingList->addItem("Pane", Item::Gruppo::FORNO, 1);

    // Rimuovi l'elemento con indice 1 dalla ShoppingList utilizzando User::removeItem()
    user->removeItem(*shoppingList, 1);

    // Assert che l'elemento sia stato rimosso correttamente dalla lista
     ASSERT_EQ(shoppingList->getSize(), 1);
}



TEST(CreatorListTest, CreateListTest) {
    // Crea la lista usando il metodo createList()
    CreatorList creator;
    std::unique_ptr<ShoppingList> shoppingList = creator.createList();

    // Verifica che la lista non sia vuota
    EXPECT_TRUE(shoppingList != nullptr);

    // Verifica che la lista contenga gli elementi desiderati
    const std::vector<Item>& items = shoppingList->getItems();
    EXPECT_EQ(items.size(), 5);
    EXPECT_EQ(items[0].getName(), "Carote");
    EXPECT_EQ(items[1].getName(), "Patate");
    EXPECT_EQ(items[2].getName(), "Cipolle");
    EXPECT_EQ(items[3].getName(), "Insalata");
    EXPECT_EQ(items[4].getName(), "Pomodori");
}

TEST(CreatorListTest, CreateUserTest) {
    // Crea la lista e l'utente usando i metodi createList() e createUser()
    CreatorList creator;
    std::unique_ptr<ShoppingList> shoppingList = creator.createList();
    std::string userName = "John";
    std::unique_ptr<User> user = creator.createUser(shoppingList.get(), userName);

    // Verifica che l'utente non sia vuoto
    EXPECT_TRUE(user != nullptr);

    // Verifica che l'utente abbia il nome desiderato
    EXPECT_EQ(user->getName(), userName);
}





