#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include <stdio.h>
#include <stdlib.h>

void test_example(void);
void test_isEmpty(void);
int isEmpty(int stack[]);

int main(void) {
    
    CU_pSuite sort_suite;
    
    CU_initialize_registry();
    //sort_suite = CU_add_suite("Sort", NULL, NULL);
    sort_suite = CU_add_suite("isEmpty", NULL, NULL);
    //CU_add_test(sort_suite, "test_example", test_example);
    CU_add_test(sort_suite, "test_isEmpty", test_isEmpty);
    CU_console_run_tests();
    CU_cleanup_registry();
    
    return 0;
}


void test_example(void){
    
    CU_ASSERT(CU_FALSE);
}

void test_isEmpty(void) {
    
    int stack[10] = {0};
    
    CU_ASSERT(isEmpty(stack) == 1);
}

int isEmpty(int stack[]) {
    return 1;
};
