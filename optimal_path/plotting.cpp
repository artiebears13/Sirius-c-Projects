//
// Created by ArtMed on 31.10.2022.
//
#include <iostream>

void plot(std::string filename){
    std::string cmd_command = "python ..\\plot.py "+filename;
    std::cout<<cmd_command;
    system((cmd_command.c_str()));
}