# MC202AB - Estrutura de Dados

## Lab 05 - Vetores Dinâmicos

**Data da Primeira Chance:** 26 de setembro de 2022  
**Peso:** 3

Tony Stark e Bruce Banner ainda continuam na tarefa de criar o sistema Ultron. Agora estão em uma fase em que Dr. Banner conseguiu calcular valores neurais para que a consciência única do sistema funcione. Porém, Tony ainda precisa testar certas combinações matriciais destes valores.

A tarefa de Tony Stark é fazer um TAD (Tipo Abstrato de Dados) para trabalhar com uma matriz de inteiros, porém ela precisa mudar de tamanho dinamicamente, pois serão adicionados e removidos valores dela conforme o teste de combinação matricial que ele planeja fazer.

Dr. Banner fornecerá uma matriz com valores ordenados nas linhas e após isso, dados os parâmetros de posição, serão solicitadas as seguintes operações (não necessariamente nesta ordem, e com repetição de operações):

### Operações

- **IN L [valores separados por “ ”]**  
  Comando para inserção de linha na matriz, em que a linha deve ser inserida na última posição da matriz.
  - Obs.: Se no momento desta operação a matriz tiver `N` colunas, a quantidade de valores da nova linha inserida também será `N`.

- **OUT L [X]**  
  Comando para remoção da linha na posição `X` da matriz, fazendo com que todas as linhas alocadas em posições após o `X` passem a ter índice subtraído de 1 por causa da remoção.

- **IN C [valores separados por “ ”]**  
  Comando para inserção de coluna na matriz, em que cada valor deve ser inserido em cada linha da matriz com a atenção para manter a ordem dos valores já existentes em cada linha.
  - Obs.: Se no momento desta operação a matriz tiver `M` linhas, a quantidade de valores da nova coluna inserida também será `M`.

- **OUT C [Y]**  
  Comando para remoção de coluna, em que todos os valores neurais na posição `Y` de cada linha devem ser removidos, fazendo com que todos os valores em posições após o `Y` passem a ter índice subtraído de 1 por causa da remoção.

Para otimizar seu código, Tony Stark definiu que o espaço alocado de uma linha ou de uma coluna deve dobrar quando a linha ou coluna estiver cheia. Assim como, o espaço alocado deve cair pela metade quando somente 1/4 das posições alocadas estiverem cheias.

Mais explicitamente, esta regra define que a quantidade de memória alocada para o tamanho da linha da matriz vai aumentar e diminuir, e a quantidade de memória alocada para o número de vetores nesta matriz (isto é, número de linhas) vai aumentar e diminuir também.

A outra regra definida é que cada linha da matriz se mantenha ordenada após cada operação realizada, então é preciso ter bastante atenção ao inserir valores nesta matriz.

Como aluno de MC202, você deve fazer o papel de Tony Stark e implementar esta tarefa para continuar a construção do sistema Ultron.

### Dicas para evitar vazamento de memória:
- Toda vez que a função `malloc` for utilizada, o `free` também precisa ser chamado.
- Não deixe ponteiros “orfãos”: Se você utilizar um ponteiro para alocar memória para uma struct, depois aloca memória para uma variável interna dessa struct, primeiro você faz `free` para o ponteiro de dentro da struct e depois o `free` para o ponteiro da struct em si (“from child to parent”).
- Escreva comentários acima das funções, isso pode te ajudar a lembrar onde alocou e desalocou memória.
- Faça o chamado “Teste de mesa” com seu código, pegando um teste bem pequeno e anotando no seu caderno passo a passo do que está acontecendo no seu código.
- Evite fazer todo o código de uma única vez: Faça um trecho, teste. Faça outro trecho, teste de novo, e assim por diante. Isso melhora seu tempo na hora de procurar saber onde está o erro.

### Entrada

Primeiramente será dado o tamanho inicial da matriz informando a quantidade de linhas e a quantidade de colunas em uma única linha separados por “ “, e em seguida a matriz com valores de cada linha separados por um único “ “, como mostra o exemplo abaixo:
3 4
50 62 85 87
20 26 34 35
12 13 28 29

css
Copiar código

Em seguida, será passada a quantidade de operações que dizem respeito a combinação matricial que Tony Stark deseja fazer, seguido das operações e seus respectivos parâmetros, como mostra o exemplo abaixo:
2
IN C 3 57 6
IN L 23 25 28 29

css
Copiar código
A matriz inicial é quem vai ser alterada sempre, então cada operação depende do resultado da operação anterior.

### Saída

A saída desta tarefa é imprimir na tela a matriz resultante de cada operação realizada, seguido da separação “###” em uma única linha. Após todas as operações, imprimir na tela a seguinte frase:
COMBINACAO MATRICIAL FINALIZADA!
