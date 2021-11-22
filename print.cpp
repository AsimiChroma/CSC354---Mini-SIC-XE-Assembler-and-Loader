/*****************************************************************************
*** NAME        : Anqi Zhang                                               ***
*** CLASS       : CSC 354                                                  ***
*** ASSIGNMENT  : 5                                                        ***
*** DUE DATE    : Nov 25, 2020                                             ***
*** INSTRUCTOR  : Hamer                                                    ***
******************************************************************************
*** DESCRIPTION : Print cpp file.                                          ***
***               Prints various messages out to the terminal.             ***
*****************************************************************************/

#include <string>
#include <vector>
#include <iostream>
#include <iomanip> // For setw()
#include <fstream>
#include <math.h>
#include "print.h"
#include "bst.h"
#include "conversions.h"
#include "string_handler.h"


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
void print_blank_line()
{
	cout << endl;
}

/**********************************************************************
*** FUNCTION: print_symbol_header                                   ***
***********************************************************************
*** DESCRIPTION : Prints the header columns of the symbol table     ***
*** INPUT ARGS : N/A                                                ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : N/A                                               ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void print_symbol_header()
{
	cout << left << setw(14) << "SYMBOL" << setw(14) << "ADDRESS" << endl;
}

/**********************************************************************
*** FUNCTION: print_tree                                            ***
***********************************************************************
*** DESCRIPTION : Prints each bst node with proper formating        ***
***    with all attributes                                          ***
*** INPUT ARGS : TreeNode* tree                                     ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : N/A                                               ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void print_symbols(TreeNode* tree)
{
	cout << left << setw(14) << tree->symb << setw(14) << tree->addr << setw(14) << endl;
}

/**********************************************************************
*** FUNCTION: print_both_blank                                      ***
***********************************************************************
*** DESCRIPTION : Prints an empty line for both cout and outfile    ***
*** INPUT ARGS : N/A                                                ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : ofstream &outFile                                 ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void print_both_blank(ofstream& outFile)
{
	cout << endl;
	outFile << endl;
}

/**********************************************************************
*** FUNCTION: print_memory_header                                   ***
***********************************************************************
*** DESCRIPTION : Prints each memory header with proper formating   ***
*** INPUT ARGS : N/A                                                ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : N/A                                               ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void print_memory_header(ofstream& outFile)
{
	cout << left << setw(10) << "" << setw(4) << '0' << setw(4) << '1' << setw(4) << '2' << setw(4) << '3' << setw(4) <<
		setw(4) << '4' << setw(4) << '5' << setw(4) << '6' << setw(4) << '7' <<
		setw(4) << '8' << setw(4) << '9' << setw(4) << 'A' << setw(4) << 'B' <<
		setw(4) << 'C' << setw(4) << 'D' << setw(4) << 'E' << setw(4) << 'F' << endl;

	outFile << left << setw(10) << "" << setw(4) << '0' << setw(4) << '1' << setw(4) << '2' << setw(4) << '3' << setw(4) <<
		setw(4) << '4' << setw(4) << '5' << setw(4) << '6' << setw(4) << '7' <<
		setw(4) << '8' << setw(4) << '9' << setw(4) << 'A' << setw(4) << 'B' <<
		setw(4) << 'C' << setw(4) << 'D' << setw(4) << 'E' << setw(4) << 'F' << endl;
}

/**********************************************************************
*** FUNCTION: print_memory                                          ***
***********************************************************************
*** DESCRIPTION : Prints each byte in memory with proper formating  ***
*** INPUT ARGS : vector<string> memory, string progaddr             ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : N/A                                               ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void print_memory(vector<string> memory, string progaddr, ofstream& outFile)
{
	int index = 0;
	double columns = 16;
	double rows = ceil(memory.size() / columns);

	for (int i = 0; i < rows; i++)
	{
		cout << left << setw(10) << pad_five_hex(progaddr);
		outFile << left << setw(10) << pad_five_hex(progaddr);
			
		for (int j = 0; j < columns; j++)
		{
			if (index >= memory.size())
			{
				break;
			}
			cout << setw(4) << memory[index];
			outFile << setw(4) << memory[index];
			index++;
			
		}
		cout << endl;
		outFile << endl;

		progaddr = dec_to_hex(hex_to_dec(progaddr) + 16);
	}
}

/**********************************************************************
*** FUNCTION: print_exec                                            ***
***********************************************************************
*** DESCRIPTION : Prints execution address                          ***
*** INPUT ARGS : string execaddr                                    ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : ofstream& outFile                                 ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void print_exec(string execaddr, ofstream& outfile)
{
	cout << "Execution begins at address: " << execaddr << endl;
	outfile << "Execution begins at address: " << execaddr << endl;
}
