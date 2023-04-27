//---------------------------------------------------------------------
//   Authors: Bryan Medina, Cristopher Briseno, Oscar Hernandez
//   Assignment  : No.5
//   Due Date    : 3/2/23
//   Description : Program cleans up text document by removing leading
//                  whitespace, comments, and any trailing whitespace
//                  as well. It also adds a space between each token.
//                  Condenses number of lines to only include necessary
//                  information. Varies indenting based on type of content
//                  on each line. Outputs to a text file labeled "newh5.txt".
//---------------------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

int main()
{
     fstream original;
     original.open("h5.txt", ios::in);
     string token;

     ofstream newFile("newh5.txt");

     if (original.is_open())
     {
          getline(original, token);
          bool isComment = false;
          int starCount = 0;
          while (original)
          {
               string toAdd;
               // removes leading whitespace
               size_t leadingWS = token.find_first_not_of(" ");
               bool endOfLine = false;
               for (int i = leadingWS; i < token.size(); ++i)
               {
                    int spaceCount = 0;
                    if (token[i] == ';')
                    {
                         endOfLine = true;
                    }
                    if (i == 0 || i == leadingWS)
                    {
                         endOfLine = false;
                    }
                    // looks for start of comment and flags comment
                    if (token[i] == '*')
                    {
                         ++starCount;
                         isComment = true;
                         
                    }
                    // iterates through comment until 4th asterisk is reached
                    while (isComment)
                    {
                         ++i;
                         if (i == token.size())
                         {
                              getline(original, token);
                              i = 0;
                         }
                         else if (token[i] == '*')
                         {
                              ++starCount;
                         }
                         if (starCount == 4)
                         {
                              isComment = false;
                              starCount = 0;
                              ++i;
                         }
                    }
                    // handles whitespace between tokens to limit it to just 1
                    if (token[i] == ' ' && !endOfLine)
                    {
                         toAdd.push_back(' ');
                         string restOfString = token.substr(i, token.size() - i);
                         size_t nextNonSpace = restOfString.find_first_not_of(' ');
                         i += nextNonSpace;
                         if (token[i] == '*')
                         {
                              ++starCount;
                         }
                    }
                    // adds character in token to string
                    if ((!endOfLine || token[i] == ';') && token[i] != '*')
                    {
                         toAdd.push_back(token[i]);
                         if ((token[i] == ')') && (token[i+1] == ';'))
                         {
                              toAdd.push_back(' ');
                         }
                    }
               }
               // if size < 2, it is assumed just whitespace, clear string
               if (toAdd.size() < 2)
               {
                    toAdd.clear();
               }
               // if there is content in string, pushed to file
               if (!toAdd.empty())
               {
                    if (isalpha(toAdd.back()) || toAdd.back() == '.')
                    {
                         newFile << string(5, ' ') << toAdd;
                    }
                    else
                    {
                         newFile << string(10, ' ') << toAdd;
                    }
               }
               // moves to next line
               getline(original, token);
               // if there is content in string and buffer, add new line
               if (original && !toAdd.empty())
               {
                    newFile << endl;
               }
          }
     }
     newFile.close();
     return 0;
}
