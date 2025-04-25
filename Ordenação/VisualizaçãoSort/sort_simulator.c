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

void generate_numbers() {
    printf("[LOG] Gerando números aleatórios...\n");
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = rand() % 500 + 1;
    }
    printf("[LOG] Números gerados com sucesso.\n");
}

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
// A função start_sorting() é um dos pontos principais para iniciar a ordenação dos números escolhidos pelo usuário, 
// baseando-se em uma seleção feita na interface gráfica. Ela é chamada quando o usuário clica 
// em um botão para começar a ordenação.
void start_sorting(GtkButton *button, gpointer user_data) {
    if (is_sorting) return; // Isso evita que múltiplos algoritmos sejam executados ao mesmo tempo
    
    // retorna o texto do item selecionado em um ComboBox, 
    // que contém o nome do algoritmo de ordenação escolhido pelo usuário
    const char *selected_algo = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(user_data)); // O parâmetro user_data é passado pela função de callback do GTK, e, neste caso, refere-se ao widget ComboBox.

    // Se nenhum algoritmo for selecionado
    // a função imprime um erro e retorna sem fazer nada
    if (selected_algo == NULL) {
        printf("[ERRO] Nenhum algoritmo selecionado.\n");
        return;
    }

    generate_numbers(); // é chamada para preencher o array numbers com valores aleatórios 
    gtk_widget_queue_draw(drawing_area); // solicita ao GTK que redesenhe a área de desenho (drawing_area)
    update_display(); //  atualiza a interface e mostrar os números gerados ao usuário

    if (g_strcmp0(selected_algo, "BubbleSort") == 0) { // Se for o BubbleSort chama a função bubble_sort(); ... e assim vai
        bubble_sort();
    } else if (g_strcmp0(selected_algo, "MergeSort") == 0) {
        is_sorting = TRUE;
        merge_sort(numbers, 0, SIZE - 1);
        is_sorting = FALSE;
    } else if (g_strcmp0(selected_algo, "QuickSort") == 0) {
        is_sorting = TRUE;
        quick_sort(numbers, 0, SIZE - 1);
        is_sorting = FALSE;
    } else {
        printf("[ERRO] Algoritmo desconhecido!\n");
    }

    // Após a execução do algoritmo de ordenação (seja qual for), essa linha solicita que a área de desenho seja redesenhada
    gtk_widget_queue_draw(drawing_area);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv); // Inicializa o GTK, preparando o ambiente gráfico para o uso da biblioteca 

    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    // usa o tempo atual como semente para garantir que a sequência de números gerados 
    // seja diferente a cada execução do programa

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // cria uma janela de nível superior 
    gtk_window_set_title(GTK_WINDOW(window), "Simulador de Algoritmos de Ordenação"); // o título da janela
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600); // define o tamanho inicial da janela 
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL); // faz o programa terminar quando a janela é fechada -  conecta o evento de "destruição" (fechamento da janela) ao gtk_main_quit

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5); // Cria um contêiner do tipo caixa vertical (VBox) e adiciona-o à janela principal.
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Componente ComboBox para selecionar o algoritmo
    // Cria um ComboBox (caixa de combinação) onde o usuário pode selecionar o algoritmo de ordenação
    GtkWidget *combo_box = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "BubbleSort");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "MergeSort");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "QuickSort");
    gtk_box_pack_start(GTK_BOX(vbox), combo_box, FALSE, FALSE, 0);

    // Botão para iniciar a ordenação
    // Cria um botão com o rótulo "Iniciar Ordenação" e o adiciona à caixa vertical
    GtkWidget *button = gtk_button_new_with_label("Iniciar Ordenação");
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
    g_signal_connect(button, "clicked", G_CALLBACK(start_sorting), combo_box);

    // Área de desenho para visualização
    // onde os números ordenados serão visualizados graficamente
    drawing_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, 800, 400);
    gtk_box_pack_start(GTK_BOX(vbox), drawing_area, TRUE, TRUE, 0);
    g_signal_connect(drawing_area, "draw", G_CALLBACK(on_draw), NULL);

    // Exibe a janela e todos os widgets (botões, ComboBox, área de desenho) adicionados a ela
    gtk_widget_show_all(window);
    // Entra no loop de eventos principal do GTK
    // sso permite que a interface gráfica fique ativa e interaja com o usuário até que a janela seja fechada
    gtk_main();

    return 0;
}