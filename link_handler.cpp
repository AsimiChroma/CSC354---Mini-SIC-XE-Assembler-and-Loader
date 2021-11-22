/*****************************************************************************
*** NAME        : Anqi Zhang                                               ***
*** CLASS       : CSC 354                                                  ***
*** ASSIGNMENT  : 5                                                        ***
*** DUE DATE    : Nov 25, 2020                                             ***
*** INSTRUCTOR  : Hamer                                                    ***
******************************************************************************
*** DESCRIPTION : Link handler cpp file for manipulating listing           ***
***               information in assembler.                                ***
*****************************************************************************/
#include <string>
#include <iostream>
#include "link_handler.h"
#include "string_handler.h"
#include "bst.h"
#include "conversions.h"

using namespace std;

/**********************************************************************
*** FUNCTION: find_cslth                                            ***
***********************************************************************
*** DESCRIPTION : finds length of program at header record          ***
*** INPUT ARGS : string data                                        ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : string& cslth                                     ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void find_cslth(string &cslth, string data)
{
	if (data[0] == 'H')
	{
		cslth = data.substr(11, 6);
	}
}

/**********************************************************************
*** FUNCTION: initialize_memory                                     ***
***********************************************************************
*** DESCRIPTION : initializes memory block with "UU"                ***
*** INPUT ARGS : string cslth, string data                          ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : vector<string>& memory                            ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void initialize_memory(vector<string>& memory, string cslth, string data)
{
	if (data[0] == 'H')
	{
		memory.resize(memory.size() + hex_to_dec(cslth), "UU");
	}
}

/**********************************************************************
*** FUNCTION: build_estab                                           ***
***********************************************************************
*** DESCRIPTION : builds external symbol table                      ***
*** INPUT ARGS : string data, string csaddr                         ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : TreeNode*& root                                   ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void build_estab(TreeNode*& root, string data, string csaddr)
{
	if (data[0] == 'H')
	{
		string symb = data.substr(1, 4);
		insert(root, symb, csaddr);
	}

	if (data[0] == 'D')
	{

		for (int i = 0; i < data.size(); i++)
		{
			if ((i - 1) % 10 == 0)
			{
				string symb = data.substr(i, 4);
				string addr = data.substr(i + 4, 6);

				symb = format_symbol(symb);
				addr = dec_to_hex(hex_to_dec(addr) + hex_to_dec(csaddr));
				insert(root, symb, addr);
			}
		}
	}
}

/**********************************************************************
*** FUNCTION: update_csaddr                                         ***
***********************************************************************
*** DESCRIPTION : updates control section address                   ***
*** INPUT ARGS : string cslth, string data                          ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : string& csaddr                                    ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void update_csaddr(string& csaddr, string cslth, string data)
{
	if (data[0] == 'E')
	{
		csaddr = dec_to_hex(hex_to_dec(csaddr) + hex_to_dec(cslth));
	}
}

/**********************************************************************
*** FUNCTION:update_memory                                          ***
***********************************************************************
*** DESCRIPTION : updates memory with "T" and "M" Records           ***
*** INPUT ARGS : TreeNode* root, string data, string csaddr,        ***
***                        string progaddr                          ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : vector<string>& memory                            ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void update_memory(vector<string>& memory, TreeNode* root, string data, string csaddr, string progaddr)
{
	if (data[0] == 'T')
	{
		string start = data.substr(1, 6);
		string length = data.substr(7, 2);
		string records = data.substr(9, data.length() - 9);

		int offset = hex_to_dec(start) + hex_to_dec(csaddr) - hex_to_dec(progaddr);
		for (int i = 0; i < hex_to_dec(length); i++)
		{
			memory[offset] = records.substr(2 * i, 2);
			offset++;
		}
	}

	if (data[0] == 'M')
	{
		string start = data.substr(1, 6);
		string length = data.substr(7, 2);
		string sign = data.substr(9, 1);
		string symbol = data.substr(10, data.length() - 10);
		string addr;

		int offset = hex_to_dec(start) + hex_to_dec(csaddr) - hex_to_dec(progaddr);
		symbol = format_symbol(symbol);
		TreeNode* ptr = search(root, symbol);
		
		if (length == "05") //Format 4 
		{
			string memory_addr = memory[offset].substr(1,1) + memory[offset + 1] + memory[offset + 2];
			string symb_addr = pad_six_hex(ptr->addr);

			if (sign == "+")
			{
				int value = hex_to_dec_signed(memory_addr) + hex_to_dec_signed(symb_addr);
				addr = pad_five_hex(dec_to_hex_signed(value));
			}

			if (sign == "-")
			{
				int value = hex_to_dec(memory_addr) - hex_to_dec(symb_addr);
				addr = pad_five_hex(dec_to_hex(value));
			}

			memory[offset] = memory[offset].substr(0, 1) + addr.substr(0, 1);
			memory[offset + 1] = addr.substr(1, 2);
			memory[offset + 2] = addr.substr(3, 2);

		}
		else if (length == "06") //Word
		{
			string memory_addr = memory[offset] + memory[offset + 1] + memory[offset + 2];
			string symb_addr = pad_six_hex(ptr->addr);

			if (sign == "+")
			{
				int value = hex_to_dec_signed(memory_addr) + hex_to_dec_signed(symb_addr);
				addr = pad_six_hex(dec_to_hex_signed(value));
			}

			if (sign == "-")
			{
				int value = hex_to_dec_signed(memory_addr) - hex_to_dec_signed(symb_addr);
				addr = pad_six_hex(dec_to_hex_signed(value));
			}

			memory[offset] = addr.substr(0, 2);
			memory[offset + 1] = addr.substr(2, 2);
			memory[offset + 2] = addr.substr(4, 2);
		}
	}
}

/**********************************************************************
*** FUNCTION: find_exec                                             ***
***********************************************************************
*** DESCRIPTION : finds execution address of programv               ***
*** INPUT ARGS : string data, string csaddr, string progaddr        ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : string& execaddr                                  ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void find_exec(string& execaddr, string data, string csaddr, string progaddr)
{
	if (data[0] == 'E' && (csaddr == progaddr))
	{
		string addr = data.substr(1,data.size()-1);
		execaddr = dec_to_hex(hex_to_dec(csaddr) + hex_to_dec(addr));
		execaddr = pad_five_hex(execaddr);
	}
}