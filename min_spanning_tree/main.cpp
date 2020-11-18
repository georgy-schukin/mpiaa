#define CATCH_CONFIG_RUNNER

#include "../catch.hpp"

#include "min_spanning_tree.h"

int main(int argc, char* argv[]) {
    int result = Catch::Session().run(argc, argv);
    return result;
}
