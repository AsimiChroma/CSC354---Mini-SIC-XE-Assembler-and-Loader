/*****************************************************************************
*** NAME        : Anqi Zhang                                               ***
*** CLASS       : CSC 354                                                  ***
*** ASSIGNMENT  : 5                                                        ***
*** DUE DATE    : Nov 25, 2020                                             ***
*** INSTRUCTOR  : Hamer                                                    ***
******************************************************************************
*** DESCRIPTION : String handler header file for manipulating lines of     ***
***               data from given data file.                               ***
***               Needs bts.h file for TreeNode data type, and user defined **
***               string data type.                                         ***
*****************************************************************************/

#ifndef _STRING_HANDLER_H  // File named string_handler.h
#define _STRING_HANDLER_H
#include<string>

using namespace std;

/*********************************************************************************
*** FUNCTION: trim_leading_spaces                                              ***
**********************************************************************************
*** DESCRIPTION : Passes in line of data as str and removes all spaces before str
*** INPUT ARGS : string str                                                    ***
*** OUTPUT ARGS : N/A                                                          ***
*** IN/OUT ARGS : N/A                                                          ***
*** RETURN : return type - string, return value - str                          ***
*********************************************************************************/
string trim_leading_spaces(string str);

/*********************************************************************************
*** FUNCTION: trim_trailing_spaces                                             ***
**********************************************************************************
*** DESCRIPTION : Passes in line of data as str and removes all spaces after str**
*** INPUT ARGS : string str                                                    ***
*** OUTPUT ARGS : N/A                                                          ***
*** IN/OUT ARGS : N/A                                                          ***
*** RETURN : return type - string, return value - str                          ***
*********************************************************************************/
string trim_trailing_spaces(string str);

/***************************************************************************
*** FUNCTION: lower_to_upper                                             ***
****************************************************************************
*** DESCRIPTION : Passes in string and converts all letters to uppercase ***
*** INPUT ARGS : string str                                              ***
*** OUTPUT ARGS : N/A                                                    ***
*** IN/OUT ARGS : N/A                                                    ***
*** RETURN : return type - string, return value - str                    ***
***************************************************************************/
string lower_to_upper(string str);

/***************************************************************************
*** FUNCTION: format_data                                               ***
****************************************************************************
*** DESCRIPTION : formats data to remove unnecessary spaces              ***
*** INPUT ARGS : string str                                              ***
*** OUTPUT ARGS : N/A                                                    ***
*** IN/OUT ARGS : N/A                                                    ***
*** RETURN : return type - str                                           ***
***************************************************************************/
string format_data(string data);

/***************************************************************************
*** FUNCTION: format_symbol                                              ***
****************************************************************************
*** DESCRIPTION : converts symbol to upper case and only 4 characters    ***
*** INPUT ARGS : string str                                              ***
*** OUTPUT ARGS : N/A                                                    ***
*** IN/OUT ARGS : N/A                                                    ***
*** RETURN : return type - str                                           ***
***************************************************************************/
string format_symbol(string str);

/***************************************************************************
*** FUNCTION: pad_five_hex                                               ***
****************************************************************************
*** DESCRIPTION : Returns the hex of length 5 with padded zeroes         ***
*** INPUT ARGS : string hex                                              ***
*** OUTPUT ARGS : N/A                                                    ***
*** IN/OUT ARGS : N/A                                                    ***
*** RETURN : return type - string                                        ***
***************************************************************************/
string pad_five_hex(string hex);

/***************************************************************************
*** FUNCTION: pad_six_hex                                                ***
****************************************************************************
*** DESCRIPTION : Returns the hex of length 6 with padded zeroes         ***
*** INPUT ARGS : string hex                                              ***
*** OUTPUT ARGS : N/A                                                    ***
*** IN/OUT ARGS : N/A                                                    ***
*** RETURN : return type - string                                        ***
***************************************************************************/
string pad_six_hex(string hex);

/***************************************************************************
*** FUNCTION: pad_six_hex                                                ***
****************************************************************************
*** DESCRIPTION : Returns the hex of length 6 with padded zeroes         ***
*** INPUT ARGS : string hex                                              ***
*** OUTPUT ARGS : N/A                                                    ***
*** IN/OUT ARGS : N/A                                                    ***
*** RETURN : return type - string                                        ***
***************************************************************************/
string pad_six_hex_signed(string hex);

/***************************************************************************
*** FUNCTION: twos_complement                                            ***
****************************************************************************
*** DESCRIPTION : Converts hex to twos complement                        ***
*** INPUT ARGS : string hex                                              ***
*** OUTPUT ARGS : N/A                                                    ***
*** IN/OUT ARGS : N/A                                                    ***
*** RETURN : return type - string                                        ***
***************************************************************************/
string twos_complement(string hex);

/***************************************************************************
*** FUNCTION: positive_hex                                               ***
****************************************************************************
*** DESCRIPTION : checks to see if hex value is postiive                 ***
*** INPUT ARGS : string hex                                              ***
*** OUTPUT ARGS : N/A                                                    ***
*** IN/OUT ARGS : N/A                                                    ***
*** RETURN : return type - bool                                          ***
***************************************************************************/
bool positive_hex(string hex);
#endif