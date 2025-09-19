// recommendShopee.cpp 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <iomanip> // for fixed and setprecision
using namespace std;

// Define a struct for items
struct Item {
    string name;
    string description;
    double basePrice; // base price to randomize from
};

double randomPrice(double base) {
    // Generate a random price within ±20% of the base price
    double factor = 0.8 + (rand() % 41) / 100.0; // 0.8 to 1.2
    return base * factor;
}

int main() {
    srand(time(0)); // Seed random generator

    int choice;
    char again;

    // Arrays of items with descriptions and base prices
    Item electronics[] = {
        {"Smartphone", "Stay connected with the latest high-performance smartphone.", 1500},
        {"Wireless Earbuds", "Enjoy music anywhere with compact, noise-cancelling earbuds.", 250},
        {"Power Bank", "Keep your devices charged on the go with a portable power bank.", 120},
        {"Smartwatch", "Track your fitness and notifications with a modern smartwatch.", 800}
    };

    Item fashion[] = {
        {"T-Shirt", "Casual and comfortable cotton T-shirt for everyday wear.", 40},
        {"Sneakers", "Trendy sneakers perfect for style and comfort.", 200},
        {"Backpack", "Durable backpack with spacious compartments for daily use.", 150},
        {"Sunglasses", "Stylish UV-protection sunglasses for outdoor activities.", 100}
    };

    Item home[] = {
        {"Blender", "Make smoothies and sauces quickly with a powerful blender.", 300},
        {"Vacuum Cleaner", "Keep your home spotless with an efficient vacuum cleaner.", 600},
        {"Rice Cooker", "Cook fluffy rice easily with this user-friendly rice cooker.", 180},
        {"Air Fryer", "Enjoy crispy meals with less oil using a modern air fryer.", 400}
    };

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
        // Random suggestion logic
        int index;
        switch (choice) {
            case 1:
                index = rand() % 4;
                cout << "Recommended Electronics: " 
                     << electronics[index].name << "\n"
                     << "   " << electronics[index].description << "\n"
                     << "   Price: RM " << fixed << setprecision(2) 
                     << randomPrice(electronics[index].basePrice) << endl;
                break;
            case 2:
                index = rand() % 4;
                cout << "Recommended Fashion: " 
                     << fashion[index].name << "\n"
                     << "   " << fashion[index].description << "\n"
                     << "   Price: RM " << fixed << setprecision(2) 
                     << randomPrice(fashion[index].basePrice) << endl;
                break;
            case 3:
                index = rand() % 4;
                cout << "Recommended Home & Living: " 
                     << home[index].name << "\n"
                     << "   " << home[index].description << "\n"
                     << "   Price: RM " << fixed << setprecision(2) 
                     << randomPrice(home[index].basePrice) << endl;
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
