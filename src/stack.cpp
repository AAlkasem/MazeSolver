//
// Created by LastA on 2/15/2023.
//

#include "stack.h"
#include <utility>

void Stack::push(Location location) {
    auto node = new Node();
    node->m_data = std::move(location);
    node->m_next = m_first;
    m_first = node;
}

void Stack::pop() {
    // Checks if the stack is empty
    if(m_first != nullptr){
        auto node = m_first;
        m_first = m_first->m_next;
        delete node;
    }else{
        std::cout << "Stack is empty" << std::endl;
    }
}

std::ostream & operator<<(std::ostream& output, const Stack &stack){
    auto node= stack.m_first;
    while(node != nullptr){
        std::cout << "Column, Row (" << node->m_data.m_col << ", " << node->m_data.m_row << ") " << std::endl;
        node = node->m_next;
    }
    return output;
}