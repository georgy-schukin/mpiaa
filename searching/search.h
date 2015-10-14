#include "person.h"

#include <map>
#include <vector>

typedef std::vector<Person> PersonCollection;
typedef std::vector<Person::Key> KeyCollection;
typedef std::map<Person::Key, Person> Dictionary;

void doBuild(const PersonCollection &persons, Dictionary &dict);
int doSearch(const Dictionary &dict, const KeyCollection &keys);
