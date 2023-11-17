#include "Knapsack.h"

Item::Item(int id, int weight, int value) : id(id), weight(weight), value(value) {}
Item::~Item() {}

Knapsack::Knapsack(int capacity, int nItems) {
    this->capacity = capacity;
    this->nItems = nItems;

    vector<Item *> items(0);
    this->items = items;
}
Knapsack::~Knapsack() {
    for (Item *i : this->items) {
        delete i;
    }

    this->items.clear();
}

void Knapsack::insert(Item *item) { this->items.push_back(item); }

Item *Knapsack::getItem(int idx) const { return this->items[idx]; }

int Knapsack::getCapacity() const { return this->capacity; }

int Knapsack::getSize() const { return this->nItems; }

int Knapsack::getChosen(int idx) { 
    return this->items[idx]->chosen; 
}

void Knapsack::setChosen(int idx, int choice) { 
    this->items[idx]->chosen = choice; 
}