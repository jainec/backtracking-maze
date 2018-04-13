#include <stdio.h>

typedef struct valores{
    int valor1;
    int valor2;
}val;

int aux;

val lerLabirinto(int linha, int coluna, char labirinto[linha][coluna], val valores, FILE* input){
    int i, j;
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            fscanf(input, " %c", &labirinto[i][j]);
            if(labirinto[i][j] == 'X'){
                valores.valor1 = i;
                valores.valor2 = j;
            }
        }
    }
    return valores;
}

int isEspacoLivre(int linha, int coluna, char labirinto[linha][coluna], int x, int y){
   if(x >= 0 && x < linha && y >= 0 && y < coluna && (labirinto[x][y] == '0'))
        return 1; //(true)

    return 0; //(false)
}

int resolveLabirinto(int linha, int coluna, char labirinto[linha][coluna], int x, int y, FILE* output){
    if(labirinto[x][y] == '0' && (x == 0 || y == 0 || x == linha-1 || y == coluna-1)){ //se x,y sao saida (solucao) do labirinto
        fprintf(output, "SAIDA [%d,%d]\n", x, y);
        aux = 1;
        return 0;
    }

    labirinto[x][y] = 'V';

    if(isEspacoLivre(linha, coluna, labirinto, x, y+1) == 1){
        fprintf(output, "D [%d,%d]->[%d,%d]\n", x, y, x, y+1);
        resolveLabirinto(linha, coluna, labirinto, x, y+1, output); //direita
        if(aux != 1)
            fprintf(output, "BT [%d,%d]<-[%d,%d]\n", x, y, x, y+1);
        else
            return 0;
    }

    if(isEspacoLivre(linha, coluna, labirinto, x-1, y) == 1){
        fprintf(output, "F [%d,%d]->[%d,%d]\n", x, y, x-1, y);
        resolveLabirinto(linha, coluna, labirinto, x-1, y, output); //frente
        if(aux != 1)
            fprintf(output, "BT [%d,%d]<-[%d,%d]\n", x, y, x-1, y);
        else
            return 0;
    }

    if(isEspacoLivre(linha, coluna, labirinto, x, y-1)  == 1){
        fprintf(output, "E [%d,%d]->[%d,%d]\n", x, y, x, y-1);
        resolveLabirinto(linha, coluna, labirinto, x, y-1, output); //esquerda
        if(aux != 1)
            fprintf(output, "BT [%d,%d]<-[%d,%d]\n", x, y, x, y-1);
       else
            return 0;
    }


    if(isEspacoLivre(linha, coluna, labirinto, x+1, y)  == 1){
        fprintf(output, "T [%d,%d]->[%d,%d]\n", x, y, x+1, y);
        resolveLabirinto(linha, coluna, labirinto, x+1, y, output); //tras
        if(aux != 1)
            fprintf(output, "BT [%d,%d]<-[%d,%d]\n", x, y, x+1, y);
        else
            return 0;
    }
    return 0;
}

int main(int argc, char* argv[]){
    printf("#ARGS = %i\n", argc);
    printf("PROGRAMA = %s\n", argv[0]);
    printf("ARG1 = %s, ARG2 = %s\n", argv[1], argv[2]);
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");
    int num_labirintos, linha, coluna, i;
    fscanf(input, "%d", &num_labirintos);
    for(i = 0; i < num_labirintos; i++){
        fscanf(input, "%d %d", &coluna, &linha);
        char labirinto[linha][coluna];
        val valores;
        valores = lerLabirinto(linha, coluna, labirinto, valores, input);
        fprintf(output, "L%d:\n", i);
        fprintf(output, "INICIO [%d,%d]\n", valores.valor1, valores.valor2);
        resolveLabirinto(linha, coluna, labirinto, valores.valor1, valores.valor2, output);
        if(aux == 0)
            fprintf(output, "SEM SAIDA\n");
        aux = 0;
    }
    fclose(input);
    fclose(output);
    return 0;
}
