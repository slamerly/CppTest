#pragma once
#include <string>
#include "Color.h"

class Car
{
private:
	std::string mBrand;
	std::string mModel;
	Color mColor;
	std::string mLicensePlate;
	int mYear;
	float mMileage;
	float mCostValue;

public:
	Car();
	Car(std::string brand, std::string model, Color color, std::string license, int year, float mileage, float cost);
	~Car();

	std::string GetBrand();
	std::string GetModel();
	Color GetColor();
	std::string GetLicensePlate();
	int GetYear();
	float GetMileage();
	float GetCostValue();

	void SetMileage(float mileage);
	void SetCostValue(float cost);

	void Roll(float miles);
	void ChangeColor(Color newColor);

	void ToString();

};

