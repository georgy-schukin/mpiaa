#include "search.h"

void doBuild(const PersonCollection &persons, Dictionary &dict) {
    for (PersonCollection::const_iterator it = persons.begin(); it != persons.end(); it++) {
        dict.insert(Dictionary::value_type((*it).makeKey(), *it));
    }    
}

int doSearch(const Dictionary &dict, const KeyCollection &keys) {
    int found = 0;
    for (KeyCollection::const_iterator it = keys.begin(); it != keys.end(); it++) {
        if (dict.find(*it) != dict.end()) {
            found++;
        }
    }
    return found;
}
