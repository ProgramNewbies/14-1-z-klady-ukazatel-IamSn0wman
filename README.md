# Cvičení 14.1 – Základy ukazatelů

**Předmět:** Programování v C  
**Kapitola:** 14 – Ukazatele (základy)  
**Obtížnost:** ⭐☆☆ (1/3)  
**Body:** 5

---

## Zadání

Napište program, který pomocí ukazatelů pracuje se třemi celými čísly.

Program musí:

1. Načíst od uživatele tři celá čísla a uložit je do proměnných `a`, `b`, `c`.
2. Vytvořit ukazatele `p_a`, `p_b`, `p_c`, které ukazují na tyto proměnné.
3. Pomocí ukazatelů (tedy přes `*p_a`, `*p_b`, `*p_c`) vypočítat a vypsat:
   - součet všech tří čísel
   - největší z nich
   - zda je součet sudý nebo lichý

## Požadovaný výstup

Program načte tři čísla ze standardního vstupu (každé na samostatném řádku).  
Výstup musí být přesně ve tvaru (čísla jsou jen příklad):

```
Soucet: 15
Maximum: 8
Soucet je lichy
```

nebo pokud je součet sudý:

```
Soucet: 14
Maximum: 8
Soucet je sudy
```

> **Pozor:** Dodržuj přesné názvy výpisů včetně diakritiky – testy jsou citlivé na přesný formát výstupu.

## Podmínky

- Hodnoty `a`, `b`, `c` musí být deklarovány jako `int`.
- Součet, maximum i test sudosti musí být vypočítány výhradně přes ukazatele (`*p_a`, `*p_b`, `*p_c`), nikoli přímo přes `a`, `b`, `c`.
- Program musí správně fungovat i pro záporná čísla.
- Soubor se musí jmenovat `main.c`.

## Nápověda

Připomenutí syntaxe ukazatelů:

```c
int x = 42;
int *p = &x;   // p ukazuje na x
printf("%d\n", *p);  // vypíše hodnotu x přes ukazatel → 42
```

## Hodnocení

| Kritérium | Body |
|---|---|
| Program se zkompiluje bez chyb | 1 |
| Správný součet | 1 |
| Správné maximum | 1 |
| Správné určení sudosti/lichosti | 1 |
| Použití ukazatelů (kontrola kódu při obhajobě) | 1 |

## Odevzdání

- Soubor `main.c` nahraj do tohoto repozitáře.
- Proveď alespoň **3 commity** zachycující postup práce (ne jen jeden commit s hotovým řešením).
- Po nahrání se automaticky spustí testy – výsledek uvidíš v záložce **Actions**.
