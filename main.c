#if testing
#include "tests.h"
int main(void) { return run_tests(); }
#else 


#include <stdio.h>

int main(int argc, char** argv) {
    puts("this will work normally");    
}

#endif