#include <iostream>

int main()
{
	float a, b, c, d, e;
	float total;
	total = a = b = c = d = e = 0.0f;

	std::cout << "Please enter 5 positive or negative numbers." << std::endl;
	std::cin >> a >> b >> c >> d >> e;

	total = a + b + c + d + e;

	if (total > 0)
	{
		std::cout << "Positive" << std::endl;
	}
	else if (total < 0)
	{
		std::cout << "Negative" << std::endl;
	}
	else if (total == 0)
	{
		std::cout << "Zero" << std::endl;
	}


	system("Pause");
	std::cin.get();

	return 0;
}