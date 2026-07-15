# Simulador de Roleta em C++

Este repositório apresenta o desenvolvimento de um simulador de roleta implementado em **C++**, utilizando uma **lista circular duplamente encadeada** para representar a estrutura da roleta.

O projeto foi proposto pela professora da disciplina de **Estruturas de Dados e Algoritmos (EDA)** durante o segundo período do curso, com o objetivo de aplicar e consolidar os conceitos estudados em sala, especialmente relacionados à manipulação de ponteiros, estruturas encadeadas e gerenciamento dinâmico de memória.

A aplicação simula um sistema de apostas baseado em uma roleta europeia (números de 0 a 36), permitindo que o jogador gerencie seu saldo, realize apostas em números específicos ou em par/ímpar e receba recompensas de acordo com o resultado do sorteio.

---

## Funcionalidades

O programa possui as seguintes operações:

* Inserção de saldo inicial;
* Apostas em números específicos da roleta;
* Apostas em números pares ou ímpares;
* Sorteio automático do número vencedor;
* Atualização do saldo após cada rodada;
* Validação de entradas do usuário;
* Liberação da memória utilizada pela estrutura da roleta.

---

## Estrutura da Roleta

A roleta foi implementada utilizando uma **lista circular duplamente encadeada**.

Cada elemento da estrutura possui:

* O valor correspondente ao número da roleta;
* Um ponteiro para o próximo elemento;
* Um ponteiro para o elemento anterior.

Essa estrutura permite que a roleta seja percorrida de forma circular, simulando o giro entre os números.

---

## Funcionamento do Sorteio

O sorteio utiliza geração de números aleatórios para determinar a posição inicial do giro:

```cpp
rand() % 37
```

O programa percorre a lista circular até a posição sorteada e retorna o número correspondente da roleta.

---

## Sistema de Apostas

### 1. Aposta em Número Específico

O jogador escolhe um número entre 0 e 36.

Caso o número sorteado seja igual ao escolhido:

* O jogador recebe o valor apostado multiplicado por 36.

Caso contrário:

* O valor apostado é perdido.

---

### 2. Aposta em Par ou Ímpar

O jogador escolhe entre:

* Número par;
* Número ímpar.

O número 0 não participa desse tipo de aposta.

Caso a escolha corresponda ao resultado:

* O jogador recebe o valor apostado multiplicado por 2.

---

## Conceitos Aplicados

Durante o desenvolvimento foram utilizados:

* Linguagem C++;
* Estruturas (`struct`);
* Ponteiros;
* Lista circular duplamente encadeada;
* Alocação dinâmica de memória (`new` e `delete`);
* Manipulação de funções;
* Geração de números aleatórios;
* Controle de fluxo com menus e estruturas condicionais.

---

## Gerenciamento de Memória

Como a roleta utiliza alocação dinâmica, cada nó criado com:

```cpp
new Roleta;
```

é posteriormente liberado utilizando:

```cpp
delete;
```

A função responsável pela limpeza da estrutura percorre todos os elementos da lista e remove os nós antes do encerramento do programa, evitando vazamentos de memória.

---

## Aprendizados

O desenvolvimento deste projeto contribuiu para a compreensão prática de:

* Como estruturas encadeadas funcionam internamente;
* Manipulação de ponteiros;
* Criação e destruição de estruturas dinâmicas;
* Organização de programas utilizando funções separadas;
* Aplicação de estruturas de dados em problemas simulados.
