#include<cpr/cpr.h>
#include<fstream>
#include<iostream>
#include<expected>
#include<string>
#include<format>
#include<argparse/argparse.hpp>
#include<dotenv.h>
#include<fstream>

int main(int argc, char *argv[]){
    argparse::ArgumentParser program("AOC Input Parser");
    program.add_argument("day")
        .help("Input the day you would like to work on")
        .scan<'i',int>();
    try {
        program.parse_args(argc,argv);
    } catch (const std::exception& err) {
        std:: cerr << err.what() << std::endl;
        std::cerr << program;
        return 1;
    }
    auto input = program.get<int>("day");

    dotenv::init(".env");
    if(!std::getenv("SESSION")){
        std::cerr << "Session not found." << std::endl;
        return 1;
    }

    std::string formatted_url = std::format(
        "https://adventofcode.com/2024/day/{}/input",
        input 
    );

    std::cout << "Sending to " << formatted_url << std::endl;

    cpr::Response input_data = cpr::Get(
        cpr::Url(formatted_url),
        cpr::Cookies({"session",std::getenv("SESSION")})

    );


    std::ofstream outFile("input1.txt");
    outFile << input_data.text << std::endl;
    outFile.close();

    std::cout << input_data.text << std::endl;
}