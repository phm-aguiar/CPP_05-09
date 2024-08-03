#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

void	testSerializeDataValue( void ) {
	Data		*data = new Data(42, "Forty-Two");
	uintptr_t	raw = Serializer::serialize(data);
	Data		*data_copy = Serializer::deserialize(raw);
	
	std::cout << GREEN "Original Data: " RESET << PINK << data->getData() << ", " << data->getStr() << RESET << std::endl;
	std::cout << GREEN "Data_copy: " RESET << PINK << data_copy->getData() << ", " << data_copy->getStr() << RESET << std::endl;
	delete data;
}

void	testSerializeDataAddress( void ) {
	Data		*data = new Data;
	uintptr_t	raw = Serializer::serialize(data);
	Data		*data_copy = Serializer::deserialize(raw);
	std::cout << GREEN "original data adress: " RESET << PINK << data << RESET <<std::endl;
	std::cout << GREEN "Copy_data adress: " RESET << PINK << data_copy << RESET << std::endl;
	delete data;
}

int main() {
    Data originalData;
    std::cout << RED "Original Data: " RESET << BLUE <<originalData.getData() << ", " << originalData.getStr() << RESET <<std::endl;
    uintptr_t serializedData = Serializer::serialize(&originalData);
    std::cout << RED "Serialized Data: " RESET << BLUE << serializedData << RESET <<std::endl;
    Data* deserializedData = Serializer::deserialize(serializedData);
    std::cout << RED "Deserialized Data: " RESET << BLUE <<deserializedData->getData() << ", " << deserializedData->getStr() << RESET <<std::endl;

    if (&originalData == deserializedData) {
        std::cout << YELLOW "Serialization and deserialization successful!" RESET << std::endl;
    } else {
        std::cout << RED "Serialization and deserialization failed!" << RESET << std::endl;
    }

	testSerializeDataValue();
	testSerializeDataAddress();

    return 0;
}