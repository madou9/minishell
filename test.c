#include <stdlib.h>
#include <stdio.h>

void swapme(char **p1, char **p2)
{
    char *tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main() {

    char *s1 = "Hello";
    char *s2 = "Ben";
    swapme(&s1, &s2);

    printf("%s   %s\n", s1, s2);
    return 0;
}
