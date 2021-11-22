/*****************************************************************************
*** NAME        : Anqi Zhang                                               ***
*** CLASS       : CSC 354                                                  ***
*** ASSIGNMENT  : 5                                                        ***
*** DUE DATE    : Nov 25, 2020                                             ***
*** INSTRUCTOR  : Hamer                                                    ***
******************************************************************************
*** DESCRIPTION : String handler cpp file for manipulating lines of        ***
***               data from given data file.                               ***
***               Needs bts.h file for TreeNode data type, and user defined **
***               string data type.                                        ***
*****************************************************************************/

#include <string>
#include <iostream>
#include "string_handler.h"
#include "conversions.h"

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
string trim_leading_spaces(string str)
{
    int size = str.length(); // Keeps the size constant
    for (int i = 0; i < size; i++)
    {
        if (str[0] == ' ' || str[0] == '\t')
        {
            str.erase(0, 1);
        }
        else
        {
            break;
        }
    }
    return str;
}

/*********************************************************************************
*** FUNCTION: trim_trailing_spaces                                             ***
**********************************************************************************
*** DESCRIPTION : Passes in line of data as str and removes all spaces after str**
*** INPUT ARGS : string str                                                    ***
*** OUTPUT ARGS : N/A                                                          ***
*** IN/OUT ARGS : N/A                                                          ***
*** RETURN : return type - string, return value - str                          ***
*********************************************************************************/
string trim_trailing_spaces(string str)
{
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            str.erase(i, 1);
        }
        else
        {
            break;
        }
    }
    return str;
}


/***************************************************************************
*** FUNCTION: lower_to_upper                                             ***
****************************************************************************
*** DESCRIPTION : Passes in string and converts all letters to uppercase ***
*** INPUT ARGS : string str                                              ***
*** OUTPUT ARGS : N/A                                                    ***
*** IN/OUT ARGS : N/A                                                    ***
*** RETURN : return type - string, return value - str                    ***
***************************************************************************/
string lower_to_upper(string str)
{
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	return str;
}

/***************************************************************************
*** FUNCTION: format_data                                               ***
****************************************************************************
*** DESCRIPTION : formats data to remove unnecessary spaces              ***
*** INPUT ARGS : string str                                              ***
*** OUTPUT ARGS : N/A                                                    ***
*** IN/OUT ARGS : N/A                                                    ***
*** RETURN : return type - str                                           ***
***************************************************************************/
string format_data(string data)
{
    data = trim_leading_spaces(data);
    data = trim_trailing_spaces(data);
    data = lower_to_upper(data);

    return data;
}

/***************************************************************************
*** FUNCTION: format_symbol                                              ***
****************************************************************************
*** DESCRIPTION : formats symbol to remove unnecessary spaces            ***
*** INPUT ARGS : string symb                                             ***
*** OUTPUT ARGS : N/A                                                    ***
*** IN/OUT ARGS : N/A                                                    ***
*** RETURN : return type - symb                                          ***
***************************************************************************/
string format_symbol(string symb)
{
    symb = trim_leading_spaces(symb);
    symb = trim_trailing_spaces(symb);
    symb = lower_to_upper(symb);

    return symb;
}

/***************************************************************************
*** FUNCTION: pad_five_hex                                               ***
****************************************************************************
*** DESCRIPTION : Returns the hex of length 5 with padded zeroes         ***
*** INPUT ARGS : string hex                                              ***
*** OUTPUT ARGS : N/A                                                    ***
*** IN/OUT ARGS : N/A                                                    ***
*** RETURN : return type - string                                        ***
***************************************************************************/
string pad_five_hex(string hex)
{
    if (hex.length() == 1)
    {
        return "0000" + hex;
    }

    if (hex.length() == 2)
    {
        return "000" + hex;
    }

    if (hex.length() == 3)
    {
        return "00" + hex;
    }

    if (hex.length() == 4)
    {
        return "0" + hex;
    }

    if (hex.length() == 5)
    {
        return hex;
    }

    if (hex.length() > 5)
    {
        return hex.substr(hex.size() - 5, 5);
    }

    cout << "DEBUG: pad_five_hex returned no valid hex value" << endl;
    cout << "hex - " << hex << endl;
    cout << "hex.length() - " << hex.length() << endl;
    return "";
}

string pad_six_hex(string hex)
{
    if (hex.length() == 1)
    {
        return "00000" + hex;
    }

    if (hex.length() == 2)
    {
        return "0000" + hex;
    }

    if (hex.length() == 3)
    {
        return "000" + hex;
    }

    if (hex.length() == 4)
    {
        return "00" + hex;
    }

    if (hex.length() == 5)
    {
        return "0" + hex;
    }

    if (hex.length() == 6)
    {
        return hex;
    }

    cout << "DEBUG: pad_six_hex returned no valid hex value" << endl;
    cout << "hex - " << hex << endl;
    cout << "hex.length() - " << hex.length() << endl;
    return "";
}

string pad_six_hex_signed(string hex)
{
    if (positive_hex(hex))
    {
        if (hex.length() == 1)
        {
            return "00000" + hex;
        }

        if (hex.length() == 2)
        {
            return "0000" + hex;
        }

        if (hex.length() == 3)
        {
            return "000" + hex;
        }

        if (hex.length() == 4)
        {
            return "00" + hex;
        }

        if (hex.length() == 5)
        {
            return "0" + hex;
        }

        if (hex.length() == 6)
        {
            return hex;
        }
    }
    else
    {
        if (hex.length() == 1)
        {
            return "FFFFF" + hex;
        }

        if (hex.length() == 2)
        {
            return "FFFF" + hex;
        }

        if (hex.length() == 3)
        {
            return "FFF" + hex;
        }

        if (hex.length() == 4)
        {
            return "FF" + hex;
        }

        if (hex.length() == 5)
        {
            return "F" + hex;
        }

        if (hex.length() == 6)
        {
            return hex;
        }
    }

    cout << "DEBUG: pad_six_hex_signed returned no valid hex value" << endl;
    cout << "hex - " << hex << endl;
    cout << "hex.length() - " << hex.length() << endl;
    return "";
}

/***************************************************************************
*** FUNCTION: twos_complement                                            ***
****************************************************************************
*** DESCRIPTION : Converts hex to twos complement                        ***
*** INPUT ARGS : string hex                                              ***
*** OUTPUT ARGS : N/A                                                    ***
*** IN/OUT ARGS : N/A                                                    ***
*** RETURN : return type - string                                        ***
***************************************************************************/
string twos_complement(string hex)
{
    string flipped = "";
    for (int i = 0; i < hex.size(); i++)
    {
        if (hex[i] == '0')
        {
            flipped.append("F");
        }

        if (hex[i] == '1')
        {
            flipped.append("E");
        }

        if (hex[i] == '2')
        {
            flipped.append("D");
        }

        if (hex[i] == '3')
        {
            flipped.append("C");
        }

        if (hex[i] == '4')
        {
            flipped.append("B");
        }

        if (hex[i] == '5')
        {
            flipped.append("A");
        }

        if (hex[i] == '6')
        {
            flipped.append("9");
        }

        if (hex[i] == '7')
        {
            flipped.append("8");
        }

        if (hex[i] == '8')
        {
            flipped.append("7");
        }

        if (hex[i] == '9')
        {
            flipped.append("6");
        }

        if (hex[i] == 'A')
        {
            flipped.append("5");
        }

        if (hex[i] == 'B')
        {
            flipped.append("4");
        }

        if (hex[i] == 'C')
        {
            flipped.append("3");
        }

        if (hex[i] == 'D')
        {
            flipped.append("2");
        }

        if (hex[i] == 'E')
        {
            flipped.append("1");
        }

        if (hex[i] == 'F')
        {
            flipped.append("0");
        }
    }
    return pad_six_hex_signed(dec_to_hex(hex_to_dec(flipped) + 1));
}

/***************************************************************************
*** FUNCTION: positive_hex                                               ***
****************************************************************************
*** DESCRIPTION : checks to see if hex value is postiive                 ***
*** INPUT ARGS : string hex                                              ***
*** OUTPUT ARGS : N/A                                                    ***
*** IN/OUT ARGS : N/A                                                    ***
*** RETURN : return type - bool                                          ***
***************************************************************************/
bool positive_hex(string hex)
{
    if (hex[0] == '0')
    {
        return true;
    }
    if (hex[0] == '1')
    {
        return true;
    }
    if (hex[0] == '2')
    {
        return true;
    }
    if (hex[0] == '3')
    {
        return true;
    }
    if (hex[0] == '4')
    {
        return true;
    }
    if (hex[0] == '5')
    {
        return true;
    }
    if (hex[0] == '6')
    {
        return true;
    }
    if (hex[0] == '7')
    {
        return true;
    }

     return false;
}

