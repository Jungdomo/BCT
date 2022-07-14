#include<stdio.h>

int bit[10001] = {0,};

int main() {
    char str[1001], block;
    int N, M, o, bitset = (1 << 26) - 1;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%s", str);
        for(int j = 0; str[j] != '\0'; j++) {
            bit[i] |= 1 << (str[j] - 'a');
        }
    }
    for(int i = 0, result = 0; i < M; i++, result = 0) {
        scanf(" %d %c", &o, &block);
        if(o == 1) {
            bitset = bitset & ~(1 << block - 'a');
        }
        else {
            bitset = bitset | (1 << block - 'a');
        }

        for(int j = 0; j < N; j++) {
            result += !(~bitset & bit[j]);
        }

        printf("%d\n", result);
    }
}
