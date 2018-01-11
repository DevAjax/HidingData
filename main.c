#include <assert.h>
#include <stdio.h>

void place2bitsNum(int *p, unsigned int num)
{
    assert(num < 4);
    *p |= num;
}

unsigned int getData(unsigned int p)
{
    return (p & 3);
}

void cleanOut(int *p)
{
    *p &= ~3;
}

int main(void)
{
    unsigned int x = 701;
    unsigned int p = (unsigned int) &x;

    printf("pointer val: %u\n", p);

    place2bitsNum(&p, 3);

    printf("data pointer: %u\n", p);
    printf("data allocated in ptr: %u\n", getData(p));

    cleanOut(&p);

    printf("cleansed pointer val: %u\n", p);
    printf("dereferencing cleansed pointer: %u\n", *(int*)p);

    return 0;
}