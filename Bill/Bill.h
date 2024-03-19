#pragma once

#include "../ItemsController/ItemsController.h"

class Bill {
private:
    int billID;
    vector <int> itemID;
    vector <int> itemQuantity;

public:
    // Constructors
    Bill() : billID(0) {}

    // Overloaded << operator to display Bill
    friend ostream& operator<<(ostream& os, const Bill& bill);

    // Overloaded >> operator to input Bill
    friend istream& operator>>(istream& is, Bill& bill);

};
