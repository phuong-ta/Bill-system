//
// Created by phuon on 21/03/2024.
//

#include "BillController.h"
#include <map> // Include for using map

BillController::BillController() : head(nullptr) {
    ifstream file(BILLFILENAME);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue; // Skip empty lines
            istringstream iss(line);
            int billID;
            iss >> billID;

            vector<int> itemIDs, itemQuantities;
            char separator;
            int id, quantity;
            while (iss >> id >> separator >> quantity) {
                itemIDs.push_back(id);
                itemQuantities.push_back(quantity);
            }

            // Create new Node and Bill object
            Node* newNode = new Node;
            newNode->data = Bill(billID, itemIDs, itemQuantities);
            newNode->next = nullptr;

            // Insert Node into linked list
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << BILLFILENAME << endl;
    }
}

BillController::~BillController() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void BillController::displayAllBills() {
    Node* current = head;
    cout <<setw(5) << "Bill ID" << setw(20) << "Total\n";
    while (current != nullptr) {
        current->data.showBillShort();
        current = current->next;
    }
}

void BillController::searchBillByID(int id) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.getBillID() == id) {
            // Found the bill, display its details using the overloaded << operator
            cout << current->data << endl;
            return;
        }
        current = current->next;
    }
    // If bill with specified ID is not found, display a message
    cout << "Bill with ID " << id << " not found." << endl;
}

void BillController::showReport() {
    map<int, int> itemTotal; // Use map instead of unordered_map

    Node* current = head;

    // Iterate through all bills in the linked list
    while (current != nullptr) {
        const vector<int>& itemIDs = current->data.getItemIDs();
        const vector<int>& itemQuantities = current->data.getItemQuantities();

        // Accumulate quantities for each ItemID
        for (size_t i = 0; i < itemIDs.size(); ++i) {
            itemTotal[itemIDs[i]] += itemQuantities[i];
        }

        current = current->next;
    }

    // Display the report
    cout << "Sale Report:" << std::endl;
    cout <<setw(5) << "ID" << setw(25) << "Name" << setw(20) << "Total Quantity" << endl;
    ItemController itemList;
    for (const auto& pair : itemTotal) {
        cout <<setw(5) << pair.first <<setw(25) << itemList.getNameByID(pair.first) <<setw(20) << pair.second << endl;
    }
    itemList.emptyList();
}