#ifndef Knapsack_H
#define Knapsack_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Item {
   public:
    const int id;      // Item's identifier
    const int weight;  // Item's weight
    const int value;   // Item's monetary value
    
    int chosen;

    Item(int id, int weight, int value);
    ~Item();
};

class Knapsack {
private:
    int capacity;
    int nItems;
    vector<Item *> items;

   public:
    Knapsack(int capacity, int nItems);
    ~Knapsack();

    /**
     * Insert an item into the items vector;
     */
    void insert(Item *item);

    /**
     * Get an item from the items vector;
     */
    Item *getItem(int idx) const;

    /**
     * Get the full capacity of the backpack;
     */
    int getCapacity() const;

    /**
     * Get the number of items for the instance;
     */
    int getSize() const;

    int getChosen(int idx);

    void setChosen(int idx, int choice);
};

#endif