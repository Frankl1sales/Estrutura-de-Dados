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

static gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data) // Essa função é chamada automaticamente toda vez que a interface precisa ser redesenhada
{   
    //  tamanho da área de desenho
    int width = gtk_widget_get_allocated_width(widget);
    int height = gtk_widget_get_allocated_height(widget);
    
    // largura de cada barra
    int bar_width = width / SIZE;

    // preenche o fundo com cor 
    cairo_set_source_rgb(cr, 0.9, 0.9, 0.9);
    cairo_paint(cr);

    for (int i = 0; i < SIZE; i++) {
        // cada uma das SIZE barras
        double bar_height = (double)numbers[i] / 500.0 * height;
        
        // Desenha o contorno da barra
        cairo_rectangle(cr, i * bar_width + 1, height - bar_height, 
                       bar_width - 2, bar_height);
        
        // Define cor com base no estado de ordenação
        if (is_sorting) {
            cairo_set_source_rgb(cr, 0.1, 0.6, 0.3); // Verde durante a ordenação
        } else {
            cairo_set_source_rgb(cr, 0.3, 0.3, 0.8); // Azul quando não está ordenando
        }
        
        cairo_fill(cr);
    }
    // Retorna FALSE indicando que o evento de desenho não foi completamente tratado 
    // (GTK pode continuar o processamento padrão)
    return FALSE;
}

//  troca de valores entre duas variáveis inteiras
void swap(int *a, int *b) {
    int temp = *a;        // Guarda o valor de a em uma variável temporária
    *a = *b;              // Coloca o valor de b no lugar de a
    *b = temp;            // Coloca o valor salvo de a no lugar de b
}

//  força a atualização da interface gráfica para que possamos ver a mudança visual na tela
//  por exemplo, quando dois elementos são trocados durante a ordenação
void update_display() {
    // Processa todos os eventos pendentes para atualizar a tela
    while (gtk_events_pending()) {
        gtk_main_iteration();
    }
    usleep(50000); // Pausa de 50 milissegundos para visualização 
}