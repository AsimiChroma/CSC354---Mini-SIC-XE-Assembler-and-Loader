/***********************************************************************
*** NAME        : Anqi Zhang                                         ***
*** CLASS       : CSC 354                                            ***
*** ASSIGNMENT  : 5                                                  ***
*** DUE DATE    : Nov 25, 2020                                       ***
*** INSTRUCTOR  : Hamer                                              ***
************************************************************************
*** DESCRIPTION : Binary search tree cpp file.                       ***
***               Includes user defined string data type and "bst.h". **
***********************************************************************/

#include "bst.h"
#include "print.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/********************************************************************
*** FUNCTION: destroy(TreeNode* &tree)                            ***
*********************************************************************
*** DESCRIPTION : Passes address of tree node and destroys bst.   ***
*** INPUT ARGS : N/A                                              ***
*** OUTPUT ARGS : N/A                                             ***
*** IN/OUT ARGS : TreeNode* &tree                                 ***
*** RETURN : N/A                                                  ***
********************************************************************/
void destroy(TreeNode*& tree) // post order traversal
{
    if (tree != NULL)
    {
        destroy(tree->left); // Go Left
        destroy(tree->right); // Go Right
        delete tree; // Visit Current Node
        tree = NULL;
    }
    return;
}

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
void insert(TreeNode*& tree, string symb, string addr)
{
    if (tree == NULL)
    {
        tree = new TreeNode; // Exception Handling Not Used
        if (tree == NULL)
        {
            cerr << "Tree FULL – No Insertion" << endl;
        }
        else
        {
            tree->symb = symb;
            tree->left = NULL;
            tree->right = NULL;
            tree->addr = addr;

        }
    }
    else if (tree->symb > symb)
    {
        insert(tree->left, symb, addr);
    }
    else
    {
        insert(tree->right, symb, addr);
    }
    return;
}

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
TreeNode* search(TreeNode* tree, string symb)
{
    if (tree == NULL)
    {
        return tree; // return NULL;
    }
    else if (tree->symb == symb)
    {
        return tree;
    }
    else if (tree->symb > symb)
    {
        return search(tree->left, symb);
    }
    else
    {
        return search(tree->right, symb);
    }
}

/*****************************************************************************************
*** FUNCTION: view(TreeNode* tree)                                                     ***
******************************************************************************************
*** DESCRIPTION : Passes TreeNode pointer variable tree and outputs bst values.        ***
*** INPUT ARGS : TreeNode* tree                                                        ***
*** OUTPUT ARGS : N/A                                                                  ***
*** IN/OUT ARGS : int &line_count                                                      ***
*** RETURN : N/A                                                                       ***
*****************************************************************************************/
void view(TreeNode* tree) // in order traversal
{
    string enter;

    if (tree != NULL)
    {
        view(tree->left); // Go Left
        // visit current node (process current node – display current node)

        print_symbols(tree);

        view(tree->right); // Go Right
    }
    return;
}