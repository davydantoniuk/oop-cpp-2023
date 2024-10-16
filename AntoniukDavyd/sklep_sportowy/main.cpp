#include "przedmiot.h"
#include "namiot.h"
#include "pilka.h"
#include "magazyn.h"
#include <iostream>
#include <memory>

using namespace std;
int main() {
    magazyn storage;
    shared_ptr<namiot> tent = make_shared<namiot>("turysta", 1000.0, 4, 1, 2);
    shared_ptr<pilka> ball = make_shared<pilka>("Pilka nozna", 50.0, 1, 2, 22);
    shared_ptr<namiot> tent2 = make_shared<namiot>("Ultra", 1500.0, 2, 3, 3);
    storage.addItem(tent);
    storage.addItem(ball);
    storage.addItem(tent2);
    storage.report(0.0, 100000.0);
    return 0;
}
