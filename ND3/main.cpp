#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MENU_SIZE = 8;
const double PVM = 0.21;

struct menuItemType {
    string menuItem;     // patiekalo pavadinimas
    double menuPrice;    // patiekalo kaina
};

// Funkcija nuskaito meniu duomenis is menu.txt failo
void getData(menuItemType menuList[], int& menuCount) {
    ifstream file("menu.txt");

    if (!file) {
        cout << "Klaida: nepavyko atidaryti menu.txt failo." << endl;
        return;
    }

    string line;
    menuCount = 0;

    while (getline(file, line) && menuCount < MENU_SIZE) {
        size_t separator = line.find(';');

        if (separator != string::npos) {
            menuList[menuCount].menuItem = line.substr(0, separator);
            menuList[menuCount].menuPrice = stod(line.substr(separator + 1));
            menuCount++;
        }
    }

    file.close();
}

// Funkcija parodo pusryciu meniu vartotojui
void showMenu(menuItemType menuList[], int menuCount) {
    cout << "Sveiki atvyke i restorana \"Jusras\"" << endl << endl;
    cout << "Pusryciu meniu:" << endl;

    cout << fixed << setprecision(2);

    for (int i = 0; i < menuCount; i++) {
        cout << i + 1 << ". "
             << left << setw(45) << menuList[i].menuItem
             << right << setw(6) << menuList[i].menuPrice << " EUR" << endl;
    }

    cout << endl;
    cout << "Pasirinkite patiekalo numeri ir porciju kieki." << endl;
    cout << "Jei norite baigti uzsakyma, iveskite 0." << endl << endl;
}

// Funkcija apskaiciuoja saskaita, isveda i ekrana ir iraso i receipt.txt
void printCheck(menuItemType menuList[], int menuCount, int portions[]) {
    ofstream receipt("receipt.txt");

    if (!receipt) {
        cout << "Klaida: nepavyko sukurti receipt.txt failo." << endl;
        return;
    }

    double subtotal = 0;

    cout << endl;
    cout << "Sveiki atvyke i restorana \"Pavadinimas\"" << endl << endl;

    receipt << "Sveiki atvyke i restorana \"Pavadinimas\"" << endl << endl;

    cout << fixed << setprecision(2);
    receipt << fixed << setprecision(2);

    for (int i = 0; i < menuCount; i++) {
        if (portions[i] > 0) {
            double itemTotal = portions[i] * menuList[i].menuPrice;
            subtotal += itemTotal;

            cout << left << setw(3) << portions[i]
                 << setw(45) << menuList[i].menuItem
                 << right << setw(7) << itemTotal << " EUR" << endl;

            receipt << left << setw(3) << portions[i]
                    << setw(45) << menuList[i].menuItem
                    << right << setw(7) << itemTotal << " EUR" << endl;
        }
    }

    double tax = subtotal * PVM;
    double total = subtotal + tax;

    cout << endl;
    cout << left << setw(48) << "Mokesciai (21%)"
         << right << setw(7) << tax << " EUR" << endl;

    cout << left << setw(48) << "Galutine suma"
         << right << setw(7) << total << " EUR" << endl;

    receipt << endl;
    receipt << left << setw(48) << "Mokesciai (21%)"
            << right << setw(7) << tax << " EUR" << endl;

    receipt << left << setw(48) << "Galutine suma"
            << right << setw(7) << total << " EUR" << endl;

    receipt.close();

    cout << endl << "Saskaita issaugota faile receipt.txt" << endl;
}

int main() {
    menuItemType menuList[MENU_SIZE];
    int portions[MENU_SIZE] = {0};
    int menuCount = 0;

    getData(menuList, menuCount);

    if (menuCount == 0) {
        cout << "Meniu tuscias arba nepavyko nuskaityti duomenu." << endl;
        return 0;
    }

    showMenu(menuList, menuCount);

    int choice;
    int quantity;

    do {
        cout << "Iveskite patiekalo numeri: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > menuCount) {
            cout << "Tokio patiekalo nera. Bandykite dar karta." << endl;
        } else {
            cout << "Iveskite porciju kieki: ";
            cin >> quantity;

            if (quantity <= 0) {
                cout << "Porciju kiekis turi buti didesnis uz 0." << endl;
            } else {
                portions[choice - 1] += quantity;
                cout << "Patiekalas pridetas i uzsakyma." << endl;
            }
        }

        cout << endl;

    } while (choice != 0);

    printCheck(menuList, menuCount, portions);

    return 0;
}