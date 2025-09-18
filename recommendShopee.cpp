// recommendShopee.cpp 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main() {
    srand(time(0)); // Seed random generator

    int choice;
    char again;

    string electronics[] = {"Smartphone", "Wireless Earbuds", "Power Bank", "Smartwatch"};
    string fashion[]     = {"T-Shirt", "Sneakers", "Backpack", "Sunglasses"};
    string home[]        = {"Blender", "Vacuum Cleaner", "Rice Cooker", "Air Fryer"};

    cout << "============================\n";
    cout << " Welcome to Shopee Assistant\n";
    cout << "============================\n";

    do {
        // Show menu
        cout << "\nChoose a category to shop:\n";
        cout << "1. Electronics\n";
        cout << "2. Fashion\n";
        cout << "3. Home & Living\n";
        cout << "Enter your choice (1-3): ";

        // Input validation
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number (1-3): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Random suggestion logic
        switch (choice) {
            case 1:
                cout << "Recommended Electronics: "
                     << electronics[rand() % 4] << endl;
                break;
            case 2:
                cout << "Recommended Fashion: "
                     << fashion[rand() % 4] << endl;
                break;
            case 3:
                cout << "Recommended Home & Living: "
                     << home[rand() % 4] << endl;
                break;
            default:
                cout << "Invalid category. Please select 1, 2, or 3." << endl;
        }

        // Ask if user wants to continue
        cout << "\nDo you want another suggestion? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nThank you for using Shopee Assistant! Happy shopping! 🛒\n";
    return 0;
}
