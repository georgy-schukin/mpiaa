#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <cstdio>

#include "bruteforce.h"
#include "sha256.h"

typedef std::chrono::high_resolution_clock hrc;

namespace {
    class Timer {
    public:
        Timer() {}

        void start() {
            begin = hrc::now();
        }

        double getTime() {            
            return std::chrono::duration<double>(hrc::now() - begin).count();    
        }

    private:
        hrc::time_point begin;
    };
}

std::string gen_random_str(const std::string &alphabet, int size) {
    std::string result(size, ' ');
    for (int i = 0; i < size; i++) {
        result[i] = alphabet[rand() % alphabet.size()];
    }
    return result;
}

void measure(const std::string &alphabet, int size, int num_of_passwords) {

    Timer t;
    int cracked_num = 0;    
        
    t.start();
    for (int i = 0; i < num_of_passwords; i++) {
        const auto password = gen_random_str(alphabet, std::max(1, rand() % size));
        const auto cracked = bruteforce(alphabet, size, sha256(password));
        if (password == cracked) {
            cracked_num++;
        }
    }
    double time = t.getTime();
    
    printf("N: %d, time: %.5f sec (cracked %d)\n", size, time, cracked_num);
}

int main() {
    for (int i = 1; i < 6; i++) {
        measure("abcd1234", i, 1000);
    }
    return 0;
}
