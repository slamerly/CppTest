#include "Dealership.h"
#include <iostream>

using namespace std;

Dealership::Dealership()
{
	mMoney = 0;
}

Dealership::Dealership(float money, vector<Car*> carPark, vector<Person*> clients)
{
	mMoney = money;
	mpCarPark = carPark;
	mpClients = clients;
}

Dealership::~Dealership()
{
	mpCarPark.~vector();
	mpClients.~vector();
}

void Dealership::CreateCar()
{
	string brand;
	string model;
	string colorEnter;
	Color color = Color::Default;
	string license;
	int year;
	float mileage;
	float cost;

	cout << "Creation new car :\nEnter the brand : ";
	cin >> brand;
	cout << "Enter model : ";
	cin >> model;
	cout << "Choose color (red, green, blue, yellow, cyan, magenta) : ";
	cin >> colorEnter;

	if (colorEnter == "red")
		color = Color::Red;
	if (colorEnter == "green")
		color = Color::Green;
	if (colorEnter == "blue")
		color = Color::Blue;
	if (colorEnter == "yellow")
		color = Color::Yellow;
	if (colorEnter == "cyan")
		color = Color::Cyan;
	if (colorEnter == "magenta")
		color = Color::Magenta;

	cout << "Put the license plate : ";
	cin >> license;
	cout << "Production year : ";
	cin >> year;
	cout << "Mileage : ";
	cin >> mileage;
	cout << "Cost value : ";
	cin >> cost;
	cout << endl;

	Car* newCar = new Car(brand, model, color, license, year, mileage, cost);

	mpCarPark.push_back(newCar);
}

void Dealership::CreatePerson()
{
	string name;
	string lastName;
	string birthDate;
	string gender;
	float money;

	cout << "Creation new client :\nName : ";
	cin >> name;
	cout << "Last name : ";
	cin >> lastName;
	cout << "Birth date (mouth day, year) : ";
	getline(cin >> ws, birthDate);
	cout << "Gender : ";
	cin >> gender;
	cout << "Money : ";
	cin >> money;
	cout << endl;

	Person* newPerson = new Person(name, lastName, birthDate, gender, money);
	//Person* newPerson = new Person("Jack", "Sparrow", "August 15, 1740", "man", 123);
	
	mpClients.push_back(newPerson);
}

void Dealership::BuyCar()
{
	Car* car;
	int choice;

	cout << "========== BUY CAR ==========\n";
	ClientsDisplay();
	
	do {
		cout << "Enter your choice : ";
		cin >> choice;
	} while (choice < 0 || choice > mpClients.size());

	cout << endl;

	car = mpClients[choice]->GetCar();

	mMoney -= car->GetCostValue();
	mpCarPark.push_back(car);
	mpClients[choice]->SellCar();
	cout << "You have buy " << car->GetBrand() << " " << car->GetModel() << " (" << car->GetLicensePlate() << ")\n";
	cout << "You have now " << mMoney << " Euros\n";
}

void Dealership::SellCar()
{
	Car* car;
	Person* person;
	int choiceClient;
	int choiceCar;

	cout << "========== SELL CAR ==========\n";
	ClientsDisplay();
	
	do {
		cout << "Choose the byer : ";
		cin >> choiceClient;
	} while (choiceClient < 0 || choiceClient > mpClients.size());

	person = mpClients[choiceClient];

	cout << endl;
	CarParkDisplay();

	do {
		cout << "Choose the car you want to sell : ";
		cin >> choiceCar;
	} while (choiceCar < 0 || choiceCar > mpCarPark.size());

	car = mpCarPark[choiceCar];

	cout << endl;

	int index = 0;
	mMoney += car->GetCostValue();
	person->BuyCar(*car);
	mpCarPark.erase(mpCarPark.begin() + choiceCar);

	cout << "You have sell " << car->GetBrand() << " " << car->GetModel() << " (" << car->GetLicensePlate() << ") to " << person->GetName() << endl;
	cout << "You have now " << mMoney << " Euros\n";
}

void Dealership::CarParkDisplay()
{
	cout << "========== Car Park ==========\n";
	for (int i = 0; i < mpCarPark.size(); i++) {
		cout << i << " - ";
		mpCarPark[i]->ToString();
		cout << endl;
	}
}

void Dealership::ClientsDisplay()
{
	cout << "========== Clients ==========\n";
	for (int i = 0; i < mpClients.size(); i++) {
		cout << i << " - ";
		mpClients[i]->ToString();
		cout << endl;
	}
}
