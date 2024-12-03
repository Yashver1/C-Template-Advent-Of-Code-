#include<string>
#include <catch2/catch_test_macros.hpp>
#include<part2.h>

using namespace std;

string process(string &input){
    return "Hello";
    //throw logic_error("TODO: part1 not implemented");
}

namespace tests {
    TEST_CASE("Process function returns Hello") {
        string test = "2";
        REQUIRE( process(test) == "Hello");
    }
}






