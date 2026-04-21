/* test_runner.c
   Testovací program pro cvičení 14.1 – Základy ukazatelů.
   Spouští main.c žáka s různými vstupy a kontroluje výstup.
   Kompilace: gcc test_runner.c -o test_runner
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OUTPUT 512

/* Spustí program main s daným vstupem a vrátí stdout jako řetězec. */
int run_test(const char *input, char *output, int output_size) {
    FILE *f = fopen("input.txt", "w");
    if (!f) return -1;
    fputs(input, f);
    fclose(f);

    int ret = system("./main < input.txt > output.txt 2>/dev/null");
    if (ret != 0) return -1;

    f = fopen("output.txt", "r");
    if (!f) return -1;
    int n = fread(output, 1, output_size - 1, f);
    output[n] = '\0';
    fclose(f);

    /* Odstraní případný trailing newline pro snazší porovnání */
    while (n > 0 && (output[n-1] == '\n' || output[n-1] == '\r')) {
        output[--n] = '\0';
    }
    return 0;
}

int check(const char *got, const char *expected, const char *test_name) {
    if (strcmp(got, expected) == 0) {
        printf("[OK] %s\n", test_name);
        return 1;
    } else {
        printf("[FAIL] %s\n", test_name);
        printf("  Ocekavano: %s\n", expected);
        printf("  Dostali jsme: %s\n", got);
        return 0;
    }
}

int main(void) {
    char output[MAX_OUTPUT];
    int passed = 0;
    int total = 0;

    /* Test 1: kladná čísla, lichý součet */
    total++;
    if (run_test("3\n4\n8\n", output, MAX_OUTPUT) == 0) {
        passed += check(output,
            "Soucet: 15\nMaximum: 8\nSoucet je lichy",
            "Test 1: kladna cisla, lichy soucet (3, 4, 8)");
    } else {
        printf("[FAIL] Test 1: program nešel spustit\n");
    }

    /* Test 2: kladná čísla, sudý součet */
    total++;
    if (run_test("2\n6\n4\n", output, MAX_OUTPUT) == 0) {
        passed += check(output,
            "Soucet: 12\nMaximum: 6\nSoucet je sudy",
            "Test 2: kladna cisla, sudy soucet (2, 6, 4)");
    } else {
        printf("[FAIL] Test 2: program nešel spustit\n");
    }

    /* Test 3: záporné číslo */
    total++;
    if (run_test("-5\n3\n7\n", output, MAX_OUTPUT) == 0) {
        passed += check(output,
            "Soucet: 5\nMaximum: 7\nSoucet je lichy",
            "Test 3: zaporne cislo (-5, 3, 7)");
    } else {
        printf("[FAIL] Test 3: program nešel spustit\n");
    }

    /* Test 4: všechna čísla stejná */
    total++;
    if (run_test("4\n4\n4\n", output, MAX_OUTPUT) == 0) {
        passed += check(output,
            "Soucet: 12\nMaximum: 4\nSoucet je sudy",
            "Test 4: vsechna stejna (4, 4, 4)");
    } else {
        printf("[FAIL] Test 4: program nešel spustit\n");
    }

    /* Test 5: záporný součet */
    total++;
    if (run_test("-10\n-3\n-2\n", output, MAX_OUTPUT) == 0) {
        passed += check(output,
            "Soucet: -15\nMaximum: -2\nSoucet je lichy",
            "Test 5: vsechna zaporna (-10, -3, -2)");
    } else {
        printf("[FAIL] Test 5: program nešel spustit\n");
    }

    printf("\nVysledek: %d / %d testu proslo\n", passed, total);

    /* Úklid */
    remove("input.txt");
    remove("output.txt");

    return (passed == total) ? 0 : 1;
}
