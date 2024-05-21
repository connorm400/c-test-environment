#ifndef TESTS_HEADER
#define TESTS_HEADER

typedef enum { TEST_FAIL, TEST_PASS } test_result;
typedef test_result(*test_fn)(void);
typedef struct {
    test_fn fn;
    const char* str;
} test;

test_result test_math(void);
test_result will_fail(void);

#define TEST(fnname) \
    { .fn = fnname, .str = #fnname }

static const test tests[] = {
    TEST(test_math),
    TEST(will_fail),
    TEST(test_math),
};

test_result _tassert_fail(const char* expr, const char* file, unsigned int line);

#define TASSERT(expr) \
    if (!expr) { \
        return _tassert_fail(#expr, __FILE__, __LINE__); } 


int run_tests(void);

#endif