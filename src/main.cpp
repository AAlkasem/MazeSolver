#include <iostream>
#include "stack.h"
#include "maze_solver.h"


int main() {

    std::string mazeFile = "maze.txt";
    Maze_Solver(mazeFile, "output.txt");
//    std::ifstream inputFile(mazeFile);
//
//    // read in maze from file
//    std::vector<std::vector<char>> maze, solvedMaze;
//    char c;
//    std::vector<char> temp;
//    if (inputFile.is_open()) {
//        std::cout << "File opened successfully" << std::endl;
//        while (inputFile.get(c)) {
//            if (c == '\n') { // check if end of line is reached
//                maze.push_back(temp);
//                temp.clear();
//            } else {
//                temp.push_back(c);
//            }
//        }
//        // add last row to maze
//        if (!temp.empty()) {
//            maze.push_back(temp);
//        }
//        inputFile.close();
//    }else{
//        std::cout << "File cannot be opened" << std::endl;
//        return 0;
//    }
//
//    solvedMaze = maze;
//
//    // initialize start and end positions
//    int m_start_row = 1;
//    int m_start_col = 0;
//    int m_end_row = maze.size()-1;
//    int m_end_col = maze[0].size()-1;
//    int m_current_row = m_start_row;
//    int m_current_col = m_start_col;
//
//
//    // initialize stack and push starting position onto stack
//    Stack stack;
//    Location location;
//    location.m_col = m_current_col;
//    location.m_row = m_current_row;
//    stack.push(location);
//
//    while (m_current_row != m_end_row && m_current_col != m_end_col){
//
//        // if position to the right is open
//        if (maze[m_current_row][m_current_col + 1] == ' ') {
//            // push position to the right onto stack
//            location.m_col = m_current_col = m_current_col + 1;
//            location.m_row = m_current_row;
//            maze[m_current_row][m_current_col] = 'X';
//            stack.push(location);
//        }
//            // if position to the left is open
//        else if(maze[m_current_row][m_current_col - 1] == ' ') {
//            // push position to the left onto stack
//            location.m_col = m_current_col = m_current_col - 1;
//            location.m_row = m_current_row;
//            maze[m_current_row][m_current_col] = 'X';
//            stack.push(location);
//        }
//            // if position above is open
//        else if(maze[m_current_row+1][m_current_col] == ' '){
//            // push position above onto stack
//            location.m_col = m_current_col;
//            location.m_row = m_current_row = m_current_row + 1;
//            maze[m_current_row][m_current_col] = 'X';
//            stack.push(location);
//        }
//            // if position below is open
//        else if(maze[m_current_row-1][m_current_col] == ' '){
//            // push position above onto stack
//            location.m_col = m_current_col;
//            location.m_row = m_current_row = m_current_row - 1;
//            maze[m_current_row][m_current_col] = 'X';
//            stack.push(location);
//        } else {
//            // pop position off stack
//            stack.pop();
//            m_current_col = stack.getCol();
//            m_current_row = stack.getRow();
//        }
//    }
//    while (stack.m_first != nullptr){
//        m_current_col = stack.getCol();
//        m_current_row = stack.getRow();
//        solvedMaze[m_current_row][m_current_col] = '#';
//        stack.pop();
//    }
//    // print maze on console
//    for (int i = 0; i < solvedMaze.size(); i++) {
//        for (int j = 0; j < solvedMaze[i].size(); j++) {
//            std::cout << solvedMaze[i][j];
//        }
//        std::cout << std::endl;
//    }
    return 0;
}