#pragma once

#include "../ItemsController/ItemsController.h"
#define BILLFILENAME "../Data/Bills.txt"

class Bill {
private:
    int billID;
    vector <int> itemID;
    vector <int> itemQuantity;
    float total;

public:
    // Constructors
    Bill() : billID(0) {}
    Bill(int id, const std::vector<int>& ids, const std::vector<int>& quantities);

    // Overloaded << operator to display Bill
    friend ostream& operator<<(ostream& os, const Bill& bill);

    // Overloaded >> operator to input Bill
    friend istream& operator>>(istream& is, Bill& bill);

    void appendBillToFile();
    void showBillShort() const;
    int getBillID() const;
    vector<int> getItemIDs() const;
    vector<int> getItemQuantities() const;
};