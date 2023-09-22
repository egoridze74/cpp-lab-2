#include <stdio.h>

//���������� � �������
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

//������� ���������
double double_factorial(double argument)
{
	double result = 1;
	for (int k = argument; k > 0; k -= 2)
	{
		result *= k;
	}
	return result;
}

//��������� t (�������� ��� �����, � ����� �� �������)
double get_t(double argument)
{
	double sum1 = 0, sum2 = 0;
	for (int k = 0; k <= 10; k++) //������� �����
	{
		sum1 += in_power(argument, 2 * k + 1) / double_factorial(2 * k + 1);
	}
	for (int k = 0; k <= 10; k++) //������ �����
	{
		sum2 += in_power(argument, 2 * k) / double_factorial(2 * k);
	}
	return sum1 / sum2;
}

//�������� �����
int main()
{
	double y, numerator, denominator, result;
	scanf_s("%Lf", &y);
	numerator = 7 * get_t(0.25) + 2 * get_t(1 + y); //��������� �����
	denominator = 6 - get_t(in_power(y, 2) - 1); //����������� �����
	result = numerator / denominator;
	printf("%.5Lf", result);
	return 0;
}