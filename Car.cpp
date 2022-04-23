#include <iostream>
#include "Car.h"

using namespace std;

Car::Car()
{
	mBrand = "Default";
	mModel = "Default";
	mColor = Color::Default;
	mLicensePlate = "Default";
	mYear = 0;
	mMileage = 0;
	mCostValue = 0;

	//cout << "The car " << mBrand << " " << mModel << " was created\n";
}

Car::Car(string brand, string model, Color color, string license, int year, float mileage, float cost)
{
	mBrand = brand;
	mModel = model;
	mColor = color;
	mLicensePlate = license;
	mYear = year;
	mMileage = mileage;
	mCostValue = cost;

	cout << "The car " << mBrand << " " << mModel << " was created\n";
}

Car::~Car()
{

}

string Car::GetBrand()
{
	return mBrand;
}


string Car::GetModel()
{
	return mModel;
}

Color Car::GetColor() 
{
	return mColor;
}

string Car::GetLicensePlate()
{
	return mLicensePlate;
}

int Car::GetYear() 
{
	return mYear;
}

float Car::GetMileage()
{
	return mMileage;
}

float Car::GetCostValue()
{
	return mCostValue;
}

void Car::SetMileage(float mileage)
{
	mMileage = mileage;
}

void Car::SetCostValue(float cost) 
{
	mCostValue = cost;
}


void Car::Roll(float miles)
{
	mMileage += miles;
}

void Car::ChangeColor(Color newColor)
{
	mColor = newColor;
}

void Car::ToString()
{
	string color;

	switch (mColor)
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

	cout << "The " << mBrand << " " << mModel << " is a " << color << " car with license plate " << mLicensePlate << endl;
	cout << "With a mileage of " << mMileage << " km, it has a value of " << mCostValue << " Euros \n\n";
}
