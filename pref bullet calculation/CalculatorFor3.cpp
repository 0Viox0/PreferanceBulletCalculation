#include "CalculatorFor3.h"

CalculatorFor3::CalculatorFor3(std::string a, int g1, int vi_1na2, int vi_1na3,
	std::string b, int g2, int vi_2na3, int vi_2na1,
	std::string c, int g3, int vi_3na1, int vi_3na2)
{
	name1 = a;
	name2 = b;
	name3 = c;

	gora1 = g1;
	visti_1na2 = vi_1na2;
	visti_1na3 = vi_1na3;
	
	gora2 = g2;
	visti_2na1 = vi_2na1;
	visti_2na3 = vi_2na3;

	gora3 = g3;
	visti_3na1 = vi_3na1;
	visti_3na2 = vi_3na2;
}

void CalculatorFor3::get(int cost)
{
	cost_of_one_vist = cost;
}

void CalculatorFor3::count_gora()
{
	float avg = static_cast<float>(gora1 + gora2 + gora3) / 3.f;
	res1 = (avg - gora1) * cost_of_one_vist;
	res2 = (avg - gora2) * cost_of_one_vist;
	res3 = (avg - gora3) * cost_of_one_vist;
}

void CalculatorFor3::count_visti()
{
	res1 -= (visti_3na1 + visti_2na1);
	res1 += (visti_1na2 + visti_1na3);

	res2 -= (visti_1na2 + visti_3na2);
	res2 += (visti_2na1 + visti_2na3);

	res3 -= (visti_1na3 + visti_2na3);
	res3 += (visti_3na1 + visti_3na2);
}

result CalculatorFor3::calculate(std::string a, int g1, int vi_1na2, int vi_1na3,
	std::string b, int g2, int vi_2na3, int vi_2na1,
	std::string c, int g3, int vi_3na1, int vi_3na2)
{
	//std::cout << g1 << ' ' << vi_1na2 << ' ' << vi_1na3 << '\n'
	//	<< g2 << ' ' << vi_2na3 << ' ' << vi_2na1 << '\n'
	//	<< g3 << ' ' << vi_3na1 << ' ' << vi_3na2 << '\n';
	//
	//std::cout << "\n----------------------\n";

	name1 = a;
	name2 = b;
	name3 = c;

	gora1 = g1;
	visti_1na2 = vi_1na2;
	visti_1na3 = vi_1na3;

	gora2 = g2;
	visti_2na1 = vi_2na1;
	visti_2na3 = vi_2na3;

	gora3 = g3;
	visti_3na1 = vi_3na1;
	visti_3na2 = vi_3na2;


	get(10);
	count_gora();
	count_visti();

	result res;

	player temp; temp.nameOfThePlayer = name1; temp.res = res1;
	res.player[0] = temp;

	temp.nameOfThePlayer = name2; temp.res = res2;
	res.player[1] = temp;

	temp.nameOfThePlayer = name3; temp.res = res3;
	res.player[2] = temp;

	return res;
}