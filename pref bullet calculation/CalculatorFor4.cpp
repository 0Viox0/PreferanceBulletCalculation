#include "CalculatorFor4.h"

CalculatorFor4::CalculatorFor4(std::string a, int g1, int vi_1na4, int vi_1na3, int vi_1na2,
	std::string b, int g2, int vi_2na3, int vi_2na4, int vi_2na1,
	std::string c, int g3, int vi_3na4, int vi_3na1, int vi_3na2,
	std::string d, int g4, int vi_4na1, int vi_4na2, int vi_4na3)
{
	name1 = a;
	name2 = b;
	name3 = c;
	name4 = d;

	gora1 = g1;
	visti_1na2 = vi_1na2;
	visti_1na3 = vi_1na3;
	visti_1na4 = vi_1na4;

	gora2 = g2;
	visti_2na1 = vi_2na1;
	visti_2na3 = vi_2na3;
	visti_2na4 = vi_2na4;

	gora3 = g3;
	visti_3na1 = vi_3na1;
	visti_3na2 = vi_3na2;
	visti_3na4 = vi_3na4;

	gora4 = g4;
	visti_4na1 = vi_4na1;
	visti_4na2 = vi_4na2;
	visti_4na3 = vi_4na3;
}

void CalculatorFor4::get(int cost)
{
	cost_of_one_vist = cost;
}

void CalculatorFor4::count_gora()
{
	float avg = static_cast<float>(gora1 + gora2 + gora3 + gora4) / 4.f;
	res1 = (avg - gora1) * cost_of_one_vist;
	res2 = (avg - gora2) * cost_of_one_vist;
	res3 = (avg - gora3) * cost_of_one_vist;
	res4 = (avg - gora4) * cost_of_one_vist;
}

void CalculatorFor4::count_visti()
{
	res1 -= (visti_3na1 + visti_2na1 + visti_4na1);
	res1 += (visti_1na2 + visti_1na3 + visti_1na4);

	res2 -= (visti_1na2 + visti_3na2 + visti_4na2);
	res2 += (visti_2na1 + visti_2na3 + visti_2na4);

	res3 -= (visti_1na3 + visti_2na3 + visti_4na3);
	res3 += (visti_3na1 + visti_3na2 + visti_3na4);

	res4 -= (visti_1na4 + visti_2na4 + visti_3na4);
	res4 += (visti_4na1 + visti_4na2 + visti_4na3);
}

result2 CalculatorFor4::calculate(std::string a, int g1, int vi_1na4, int vi_1na3, int vi_1na2,
	std::string b, int g2, int vi_2na3, int vi_2na4, int vi_2na1,
	std::string c, int g3, int vi_3na4, int vi_3na1, int vi_3na2,
	std::string d, int g4, int vi_4na1, int vi_4na2, int vi_4na3)
{
	name1 = a;
	name2 = b;
	name3 = c;
	name4 = d;

	gora1 = g1;
	visti_1na2 = vi_1na2;
	visti_1na3 = vi_1na3;
	visti_1na4 = vi_1na4;

	gora2 = g2;
	visti_2na1 = vi_2na1;
	visti_2na3 = vi_2na3;
	visti_2na4 = vi_2na4;

	gora3 = g3;
	visti_3na1 = vi_3na1;
	visti_3na2 = vi_3na2;
	visti_3na4 = vi_3na4;

	gora4 = g4;
	visti_4na1 = vi_4na1;
	visti_4na2 = vi_4na2;
	visti_4na3 = vi_4na3;

	get(10);
	count_gora();
	count_visti();

	result2 res;

	player2 temp; temp.nameOfThePlayer = name1; temp.res = res1;
	res.player[0] = temp;

	temp.nameOfThePlayer = name2; temp.res = res2;
	res.player[1] = temp;

	temp.nameOfThePlayer = name3; temp.res = res3;
	res.player[2] = temp;

	temp.nameOfThePlayer = name4; temp.res = res4;
	res.player[3] = temp;

	return res;
}