//
// Created by LastA on 2/15/2023.
//

#include "stack.h"


void Stack::push(Location location) {
    auto node = new Node();
    node->m_data = std::move(location);
    node->m_next = m_first;
    m_first = node;
}

void Stack::pop() {
    // Checks if the stack is empty
    auto node = m_first;
    m_first = m_first ? m_first->m_next : nullptr;
    delete node;
}

int Stack::getCol() {
    return m_first->m_data.m_col;
}

int Stack::getRow() {
    return m_first->m_data.m_row;
}

std::ostream & operator<<(std::ostream& output, const Stack &stack){
    auto node= stack.m_first;
    while(node != nullptr){
        output << "Column, Row (" << node->m_data.m_col << ", " << node->m_data.m_row << ") " << std::endl;
        node = node->m_next;
    }
    return output;
}