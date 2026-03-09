#include <stdio.h>
int main(){
    int a[5]= {1,2,3,4,5};
    int *ptr = a;
    for(int i=0; i<5; i++){
        printf("the value of a[%d] is : %d\n", i, a[i]);
        printf("the value of ptr[%d] is : %d\n", i, ptr[i]);
    }
    return 0;
}