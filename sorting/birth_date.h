#pragma once

#include <string>
#include <iostream>

class BirthDate {
public:
    BirthDate() {}

    friend std::ostream& operator<<(std::ostream &out, const BirthDate &b) {
        out << b.year << " " << b.month << " " << b.day;
        return out;
    }

    friend std::istream& operator>>(std::istream &in, BirthDate &b) {
        in >> b.year >> b.month >> b.day;
        return in;
    }

public:
    int year;
    std::string month;
    int day;
};


