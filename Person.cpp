#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

Person::Person()
{
	mName = "Default";
	mLastName = "Default";
	mBirthDate = "Default";
	mGender = "Default";
	mMoney = 0;
	mpCar = nullptr;
}

Person::Person(string name, string lastName, string birthDate, string gender, float money)
{
	mName = name;
	mLastName = lastName;
	mBirthDate = birthDate;
	mGender = gender;
	mMoney = money;
	mpCar = nullptr;

	cout << "The person " << mName << " was created\n";
}

Person::Person(string name, string lastName, string birthDate, string gender, float money, Car& car)
{
	mName = name;
	mLastName = lastName;
	mBirthDate = birthDate;
	mGender = gender;
	mMoney = money;
	mpCar = &car;

	cout << "The person " << mName << " was created\n";
}

Person::~Person()
{
}

std::string Person::GetName()
{
	return mName;
}

Car* Person::GetCar()
{
	return mpCar;
}

void Person::SetCar(Car& car)
{
	mpCar = &car;
}

void Person::BuyCar(Car& newCar)
{
	cout << mName << " spent " << mMoney << " Euros, ";
	mMoney -= newCar.GetCostValue();
	mpCar = &newCar;
	cout << "they now have " << mMoney << " Euros\n";
}

void Person::SellCar()
{
	cout << mName << " earned " << mMoney << " Euros, ";
	mMoney += mpCar->GetCostValue();
	mpCar = nullptr;
	cout << "they now have " << mMoney << " Euros\n";
}

void Person::RollCar(float miles)
{
	cout << mName << " rolls with the " << mpCar->GetBrand() << " " << mpCar->GetModel() << " (" << mpCar->GetLicensePlate() << ") for " << miles << "km\n";
	mpCar->Roll(miles);
	cout << "The " << mpCar->GetBrand() << " " << mpCar->GetModel() << " (" << mpCar->GetLicensePlate() << ") mileage is now " << mpCar->GetMileage() << "km\n";
}

void Person::PaintCar(Color newColor)
{
	string color;

	switch (mpCar->GetColor())
	{
	case Color::Red:
		color = "red";
		break;
	case Color::Green:
		color = "green";
		break;
	case Color::Blue:
		color = "blue";
		break;
	case Color::Yellow:
		color = "yellow";
		break;
	case Color::Cyan:
		color = "cyan";
		break;
	case Color::Magenta:
		color = "magenta";
		break;
	case Color::Default:
		color = "no color";
		break;
	}

	cout << mName << " paints his car " << color << endl;

	switch (newColor)
	{
	case Color::Red:
		color = "red";
		break;
	case Color::Green:
		color = "green";
		break;
	case Color::Blue:
		color = "blue";
		break;
	case Color::Yellow:
		color = "yellow";
		break;
	case Color::Cyan:
		color = "cyan";
		break;
	case Color::Magenta:
		color = "magenta";
		break;
	case Color::Default:
		color = "no color";
		break;
	}

	mpCar->ChangeColor(newColor);
	cout << mpCar->GetBrand() << " " << mpCar->GetModel() << " now has the color " << color << endl;
}

void Person::ToString()
{
	cout << mName << " " << mLastName << " was born on " << mBirthDate << " and is a " << mGender << endl;
	if (mpCar == nullptr)
		cout << mName << " has " << mMoney << " Euros and no car\n";
	else
		cout << mName << " has " << mMoney << " Euros and " << mpCar->GetBrand() << " " << mpCar->GetModel() << " (" << mpCar->GetLicensePlate() << ")\n";
}
