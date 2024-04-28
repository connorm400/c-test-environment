#include "tests.h"
#include <stdio.h>
#include <stdint.h>

int run_tests(void) {
    puts("\033[36m===starting tests===\033[m");
    uint8_t tests_failed = 0;
    for (size_t i = 0; i < sizeof(tests) / sizeof(test); i++) {
        if (!tests[i].fn()) {
            printf("\033[91m===test \"%s\" failed===\033[m\n", tests[i].description);
            tests_failed++;
        } else {
            printf("\033[92m===test \"%s\" passed===\033[m\n", tests[i].description);
        }
    }
    
    if (tests_failed == 0) {
        puts("\033[102m===tests passed\033[m");
        return 0;
    } else {
        printf("\033[101m===%d tests failed===\033[m\n", tests_failed);
        return 1;
    }
}

test_result _tassert_fail(const char* expr, const char* file, unsigned int line) {
    printf("\033[91m====assert failed: \"%s\", line %d, %s===\033[m\n",
        expr, line, file);
    return TEST_FAIL;
}

test_result test_math(void) {
    TASSERT(1 > 2);
    return TEST_PASS;
}

test_result will_fail(void) {
    TASSERT(1 < 2);
}
