#ifndef OURFUNCTIONS
#define OURFUNCTIONS

#include <string>
#include <fstream>
#include <stack>

void leftTrim(std::string& current);

void rightTrim(std::string& current);

void cleanup(std::string filename);

void errorCheck(std::string newProgram, bool& errorFound);

void checkReserved(bool& programFound, bool& varFound, bool& beginFound,
     bool& endFound, bool& integerFound, std::string str);

void addToStack(std::stack<std::string>& myStack, std::string entry);

void getCol(std::string a, int& col);

void getRow(std::string a, int& row);

void printStack(std::stack<std::string> myStack);

void parse(std::string filename);

void pushAndPop(std::stack<std::string>& stack1, std::string& newToken, bool& done);


#endif 
