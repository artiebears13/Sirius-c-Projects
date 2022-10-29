//
// Created by ArtMed on 29.10.2022.
//
#include <sstream>
#include <cstdio>
#include <iostream>
#include <filesystem>
#include "parser.h"
#include "robot.h"


ParseErrors parse_arguments(int argc, char **argv, std::string &filename, double &x, double &y)
{
    if (argc < 4)
    {
        return ParseErrors::INSUFFICIENT_ARGUMENTS;
    }
    if (argc > 4)
    {
        return ParseErrors::TO_MUCH_ARGUMENTS;
    }

    filename = std::string(argv[1]);

    if (!std::filesystem::exists(filename)) {
        return ParseErrors::DOES_NOT_EXIST;
    }

    std::istringstream iss(argv[2]);

    iss >> x;

    if (iss.fail() || (sscanf(argv[3], "%lf", &y) != 1))
    {
        return ParseErrors::NOT_A_NUMBER;
    }
    return ParseErrors::SUCCESS;
}


std::string get_error_name(ParseErrors err_info)
{
    switch (err_info)
    {
        case ParseErrors::DOES_NOT_EXIST:
            return "File doesn't exist";
        case ParseErrors::INSUFFICIENT_ARGUMENTS:
            return "Not enough arguments";
        case ParseErrors::TO_MUCH_ARGUMENTS:
            return "To much arguments";
        case ParseErrors::NOT_A_NUMBER:
            return "Can not convert input argument to double";
        case ParseErrors::SUCCESS:
            return "No error";
    }
    return "Unknown error";
}