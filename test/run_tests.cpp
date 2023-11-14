//
// Created by Martina Buccioni on 30/07/23.
//

#include <gtest/gtest.h>

// Includi i file di test per le diverse classi
#include "UserTest.cpp"
#include "ShoppingListTest.cpp"
#include "ItemTest.cpp"

// Opzionale: definisci altri test specifici, se necessario

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



