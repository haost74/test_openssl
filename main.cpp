#define _CRT_SECURE_NO_WARNINGS
// cmake -G "MSYS Makefiles" ..

#include <iostream>
#include <fstream>
#include <sstream>

#include <stdio.h>

#include <string>
#include <vector>

#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>

#include<stdio.h>
#include<windows.h>


int main(int argc, char **argv){


   setlocale(LC_ALL, "Russian");


  std::ifstream input( "../test.txt", std::ios::binary );

    // copies all data into buffer
    //std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(input), {});
    // std::stringstream ss_;
    // std::string s( buffer.begin(), buffer.end() );
    // std::cout << s << '\n';
    std::ofstream output ("../me2.doc",std::fstream::trunc|std::fstream::binary);

    std::copy( 
        std::istreambuf_iterator<char>(input), 
        std::istreambuf_iterator<char>( ),
        std::ostreambuf_iterator<char>(output));

    return 0;
}
