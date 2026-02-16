//Benigno BSCS1A

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    char again;

    do {
        const int PRODUCTS = 5;
        const int SALESPEOPLE = 4;

        double sales[PRODUCTS][SALESPEOPLE] = {0};

        int salesperson, product;
        double amount;
        char choice;

        do {
            cout << "\nEnter salesperson number (1-4): ";
            cin >> salesperson;

            cout << "Enter product number (1-5): ";
            cin >> product;

            cout << "Enter amount sold: ";
            cin >> amount;

            sales[product - 1][salesperson - 1] += amount;

            cout << "Add another sale? (Y/N): ";
            cin >> choice;

        } while (choice == 'Y' || choice == 'y');

        // Display Table
        cout << "\n\t\tSalesperson\n";
        cout << "Product\t1\t2\t3\t4\tTotal\n";

        double colTotals[SALESPEOPLE] = {0};
        double grandTotal = 0;

        for (int p = 0; p < PRODUCTS; p++) {
            double rowTotal = 0;

            cout << (p + 1) << "\t";

            for (int sp = 0; sp < SALESPEOPLE; sp++) {
                cout << sales[p][sp] << "\t";
                rowTotal += sales[p][sp];
                colTotals[sp] += sales[p][sp];
            }

            cout << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << "Total\t";
        for (int sp = 0; sp < SALESPEOPLE; sp++) {
            cout << colTotals[sp] << "\t";
        }
        cout << grandTotal << endl;

        cout << "\nRun again? (Y/N): ";
        cin >> again;

    } while (again == 'Y' || again == 'y');

    return 0;
}
