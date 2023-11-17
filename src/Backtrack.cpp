#include "Backtrack.h"

Node::Node(int weight, int value, int numChildren) : weight(weight), value(value), numChildren(numChildren), parent(nullptr)
{
    children = new Node *[numChildren](); // Inicializa o array com nullptr
}

Node::~Node()
{
    for (int i = 0; i <= (int)this->numChildren; i++)
    {
        delete[] this->children[i];
    }
    delete[] this->children;
}

int Node::getWeight() const
{
    return weight;
}

int Node::getValue() const
{
    return value;
}

int Node::getNumChildren() const
{
    return numChildren;
}

Backtrack::Backtrack() : max_value(0), max_node(nullptr) {}

Backtrack::~Backtrack() {}

void Backtrack::TRACE_MAX(Node *max_node, Knapsack *knapsack)
{
    for (int i = 0; i < knapsack->getSize(); i++)
    {
        if ((*max_node->parent).children[i] == max_node)
        {
            knapsack->setChosen(i, 1);
            break;
        }
    }
    if (max_node->parent->parent == NULL)
    { 
        return;
    }
    TRACE_MAX(max_node->parent, knapsack);
}

void Backtrack::BACK_TRACE(Node *root, Knapsack *knapsack, int *isChoosen)
{

    for (int i = 0; i < knapsack->getSize(); i++)
    {
        if ((root->getWeight() - knapsack->getItem(i)->weight) >= 0 && !isChoosen[i])
        {
            //cout << "Entrou no if" << endl;
            int *d = new int[knapsack->getSize()];

            for (int j = 0; j < knapsack->getSize(); j++)
            {
                d[j] = isChoosen[j];
            }

            d[i] = 1;

            root->children[i] = new Node(
                root->getWeight() - knapsack->getItem(i)->weight,
                root->getValue() + knapsack->getItem(i)->value,
                knapsack->getSize());
            
            (*root->children[i]).parent = root;

            if (root->getValue() + knapsack->getItem(i)->value > max_value) {
                this->max_value = root->getValue() + knapsack->getItem(i)->value;
                this->max_node = root->children[i];
            }

            BACK_TRACE(root->children[i], knapsack, d);
        
        } else {
            root->children[i] = NULL;
        }
    }
}

void Backtrack::solve(Knapsack *knapsack) {
    int *isChoosen = new int[knapsack->getSize()];
    for (int i = 0; i < knapsack->getSize(); i++){
       isChoosen[i] = 0;
       knapsack->setChosen(i, 0);
    }

    
    Node* root = new Node(knapsack->getCapacity(), 0, knapsack->getSize());

    // Chamada do Backtracking
    BACK_TRACE(root, knapsack, isChoosen);
    // Rastreamento da solução ótima
    TRACE_MAX(this->max_node, knapsack);
    
    // Impressão do valor máximo
    //printf("Max value: %d\n", this->max_value);
}