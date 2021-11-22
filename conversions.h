/*****************************************************************************
*** NAME        : Anqi Zhang                                               ***
*** CLASS       : CSC 354                                                  ***
*** ASSIGNMENT  : 5                                                        ***
*** DUE DATE    : Nov 25, 2020                                             ***
*** INSTRUCTOR  : Hamer                                                    ***
******************************************************************************
*** DESCRIPTION : Conversions header file.                                 ***
***               Converts generic inputs into an output of another        ***
***               format.                                                  ***
*****************************************************************************/

#ifndef _CONVERSIONS_H  // File named conversions.h
#define _CONVERSIONS_H

#include <string>
using namespace std;

/**********************************************************************
*** FUNCTION: dec_to_hex                                            ***
***********************************************************************
*** DESCRIPTION : Converts a decimal integer into a hexidecimal     *** 
***                that is formatted as datatype string             ***
*** INPUT ARGS : int dec                                            ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : N/A                                               ***
*** RETURN : return type - string, return value - store             ***
**********************************************************************/ 
string dec_to_hex(int dec);

/**********************************************************************
*** FUNCTION: hex_to_dec                                            ***
***********************************************************************
*** DESCRIPTION : Converts a hexidecimal into a decimal integer     *** 
***                that is formatted as datatype integer            ***
*** INPUT ARGS : int dec                                            ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : N/A                                               ***
*** RETURN : return type - int, return value - dec_val              ***
**********************************************************************/ 
int hex_to_dec(string str);

/**********************************************************************
*** FUNCTION: dec_to_hex_signed                                     ***
***********************************************************************
*** DESCRIPTION : Converts a decimal integer into a hexidecimal     ***
***                that is formatted as datatype string             ***
*** INPUT ARGS : int dec                                            ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : N/A                                               ***
*** RETURN : return type - string, return value - store             ***
**********************************************************************/
string dec_to_hex_signed(int dec);

/**********************************************************************
*** FUNCTION: hec_to_dex_signed                                     ***
***********************************************************************
*** DESCRIPTION : Converts a hexidecimal into a decimal integer     ***
***                that is formatted as datatype integer            ***
*** INPUT ARGS : int dec                                            ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : N/A                                               ***
*** RETURN : return type - int, return value - dec_val              ***
**********************************************************************/
int hex_to_dec_signed(string str);

#endif