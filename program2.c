#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void sort(int array[], int num);
void test_001(void);
int FileOpen(char list[]);

int main() {
  CU_pSuite sort_suite;

  CU_initialize_registry();
  sort_suite = CU_add_suite("radius", NULL, NULL);
  CU_add_test(sort_suite, "test_001", test_001);
  CU_console_run_tests();
  CU_cleanup_registry();

  return(0);
}

void test_001(void){
    char list[] = "radius.list";
    CU_ASSERT(FileOpen(list)==1);
}

int FileOpen(char list[]) {
    
    FILE *fp;
    
    char filename[256];
    char path[256];
    
    
    strcpy(filename,list);
    sprintf(path,"%s",filename);
    //printf("path=[%s]\n", path);
    
    fp = fopen( path, "r" );
    if( fp == NULL )
    {
        //fprintf(stderr, "file [%s] open error: %s\n", path, strerror(errno));
        return -1;
    } else {
        
        return 1;
    }
    //fp = fopen(*list,"r");

}
