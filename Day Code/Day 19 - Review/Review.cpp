#include <iostream>
#include <vector>

// using namespace std; // makes for a sad code review

namespace Adam
{
	enum class GirlName : unsigned char
	{
		Adam = 10,
		Peter = 20,
		Ashley = 30
	};
}

// enum class/scope enumName : optional size type
enum Colour
{
	None = 0,
	Red,
	Blue
};

enum class GirlName : unsigned char
{
	Adam = 1,
	Peter = 2,
	Ashley = 3
};

enum class BoysName
{
	Amy = 1,
	Amanda = 2,
	Ashley = 3
};

class thing {
public:
	int data;
	thing(int a_new_data)
	{
		data = a_new_data;
	}

	thing operator+(const thing& a_LHS)
	{
		return thing(this->data + a_LHS.data);
	}
};

const int Green = 3;

int main()
{
	int x = Red;
	int y = Green;

	int a = (int)BoysName::Ashley;
	int b = int(GirlName::Ashley);

	int c = int(Adam::GirlName::Ashley);

	thing z = thing(10) + thing(5);


	return 0;
}