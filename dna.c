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

    //retorna val1 se val1 maior que val2
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

    //se o valor já foi calculado, não há necessidade de recalcular
    else if(length[n][m] != -1){
        return length[n][m];
    }

    //se o n-ésimo caractere do primeiro vetor é igual ao m-ésimo caractere do segundo vetor...
    else if(a[n-1] == b[m-1]){
        length[n][m] = mlcs_w(a, n-1, b, m-1, length) + 1;
    }

    //verifica qual o maior valor
    else{
        length[n][m] = return_max(mlcs_w(a,n-1,b,m,length), mlcs_w(a,n,b,m-1,length));
    }

    return length[n][m];
}

int mlcs(char a[], int n, char b[], int m) {

    //inicializa a matriz
    int length[MAX_SIZE+1][MAX_SIZE+1];

    //percorre as linhas
    for(int l=0; l<=n; l++){

        //percorre as colunas
        for(int c=0; c<=m; c++){
            length[l][c] = -1;
        }
    }

    int resp = mlcs_w(a, n, b, m, length);

    return resp;
}

int dlcs(char a[], int n, char b[], int m) {

    //inicializa a matriz
    int matriz[n+1][m+1];

    //percorre as linhas
    for(int l=0; l<=n; l++){

        //percorre as colunas
        for(int c=0; c<=m; c++){

            //se for primeira linha, ou coluna, recebe 0
            if(l==0 || c==0){
                matriz[l][c] = 0;
            }

            //se o l-ésimo caractere do primeiro vetor é igual ao c-ésimo caractere do segundo vetor...
            else if(a[l-1] == b[c-1]){
                matriz[l][c] = matriz[l-1][c-1]+1;
            }

            //verifica qual o maior valor
            else{
                matriz[l][c] = return_max(matriz[l-1][c], matriz[l][c-1]);
            }   
        }
    }

    return matriz[n][m];
}