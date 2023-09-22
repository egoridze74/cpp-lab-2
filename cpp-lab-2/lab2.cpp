#include <stdio.h>

//возведение в степень
double in_power(double base, int power)
{
	double result = 1;
	int k = 0;
	while (k < power)
	{
		result *= base;
		k++;
	}
	return result;
}

//двойной факториал
double double_factorial(double argument)
{
	double result = 1;
	for (int k = argument; k > 0; k -= 2)
	{
		result *= k;
	}
	return result;
}

//получение t (получаем две суммы, а затем их частное)
double get_t(double argument)
{
	double sum1 = 0, sum2 = 0;
	for (int k = 0; k <= 10; k++) //верхн€€ сумма
	{
		sum1 += in_power(argument, 2 * k + 1) / double_factorial(2 * k + 1);
	}
	for (int k = 0; k <= 10; k++) //нижн€€ сумма
	{
		sum2 += in_power(argument, 2 * k) / double_factorial(2 * k);
	}
	return sum1 / sum2;
}

//основна€ дробь
int main()
{
	double y, numerator, denominator, result;
	scanf_s("%Lf", &y);
	numerator = 7 * get_t(0.25) + 2 * get_t(1 + y); //числитель дроби
	denominator = 6 - get_t(in_power(y, 2) - 1); //знаменатель дроби
	result = numerator / denominator;
	printf("%.5Lf", result);
	return 0;
}