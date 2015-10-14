#pragma once

#include <string>
#include <iostream>

class Person {
public:
    typedef std::string Key;

public:
    Person() {}

    friend std::ostream& operator<<(std::ostream &out, const Person &p) {
        out << p.name << " " << p.surname << " " << p.age;
        return out;
    }

    friend std::istream& operator>>(std::istream &in, Person &p) {
        in >> p.name >> p.surname >> p.age;
        return in;
    }

    Key makeKey() const {
        return surname;
    }

public:
    std::string name;
    std::string surname;
    int age;
};
