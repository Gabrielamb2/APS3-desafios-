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

    else if(mlcs_w(a,n-1,b,m,length) > mlcs_w(a,n,b,m-1,length)){
        length[n][m] = mlcs_w(a,n-1,b,m,length);
    }

    else{
        length[n][m] = mlcs_w(a,n,b,m-1,length);
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
    return 2;
}
