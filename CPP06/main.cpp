#include "ScalarConverter.hpp"

// int main(int argc, char **argv){
// 	if(argc != 2){
// 		std::cerr << "Usage: ./scalarConverter [input]" << std::endl;
// 		return 1;
// 	}
// 	ScalarConverter::convert(argv[1]);
// }


#include <cstdlib>
#include <iostream>

int main() {
    const char* str = "ola";
    char* end;
    long int num = std::strtol(str, &end, 10);
    std::cout << "Resultado de std::strtol: " << num << std::endl;
    std::cout << "Ponteiro end aponta para: " << end << std::endl;
    return 0;
}