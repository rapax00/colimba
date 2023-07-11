/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the
rightmost 1-bit in x. Explain why. Use this observation to write a faster ver-
sion of bitcount. */

/* Explicacion en español porque si no te vas a pegar un corchazo mpr:
x & (x - 1) saca el bit mas a la derecha porque 'x - 1' hace que el bit
mas a la derecha se mueva un lugar a la derecha. Entonces, al comparar con &
ambas cosas los 1s que coinciden son todos menos el de mas a la derecha. */

int bitcount(int x) {
    int count = 0;

    while (x != 0) {
        if (x) {
            count++;
        }
        x &= (x-1);
    }

    return count;
}

/* Test */
/*
int main() {
    printf("%d", bitcount(15));

    return 0;
}
*/
