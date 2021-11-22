/*****************************************************************************
*** NAME        : Anqi Zhang                                               ***
*** CLASS       : CSC 354                                                  ***
*** ASSIGNMENT  : 5                                                        ***
*** DUE DATE    : Nov 25, 2020                                             ***
*** INSTRUCTOR  : Hamer                                                    ***
******************************************************************************
*** DESCRIPTION : Linker loader                                            ***
*****************************************************************************/
#include <iostream> // cin and cout
#include <fstream> // file input and output
#include <string>
#include <vector>
#include "bst.h"
#include "string_handler.h"
#include "link_handler.h"
#include "conversions.h"
#include "print.h"

using namespace std; // standard namespace - identifier scope

int main(const int argc, const char* argv[])
{
    string progaddr = "2750";
    string csaddr = progaddr;
    string execaddr = progaddr;
    string cslth = "";
    vector<string> memory;
    TreeNode* root = NULL; //External Symbol Table
    ifstream infile;
    ofstream outfile;

    if (argc == 1)
    {
        cerr << "No arguments passed" << endl;
    }
    else
    {
        //-------------------Pass 1 Start ------------------
        for (int i = 1; i < argc; i++)
        {
            string filename;
            string data;
            
            filename = argv[i];
            infile.open(filename);

            while (getline(infile, data))
            {
                data = format_data(data);
                find_cslth(cslth, data); //finds cslth when 'H' record
                initialize_memory(memory, cslth, data); //Initializes block of memory with "UU"
                build_estab(root, data, csaddr); //builds external symbol table
                update_csaddr(csaddr, cslth, data); //updates csaddr when 'E' record
            }

            infile.close();
        }
        //-------------------Pass 1 End---------------------


        //-------------------Pass 2 Start ------------------
        csaddr = progaddr;
        for (int i = 1; i < argc; i++)
        {
            string filename;
            string data;

            filename = argv[i];
            infile.open(filename);

            while (getline(infile, data))
            {
                data = format_data(data);
                find_cslth(cslth, data); //finds cslth when 'H' record
                update_memory(memory, root, data, csaddr, progaddr); //update memory with 'T' or 'M' record
                find_exec(execaddr, data, csaddr, progaddr); //updates execaddr
                update_csaddr(csaddr, cslth, data); //updates csaddr when 'E' record   
            }

            infile.close();
        }
        //-------------------Pass 2 End---------------------

        outfile.open("MEMDUMP.DAT");

        //Print Memory Table
        print_memory_header(outfile);
        print_memory(memory, progaddr, outfile);

        //Print Execution Address
        print_both_blank(outfile);
        print_exec(execaddr, outfile);

        outfile.close();

        //Print Symbol Table
        print_blank_line();
        print_symbol_header();

        view(root);
        destroy(root);
    }
    return 0;

} // End of main