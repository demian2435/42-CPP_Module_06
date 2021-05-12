#include <string>
#include <ctime>
#include <iostream>
#include <cstdlib>

struct Data
{
	char str1[24];
	int num;
	char str2[24];
};

void rand_string(char str[24])
{
	char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < 23; i++)
		str[i] = charset[std::rand() % 52];
	str[23] = 0;
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
	std::cout << "Size of struct Data: " << sizeof(Data) << " byte" << std::endl; 
	void *data_raw = serialize();
	Data *d = deserialize(data_raw);
	delete (d);
	return (0);
}
