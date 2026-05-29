#include <stdio.h>
#include <stdlib.h>

// Sistema de monitoramento da missão

#define MAX 50

typedef struct {
    float temperatura;
    float energia;
    int comunicacao;
} Leitura;

Leitura historico[MAX];
int total = 0;

// limpa tela
void limpar() {
    system("clear || cls");
}

// pausa
void pause() {
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

// titulo
void titulo(char texto[]) {
    printf("\n%s\n", texto);
}

// verifica alertas
void verificar(Leitura l) {

    int alerta = 0;

    titulo("--- ANALISE ---");

    // temperatura
    if(l.temperatura > 80) {
        printf("ALERTA: Superaquecimento!\n");
        alerta = 1;
    }
    else if(l.temperatura >= 60) {
        printf("Aviso: temperatura alta\n");
        alerta = 1;
    }
    else {
        printf("Temperatura normal\n");
    }

    // energia
    if(l.energia < 20) {
        printf("ALERTA: Energia baixa\n");
        alerta = 1;
    }
    else if(l.energia < 40) {
        printf("Aviso: energia diminuindo\n");
        alerta = 1;
    }
    else {
        printf("Energia normal\n");
    }

    // comunicação
    if(l.comunicacao == 0) {
        printf("Falha na comunicacao\n");
        alerta = 1;
    }
    else {
        printf("Comunicacao funcionando\n");
    }

    if(alerta == 0) {
        printf("\nMissao funcionando normalmente\n");
    }
    else {
        printf("\nAtencao necessaria na missao\n");
    }
}

// inserir dados
void inserir() {

    limpar();

    if(total >= MAX) {
        printf("Limite de leituras atingido\n");
        pause();
        return;
    }

    Leitura nova;
    int com;

    printf("Temperatura: ");
    scanf("%f", &nova.temperatura);

    printf("Energia: ");
    scanf("%f", &nova.energia);

    printf("Comunicacao ativa? (1 sim / 0 nao): ");
    scanf("%d", &com);

    if(nova.energia < 0)
        nova.energia = 0;

    if(nova.energia > 100)
        nova.energia = 100;

    if(com == 1)
        nova.comunicacao = 1;
    else
        nova.comunicacao = 0;

    historico[total] = nova;
    total++;

    printf("\nDados salvos com sucesso\n");

    pause();
}

// mostra ultimo status
void statusAtual() {

    limpar();

    if(total == 0) {
        printf("Nenhuma leitura registrada\n");
        pause();
        return;
    }

    Leitura ultima = historico[total - 1];

    titulo("--- STATUS DA MISSAO ---");

    printf("Temperatura: %.1f C\n", ultima.temperatura);
    printf("Energia: %.1f%%\n", ultima.energia);

    if(ultima.comunicacao == 1)
        printf("Comunicacao: ativa\n");
    else
        printf("Comunicacao: falha\n");

    verificar(ultima);

    pause();
}

// analise completa
void analise() {

    limpar();

    if(total == 0) {
        printf("Nenhuma leitura registrada\n");
        pause();
        return;
    }

    float maior = historico[0].temperatura;
    float menor = historico[0].temperatura;
    float mediaTemp = 0;
    float mediaEnergia = 0;

    int falhas = 0;
    int alertaTemp = 0;
    int alertaEnergia = 0;

    for(int i = 0; i < total; i++) {

        float t = historico[i].temperatura;
        float e = historico[i].energia;

        if(t > maior)
            maior = t;

        if(t < menor)
            menor = t;

        mediaTemp += t;
        mediaEnergia += e;

        if(t > 80)
            alertaTemp++;

        if(e < 20)
            alertaEnergia++;

        if(historico[i].comunicacao == 0)
            falhas++;
    }

    mediaTemp = mediaTemp / total;
    mediaEnergia = mediaEnergia / total;

    titulo("--- ANALISE COMPLETA ---");

    printf("Total de leituras: %d\n", total);
    printf("Maior temperatura: %.1f\n", maior);
    printf("Menor temperatura: %.1f\n", menor);
    printf("Media temperatura: %.1f\n", mediaTemp);
    printf("Media energia: %.1f\n", mediaEnergia);

    printf("\nAlertas temperatura: %d\n", alertaTemp);
    printf("Alertas energia: %d\n", alertaEnergia);
    printf("Falhas comunicacao: %d\n", falhas);

    titulo("--- HISTORICO ---");

    for(int i = 0; i < total; i++) {

        printf("\nLeitura %d\n", i + 1);

        printf("Temperatura: %.1f\n", historico[i].temperatura);
        printf("Energia: %.1f\n", historico[i].energia);

        if(historico[i].comunicacao == 1)
            printf("Comunicacao ativa\n");
        else
            printf("Comunicacao falhou\n");
    }

    pause();
}

// menu
void menu() {

    limpar();

    printf("\n=================================\n");
    printf("   SISTEMA DA MISSAO ESPACIAL\n");
    printf("=================================\n");

    printf("\n1 - Inserir dados");
    printf("\n2 - Ver status");
    printf("\n3 - Analise completa");
    printf("\n4 - Sair");

    printf("\n\n=================================\n");
    printf("Escolha: ");
}

int main() {

    int op;

    do {

        menu();

        scanf("%d", &op);

        switch(op) {

            case 1:
                inserir();
                break;

            case 2:
                statusAtual();
                break;

            case 3:
                analise();
                break;

            case 4:
                printf("\nSistema encerrado\n");
                break;

            default:
                printf("\nOpcao invalida\n");
                pause();
        }

    } while(op != 4);

    return 0;
}