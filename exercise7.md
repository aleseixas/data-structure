# MC202AB - Estrutura de Dados

## Lab 07 - Pilha e Fila

**Data da Primeira Chance:** 17 de outubro de 2022  
**Peso:** 3

Neste lab, sua tarefa será implementar o seu próprio editor de texto. Para isso, você vai precisar utilizar os conceitos de pilha e fila explicados em aula.

Este editor a ser implementado contém uma única string, inicialmente vazia, que poderia ser um único vetor de char. Porém, essa string poderá ser extremamente grande e alocar tudo isso de forma sequencial pode ser problemático. Além disso, nosso editor apenas permite alterações no final do texto. Portanto, a forma de representar essa string será uma pilha `P` na forma de lista ligada, em que cada nó tem um vetor de char com 50 posições e um ponteiro para outro nó. Essa pilha vai ser preenchida com strings de diferentes tamanhos e, por consequência, a cada vez que a quantidade máxima de caracteres do último nó for atingida, outro nó deve ser criado para ficar no topo da pilha `P`.

Um ponto importante é que esse editor também vai simular o funcionamento do buffer de entrada do terminal, em que as strings a serem adicionadas na pilha `P` serão primeiramente adicionadas em uma fila `F` (implementada em um vetor circular de tamanho máximo igual a 500). Somente quando o comando `EXEC [N]` for detectado em uma linha na entrada do programa é que os primeiros `N` caracteres da fila `F` serão desenfileirados e inseridos na pilha `P` (com `N` sendo no máximo o tamanho da fila `F`). Isso ilustra aquele momento em que o computador tem um pequeno travamento quando você está digitando e de repente tudo que você digitou aparece de uma única vez.

Outro ponto importante é que existe também o comando `DEL [M]` que faz com que os últimos `M` (1 ≤ M ≤ 100) caracteres na pilha sejam desempilhados, isto é, removidos da string única na pilha `P`.

### Instruções para leitura da entrada:

- Use o `fgets()` para leitura das linhas de entrada do programa;
- Você precisará remover o "\n" de cada linha a ser lida na entrada do programa, e após isso inserir os caracteres na fila;
- Os caracteres de espaço “ “ devem ser mantidos, mesmo que no final da linha lida;
- A condição de parada do programa será o comando `EXIT` que estará sempre na última linha.

### Dicas:

- Use a função `strcspn()` da biblioteca `string.h` para detectar o “\n” em uma linha lida;
- Outras funções da biblioteca `string.h` também podem ser úteis.

### Entrada

A entrada do programa consiste em várias linhas envolvendo strings a serem adicionadas e comandos do tipo `EXEC` ou `DEL`. Cada string de entrada será dada em uma única linha, isto é, sem “\n” do meio dela.

### Saída

A saída do programa deverá ser o estado atual da fila `F` e da pilha `P` a cada linha lida da entrada do programa, seguindo o formato:

FILA ATUAL: [strings concatenadas]
PILHA ATUAL: [string na pilha]
