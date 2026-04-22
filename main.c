#include <stdio.h>

int main() {
    int a, b, c;
    int *p_a = &a, *p_b = &b, *p_c = &c;

    
    scanf("%d", p_a);
    scanf("%d", p_b);
    scanf("%d", p_c);

    
    int soucet = *p_a + *p_b + *p_c;

    
    int maximum = *p_a;
    if (*p_b > maximum) {
        maximum = *p_b;
    }
    if (*p_c > maximum) {
        maximum = *p_c;
    }


    printf("Soucet: %d\n", soucet);
    printf("Maximum: %d\n", maximum);
    
    
    if (soucet % 2 == 0) {
        printf("Soucet je sudy\n");
    } else {
        printf("Soucet je lichy\n");
    }

    return 0;
}
