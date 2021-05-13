#include <string>
#include <ctime>
#include <iostream>
#include <cstdlib>

struct Data
{
	std::string str1;
	int num;
	std::string str2;
};

void rand_string(std::string &str)
{
	char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < 23; i++)
		str.append(1, charset[std::rand() % 52]);
}

Data *deserialize(void *raw)
{
	Data *data = reinterpret_cast<Data *>(raw);
	std::cout << "*** DESERIALIZED data" << std::endl;
	std::cout << "STR1: " << data->str1 << std::endl;
	std::cout << "NUM: " << data->num << std::endl;
	std::cout << "STR2: " << data->str2 << std::endl;
	return (data);
}

void *serialize(void)
{
	Data *data = new(struct Data);
	rand_string(data->str1);
	rand_string(data->str2);
	data->num = rand();
	std::cout << "*** SERIALIZED data" << std::endl;
	std::cout << "STR1: " << data->str1 << std::endl;
	std::cout << "NUM: " << data->num << std::endl;
	std::cout << "STR2: " << data->str2 << std::endl;
	return (data);
}

int main (void)
{
	std::srand(std::time(0));
	void *data_raw = serialize();
	Data *d = deserialize(data_raw);
	delete (d);
	return (0);
}
