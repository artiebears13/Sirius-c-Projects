#include <iostream>
#include <string>


int main(){
    std::string message;
    std::cout<<"enter message: "<<std::endl;
    std::cin>>message;
    std::cout << "starting python script and want to output '"<< message<<"'"<<std::endl;
    std::string command="python3 C:\\Users\\ArtMed\\Desktop\\Sirius-c-Projects\\c_and_python\\script.py "+message;
    std::cout<<command<<std::endl;
    system(command.c_str());
    return 0;
}