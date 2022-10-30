//
// Created by ArtMed on 29.10.2022.
//

#include <iostream>
#include <filesystem>
#include "parser.h"



ParseErrors parse_arguments(int argc, char **argv, std::string &filename, double &x, double &y)
{
//    check number of arguments
    if (argc < 4)
    {
        return ParseErrors::INSUFFICIENT_ARGUMENTS;
    }
    if (argc > 4)
    {
        return ParseErrors::TO_MUCH_ARGUMENTS;
    }

    filename = std::string(argv[1]);

//    checking on existing file
    if (!std::filesystem::exists(filename)) {
        return ParseErrors::DOES_NOT_EXIST;
    }

    std::istringstream iss(argv[2]);
    if (!(iss >> x))
    {
        std::cout << "Invalid Input! Please input a numerical value." << std::endl;
        return ParseErrors::NOT_A_NUMBER;
    };
    iss>>x;

    std::istringstream is(argv[3]);
    if (!(is >> y))
    {
        std::cout << "Invalid Input! Please input a numerical value." << std::endl;
        return ParseErrors::NOT_A_NUMBER;
    };
    is >> y;

    return ParseErrors::SUCCESS;
}

std::string get_error_name(ParseErrors err_info)
{
    switch (err_info)
    {
        case ParseErrors::DOES_NOT_EXIST:
            return "This file doesn't exist";
        case ParseErrors::INSUFFICIENT_ARGUMENTS:
            return "Not enough arguments";
        case ParseErrors::TO_MUCH_ARGUMENTS:
            return "To much arguments";
        case ParseErrors::NOT_A_NUMBER:
            return "Wrong input: x and y must be double";
        case ParseErrors::SUCCESS:
            return "Success";
    }
    return "Unknown error";
}