#include <string>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int r = std::rand() % 3;

	if (r == 0)
	{
		std::cout << "Class A spawned" << std::endl;
		return new A;
	}
	else if (r == 1)
	{
		std::cout << "Class B spawned" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "Class C spawned" << std::endl;
		return new C;
	}
}

void identify_from_pointer(Base * p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base & p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
}

int main (void)
{
	std::srand(std::time(0));
	Base *b = generate();
	std::cout << "Idetify from pointer: ";
	identify_from_pointer(b);
	std::cout << "Idetify from reference: ";
	identify_from_reference(*b);
	delete (b);
	return (0);
}
