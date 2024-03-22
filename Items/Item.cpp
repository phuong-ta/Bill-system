#include "Item.h"

// Constructor
// Default constructor implementation
Item::Item() : id(0), name(""), price(0.0), tax_rate(0) {}

Item::Item(int itemId, const string& itemName, float itemPrice, int itemTax) : id(itemId), name(itemName), price(itemPrice),  tax_rate(itemTax){}

// Overloaded << operator to display Item
ostream& operator<<(ostream& os, const Item& item) {

    os << setw(5) << item.id << setw(25) << item.name << setw(25) << fixed << setprecision(2) << item.price << setw(25) << item.tax_rate;

    return os;
}

// Overloaded >> operator to input Item
istream& operator>>(istream& is, Item& item) {

    cout << "Enter Name: ";
    is.ignore();  // Clear the newline character from the buffer
    getline(is, item.name);

    while (item.price<=0 ) {
        cout << "Enter Price: ";
        is >> item.price;
    }

    while (item.tax_rate <= 0) {
        cout << "Enter Tax Rate: ";
        is >> item.tax_rate;
    }
    return is;
}

void Item::setID(int id) {
    this->id = id;
}
void Item::setName(string name) {
    this->name = name;
}
void Item::setPrice(float price) {
    this->price = price;
}
void Item::setTax(int tax_rate) {
    this->tax_rate = tax_rate;
}

int Item::getID() {
    return id;
}

string Item::getName() {
    return name;
}

float Item::getPrice() {
    return price;
}
int Item::getTax() {
    return tax_rate;
}