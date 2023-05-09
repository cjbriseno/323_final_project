//---------------------------------------------------------------------
//   Authors: Bryan Medina, Cristopher Briseno, Oscar Hernandez
//   Assignment  : Final Project - Parser
//   Due Date    : 05/09/2023
//   Description : Program iterates through a text file to determine
//                  if it works.
//---------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
#include "OURFUNCTIONS.h"

using namespace std;

int main()
{

     string original = "finalp1.txt";
     cleanup(original);
     string newProgram = "finalp2.txt";
     bool errorFound = false;
     errorCheck(newProgram, errorFound);
     if (!errorFound)
     {
          parse(newProgram);
     }

     return 0;
}