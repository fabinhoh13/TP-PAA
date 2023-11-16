#ifndef BACKTRACK_H
#define BACKTRACK_H

#include "Knapsack.h"
    
    class Node
    {
    private:
        int weight;
        int value;
    public:
        int numChildren;
        Node* parent;
        Node** children;

        Node(int weight, int value, int numChildren);
        ~Node();

        int getWeight() const;
        int getValue() const;
        int getNumChildren() const;
    };
    
    class Backtrack
    {
    private:
        int max_value;
        Node* max_node;

        void TRACE_MAX(Node* max_node, Knapsack& knapsack);
        void BACK_TRACE(Node *root, Knapsack& knapsack);
    public:
        Backtrack();
        ~Backtrack();
        void solve(Knapsack& knapsack);
    };
    
#endif
    