#pragma once
#include <string>
#include <vector>
#include "Car.h"
#include "Person.h"

class Dealership
{
private:
	float mMoney;
	std::vector<Car*> mpCarPark;
	std::vector<Person*> mpClients;

public:
	Dealership();
	Dealership(float money, std::vector<Car*> carPark, std::vector<Person*> clients);
	~Dealership();

	void CreateCar();
	void CreatePerson();

	void BuyCar();
	void SellCar();

	void CarParkDisplay();
	void ClientsDisplay();
};

