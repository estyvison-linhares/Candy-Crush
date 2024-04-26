#include <stdio.h>
#include <stdlib.h>
#include "vetores.h"


void empurrar(int index, Score recordes[], int size){
    int i;
    if(size == SCORE_SIZE){
        for(i = SCORE_SIZE -1; i > index; i--){
            recordes[i] = recordes[i-1];
        }
    }else{
        for(i = size; i > index; i--){
            recordes[i] = recordes[i-1];
        }
    }
}

void adicionarNovoRecorde(Score recordista,Score leaderboard[], int size, int posicao){
        empurrar(posicao,leaderboard,size);
        leaderboard[posicao] = recordista;
}

int posicao(int score, Score leaderboard[]){
    int i;
    for(i = 0; i < SCORE_SIZE; i++){
        if(score >= leaderboard[i].score){
            return i;
        }
    }
    return -1;
}

void exibirVetor(int size, Score leaderboard[]){
    int i;
    printf("%s","Recordes");
    printf("%15s%10s\n", "|   Nome\t    |", "         Score  ");
    for(i = 0; i < SCORE_SIZE; i++){
            if(leaderboard[i].score != 0){
                printf("      %d  |%12s      |%10d\n",i+1, leaderboard[i].nome, leaderboard[i].score);
            }else{
                printf("%15s%15s\n", "", "");
            }
    }
}

Score cadastrar(int score){
    Score player;
    printf("Digite o seu nome: ");
    gets(player.nome);fflush(stdin);
    player.score = score;
    return player;
}

void salvarArquivo(Score leaderboard[], int size){
    FILE *arq = fopen(filename, "w+b");
    int i;
    if(arq != NULL){
        for(i = 0; i < size; i++){
            //fprintf(arq, "%s %d\n", leaderboard[i].nome, leaderboard[i].score);
            fwrite(&leaderboard[i],sizeof(Score),1,arq);
        }
    }
    fclose(arq);
}

int lerArquivo(Score leaderboard[]){
    FILE *arq = fopen(filename, "r+b");
    int i;
    if(arq != NULL){
            for(i = 0; i < SCORE_SIZE;i++){
                fread(&leaderboard[i],sizeof(Score),1,arq);
                if(leaderboard[i].score == 0){
                    break;
                }
            }
            fclose(arq);
            return i;

    }

    return 0;
}
