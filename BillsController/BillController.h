//
// Created by phuon on 21/03/2024.
//

#ifndef BILL_SYSTEMS_BILLCONTROLLER_H
#define BILL_SYSTEMS_BILLCONTROLLER_H
#include "../Bills/Bill.h"

class BillController {
private:
    struct Node {
        Bill data;
        Node* next;
    };

    Node* head;

public:
    BillController();
    ~BillController();

    void displayAllBills();
    void searchBillByID(int id) const;
    void showReport();
};


#endif //BILL_SYSTEMS_BILLCONTROLLER_H
