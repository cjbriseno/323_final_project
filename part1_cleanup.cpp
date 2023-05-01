//---------------------------------------------------------------------
//   Authors: Bryan Medina, Cristopher Briseno, Oscar Hernandez
//   Assignment  : Final Project - Part 1
//   Due Date    : May 2023
//   Description : Cleans up text file to remove any extra
//                  whitespaces, includes a space between
//                  each token, removes comments and 
//                  blank lines, and leaves one space before
//                  and after each token.
//---------------------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

void leftTrim(string& current);
void rightTrim(string& current);

int main()
{
     fstream original;
     original.open("finalp1.txt", ios::in);
     string token;

     ofstream newFile("finalp2.txt");

     if (original.is_open())
     {
          getline(original, token);
          bool isComment = false;
          while (original)
          {
               // If line is not blank, perform the following
               if (token.size() > 0)
               {
                    leftTrim(token);
                    rightTrim(token);
                    size_t semicolon = token.find(';');
                    // If line contains semicolon, create substring ending
                    // at that ';' position
                    if (semicolon != string::npos)
                    {
                         token = token.substr(0, semicolon + 1);
                    }
                    // If line begins with a comment or is the ending
                    // of a comment, remove those lines
                    if (token.front() == '/' || token.back() == '/')
                    {
                         isComment = true;
                    }
                    // If line is not a comment, perform the following
                    if (!isComment)
                    {
                         // Iterate through string
                         for (size_t i = 0; i < token.size(); ++i)
                         {
                              // If literal string detected, perform the following
                              if (token[i] == '"')
                              {
                                   int newPos = token.find_last_of('"');
                                   i = newPos;
                              }
                              // If whitespace, perform the following
                              else if (token[i] == ' ')
                              {
                                   if (token[i + 1] == ' ')
                                   {
                                        token.erase(i, 1);
                                        --i;
                                   }

                              }
                              // If any arithmetic operators, perform the following
                              else if (token[i] == '+' || token[i] == '-'
                                   || token[i] == '*' ||
                                   token[i] == '=' || token[i] == '('
                                   || token[i] == ')')
                              {
                                   if (token[i - 1] != ' ')
                                   {
                                        token.insert(i, " ");
                                        ++i;
                                   }
                                   if (token[i + 1] != ' ')
                                   {
                                        token.insert(i + 1, " ");
                                   }
                              }
                              else if (token[i] == ';')
                              {
                                   if (token[i - 1] != ' ')
                                   {
                                        token.insert(i, " ");
                                        ++i;
                                   }
                              }
                         }
                         // Add token to newFile
                         newFile << token;
                         // If buffer has remaining text, add new line
                         if (original)
                         {
                              newFile << endl;
                         }
                    }
               }
               // Reset isComment flag
               isComment = false;
               // Move onto next line in buffer
               getline(original, token);
          }

     }
     newFile.close();
     return 0;
}
// Removes leading whitespace from line
void leftTrim(string& current)
{
     size_t pos = current.find_first_not_of(" ");
     current = current.substr(pos);
}
// Removes trailing whitespace from line
void rightTrim(string& current)
{
     size_t pos = current.find_last_not_of(" ");
     current = current.substr(0, pos + 1);
}