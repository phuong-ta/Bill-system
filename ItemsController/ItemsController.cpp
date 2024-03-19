#include "ItemsController.h"

// Constructor
ItemController::ItemController() {
    items.clear();
    Item currentItem;
	ifstream file(FILENAME);
	string line;

	if (file.is_open()) {
		// 'line' variable. 
        while (getline(file, line)) {
            istringstream iss(line);
            int id;
            string name;
            float price;
            int tax_rate;

            if (!(iss >> id >> name >> price >> tax_rate)) {
                cerr << "Error reading line: " << line << endl;
                continue;
            }

            Item item(id, name, price,tax_rate);
            items.push_back(item);
        }
		file.close();
	}
	else {
		// Print an error message to the standard error 
		// stream if the file cannot be opened. 
		cerr << "Unable to open file: " << FILENAME << "\n";
	}
}

// Function to save items to the txt file
void ItemController::saveItemsToFile() {
    ofstream outFile(FILENAME, ios::trunc);
    if (outFile.is_open()) {
        for ( auto& item : items) {
            outFile << setw(2) << item.getID() << setw(25) << item.getName() << setw(15) << fixed << std::setprecision(2) << item.getPrice() << setw(10) << item.getTax() << "\n";
        }
        outFile.close();
        cout << "Items saved to file successfully.\n";
    }
    else {
        cerr << "Unable to open file for saving.\n";
    }
}

// Function to show all items from txt file
void ItemController::showAllItems() {

    cout <<setw(5) << "ID" << setw(25) << "Name" << setw(25) << "Price" << setw(25) << "Tax Rate" << endl;
    cout << endl;
    for (auto& s : items) {
        cout << s;
        cout << endl;
    }
}

// Function to add a new item and save it to txt file
void ItemController::addNewItem() {
    cout << "addd new item;\n";
    // get Last product's id
    int lastID = items.back().getID();

    // new product'id = last product ID+1
    Item newItem;
    cin >> newItem;
    newItem.setID(lastID + 1);
    items.push_back(newItem);
    saveItemsToFile();
}

// Function to update item price by ID
void ItemController::updateItemPrice() {
    int id;
    cout << "Enter the ID of the item to update: ";
    cin >> id;

    auto it = find_if(items.begin(), items.end(), [id]( Item& item) {
        return item.getID() == id;
        });

    if (it != items.end()) {
        cout << "Enter the new price for item ID " << id << " ";
        float newPrice;
        cin >> newPrice;

        it->setPrice(newPrice);

        cout << "Item price updated successfully.\n";
    }
    else {
        cerr << "Item with ID " << id << " not found.\n";
    }
    saveItemsToFile();
}

// Function to delete item by ID
void ItemController::deleteItem() {
    cout << "delete item\n";
    int id;
    cout << "Enter the ID of the item to delete: ";
    cin >> id;
    items.erase(remove_if(items.begin(), items.end(), [id](Item& item) {return item.getID() == id; }), items.end());
    saveItemsToFile();
}

// clear list
void ItemController::emptyList() {
    items.clear();
}

float ItemController::getPriceByID(int id) {
    auto it = find_if(items.begin(), items.end(), [id](Item& item) {
        return item.getID() == id;
        });

    if (it != items.end()) {

        return it->getPrice();
    }
    else {
        cerr << "Item with ID " << id << " not found.\n";
        return NULL;
    }
}

string ItemController::getNameByID(int id) {
    auto it = find_if(items.begin(), items.end(), [id](Item& item) {
        return item.getID() == id;
        });

    if (it != items.end()) {

        return it->getName();
    }
    else {
        cerr << "Item with ID " << id << " not found.\n";
        return NULL;
    }
}
