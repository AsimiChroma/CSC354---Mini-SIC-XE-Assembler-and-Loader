/********************************************************************
*** NAME        : Anqi Zhang                                      ***
*** CLASS       : CSC 354                                         ***
*** ASSIGNMENT  : 5                                               ***
*** DUE DATE    : Nov 25, 2020                                    ***
*** INSTRUCTOR  : Hamer                                           ***
*********************************************************************
*** DESCRIPTION : Binary search tree header file.                 ***
***               Includes user defined string data type.         ***
********************************************************************/

#ifndef _BST_H  // File named bst.h
#define _BST_H

#include<string>
using namespace std;

// Creates a struct TreeNode to hold symbol and all attributes
struct TreeNode
{
    string symb;
    TreeNode* left;
    TreeNode* right;
    string addr;
};

/**********************************************************************
*** FUNCTION: insert(TreeNode* &tree, string symb, string value, bool *
              rflag, bool iflag, bool mflag)                        ***
***********************************************************************
*** DESCRIPTION : Passes address of tree node, symbol, value, rflag, **
***                iflag, and mflag and inserts those values.       ***
*** INPUT ARGS : string symb, string value, bool rflag, bool iflag, ***
***               bool mflag                                        ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : TreeNode* &tree                                   ***
*** RETURN : N/A                                                    ***
**********************************************************************/
void insert(TreeNode*& ptr, string symb, string value);

/************************************************************************
*** FUNCTION: search(TreeNode* tree, string symb)                    ****
*************************************************************************
*** DESCRIPTION : Passes TreeNode pointer variable tree and symbol and **
***               searches through the bst to see if symbol is found. ***
*** INPUT ARGS : TreeNode* tree, string symb                          ***
*** OUTPUT ARGS : N/A                                                 ***
*** IN/OUT ARGS : N/A                                                 ***
*** RETURN : return type - TreeNode*, string ; return value - tree    ***
************************************************************************/
TreeNode* search(TreeNode* ptr, string symb);

/*****************************************************************************************
*** FUNCTION: view(TreeNode* tree)                                                     ***
******************************************************************************************
*** DESCRIPTION : Passes TreeNode pointer variable tree and outputs bst values.        ***
*** INPUT ARGS : TreeNode* tree                                                        ***
*** OUTPUT ARGS : N/A                                                                  ***
*** IN/OUT ARGS : int &line_count                                                      ***
*** RETURN : N/A                                                                       ***
*****************************************************************************************/
void view(TreeNode* ptr);

/********************************************************************
*** FUNCTION: destroy(TreeNode* &tree)                            ***
*********************************************************************
*** DESCRIPTION : Passes address of tree node and destroys bst.   ***
*** INPUT ARGS : N/A                                              ***
*** OUTPUT ARGS : N/A                                             ***
*** IN/OUT ARGS : TreeNode* &tree                                 ***
*** RETURN : N/A                                                  ***
********************************************************************/
void destroy(TreeNode*& ptr);

#endif