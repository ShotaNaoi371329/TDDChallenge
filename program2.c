#include <CUnit/CUnit.h>
#include <CUnit/Console.h>

void sort(int array[], int num);
void test_sort_001(void);


int main() {
  CU_pSuite sort_suite;

  CU_initialize_registry();
  sort_suite = CU_add_suite("Sort", NULL, NULL);
  CU_add_test(sort_suite, "test_001", test_sort_001);
  CU_console_run_tests();
  CU_cleanup_registry();

  return(0);
}

void test_001(void){
    char list[] = "radius.list";
    CU_ASSERT(FileOpen(list)==1);
}
