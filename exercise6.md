# MC202AB - Estrutura de Dados

## Lab 06 - Variações de Listas

**Data da Primeira Chance:** 10 de Outubro de 2022  
**Peso:** 3

O jogo Snake, também conhecido como "jogo da cobrinha", é um jogo antigo que ficou conhecido por diversas versões, cuja versão inicial começou com o jogo Blockade de 1976.

A cobra se move numa matriz (MxN) de posições (x,y) e seu objetivo é se mover por essa matriz e se alimentar com as frutas que aparecem aleatoriamente em posições diferentes (elas sempre aparecem individualmente). Ela começa com tamanho 1 e a cada vez que se alimenta, seu tamanho cresce e uma nova fruta aparece.

O jogo deve parar assim que ocorrer:
- A colisão da cobra com seu próprio corpo (GAME OVER);
- A cobra ocupar todas as posições (YOU WIN).

Você deve primeiro checar se a cobra está na posição para onde a cabeça irá e só mover a cobra depois.

O usuário controla a direção da cabeça da cobra (para cima, para baixo, esquerda e direita) e seu corpo segue:
- **‘w’**: a cobra se movimenta para cima, da posição (x,y) para (x-1,y);
- **‘s’**: a cobra se movimenta para baixo, da posição (x,y) para (x+1,y);
- **‘a’**: a cobra se movimenta para a esquerda, da posição (x,y) para (x,y-1);
- **‘d’**: a cobra se movimenta para direita, da posição (x,y) para (x,y+1).

Implemente o jogo da cobrinha utilizando Lista Duplamente Encadeada, que armazena a posição (x,y) da matriz do jogo que ela ocupa (cada ponto no corpo da cobra):
- A cabeça da lista é a cabeça da cobra;
- A cauda da lista é a cauda da cobra;
- Quando a cobra come a fruta, sua cauda é acrescentada ao seu tamanho.

Quando a cobra passa por pelo limite horizontal, ela aparece no começo da matriz, por exemplo, a posição (0,N-1), se seu próximo movimento for para DIREITA, sua cabeça teria posição (0,0). O mesmo vale para os outros limites.

Lembrando que a cobra deve fazer as operações e seguir as regras do jogo. A matriz possui valor zero em todas as posições, exceto:
- Os lugares que a cobra ocupa possuem valor 1;
- O lugar que a fruta ocupa no espaço de tempo em que ela está em uma certa posição, possui valor -1.

### Entrada

A entrada é formada por:
- **Inteiro M**: Tamanho das linhas da Matriz do jogo, onde `M >= 2`;
- **Inteiro N**: Tamanho das colunas da Matriz do jogo, onde `N >= 2`;
- **FRUTA x y**: Posição (x,y) da fruta no jogo no começo e a cada vez que a fruta é comida pela cobra (É garantido que ela nunca cairá numa posição em que a cobra ocupa);
- **COBRA a b**: Posição (a,b) inicial da cobra no jogo, sempre será dada na 3ª linha da entrada, apenas no começo do jogo;
- **Sequência de movimentos** (Ex: w, s, a, d) dos movimentos a serem feitos pela cobra, até ela comer a fruta.

As entradas são feitas para dar fim de jogo na última jogada.

[M N]
FRUTA [X Y]
COBRA [A B]
[MOVIMENTO]... (Até a cobra comer a fruta)
FRUTA [X Y] ...(Até o fim do jogo)

css
Copiar código

### Saída

Impressão da matriz do jogo inicial (com a posição inicial da fruta e da cobra) e a cada movimento da cobra e inserção da fruta com um espaçamento de uma linha por impressão. A matriz terá as seguintes características:
- Cada caractere da matriz terá um espaço “ “;
- Nos lugares onde a cobra está, será impresso o caractere ‘#’;
- Nos lugares onde a fruta está, será impresso o caractere ‘*’;
- Nos demais lugares da matriz do jogo, será impresso o caractere ‘_’.

Quando houver fim de jogo, deve-se imprimir o último estado da matriz do jogo e em seguida:
- Se houver fim de jogo com a cobra batendo em seu próprio corpo, imprimir a frase “GAME OVER”;
- Se a cobra ocupar todas as posições da matriz, imprimir “YOU WIN”.
