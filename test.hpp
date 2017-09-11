// the test file to test the string class
// include all needed files
#ifndef CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <cstring>
#include "NewString.h"

// use std
using namespace std;

TEST_CASE("String class","[string]"){

    // create 5 string objects
    String str1("Yu Chen");
    String str2("CSE2341");
    String str3("Program1");
    String str4("");
    String str5("\n");

    // test all functions in NewString class in order
    // test size() function first
    SECTION("size function"){
        REQUIRE(str1.size() == 7);
        REQUIRE(str2.size() == 7);
        REQUIRE(str3.size() == 8);
        REQUIRE(str4.size() == 0);
    }


    // test substring() function
    SECTION("substring function"){
        REQUIRE(str3.substring(0,2) == "Yu");
        REQUIRE(str2.substring(1,4) == "SE23");
        REQUIRE(str3.substring(7,1) == "1");
    }

    // test c_str function
    SECTION("c_str function"){
        REQUIRE(strcmp(str1.c_str(), "Yu Chen")==0);
        REQUIRE(strcmp(str2.c_str(), "CSE2341")==0);
        REQUIRE(strcmp(str4.c_str(), "")==0);
        REQUIRE(strcmp(str5.c_str(), "\n")==0);
    }

    //test = operator function and == function
    SECTION("= and == operator funtioncs"){

        // initialize new string object which equals str1
        String str6 = str1;

        //create a new object str7
        String str7;
        // change str7 to Hello
        char cstring1[]= "Hello";
        str7 = cstring1;

        REQUIRE(str1 == str6 );
        REQUIRE(str2 == "CSE2341");
        REQUIRE(str7 == "Hello");
    }

    // test + operator function
    SECTION("+ operator function"){
        REQUIRE(str1+str2 == "Yu ChenCSE2341");
        REQUIRE(str3+str2 == "Program1CSE2341");
        REQUIRE(str4+str5 == "\n");
    }

    // test > operator function
    SECTION("> operator function"){
        REQUIRE(str1 > str4);
        REQUIRE(str2 > str5);
        REQUIRE(str3 > str1);
        REQUIRE(str3 > str2);
    }

    // test [] operator function
    SECTION("[] operator function"){
        REQUIRE(str1[0] == 'Y');
        REQUIRE(str2[1] == 'S');
        REQUIRE(str3[2] == 'o');
    }

// end of test
};

#endif
