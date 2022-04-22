// CppTest.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Car.h"
#include "Person.h"

using namespace std;

int main()
{
    Person john = Person("John", "Doe", "June 25, 1990", "man", 25320);
    john.ToString();

    cout << endl;

    Car peugeot = Car("Peugeot", "208", Color::Red, "GH-456-XD", 2015, 12563, 7251);
    peugeot.ToString();

    cout << endl;

    Person alice = Person("Alice", "Bean", "September 2, 1995", "non-binary", 5432, peugeot);
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
}


