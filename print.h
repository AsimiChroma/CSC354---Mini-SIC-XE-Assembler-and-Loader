/*****************************************************************************
*** NAME        : Anqi Zhang                                               ***
*** CLASS       : CSC 354                                                  ***
*** ASSIGNMENT  : 5                                                        ***
*** DUE DATE    : Nov 25, 2020                                             ***
*** INSTRUCTOR  : Hamer                                                    ***
******************************************************************************
*** DESCRIPTION : Print header file.                                       ***
***               Prints various messages out to the terminal.             ***
*****************************************************************************/

#ifndef _PRINT_H
#define _PRINT_H

#include <string>
#include <vector>
#include <fstream>
#include "bst.h"

using namespace std;

/**********************************************************************
*** FUNCTION: print_blank_line                                      ***
***********************************************************************
*** DESCRIPTION : Prints an empty line                              ***
*** INPUT ARGS : N/A                                                ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : N/A                                               ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void print_blank_line();

/**********************************************************************
*** FUNCTION: print_symbol_header                                   ***
***********************************************************************
*** DESCRIPTION : Prints each symbol header with proper formating   ***
*** INPUT ARGS : N/A                                                ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : N/A                                               ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void print_symbol_header();

/**********************************************************************
*** FUNCTION: print_symbols                                         ***
***********************************************************************
*** DESCRIPTION : Prints each bst node with proper formating        ***
***    with all attributes                                          ***
*** INPUT ARGS : TreeNode* tree                                     ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : N/A                                               ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void print_symbols(TreeNode* tree);

/**********************************************************************
*** FUNCTION: print_both_blank                                      ***
***********************************************************************
*** DESCRIPTION : Prints an empty line for both cout and outfile    ***
*** INPUT ARGS : N/A                                                ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : ofstream &outFile                                 ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void print_both_blank(ofstream& outFile);

/**********************************************************************
*** FUNCTION: print_memory_header                                   ***
***********************************************************************
*** DESCRIPTION : Prints each memory header with proper formating   ***
*** INPUT ARGS : N/A                                                ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : ofstream& outfile                                 ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void print_memory_header(ofstream& outFile);

/**********************************************************************
*** FUNCTION: print_memory                                          ***
***********************************************************************
*** DESCRIPTION : Prints each byte in memory with proper formating  ***
*** INPUT ARGS : vector<string> memory, string progaddr             ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : ofstream& outfile                                 ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void print_memory(vector<string> memory, string progaddr, ofstream& outFile);

/**********************************************************************
*** FUNCTION: print_exec                                            ***
***********************************************************************
*** DESCRIPTION : Prints execution address                          ***
*** INPUT ARGS : string execaddr                                    ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : ofstream& outfile                                 ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void print_exec(string execaddr, ofstream& outfile);


#endif