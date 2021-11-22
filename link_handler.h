/*****************************************************************************
*** NAME        : Anqi Zhang                                               ***
*** CLASS       : CSC 354                                                  ***
*** ASSIGNMENT  : 5                                                        ***
*** DUE DATE    : Nov 25, 2020                                             ***
*** INSTRUCTOR  : Hamer                                                    ***
******************************************************************************
*** DESCRIPTION : Link handler header file for manipulating listing        ***
***               information in assembler.                                ***
*****************************************************************************/

#ifndef _LINK_HANDLER_H
#define _LINK_HANDLER_H

#include <string>
#include <vector>
#include "bst.h"

/**********************************************************************
*** FUNCTION: find_cslth                                            ***
***********************************************************************
*** DESCRIPTION : finds length of program at header record          ***
*** INPUT ARGS : string data                                        ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : string& cslth                                     ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void find_cslth(string& cslth, string data);

/**********************************************************************
*** FUNCTION: initialize_memory                                     ***
***********************************************************************
*** DESCRIPTION : initializes memory block with "UU"                ***
*** INPUT ARGS : string cslth, string data                          ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : vector<string>& memory                            ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void initialize_memory(vector<string>& memory, string cslth, string data);

/**********************************************************************
*** FUNCTION: build_estab                                           ***
***********************************************************************
*** DESCRIPTION : builds external symbol table                      ***
*** INPUT ARGS : string data, string csaddr                         ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : TreeNode*& root                                   ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void build_estab(TreeNode*& root, string data, string csaddr);

/**********************************************************************
*** FUNCTION: update_csaddr                                         ***
***********************************************************************
*** DESCRIPTION : updates control section address                   ***
*** INPUT ARGS : string cslth, string data                          ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : string& csaddr                                    ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void update_csaddr(string& csaddr, string cslth, string data);

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
void update_memory(vector<string>& memory, TreeNode* root, string data, string csaddr, string progaddr);

/**********************************************************************
*** FUNCTION: find_exec                                             ***
***********************************************************************
*** DESCRIPTION : finds execution address of programv               ***
*** INPUT ARGS : string data, string csaddr, string progaddr        ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : string& execaddr                                  ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void find_exec(string& execaddr, string data, string csaddr, string progaddr);

#endif