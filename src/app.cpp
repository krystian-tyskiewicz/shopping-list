#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string delimiter = " - ";
    string characterToDelete = "-";
    ifstream DefaultList("../files/default-list.txt");
    ofstream ShoppingList("../files/shopping-list.txt");
    string lineOfFile;

    cout << "************************************************************** \n";
    cout << "*** Press \"Enter\" to confirm the default value. \n";
    cout << "*** Provide "+ characterToDelete + " character to remove a product from the list. \n";
    cout << "************************************************************** \n";

    while (getline (DefaultList, lineOfFile)) {
        int delimiterIndex = lineOfFile.find(delimiter);
        string name = lineOfFile.substr(0, delimiterIndex);
        string quantity = lineOfFile.substr(delimiterIndex + delimiter.length(), lineOfFile.length());

        cout << name + " [" + quantity + "] " + "\n";
        
        string query;
        getline(cin, query);
        if (query.empty()) {
            query = quantity;
        }

        if (query != characterToDelete) {
            ShoppingList << name + delimiter + query + "\n";
        }
    }

    DefaultList.close();
    ShoppingList.close();
}
