#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
// #include "interpolation.h"
/*
* comand for compiling in linux using GCC: 
* gcc -Iinclude src/interpolation.c tests/interpolation_test.c -o bin/interpolation_test -lm
*/

// test relatory
int main() {
    FILE *dados, *script, *md;
    int i;

    // 1. Criar o arquivo com os dados da função (y = x^2)
    dados = fopen("data/dados.txt", "w");
    if (dados == NULL) { return 1; }
    for (i = -10; i <= 10; i++) {
        fprintf(dados, "%d %d\n", i, i * i);
    }
    fclose(dados);

    // 2. Criar o script do Gnuplot
    script = fopen("data/plot_script.gp", "w");
    fprintf(script, "set terminal pngcairo size 600,400\n");
    fprintf(script, "set output 'data/grafico.png'\n");
    fprintf(script, "set title 'Gráfico da função y = x^2'\n");
    fprintf(script, "set xlabel 'Eixo X'\n");
    fprintf(script, "set ylabel 'Eixo Y'\n");
    fprintf(script, "plot 'data/dados.txt' with linespoints title 'Parábola'\n");
    fclose(script);

    // 3. Executar o Gnuplot via C
    system("gnuplot data/plot_script.gp");

    // 4. Criar o arquivo .md com textos e o gráfico
    md = fopen("outputs/relatorio.md", "w");
    fprintf(md, "# Relatório de Simulação\n\n");
    fprintf(md, "Este é o gráfico gerado automaticamente pelo nosso programa em C.\n\n");
    fprintf(md, "![Parábola y = x^2](/data/grafico.png)\n\n");
    fprintf(md, "Fim do relatório.\n");
    fclose(md);

    printf("Relatório 'outputs/relatorio.md' gerado com sucesso!\n");
    return 0;
}

