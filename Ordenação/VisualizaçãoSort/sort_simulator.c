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

// ordena os elementos do vetor numbers[] em ordem crescente, mostrando a ordenação passo a passo na tela
void bubble_sort() {
    is_sorting = TRUE; // Define que a ordenação está em andamento  - Isso muda a cor das barras no on_draw()
    
    // O primeiro for controla as passagens no vetor
    for (int i = 0; i < SIZE - 1; i++) {
        // O segundo for compara pares de elementos adjacentes
        for (int j = 0; j < SIZE - i - 1; j++) {
            // Se o elemento atual é maior que o próximo, eles são trocados
            if (numbers[j] > numbers[j + 1]) {
                swap(&numbers[j], &numbers[j + 1]);
                gtk_widget_queue_draw(drawing_area); // gtk_widget_queue_draw() solicita que a drawing_area (área de desenho) seja redesenhada
                update_display(); // força a interface a mostrar a troca imediatamente
            }
        }
    }
    
    is_sorting = FALSE; // A ordenação terminou - isso as barras voltam a ser desenhadas com a cor azul
}
// MERGE SORT
//   Divide o array recursivamente em duas metades
//   Ordena cada metade separadamente

//   Junta (merge) as duas metades ordenadas em uma única sequência ordenada
void merge(int arr[], int l, int m, int r) {
    
    // dois subarrays
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cria arrays temporários L e R
    int L[n1], R[n2];
   
    //Copia os dados do array principal arr[] para os subarrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    // Compara os elementos de L e R
    // oloca o menor no array arr[]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
        }
        k++;
        // Atualiza a tela com gtk_widget_queue_draw() e update_display() para mostrar o processo
        gtk_widget_queue_draw(drawing_area);
        update_display();
    }

    // Se ainda restarem elementos em L ou R, eles são copiados
    while (i < n1) {
        arr[k++] = L[i++];
        gtk_widget_queue_draw(drawing_area);
        update_display();
    }
    while (j < n2) {
        arr[k++] = R[j++];
        gtk_widget_queue_draw(drawing_area);
        update_display();
    }
}

// O objetivo de merge sort é aplicar recursivamente a lógica do Merge Sort
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // divide o array ao meio
        merge_sort(arr, l, m); // aplica merge_sort() na metade da esquerda
        merge_sort(arr, m + 1, r); // aplica merge_sort() na metade da direita
        merge(arr, l, m, r); // combina (merge) as duas metades
    }
}

//  QUICK SORT

// partition tem o objetivo de reorganizar os elementos do array em torno de um pivô e retornar o índice final do pivô
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Escolhe o último elemento como pivô
    int i = low - 1; // i vai marcar o "fim da região de elementos menores que o pivô"

    // Percorre o array de low até high - 1
    // Se encontrar elemento menor que o pivô, incrementa i e faz o swap
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            // Cada swap é visualizado com gtk_widget_queue_draw() e update_display() 
            gtk_widget_queue_draw(drawing_area);
            update_display();
        }
    }
    // Coloca o pivô na posição correta: entre os menores e os maiores
    swap(&arr[i + 1], &arr[high]);
    // Atualiza a tela depois do último swap (pivô)
    gtk_widget_queue_draw(drawing_area);
    update_display();
    // retorna a posição final do pivô, que será usada na recursão do quick_sort.
    return i + 1;
}

// Aplicar recursivamente o Quick Sort dividindo o array com base na posição do pivô
void quick_sort(int arr[], int low, int high) {
    // verifica se ainda há mais de um elemento a ordenar (low < high).
    if (low < high) {
        // Chama partition() para posicionar o pivô corretamente
        int pi = partition(arr, low, high);
        // Aplica quick_sort() nas duas metades:
        // antes do pivô (low até pi - 1)
        quick_sort(arr, low, pi - 1);
        //depois do pivô (pi + 1 até high)
        quick_sort(arr, pi + 1, high);
    }
}
