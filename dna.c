#include <stdio.h>

#include "dna.h"


void load_string(FILE *file, int *p, char *s, int t) {
    if (fscanf(file, "%d", p) != 1) {
        fprintf(stderr, "erro ao ler string do teste %d\n", t);
    }

    char c;
    do {
        c = getc(file);
    } while (c != '\n');

    fgets(s, *p + 1, file);
}

int return_max(int val1, int val2){
    if (val1 > val2){
        return val1;
    }

    return val2;
}

int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE + 1][MAX_SIZE + 1]) {
    
    //base da recursão
    if(n == 0 || m == 0){
        length[n][m] = 0;
    }

    else if(length[n][m] != -1){
        return length[n][m];
    }

    else if(a[n-1] == b[m-1]){
        length[n][m] = mlcs_w(a, n-1, b, m-1, length) + 1;
    }

    else{
        length[n][m] = return_max(mlcs_w(a,n-1,b,m,length), mlcs_w(a,n,b,m-1,length));
    }

    return length[n][m];
}

int mlcs(char a[], int n, char b[], int m) {

    int size = MAX_SIZE+1;

    //inicializa a matriz
    int length[size][size];

    //percorre as linhas
    for(int l=0; l<size; l++){

        //percorre as colunas
        for(int c=0; c<size; c++){
            length[l][c] = -1;
        }
    }

    int resp = mlcs_w(a, n, b, m, length);

    return resp;
}

int dlcs(char a[], int n, char b[], int m) {

    //inicializa a matriz
    int length[n][m];

    //percorre as linhas
    for(int l=0; l<n; l++){

        //percorre as colunas
        for(int c=0; c<m; c++){

            if(l==0 || c==0){
                length[l][c] = 0;
            }

            else if(a[l-1] == b[c-1]){
                length[l][c] = length[l-1][c-1]+1;
            }

            else{
                length[l][c] = return_max(length[l-1][c], length[l][c-1]);
            }   
        }
    }

    return length[n][m];
}
