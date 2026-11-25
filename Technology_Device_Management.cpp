#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

const int MAX = 50;
const int MONTHS = 3;

// 1D arrays
int id[MAX];
string name[MAX];
string category[MAX];
string condition[MAX];
int quantity[MAX];
double price[MAX];

// 2D array
double usage[MAX][MONTHS];

int count = 0;
int nextID = 1001;

// Clear input
void clearInput()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Find device
int searchID(int search)
{
    for (int i = 0; i < count; i++)
    {
        if (id[i] == search)
        {
            return i;
        }
    }

    return -1;
}

// Add device
void addDevice()
{
    if (count == MAX)
    {
        cout << "\nInventory is full!\n";
        return;
    }

    cout << "\n--- ADD DEVICE ---\n";

    id[count] = nextID++;

    cout << "Device Name: ";
    getline(cin, name[count]);

    cout << "Category: ";
    getline(cin, category[count]);

    cout << "Quantity: ";
    cin >> quantity[count];

    cout << "Unit Price: ";
    cin >> price[count];
    clearInput();

    cout << "Condition (Working/Needs Repair): ";
    getline(cin, condition[count]);

    for (int i = 0; i < MONTHS; i++)
    {
        cout << "Usage hours for Month " << i + 1 << ": ";
        cin >> usage[count][i];
    }

    clearInput();

    cout << "\nDevice added successfully!\n";
    cout << "Device ID: " << id[count] << endl;

    count++;
}

// View devices
void viewDevices()
{
    cout << "\n--- DEVICE RECORDS ---\n";

    if (count == 0)
    {
        cout << "No devices found.\n";
        return;
    }

    for (int i = 0; i < count; i++)
    {
        cout << "\nDevice ID: " << id[i] << endl;
        cout << "Name: " << name[i] << endl;
        cout << "Category: " << category[i] << endl;
        cout << "Quantity: " << quantity[i] << endl;
        cout << "Price: PHP " << fixed << setprecision(2) << price[i] << endl;
        cout << "Condition: " << condition[i] << endl;

        cout << "Monthly Usage: ";

        for (int j = 0; j < MONTHS; j++)
        {
            cout << usage[i][j] << " ";
        }

        cout << "hours\n";
    }
}

// Search device
void searchDevice()
{
    int search;

    cout << "\nEnter Device ID: ";
    cin >> search;
    clearInput();

    int index = searchID(search);

    if (index == -1)
    {
        cout << "Device not found.\n";
    }
    else
    {
        cout << "\n--- DEVICE FOUND ---\n";
        cout << "ID: " << id[index] << endl;
        cout << "Name: " << name[index] << endl;
        cout << "Category: " << category[index] << endl;
        cout << "Quantity: " << quantity[index] << endl;
        cout << "Price: PHP " << price[index] << endl;
        cout << "Condition: " << condition[index] << endl;

        cout << "Monthly Usage: ";

        for (int i = 0; i < MONTHS; i++)
        {
            cout << usage[index][i] << " ";
        }

        cout << "hours\n";
    }
}

// Update device
void updateDevice()
{
    int search;

    cout << "\nEnter Device ID to update: ";
    cin >> search;
    clearInput();

    int index = searchID(search);

    if (index == -1)
    {
        cout << "Device not found.\n";
        return;
    }

    cout << "New Device Name: ";
    getline(cin, name[index]);

    cout << "New Category: ";
    getline(cin, category[index]);

    cout << "New Quantity: ";
    cin >> quantity[index];

    cout << "New Price: ";
    cin >> price[index];
    clearInput();

    cout << "New Condition: ";
    getline(cin, condition[index]);

    for (int i = 0; i < MONTHS; i++)
    {
        cout << "New usage for Month " << i + 1 << ": ";
        cin >> usage[index][i];
    }

    clearInput();

    cout << "\nDevice updated successfully!\n";
}

// Delete device
void deleteDevice()
{
    int search;

    cout << "\nEnter Device ID to delete: ";
    cin >> search;
    clearInput();

    int index = searchID(search);

    if (index == -1)
    {
        cout << "Device not found.\n";
        return;
    }

    for (int i = index; i < count - 1; i++)
    {
        id[i] = id[i + 1];
        name[i] = name[i + 1];
        category[i] = category[i + 1];
        quantity[i] = quantity[i + 1];
        price[i] = price[i + 1];
        condition[i] = condition[i + 1];

        for (int j = 0; j < MONTHS; j++)
        {
            usage[i][j] = usage[i + 1][j];
        }
    }

    count--;

    cout << "Device deleted successfully!\n";
}

// Inventory summary
void summary()
{
    int totalQuantity = 0;
    int working = 0;
    int repair = 0;

    double totalPrice = 0;
    double totalHours = 0;

    for (int i = 0; i < count; i++)
    {
        totalQuantity += quantity[i];
        totalPrice += quantity[i] * price[i];

        if (condition[i] == "Working" || condition[i] == "working")
        {
            working += quantity[i];
        }
        else
        {
            repair += quantity[i];
        }

        for (int j = 0; j < MONTHS; j++)
        {
            totalHours += usage[i][j];
        }
    }

    cout << "\n--- INVENTORY SUMMARY ---\n";

    cout << "Total Records: " << count << endl;
    cout << "Total Quantity: " << totalQuantity << endl;
    cout << "Working Devices: " << working << endl;
    cout << "Needs Repair: " << repair << endl;

    cout << "Total Inventory Value: PHP "
         << fixed << setprecision(2) << totalPrice << endl;

    cout << "Total Usage Hours: " << totalHours << endl;

    if (totalQuantity > 0)
    {
        cout << "Average Price: PHP "
             << totalPrice / totalQuantity << endl;
    }
    else
    {
        cout << "Average Price: PHP 0.00\n";
    }
}

// Main program
int main()
{
    int choice;

    do
    {
        cout << "\n================================\n";
        cout << " TECHNOLOGY AND DEVICE SYSTEM\n";
        cout << "================================\n";
        cout << "1. Add Device\n";
        cout << "2. View Devices\n";
        cout << "3. Search Device\n";
        cout << "4. Update Device\n";
        cout << "5. Delete Device\n";
        cout << "6. Inventory Summary\n";
        cout << "7. Exit\n";
        cout << "================================\n";

        cout << "Enter your choice: ";
        cin >> choice;
        clearInput();

        if (choice == 1)
        {
            addDevice();
        }
        else if (choice == 2)
        {
            viewDevices();
        }
        else if (choice == 3)
        {
            searchDevice();
        }
        else if (choice == 4)
        {
            updateDevice();
        }
        else if (choice == 5)
        {
            deleteDevice();
        }
        else if (choice == 6)
        {
            summary();
        }
        else if (choice == 7)
        {
            cout << "\nThank you for using the system!\n";
        }
        else
        {
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}