#pragma once

#include "includes.h"

struct player
{
	std::string nameOfThePlayer;
	int res;
};

struct result
{
	player player[3];
};

class CalculatorFor3
{
private:
	std::string name1;
	int gora1;
	int visti_1na2;
	int visti_1na3;

	std::string name2;
	int gora2;
	int visti_2na1;
	int visti_2na3;

	std::string name3;
	int gora3;
	int visti_3na1;
	int visti_3na2;

	int cost_of_one_vist;

	int res1;
	int res2;
	int res3;

	//Private functions
	void get(int);
	void count_gora();
	void count_visti();
public:
	CalculatorFor3(std::string a, int g1, int vi_1na2, int vi_1na3,
		std::string b, int g2, int vi_2na3, int vi_2na1,
		std::string c, int g3, int vi_3na1, int vi_3na2);
	
	result calculate(std::string a, int g1, int vi_1na2, int vi_1na3,
		std::string b, int g2, int vi_2na3, int vi_2na1,
		std::string c, int g3, int vi_3na1, int vi_3na2);
};