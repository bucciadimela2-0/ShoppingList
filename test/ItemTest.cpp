//
// Created by Martina Buccioni on 13/11/23.
//

#include <gtest/gtest.h>
#include "../Item.h"

class ItemTest : public ::testing::Test {
protected:
    // Puoi aggiungere eventuali inizializzazioni comuni necessarie per tutti i tuoi test
    void SetUp() override {
        // Inizializzazioni comuni per i test degli oggetti Item, se necessario
    }
};

// Test per Item
TEST_F(ItemTest, ItemMethods) {
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




