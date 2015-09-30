#pragma once

#include "birth_date.h"

#include <string>
#include <iostream>

class Person {
public:
    Person() {}

    friend std::ostream& operator<<(std::ostream &out, const Person &p) {
        out << p.name << " " << p.surname << " " << p.birth_date;
        return out;
    }

    friend std::istream& operator>>(std::istream &in, Person &p) {
        in >> p.name >> p.surname >> p.birth_date;
        return in;
    }

    bool operator<(const Person &p) const {
        return name < p.name;
    }

public:
    std::string name;
    std::string surname;
    BirthDate birth_date;
};


