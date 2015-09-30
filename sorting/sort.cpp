#include "sort.h"

#include <algorithm>

ArrayType doSort(ArrayType &data) {
    std::sort(data.begin(), data.end());
    return data;
}
