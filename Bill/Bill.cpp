#include "Bill.h"

ostream& operator<<(ostream& os, const Bill& bill) {
    ItemController itemList;
    os << "Bill ID: " << bill.billID << "\nItems:\n";
    float total = 0;
    for (int i = 0; i < bill.itemID.size(); ++i) {
        os << setw(15) << itemList.getNameByID(bill.itemID[i]) 
            << setw(10) << fixed << setprecision(2) << itemList.getPriceByID(bill.itemID[i]) 
            << setw(10) << bill.itemQuantity[i] 
            << setw(10) << fixed << setprecision(2) << itemList.getPriceByID(bill.itemID[i])* bill.itemQuantity[i]
            <<endl;
        total += itemList.getPriceByID(bill.itemID[i]) * bill.itemQuantity[i];
    }

    os << "Total: " << total << endl;
    itemList.emptyList();
    return os;
}

// Overloaded >> operator to input Bill
istream& operator>>(istream& is, Bill& bill) {
    ItemController itemList;
    int itemId, itemQuantiry;
    itemList.showAllItems();
    cout << "Enter Bill ID: ";
    is >> bill.billID;
    
    while (true) {
        cout << "Enter product ID (0 to exit): ";
        cin >> itemId;
        if (itemId <= 0) {
            break;
        }
        else {
            bill.itemID.push_back(itemId);
            cout << "Enter quantity:(0 to remove product from bill) ";
            cin >> itemQuantiry;
            if (itemQuantiry <= 0) {
                bill.itemID.pop_back();
            }
            else {
                bill.itemQuantity.push_back(itemQuantiry);
            }
        }
    }
    itemList.emptyList();
    return is;
}
