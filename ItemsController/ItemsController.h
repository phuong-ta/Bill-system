#ifndef ITEMCONTROLLER_H
#define ITEMCONTROLLER_H

#define FILENAME "ItemsController/Item.txt"

#include "../Items/Item.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

class ItemController {
private:
    vector<Item> items;
    void saveItemsToFile();

public:
    // Constructor
    ItemController();

    // Function to show all items from txt file
    void showAllItems();

    // Function to add a new item and save it to txt file
    void addNewItem();

    // Function to update item price by ID
    void updateItemPrice();

    // Function to delete item by ID
    void deleteItem();

    // funtion to empty list
    void emptyList();

    // function to get product's price
    float getPriceByID(int id);

    // function to get name by id
    string getNameByID(int id);
};

#endif // ITEMCONTROLLER_H
