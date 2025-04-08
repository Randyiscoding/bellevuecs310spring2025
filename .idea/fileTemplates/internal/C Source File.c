#parse("C File Header.h")
#if (${HEADER_FILENAME})
#[[#include]]# "${HEADER_FILENAME}"

#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
#end