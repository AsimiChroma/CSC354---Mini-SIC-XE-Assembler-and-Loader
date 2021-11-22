/*****************************************************************************
*** NAME        : Anqi Zhang                                               ***
*** CLASS       : CSC 354                                                  ***
*** ASSIGNMENT  : 5                                                        ***
*** DUE DATE    : Nov 25, 2020                                             ***
*** INSTRUCTOR  : Hamer                                                    ***
******************************************************************************
*** DESCRIPTION : Conversions cpp file.                                    ***
***               Converts generic inputs into an output of another        ***
***               format.                                                  ***
*****************************************************************************/

#include <string>
#include <iostream>
#include "conversions.h"
#include "string_handler.h"

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
string dec_to_hex(int dec) // converts decimal value into hexadecimal value
{
    string store = "";
    string digit;

    if (dec == 0)
    {
        return "0";
    }
    while (dec != 0)
    {
        int temp = 0;
        temp = dec % 16;        // divide hex by 16 and store remainder

        if (temp < 10)
        {
            digit = temp + 48;
        }
        else
        {
            digit = temp + 55;
        }
        dec = dec / 16;
        // divide recursively until dec is 1
        // convert remainder numbers to hex
        // read remainder from last to first

        store = digit.append(store); // append what's stored to the new digit
    }
    return store;
}

/**********************************************************************
*** FUNCTION: dec_to_hex                                            ***
***********************************************************************
*** DESCRIPTION : Converts a hexidecimal into a decimal integer     ***
***                that is formatted as datatype integer            ***
*** INPUT ARGS : int dec                                            ***
*** OUTPUT ARGS : N/A                                               ***
*** IN/OUT ARGS : N/A                                               ***
*** RETURN : return type - int, return value - dec_val              ***
**********************************************************************/
int hex_to_dec(string str)
{
    str = lower_to_upper(str);
    int len = str.length();

    int base = 1;
    int dec_val = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            dec_val += (str[i] - 48) * base;
            base = base * 16;
        }
        else if (str[i] >= 'A' && str[i] <= 'F')
        {
            dec_val += (str[i] - 55) * base;
            base = base * 16;
        }
    }
    return dec_val;
}

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
string dec_to_hex_signed(int dec) // converts decimal value into hexadecimal value
{
    string store = "";
    string digit;

    if (dec == 0)
    {
        return "0";
    }

    if (dec > 1)
    {
        while (dec != 0)
        {
            int temp = 0;
            temp = dec % 16;        // divide hex by 16 and store remainder

            if (temp < 10)
            {
                digit = temp + 48;
            }
            else
            {
                digit = temp + 55;
            }
            dec = dec / 16;
            // divide recursively until dec is 1
            // convert remainder numbers to hex
            // read remainder from last to first

            store = digit.append(store); // append what's stored to the new digit
        }
        return store;
    }
    else
    {
        dec = dec * -1;

        while (dec != 0)
        {
            int temp = 0;
            temp = dec % 16;        // divide hex by 16 and store remainder

            if (temp < 10)
            {
                digit = temp + 48;
            }
            else
            {
                digit = temp + 55;
            }
            dec = dec / 16;
            // divide recursively until dec is 1
            // convert remainder numbers to hex
            // read remainder from last to first

            store = digit.append(store); // append what's stored to the new digit
        }
        return twos_complement(store);
    }
}

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
int hex_to_dec_signed(string str)
{
    str = lower_to_upper(str);
    int len = str.length();

    int base = 1;
    int dec_val = 0;

    if (positive_hex(str))
    {
        for (int i = len - 1; i >= 0; i--)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                dec_val += (str[i] - 48) * base;
                base = base * 16;
            }
            else if (str[i] >= 'A' && str[i] <= 'F')
            {
                dec_val += (str[i] - 55) * base;
                base = base * 16;
            }
        }
        return dec_val;
    }
    else
    {
        str = twos_complement(str);
        for (int i = len - 1; i >= 0; i--)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                dec_val += (str[i] - 48) * base;
                base = base * 16;
            }
            else if (str[i] >= 'A' && str[i] <= 'F')
            {
                dec_val += (str[i] - 55) * base;
                base = base * 16;
            }
        }
        return dec_val * -1;
    }
}