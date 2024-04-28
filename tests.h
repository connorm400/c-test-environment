#ifndef TESTS_HEADER
#define TESTS_HEADER

typedef enum { TEST_FAIL, TEST_PASS } test_result;
typedef test_result(*test_fn)(void);
typedef struct {
    const char* description;
    test_fn fn;
} test;

test_result test_math(void);
test_result will_fail(void);


static const test tests[] = {
    { .fn = test_math, .description = "math test" },
    { .fn = will_fail, .description = "will fail" },
    { .fn = test_math, .description = "math test" },
};

test_result _tassert_fail(const char* expr, const char* file, unsigned int line);

#define TASSERT(expr) \
    if (!expr) { \
        return _tassert_fail(#expr, __FILE__, __LINE__); } 


int run_tests(void);

#endif