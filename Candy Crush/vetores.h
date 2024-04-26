#ifndef VETORES_H_INCLUDED
#define VETORES_H_INCLUDED

#define filename "recordes.bin"
#define SCORE_SIZE 10
#define NAME_SIZE 30

typedef struct Score{
    char nome[NAME_SIZE];
    int score;
}Score;

Score recordes[SCORE_SIZE];


//Vetores
int posicao(int score, Score leaderboard[]);
void empurrar(int index, Score recordes[],int size);
void exibirVetor(int size, Score leaderboard[]);
Score cadastrar(int score);
void adicionarNovoRecorde(Score recordista, Score leaderboard[], int size, int posicao);
void salvarArquivo(Score leaderboard[], int size);
int lerArquivo(Score leaderboard[]);



#endif // VETORES_H_INCLUDED
