#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

//void sort(int array[], int num);
//int FileOpen(char list[]);
//void test_002(void);
void test_001(void);
double* read_list();

int main() {
    
    CU_pSuite sort_suite;
    
    CU_initialize_registry();
    sort_suite = CU_add_suite("radius", NULL, NULL);
    CU_add_test(sort_suite, "test_001", test_001);
    CU_console_run_tests();
    CU_cleanup_registry();
    return(0);
}

double* read_list(double *r) {
    
    char buf[1000000];
    
    ssize_t str =  read(0, buf, 1000000);
    printf("\n%zd\n", str);
    char rc[100000];
    int count = 0;
    int number = 0;
    for (int i = 0; i < (int)str; i++) {
        if (buf[i] == '\n') {
            rc[count] = buf[i];
            count = 0;
            r[number] = atof(rc);
            printf("atof r = %f\n", r[number]);
            number++;
        } else {
            rc[count] = buf[i];
            count++;
        }
    }
    r[number] = -1;
    return r;
}

void test_001(void){
    double *numbers = malloc(sizeof(double) * 10000);
    numbers = read_list(numbers);
    for(int i=0;numbers[i] != -1;i++){
        double num = numbers[i];
        func(num);
        CU_ASSERT(func(num));
    }
    free(numbers);
}

double func(double *ra){
    return ra*ra*PI;
}

/*double func(double *r){
    return *r
}*/



//void

//void test_001(void){
//    char list[] = "radius.list";
//    CU_ASSERT(FileOpen(list)==1);
//}
//
//void test_002(void) {
//    
//}
//
//int FileOpen(char list[]) {
//    
//    FILE *fp;
//    
//    char filename[256];
//    char path[256];
//    
//    
//    strcpy(filename,list);
//    sprintf(path,"%s",filename);
//    //printf("path=[%s]\n", path);
//    
//    fp = fopen( path, "r" );
//    if( fp == NULL )
//    {
//        //fprintf(stderr, "file [%s] open error: %s\n", path, strerror(errno));
//        return -1;
//    } else {
//        
//        return 1;
//    }
//    //fp = fopen(*list,"r");
//
//}
