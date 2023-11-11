cmake_minimum_required(VERSION 3.20)
set(CMAKE_OSX_SYSROOT  "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.0.sdk")
project(untitled4)




set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Aggiungi tutti i file sorgente al progetto
set(SOURCES
        main.cpp
        ShoppingList.cpp
        User.cpp
        CreatorList.cpp
        # Aggiungi qui eventuali altri file sorgente
        )

# Aggiungi tutti i file di intestazione al progetto
set(HEADERS
        ShoppingList.h
        User.h
        Subject.h
        Item.h
        CreatorList.h
        # Aggiungi qui eventuali altri file di intestazione
        )




find_package(Qt5 COMPONENTS
        Core
        REQUIRED)

add_executable(untitled4 main.cpp)

target_link_libraries(untitled4
        Qt5::Core
        )

#set(CMAKE_OSX_SYSROOT  "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.3.sdk")
# Sostituisci "/percorso/del/VulkanSDK" con il percorso effettivo del Vulkan SDK

#set(CMAKE_CXX_STANDARD 17)





# Esegui la definizione dell'eseguibile per l'applicazione principale
#add_executable(untitled2 ${SOURCES} ${HEADERS})

# Set the correct Qt5 installation path
#set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt@5/5.15.10" ${CMAKE_PREFIX_PATH})


set(GTest_ROOT "/usr/local/Cellar/googletest/1.13.0" CACHE PATH "Path to Google Test installation")


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
# Crea un target per gli eseguibili dei test
set(TEST_SOURCES
        test/testing.cpp
        test/run_tests.cpp
        )

add_executable(run_tests ${TEST_SOURCES}) #${SOURCES} ${HEADERS})

# Aggiungi la libreria di Google Test come dipendenza per l'eseguibile run_tests
target_link_libraries(run_tests PRIVATE ${GTEST_BOTH_LIBRARIES})

enable_testing()
add_test(NAME test COMMAND run_tests)