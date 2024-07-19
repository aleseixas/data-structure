# MC202AB - Estrutura de Dados

## Lab 1 - Vetores e Inteiros

**Data da Primeira Chance:** 29 de agosto de 2022  
**Peso:** 1

Tony Stark está planejando construir um exército de robôs autônomos com um tipo de consciência única, o chamado Projeto Ultron. Para isso, ele vai precisar da ajuda de Bruce Banner, que também é um cientista extraordinário.

O plano de Tony é modelar todo o sistema autônomo com base em um artefato alienígena encontrado em uma missão, que parece funcionar na forma de neurônios. Bruce Banner pode ajudar a colocar essa estrutura do artefato no sistema.

Para ajudá-lo, Tony propôs que Bruce escreva um código em C para manipular um vetor de inteiros com base em várias operações. Abaixo estão as operações que devem ser implementadas:

### Operações a Serem Implementadas

1. **Conjunto de Banner**
    - **Entrada:**
      - Valor inteiro `B` (4 ≤ B ≤ 1000) seguido pelos valores `b1, b2, ..., bB` que fazem parte do Conjunto de Banner.
    - **Objetivo:**
      - Modificar o vetor `u` para que os valores que não pertencem ao Conjunto de Banner sejam alterados para zero.
    - **Saída:**
      - Imprimir o vetor `u` modificado.

2. **Multiplicação de Mobius**
    - **Entrada:**
      - Valor `M` (2 ≤ M ≤ 100) que representa a constante para a Multiplicação de Mobius.
    - **Objetivo:**
      - Modificar o vetor `u` multiplicando os valores nas posições ímpares por `M`.
    - **Saída:**
      - Imprimir o vetor `u` modificado.

3. **Movimento Cíclico**
    - **Entrada:**
      - Valor `P` (1 ≤ P < T) que representa o tamanho do passo para o Movimento Cíclico.
    - **Objetivo:**
      - Modificar o vetor `u` realizando um movimento cíclico, movendo o valor da última posição para a primeira posição `P` vezes.
    - **Saída:**
      - Imprimir o vetor `u` modificado.

4. **Inversão de Vetor**
    - **Objetivo:**
      - Modificar o vetor `u` para que os valores estejam em ordem inversa.
    - **Saída:**
      - Imprimir o vetor `u` modificado.

### Entrada

A entrada será fornecida da seguinte forma:
1. Valor `T`, representando a quantidade de valores a serem disponibilizados em seguida.
2. Na linha seguinte, uma quantidade `T` de valores inteiros, separados por espaço.
3. Na linha seguinte, a quantidade de operações a serem feitas.
4. Nas linhas seguintes (cada operação pode ser executada várias vezes e em várias ordens), o número correspondente da operação e seus parâmetros:
    - **Operação 1:** Número da operação + `B` + valores do Conjunto de Banner.
      - Ex.: `1 11 12 15 78 52 48 68 57 9 2 35 77`
    - **Operação 2:** Número da operação + `M`.
      - Ex.: `2 45`
    - **Operação 3:** Número da operação + `P`.
      - Ex.: `3 4`
    - **Operação 4:** Número da operação somente.
      - Ex.: `4`

### Saída

Todos os vetores de saída devem ser impressos em uma única linha, separando valores por espaço. Cada operação realizada deve imprimir o vetor resultante após a aplicação da operação.

**Dica:** Use funções para implementar as operações.

**Observação:** O vetor `u` modificado em uma operação é o mesmo vetor que será utilizado na operação seguinte. Portanto, ao final do programa, o vetor `u` terá sido modificado várias vezes de forma sequencial.
