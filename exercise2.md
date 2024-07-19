## Lab 2 - Matrizes

**Data da Primeira Chance:** 5 de setembro de 2022  
**Peso:** 1

QR Codes são códigos de barra formados por padrões em uma imagem binária que podem ser escaneados na câmera do celular. Eles contêm informações, como links de sites, imagens e textos.

Imagens podem ser vistas como matrizes, onde cada elemento da matriz corresponde ao valor de intensidade do píxel. No caso de imagens binárias, os elementos assumem valores 1 (branco) ou 0 (preto).

### Tarefas

(a) **Inicialização das Matrizes**  
Defina uma imagem binária `A` de dimensão NxN, com listras verticais de espessura de 3 colunas, começando com branco. Defina também uma matriz `B` iniciada igual à matriz `A`.

(b) **Operação TRANSPOSTA**  
Elabore uma operação `TRANSPOSTA` que, dada uma matriz de entrada `A`, transpõe a matriz.

(c) **Operação SOMA**  
Elabore uma operação `SOMA` que calcula a soma de duas matrizes de entrada NxN (e.g., `A` e `B`). Lembrando que, como a imagem binária só assume valores de 0 e 1, considere que 1 + 1 = 1.

(d) **Operação MULTI_ELEM**  
Elabore uma operação `MULTI_ELEM` de multiplicação elemento a elemento de duas matrizes de entrada NxN (e.g., `A` e `B`) e calcula o resultado, onde `CMxN = AMxN X BMxN`. Lembrando que, como a imagem binária só assume valores de 0 e 1, considere que 1 + 1 = 1.

(e) **Operação MULTI_MAT**  
Elabore uma operação `MULTI_MAT` de multiplicação de matrizes com duas matrizes de entrada NxN (e.g., `A` e `B`) e calcula o resultado, onde `C = A . B`. Lembrando que, como a imagem binária só assume valores de 0 e 1, considere que 1 + 1 = 1.

(f) **Operação BORDAS**  
Bordas são transições na imagem que definem objetos. Dada uma imagem de entrada `X`, a imagem `Y` representa as bordas do objeto. Elabore uma operação `BORDAS` que define as bordas da matriz de entrada NxN (e.g., `A`).

### Entrada

A primeira entrada é o número inteiro `N` de linhas e colunas para as matrizes (6 ≤ N ≤ 99 e múltiplo de 3) da matriz `A`. A segunda entrada é o valor inteiro `O` que representa a quantidade de operações a serem feitas. Em seguida, recebe-se uma lista de operações a serem feitas com suas devidas entradas, onde a saída é guardada em um acumulador `B` a ser utilizado na próxima operação.

Lembre-se que as matrizes `A` e `B` começam como definido no item (a) do enunciado, porém podem ser usadas como um "acumulador", logo seu valor pode ser alterado após as operações.

### Operações

- **TRANSPOSTA X Y**  
  Faz a transposta de `X` e guarda em `Y`.

- **SOMA X Y Z**  
  Soma `X` e `Y` e guarda em `Z`.

- **MULTI_ELEM X Y Z**  
  Multiplica `X` e `Y` elemento a elemento e guarda em `Z`.

- **MULTI_MAT X Y Z**  
  Multiplica `X` e `Y` e guarda em `Z`.

- **BORDAS X Y**  
  Define as bordas de `X` e guarda em `Y`.

### Saída

A saída é formada pela impressão da imagem resultante de cada operação com um espaço em branco (`" "`) entre píxeis até depois do último píxel da linha e pulando uma linha antes de começar a próxima linha de saída.

**Exemplo de saída:**  
Para a matriz resultante da operação, a saída deve ser formatada como:
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0
...

Copiar código

Sinta-se à vontade para ajustar qualquer parte conforme necessário!
