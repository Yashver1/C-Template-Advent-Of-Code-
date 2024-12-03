#include <part2.h>
#include <fstream>
#include <sstream>
#include <iostream>
//array of pointers not pointer to array
int main(int argc, char* argv[]){

    try{
        std::fstream f("input1.txt");
        std::stringstream buffer;
        buffer << f.rdbuf();
        auto contents = buffer.str();
        std::cout << contents << std::endl;
        process(contents);
    } catch(std::exception &err){
        std::cerr << err.what() << std::endl;
        return 1;
    }

    return 0;
}