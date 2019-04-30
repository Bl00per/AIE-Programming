#include <iostream>

	unsigned int basicHash(const char* data, unsigned int size) 
	{ 
		unsigned int hash = 0; 
		for (unsigned int i = 0; i < size; ++i) 
		{ 
			hash += data[i]; 
		}
		return hash; 
	}

	unsigned int BKDRHash(const char* data, unsigned int size) 
	{
		unsigned int hash = 0;
		for( unsigned int i= 0 ; i < size; ++i) 
		{
			hash = (hash * 1313) + data[i];
		}
		return(hash & 0x7FFFFFFF);
	}

	unsigned int ELFHash(const char* data, unsigned int size) 
	{ 
		unsigned int hash = 0, x = 0; 
		for (unsigned int i = 0; i < size; ++i) 
		{ 
			hash = (hash << 4) + data[i]; 
			if ((x = hash & 0xF0000000L) != 0) 
			{ 
				hash ^= (x >> 24); 
				hash &= ~x; 
			} 
		}
		return(hash & 0x7FFFFFFF); 
	}

int main(void)
{
	std::cout << basicHash("Adam", 4) << std::endl;

	std::cout << BKDRHash("Adam", 4) << std::endl;

	std::cout << BKDRHash("madA", 4) << std::endl;

	std::cout << ELFHash("Adam", 4) << std::endl;

	std::cout << ELFHash("madA", 4) << std::endl;

	return 0;
}