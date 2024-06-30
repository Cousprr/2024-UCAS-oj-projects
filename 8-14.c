#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int emb[100][100];

void input(){
    char buf[100];
    while (fgets(buf, sizeof(buf), stdin) != NULL){
        int a[100] = {0};
        int n = 0;
        char *t = strtok(buf, " ");
        while (t != NULL){
            a[n++] = atoi(t);
            t = strtok(NULL, " ");
        }
        int size = a[0];
        for (int i = 1; i < n; i++){
            emb[size][++emb[size][0]] = a[i];
        }
    }
}

void merge(){
    for (int b = 0; b < 20; b++){
        for (int i = 1; i <= emb[b][0]; i++){
            for (int j = 1; j <= emb[b][0]; j++){
                if (emb[b][i] + (1 << b) == emb[b][j] && (emb[b][i] % (1 << (b + 1))) == 0){
                    int temp[100] = {0};
                    for (int k = 1; k <= emb[b][0]; k++){
                        if (k != i && k != j){
                            temp[++temp[0]] = emb[b][k];
                        }
                    }
                    emb[b + 1][++emb[b + 1][0]] = emb[b][i];
                    for (int k = 0; k < 100; k++){
                        emb[b][k] = temp[k];
                    }
                    b--;
                    goto next;
                }
            }
        }
next:   ;
    }
}

void sort(){
    for (int i = 0; i < 20; i++){
        if (emb[i][0] != 0){
            for (int t1 = 1; t1 <= emb[i][0]; t1++){
                for (int t2 = 1; t2 < emb[i][0]; t2++){
                    if (emb[i][t2] > emb[i][t2 + 1]){
                        int temp = emb[i][t2];
                        emb[i][t2] = emb[i][t2 + 1];
                        emb[i][t2 + 1] = temp;
                    }
                }
            }
        }
    }
}

void print(){
    for (int i = 0; i < 20; i++){
        if (emb[i][0] != 0){
            printf("%d", i);
            for (int j = 1; j <= emb[i][0]; j++){
                printf(" %d", emb[i][j]);
            }
            printf("\n");
        }
    }
}

int main(){
    input();
    merge();
    sort();
    print();
    return 0;
}