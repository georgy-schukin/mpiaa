#include "bruteforce.h"
#include "sha256.h"

using namespace std;

string bruteforce(const string &password_hash, const string &alphabet, int max_length) {
    // Try to crack password by brute force, using all possible passwords with given alphabet and length in [1, max_length].
    // Use sha256(string) function to compute password's hash and match it with given hash.
    // If password is found for which hashes are equal, return it.
    // Return empty string if password wasn't found.

    // Your implementation here.
    
    return "";
}
