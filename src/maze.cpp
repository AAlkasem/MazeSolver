//
// Created by LastA on 2/15/2023.
//

#include "maze.h"
#include "stack.h"

void SavePath(std::stack<Stack *> &path) {

    std::ofstream outfile("text_solution.txt"); // create a new text file called "text_solution.txt"
    if (outfile.is_open()) { // check if the file was successfully opened
        std::stringstream line; // the text to write to the file
        while (!path.empty()) {
            Stack *cell = path.top();
            path.pop();
            line << "(" << cell->m_row << ", " << cell->m_col << ") ";
        }
        outfile << line.str() << std::endl; // write the text to the file
        outfile.close(); // close the file
        std::cout << "File saved successfully" << std::endl;
    } else {
        std::cout << "Failed to open file" << std::endl;
    }

}