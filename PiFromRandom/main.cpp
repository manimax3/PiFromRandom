// Calculating pi from random numbers
#include <iostream>
#include <random>
#include <tuple>
#include <vector>
#include <assert.h>
#include <string>

#define ENDL << '\n'

using uint = unsigned int;
using uint_vector = std::vector<uint>;

uint greatest_common_divisor(const uint &a, const uint &b);
bool coprime(const uint &a, const uint &b);
uint count_coprimes(const uint &count, const uint &seed);
double approx_pi(const uint &total, const uint &coprimes);

int main()
{
	while (true) 
	{
		std::cout << "How many numbers to check [0 to exit]: (uint) ";
		uint count;
		std::cin >> count;
		if (count == 0)
			break;
		std::cout << "Enter a Seed: (uint) ";
		uint seed;
		std::cin >> seed;

		auto coprimes = count_coprimes(count, seed);
		auto pi = approx_pi(count, coprimes);

		std::cout << "Pi: " << pi ENDL;

		std::cout << "==================" ENDL;
	}

	return 0;
}

uint greatest_common_divisor(const uint &a, const uint &b)
{
	auto m = a < b ? b : a; // Bigger
	auto n = a < b ? a : b; // Smaller
	auto mod = m % n;

	if (mod == 0)
		return n;
	else
		return greatest_common_divisor(n, mod);
}

bool coprime(const uint &a, const uint &b)
{
	return greatest_common_divisor(a, b) == 1;
}

uint count_coprimes(const uint &count, const uint &seed)
{
	uint amount = 0;

	std::mt19937 engine;
	engine.seed(seed);

	std::cout << "Generating the random numbers" ENDL;
	for (uint i = 0; i < count; i++)
	{
		if (coprime(engine(), engine()))
			amount++;
	}

	return amount;
}

double approx_pi(const uint &total, const uint &coprimes)
{
	double probability = static_cast<double>(coprimes) / static_cast<double>(total);
	double pi = std::sqrt(6 / probability);
	return pi;
}



