#include "tokens.hpp"
#include <map>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;


 /*
 ||  ||  ||
             || sub_string == "\\0"
 */
std::string TokenTypes[] =
{
     "Error"
     "VOID"
     "INT"
     "BYTE"
     "B"
     "BOOL"
     "AND"
     "OR"
     "NOT"
     "TRUE"
     "FALSE"
     "RETURN"
     "IF"
     "ELSE"
     "WHILE"
     "BREAK"
     "CONTINUE"
     "SWITCH"
     "CASE"
     "DEFAULT"
     "COLON"
     "SC"
     "COMMA"
     "LPAREN"
     "RPAREN"
     "LBRACE"
     "RBRACE"
     "ASSIGN"
     "RELOP"
     "BINOP"
     "COMMENT"
     "ID"
     "NUM"
     "STRING"
};


string print_token(string token_string, int type)
{
    string str = token_string;
    if(type == STRING){
        while((str.find("\\") != string::npos))
        {
            size_t position = str.find("\\"); //use "size_t"?
            string sub_string = str.substr(position,2);
            if(sub_string == "\\\\")
            {
                string updated_string = str.substr(0,position);
                updated_string += "\\";
                updated_string += str.substr(position+2);
                str = updated_string;
            }
            else if(sub_string == "\\\"")
            {
                string updated_string = str.substr(0,position);
                updated_string += "\"";
                updated_string += str.substr(position+2);
                str = updated_string;
            }
            else if(sub_string == "\\r")
            {
                string updated_string = str.substr(0,position);
                updated_string += "\r";
                updated_string += str.substr(position+2);
                str = updated_string;
            }
            else if(sub_string == "\\t")
            {
                string updated_string = str.substr(0,position);
                updated_string += "\t";
                updated_string += str.substr(position+2);
                str = updated_string;
            }
            else if(sub_string == "\\0")
            {
                string updated_string = str.substr(0,position);
                updated_string += "\0";
                //updated_string += str.substr(position+2);
                str = updated_string;
            }
            else if(sub_string == "\\x")
            {
                string phrase = str.substr(position+1,4);
                char phrase2[phrase.length() + 1];
                strcpy(phrase2, phrase.c_str());
                int heximal_val = strtol(phrase2,NULL,16);
                if(heximal_val == 0)
                {
                    std::cout << "Error undefined escape sequence " << token_string.substr(position + 1,3);
                    std::cout << std::endl;
                    exit(0);
                }
            }
            else
            {
                std::cout << "Error undefined escape sequence " << token_string.substr(position + 1,1);
                std::cout << std::endl;
                exit(0);
            }
        }
        return str;
    }
    else
    {
        return token_string;
    }
}

void print_token_aux(int num)
{
    if(num<0)
    {
        if(num == -1)
        {
            std::cout << "Error" << yytext;
            std::cout << std::endl;
            exit(0);
        }
        else if (num == -2)
        {
            std::cout << "Error unclosed string";
            std::cout << std::endl;
            exit(0);
        }
    }
    else
    {
        std::string line_num = to_string(yylineno);
        std::cout << line_num << " " << TokenTypes[num] << " " << print_token(yytext,num);
        std::cout << std::endl;
    }

}


int main()
{
	int token;
	while(token = yylex()) {
	    if(token != -4)
	    {
            print_token_aux(token);
	    }
	// Your code here
	}
	return 0;
}