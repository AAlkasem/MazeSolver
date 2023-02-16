#include <iostream>
#include "stack.h"
#include "maze.h"


int main() {
    std::string mazeFile = "maze.txt";
    std::ifstream inputFile(mazeFile);

    // read in maze from file
    std::vector<std::vector<char>> maze;
    char c;
    std::vector<char> temp;
    if (inputFile.is_open()) {
        std::cout << "File opened successfully" << std::endl;
        while (inputFile.get(c)) {
            if (c == '\n') { // check if end of line is reached
                maze.push_back(temp);
                temp.clear();
            } else {
                temp.push_back(c);
            }
        }
        // add last row to maze
        if (!temp.empty()) {
            maze.push_back(temp);
        }
        inputFile.close();
    }else{
        std::cout << "File cannot be opened" << std::endl;
        return 0;
    }

    // print maze on console
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[i].size(); j++) {
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << maze.size() << std::endl;


    // initialize start and end positions
    int rows = 1, cols = 0;
    int endRows = maze.size() - 1, endCols = maze[0].size() - 2;

    // initialize stack and visited/parent vectors
    Stack stack;
    // push starting position onto stack and mark as visited
    // mark cell as visited and put a '#' symbol in the maze
    // examine neighbors
    // print maze on console

    return 0;
}