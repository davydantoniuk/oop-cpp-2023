#ifndef MAGAZYN_H
#define MAGAZYN_H

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "przedmiot.h"
using namespace std;

class magazyn {
private:
    vector<shared_ptr<przedmiot>> items;

public:
    void addItem(shared_ptr<przedmiot> item) {
        items.push_back(item);
    }

    void report(double minPrice, double maxPrice) {
        vector<pair<double, string>> descriptions;

        for (const auto& item : items) {
            double totalPrice = item->getPrice() * item->getLiczba();
            if (totalPrice >= minPrice && totalPrice <= maxPrice) {
                descriptions.emplace_back(totalPrice, item->getOpis());
            }
        }

        sort(descriptions.rbegin(), descriptions.rend());

        for (const auto& desc : descriptions) {
            cout << "Koszt: " << desc.first << ", Opis: " << desc.second << endl;
        }
    }
};

#endif //MAGAZYN_H
