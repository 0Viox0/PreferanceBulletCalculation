#pragma once

#include "includes.h"

struct player2
{
	std::string nameOfThePlayer;
	int res;
};

struct result2
{
	player2 player[4];
};

class CalculatorFor4
{
private:
	std::string name1;
	int gora1;
	int visti_1na2;
	int visti_1na3;
	int visti_1na4;

	std::string name2;
	int gora2;
	int visti_2na1;
	int visti_2na3;
	int visti_2na4;
		
	std::string name3;
	int gora3;
	int visti_3na1;
	int visti_3na2;
	int visti_3na4;

	std::string name4;
	int gora4;
	int visti_4na1;
	int visti_4na2;
	int visti_4na3;

	int cost_of_one_vist;

	int res1;
	int res2;
	int res3;
	int res4;


	void get(int);
	void count_gora();
	void count_visti();

public:
	CalculatorFor4(std::string a, int g1, int vi_1na4, int vi_1na3, int vi_1na2,
		std::string b, int g2, int vi_2na3, int vi_2na4, int vi_2na1,
		std::string c, int g3, int vi_3na4, int vi_3na1, int vi_3na2,
		std::string d, int g4, int vi_4na1, int vi_4na2, int vi_4na3);

	result2 calculate(std::string a, int g1, int vi_1na4, int vi_1na3, int vi_1na2,
		std::string b, int g2, int vi_2na3, int vi_2na4, int vi_2na1,
		std::string c, int g3, int vi_3na4, int vi_3na1, int vi_3na2,
		std::string d, int g4, int vi_4na1, int vi_4na2, int vi_4na3);
};