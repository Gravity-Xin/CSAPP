#include <stdio.h>

typedef unsigned char *bytePointer;

void showBytes(bytePointer start, int len){
    int i = 0;
    for( ; i<len ; i++ ){
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void showInt(int x){
    showBytes((bytePointer)&x, sizeof(int));
}

void showFloat(float x){
    showBytes((bytePointer)&x, sizeof(float));
}

void showPointer(void *x){
    showBytes(bytePointer(x), sizeof(void*));
}

void testShowBytes(int val){
    int iVal = val;
    float fVal = val;
    void* pVal = &val;
    showInt(iVal);
    showFloat(fVal);
    showPointer(pVal);
}

int main(int argc, char const *argv[])
{
    testShowBytes(12345);
    return 0;
}
