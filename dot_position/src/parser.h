#pragma once
#include <string>

enum class ParseErrors
{
    DOES_NOT_EXIST = -4,
    INSUFFICIENT_ARGUMENTS = -3,
    TO_MUCH_ARGUMENTS = -2,
    NOT_A_NUMBER = -1,
    SUCCESS = 0
};

ParseErrors parse_arguments(int argc, char **argv, std::string &filename, double &x, double &y);

std::string get_error_name(ParseErrors err_info); 