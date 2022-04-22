#pragma once
#include <string>
#include "Car.h"

class Person
{
private:
	std::string mName;
	std::string mLastName;
	std::string mBirthDate;
	std::string mGender;
	float mMoney;
	Car* mpCar;

public:
	Person();
	Person(std::string name, std::string lastName, std::string birthDate, std::string gender, float money);
	Person(std::string name, std::string lastName, std::string birthDate, std::string gender, float money, Car& car);
	~Person();

	void BuyCar(Car& newCar);
	void SellCar();
	void RollCar(float miles);
	void PaintCar(Color newColor);

	void ToString();
};

