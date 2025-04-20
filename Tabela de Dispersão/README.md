# 🗃️ Tabela de Dispersão (Hash) em C

Implementação de tabela hash com tratamento de colisões, baseada no material de Estruturas de Dados da PUC-Rio (CELES, RANGEL, 2002).

## 📚 Conteúdo

1. **Implementação da Tabela Hash**
   - Tratamento de colisões por:
     - Endereçamento aberto com hash duplo
     - Listas encadeadas
   - Funções básicas: busca, inserção e remoção

2. **Aplicação Prática**
   - Contagem de ocorrências de palavras em texto
   - Ordenação e exibição dos resultados

3. **Técnicas Avançadas**
   - Uso de callbacks para percorrer a tabela
   - Funções de dispersão para strings

## 🛠 Como Usar

### Compilação

```bash
gcc tabela_hash.c -o tabela_hash
```

Execução

```bash
./tabela_hash texto.txt
```

## 📋 Estrutura do Código

### Tabela Hash

- hash() - Função de dispersão principal
- hash2() - Função de dispersão secundária
- busca() - Busca por elemento
- insere() - Inserção de elemento
- remove() - Remoção de elemento

### Aplicação de Contagem

- le_palavra() - Leitura de palavras de arquivo
- conta_ocorrencias() - Contagem de palavras
- imprime_resultados() - Exibição ordenada

## Exemplo de Saída

- palavra1 = 15
- palavra2 = 12
- palavra3 = 8
  
---

📌 Referência

CELES, Waldemar; RANGEL, José Lucas. Apostila de Estruturas de Dados. PUC-Rio, 2002.