#include <assert.h>
#include <limits.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <tps.h>
#include <sem.h>

#define TEST_ASSERT(assert)            \
do {                        \
    printf("ASSERT: " #assert " ... ");    \
    if (assert) {                \
        printf("PASS\n");        \
    } else    {                \
        printf("FAIL\n");        \
        exit(1);            \
    }                    \
} while(0)
                         
void *test_write_and_read_struct(){
    void* big_data = malloc(TPS_SIZE+10086);
    tps_create();
    TEST_ASSERT(tps_write(0,TPS_SIZE+10086,big_data)==-1);
    tps_destroy();
    return NULL;
}


int main() {
    pthread_t tid;
    tps_init(0);

    /*go the big input*/
    pthread_create(&tid, NULL, (void*)test_write_and_read_struct, NULL);
    pthread_join(tid, NULL);

  return 0;
}
