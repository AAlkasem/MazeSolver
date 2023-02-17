#include <iostream>
#include "stack.h"
#include "maze_solver.h"


int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " arg1 arg2" << std::endl;
        return 1;
    }

    std::string mazeFile = argv[1],
                mazeOutFile = argv[2];

    //Maze_Solver(mazeFile, "output.txt");
    std::ifstream inputFile(mazeFile);

    // read in maze from file
    std::vector<std::vector<char>> maze, solvedMaze;
    char c;
    std::vector<char> temp;
    if (inputFile.is_open()) {
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

    solvedMaze = maze;

    // initialize start and end positions
    int m_start_row = MAZE_START_ROW;
    int m_start_col = MAZE_START_COL;
    int m_end_row = maze.size()-1;
    int m_end_col = maze[0].size()-1;
    int m_current_row = m_start_row;
    int m_current_col = m_start_col;


    // initialize stack and push starting position onto stack
    Stack stack;
    Location location;
    location.m_col = m_current_col;
    location.m_row = m_current_row;
    stack.push(location);

    while (m_current_row != m_end_row && m_current_col != m_end_col){

        // if position to the right is open
        if (maze[m_current_row][m_current_col + 1] == ' ') {
            // push position to the right onto stack
            location.m_col = m_current_col = m_current_col + 1;
            location.m_row = m_current_row;
            maze[m_current_row][m_current_col] = 'X';
            stack.push(location);
        }
            // if position to the left is open
        else if(maze[m_current_row][m_current_col - 1] == ' ') {
            // push position to the left onto stack
            location.m_col = m_current_col = m_current_col - 1;
            location.m_row = m_current_row;
            maze[m_current_row][m_current_col] = 'X';
            stack.push(location);
        }
            // if position above is open
        else if(maze[m_current_row+1][m_current_col] == ' '){
            // push position above onto stack
            location.m_col = m_current_col;
            location.m_row = m_current_row = m_current_row + 1;
            maze[m_current_row][m_current_col] = 'X';
            stack.push(location);
        }
            // if position below is open
        else if(maze[m_current_row-1][m_current_col] == ' '){
            // push position above onto stack
            location.m_col = m_current_col;
            location.m_row = m_current_row = m_current_row - 1;
            maze[m_current_row][m_current_col] = 'X';
            stack.push(location);
        } else {
            // pop position off stack
            stack.pop();
            m_current_col = stack.getCol();
            m_current_row = stack.getRow();
        }
    }
    while (stack.m_first != nullptr){
        m_current_col = stack.getCol();
        m_current_row = stack.getRow();
        solvedMaze[m_current_row][m_current_col] = '#';
        stack.pop();
    }
    // Use a loop to iterate over the elements of the vector and write them to the file
    std::ofstream outputFile(mazeOutFile);
    for (const auto& innerVector : solvedMaze) {
        for (const auto& element : innerVector) {
            outputFile << element;
        }
        outputFile << std::endl;  // Add a newline character after each inner vector
    }
    // Close the output file stream
    outputFile.close();

    // Prints the solved maze to the console
    std::cout << "Maze solved!" << std::endl;
    for (const auto& innerVector : solvedMaze) {
        for (const auto& element : innerVector) {
            std::cout << element;
        }
        std::cout << std::endl;  // Add a newline character after each inner vector
    }
    return 0;
}