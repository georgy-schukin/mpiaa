#include "dictionary.h"
#include "util.h"
#include <iostream>

#define CATCH_CONFIG_RUNNER
#include "../catch.hpp"

int main(int argc, char **argv) {
    int result = Catch::Session().run(argc, argv);

    for(int i = 0;i < 10; i++) {
    		std::cout << random_string(10) << std::endl;
    }
    return result;
}
