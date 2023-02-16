//
// Created by LastA on 2/15/2023.
//

#ifndef ASSIGNMENT_2_STACK_H
#define ASSIGNMENT_2_STACK_H
#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <sstream>

struct Location{
    int m_col, m_row;
};

struct Node {
    Location m_data;
    Node *m_next;
};

class Stack {
private:
    Node *m_first{nullptr};


public:
    void push(Location location);
    void pop();
    friend std::ostream & operator<<(std::ostream &os, const Stack &stack);
};


#endif //ASSIGNMENT_2_STACK_H