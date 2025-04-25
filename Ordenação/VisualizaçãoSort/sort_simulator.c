// bibliotecas funcionais 
#include <gtk/gtk.h>     // Interface gráfica com GTK
#include <stdlib.h>      // Funções padrão (como rand())
#include <stdio.h>       // Entrada e saída (printf)
#include <time.h>        // Manipulação de tempo (seed para rand)
#include <unistd.h>      // usleep() para pausar a execução

#define SIZE 50 // número de elementos a serem ordenados 

int numbers[SIZE]; // vetor de inteiros que armazena os valores 
GtkWidget *drawing_area; // área gráfica onde as barras serão desenhadas 
gboolean is_sorting = FALSE; // flag booleana que indica se a ordenação está em andamento 

