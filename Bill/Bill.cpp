#include "Bill.h"

// Constructor implementation
Bill::Bill(int id, const vector<int>& ids, const vector<int>& quantities)
        : billID(id), itemID(ids), itemQuantity(quantities), total(0.0) {
    ItemController itemList;
    for (int i = 0; i < itemID.size(); ++i) {
        total += itemList.getPriceByID(itemID[i]) * itemQuantity[i];
    }
}

int lastId() {
    ifstream file(BILLFILENAME);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << BILLFILENAME << std::endl;
        return -1; // return -1 to indicate error
    }

    int lineCount = 0;
    string line;
    while (getline(file, line)) {
        lineCount++;
    }

    file.close();
    return lineCount;
}

//show receipt
ostream& operator<<(ostream& os, const Bill& bill) {
    ItemController itemList;
    os << "Bill ID: " << bill.billID << "\nItems:\n";
    for (int i = 0; i < bill.itemID.size(); ++i) {
        os << setw(15) << itemList.getNameByID(bill.itemID[i])
           << setw(10) << fixed << setprecision(2) << itemList.getPriceByID(bill.itemID[i])
           << setw(10) << bill.itemQuantity[i]
           << setw(10) << fixed << setprecision(2) << itemList.getPriceByID(bill.itemID[i])* bill.itemQuantity[i]
           <<endl;
    }
    os << "Total: " << bill.total << endl;
    itemList.emptyList();
    return os;
}

// Overloaded >> operator to input Bill
istream& operator>>(istream& is, Bill& bill) {
    ItemController itemList;
    int itemId, itemQuantity;
    itemList.showAllItems();
    bill.billID = lastId()+1;
    while (true) {
        cout << "Enter product ID (0 to exit): ";
        cin >> itemId;
        if (itemId <= 0) {
            break;
        }
        else {
            bill.itemID.push_back(itemId);
            cout << "Enter quantity:(0 to remove product from bill) ";
            cin >> itemQuantity;
            if (itemQuantity <= 0) {
                bill.itemID.pop_back();
            }
            else {
                bill.itemQuantity.push_back(itemQuantity);
            }
        }
    }
    bill.total = 0;
    for (int i = 0; i < bill.itemID.size(); ++i) {
        bill.total += itemList.getPriceByID(bill.itemID[i]) * bill.itemQuantity[i];
    }
    itemList.emptyList();
    bill.appendBillToFile();
    return is;
}

void Bill::appendBillToFile() {
    // Open the file in append mode
    fstream file(BILLFILENAME, ios::app);

    if (file.is_open()) {
        if (itemID.empty()) {
            cerr << "No items to append to file." << endl;
            file.close();  // Close the file before returning
            return;
        }

        file << billID << " ";
        for (size_t i = 0; i < itemID.size(); ++i) {
            file << itemID[i] << ";" << itemQuantity[i];
            if (i != itemID.size() - 1)
                file << " ";
        }

        file << endl;
        file.close();
        cout << "Items saved to file successfully." << endl;
    }
    else {
        cerr << "Unable to open file for saving." << endl;
    }
}

void Bill::showBillShort() const {
    cout <<setw(5) << billID << setw(20) << total <<endl;
}

int Bill::getBillID() const {
    return billID;
}

vector<int> Bill::getItemIDs() const {
    return itemID;
}

vector<int> Bill::getItemQuantities() const{
    return itemQuantity;
}
