#include "function.h"

bool is_sorted(int *items, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (items[i] > items[i + 1]) {
            return false;
        }
    }
    return true;
}
