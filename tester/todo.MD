# Ideias para exercícios

https://www.w3resource.com/c-programming-exercises/linked_list/index.php

### Básicos - percorrer a lista - leitura da lista

- [X] Crie uma função is_empty que retorna 1 se a lista estiver vazia e 0 caso contrário.
- [X] Crie uma função first_node que retorne o primeiro nó da lista se ele existir, ou null se não existir.
- [X] Crie uma função third_node que retorne o terceiro nó da lista se ele existir, ou null se não existir.
- [X] Escreva uma função lst_index que retorne o nó que está em um índice dado como parâmetro se ele existir, ou null se não existir.
- [ ] Escreva uma função lst_rev_index que retorne o nó que está em um índice de trás pra frente dado como parâmetro se ele existir, ou null se não existir.
- [ ] Escreva uma função lst_index_two que retorne o nó que está em um índice dado como parâmetro se ele existir se for positivo, ou o índice de trás pra frente se ele existir se for negativo, ou null se não existir.
- [X] Implemente uma função lst_contains que verifica se um determinado conteúdo existe na lista. Retorna 1 se encontrado, 0 caso contrário.
- [X] Implemente uma função lst_search que recebe uma lista e um inteiro a ser buscado. A função deve retornar o primeiro nó que contém o conteúdo ou NULL se não encontrado.
- [X] Crie uma função lst_count que conta quantas vezes um determinado conteúdo aparece na lista.
- [X] Crie uma função lst_index_all que retorne o índice + 1 de um determinado valor na lista, ou o tamanho da lista caso não seja encontrado.
- [X] Escreva uma função lst_sum que percorre a lista e retorna a soma de todos os elementos.
- [X] Implemente uma função lst_count_odd que conta o número de elementos ímpares na lista.
- [X] Implemente uma função lst_count_even que conta o número de elementos pares na lista.
- [ ] Escreva uma função lst_count_mutiple que recebe um número como parâmetro e conta quantos números são divisiveis por esse número.
- [ ] Escreva uma função lst_average que calcula a média dos valores na lista.
- [ ] Escreva uma função lst_max_value que retorna o nó que contém o valor máximo na lista.
- [ ] Escreva uma função lst_min_value que retorna o nó que contém o valor máximo na lista.
- [X] Crie uma função lst_is_palindrome que checa se a lista é palindroma ou não.
- [ ] Crie uma função que econtre um par cuja a soma é igual a um valor X. Ex: (1 2 3 4 5 6 7), X = 4 -> (1,3)
- [ ] Escreva uma função lst_sub_lst que verifica se uma determinada sequência de elementos aparece na lista. Tipo como a função substr, mas ao invés de string, o big e o little são listas encadeadas.
- [ ] Escreva uma função que compare 2 listas, assim como a strcmp.


### Intermediários - percorrer e mudar a lista - manipulação da lista

- [X] Escreva uma função que crie uma lista com um único nó contendo um inteiro fornecido como parâmetro.
- [X] Crie uma função que receba como parâmetro dois inteiro e crie uma lista com dois nós contendo esses dois inteiros
- [ ] Crie uma função lst_insert que insira um novo elemento no meio da lista, após um elemento específico.
- [ ] Crie uma função lst_replace que substitui o conteúdo de um nó específico por um novo conteúdo fornecido.
- [ ] Crie uma função que faz um swap de 2 elementos
- [ ] Crie uma função que apague o primeiro nó da lista.
- [ ] Crie uma função que apague o último nó da lista.
- [ ] Implemente uma função lst_remove_at que remove o nó em um índice específico da lista.
- [ ] Crie uma função que concatene duas listas
- [ ] Crie uma função lst_reverse que inverte a ordem da lista
- [ ] Crie uma função que ordene a lista em ordem crescente
- [ ] Crie uma função que remove os itens duplicados
- [ ] Implemente uma função lst_to_array que converte uma lista encadeada inteira para um array.
- [ ] Implemente uma função lst_to_array que converte uma parte lista encadeada inteira para um array, até um índice específico da lista.
- [ ] Implemente uma função lst_to_array que converte uma parte lista encadeada inteira para um array, até um conteúdo específico da lista ou toda se o conteúdo não foi encontrado.
- [ ] Crie uma função que retorne uma string a partir de uma lista e apague a lista junto
- [ ] Crie uma função que gire uma lista n vezes nos dois sentidos
- [ ] Crie uma função que inverta os pares da lista. Ex: (1 2 3 4) -> (2 1 4 3)
- [ ] Crie uma função que encontre e remova um loop em uma lista
- [ ] Crie uma função que remova todos os valores acima de um valor X
- [ ] Crie uma função que remova todos os nós com conteúdo NULL
- [ ] Crie uma função que remova todos os nós de uma lista que estão em outra lista.
- [ ] Dada uma lista encadeada, escreva uma função para inverter todos os k primeiros nós (onde k é dado como parâmetro). https://redquark.org/leetcode/0025-reverse-nodes-in-k-group/

### Avançados - Cria novas listas - Criação de novas listas

- [ ] Crie uma função que faça uma cópia da lista para uma nova
- [ ] Crie uma função que remova uma gama de nós pelo índice. Ex: (2, 5) - A função vai apagar todos os nós que estão entre os índices 2 a 5
- [ ] Crie uma função lst_split que divide uma lista em duas, dado um ponto de divisão, com índice ou um valor (igual a split).
- [ ] Escreva uma função lst_from_array que cria uma lista encadeada a partir de um array fornecido.
- [ ] Crie uma função que junte duas listas ordenadas e crie outra lista ordenada
- [ ] Crie uma função que junte k listas encadeadas ordenadas em uma lista encadeada ordenada. https://afteracademy.com/blog/merge-k-sorted-lists
- [ ] Crie uma função que crie uma sub lista de outra (tipo igual strdup)
- [ ] Crie uma função que crie uma sub lista de outra (tipo igual substr)
- [ ] Crie uma função que faça uma cópia da lista com a ordem embaralhada
- [ ] Crie uma função que receba 2 listas. Cada nó contém um inteiro. A função deve retornar uma nova lista contendo a soma de cada nó respectivo.
- [ ] Crie uma função que receba 2 listas e crie uma nova a partir da intersecção delas
- [ ] Escreva uma função merge que mescle nós alternativos de duas listas vinculadas individualmente. Ex: lst1 (1 3 5 7 9), lst2 (2 4 6 8) -> (1 2 3 4 5 6 7 8 9)
