// CppTest.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include "Car.h"
#include "Person.h"
#include "Dealership.h"

using namespace std;

int DisplayMenu()
{
    int choice;

    cout << "========== MENU ==========\n\n";
    cout << "1 - Show car park\n";
    cout << "2 - Show clients list\n";
    cout << "3 - Add car\n";
    cout << "4 - Add client\n";
    cout << "5 - Buy car\n";
    cout << "6 - Sell car\n";
    cout << "0 - Quit\n\n";

    do {
        cout << "Enter your choice : ";
        cin >> choice;
    } while (choice < 0 || choice > 7);

    return choice;
}

int main()
{
    Person john = Person("John", "Doe", "June 25, 1990", "man", 25320);
    john.ToString();

    cout << endl;

    Car peugeot = Car("Peugeot", "208", Color::Red, "GH-456-XD", 2015, 12563, 7251);
    peugeot.ToString();

    cout << endl;

    Person alice = Person("Alice", "Bean", "September 2, 1995", "non-binary", 20000, peugeot);
    alice.ToString();

    cout << endl;

    cout << "Alice sells their car to Jhon\n";
    alice.SellCar();
    john.BuyCar(peugeot);

    cout << endl;

    john.ToString();

    cout << endl;

    john.RollCar(16);
    john.PaintCar(Color::Blue);

    Car citroen = Car("Citroen", "C3", Color::Green, "SG-839-OR", 2020, 10000, 14000);

    // Dealership

    cout << endl;
    cout << "========== Dealership ==========\n";
    cout << endl;

    vector<Car*> carPark;
    vector<Person*> clients;

    carPark.push_back(&citroen);

    clients.push_back(&john);
    clients.push_back(&alice);

    Dealership player = Dealership(100000, carPark, clients);

    int choice = 0;
    do {
        choice = DisplayMenu();
        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
            cout << endl;
            player.CarParkDisplay();
            cout << endl;
            break;
        case 2:
            cout << endl;
            player.ClientsDisplay();
            cout << endl;
            break;
        case 3:
            cout << endl;
            player.CreateCar();
            cout << endl;
            break;
        case 4:
            cout << endl;
            player.CreatePerson();
            cout << endl;
            break;
        case 5:
            cout << endl;
            player.BuyCar();
            cout << endl;
            break;
        case 6:
            cout << endl;
            player.SellCar();
            cout << endl;
            break;
        default:
            break;
        }
    } while (choice != -1);
}