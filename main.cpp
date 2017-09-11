#define TEST false
#include "checker.h"
#include "NewString.h"
#include "test.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int runCatchTests(int argc, char* const argv[]){
    return Catch::Session().run(argc, argv);

}
int main( int argc, char* const argv[] ){

    if(TEST){
        return runCatchTests(argc, argv);
    }

    return 0;

    if(argc ==4){
        Checker checker1(argv[1],argv[2],argv[3]);
    }
}
