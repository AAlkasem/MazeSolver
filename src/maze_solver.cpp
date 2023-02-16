//
// Created by LastA on 2/15/2023.
//

#include "maze_solver.h"
#include "stack.h"

Maze_Solver(std::string file_name, std::string output_file_name) {
    std::ifstream inputFile(file_name);
    std::ofstream outputFile(output_file_name);

    // read in maze from file
    std::vector<std::vector<char>> maze, solvedMaze;
    char c;
    std::vector<char> temp;
    if (inputFile.

    is_open()

    ) {
    std::cout << "File opened successfully" <<
    std::endl;
    while (inputFile.
    get(c)
    ) {
    if (c == '\n') { // check if end of line is reached
    maze.
    push_back(temp);
    temp.

    clear();

    } else {
    temp.
    push_back(c);
    }
    }
    // add last row to maze
    if (!temp.

    empty()

    ) {
    maze.
    push_back(temp);
    }
    inputFile.

    close();

    }else{
    std::cout << "File cannot be opened" <<
    std::endl;
    }


}
