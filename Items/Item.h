#ifndef ITEM_H
#define ITEM_H

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Item {
private:
    int id;
    string name;
    float price;
    int tax_rate;

public:
    // Constructor
    Item();
    Item(int itemId, const string& itemName, float itemPrice, int itemTax);

    // Overloaded << operator to display Item
    friend ostream& operator<<(ostream& os, const Item& item);

    // Overloaded >> operator to input Item
    friend istream& operator>>(istream& is, Item& item);

    void setID(int id);
    void setName(string name);
    void setPrice(float price);
    void setTax(int tax_rate);

    int getID();
    string getName();
    float getPrice();
    int getTax();
};

#endif // ITEM_H
