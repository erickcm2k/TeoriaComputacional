#include "afd.h"

int main(int argc, char const *argv[])
{
    struct AFD miAFD;
    miAFD.alfabeto = "hello world";
    miAFD.edad = 19;
    printf("%s", miAFD.alfabeto);
    printf("%d", miAFD.edad);
    return 0;
}
