#include <iostream>

#define SCOPE "city"
#define HELLO_WORLD "hello world"
#define PRINT_HELLO_UNIVERSE std::cout << "hello universe" << std::endl

#define FIRST_PART_EXAMPLE false
#define DEBUG 0

#define PREPROCESSOR_SETTINGS_EXAMPLE 1


int main()
{
#if FIRST_PART_EXAMPLE
    std::cout << "Hello " << SCOPE << std::endl;
    std::cout << HELLO_WORLD << std::endl;
    PRINT_HELLO_UNIVERSE;

#else
    std::cout << "This cout is part of the preprocessor else part of the main" << std::endl;


    switch (PREPROCESSOR_SETTINGS_EXAMPLE)
    {
        case 1:
            std::cout << "First set of settings are chosen." << std::endl;
            break;
        case 2:
            std::cout << "Second set of settings are chosen." << std::endl;
            break;
        case 3:
            std::cout << "Third set of settings are chosen." << std::endl;
            break;
        default:
            std::cout << "Incorrect settings chosen --> default settings are used." << std::endl;
    }

#if DEBUG
    std::cout << "Running debug mode, you can 'outcomment' couts by using a macro in this manner." << std::endl;
#endif

#endif



}
