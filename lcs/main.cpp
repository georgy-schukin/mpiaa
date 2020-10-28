#define CATCH_CONFIG_RUNNER

#include "../catch.hpp"

#include "lcs.h"

int main(int argc, char* argv[]) {
    int result = Catch::Session().run(argc, argv);
    return result;
}
