#include <random>
// Random Engine &
// Random Device
// Distributions
#include <iostream>

int main(void)
{
	std::random_device m_random_device;
	std::mt19937_64 m_engine(m_random_device());

	// Distribution sets range - ints are inclusive
	std::uniform_int_distribution<int> m_ints(1, 6);
	std::uniform_real_distribution<float> m_floats(-1.0f, 1.0f);
	std::bernoulli_distribution m_bools;

	int max_range = 6;
	for (size_t i = 0; i < 10; i++)
	{
		int result = m_ints(m_engine, max_range);
		float f_result = m_floats(m_engine);
		bool b_bool = m_bools(m_bools);
		std::cout << result << " " << f_result << " " << b_bool << std::endl;
	}

	return 0;
}
