# MC202AB - Estrutura de Dados

## Lab 10 - Hashing (Endereçamento aberto)

**Data da Primeira Chance:** 21 de novembro de 2022  
**Peso:** 5

She-Hulk ainda está com problemas para lidar com os zilhões de processos que seu chefe deu para ela cuidar. Agora ela percebeu que os números dos processos são números extremamente altos e está cada vez mais difícil para ela ter que fazer as operações de inserir, buscar e remover processos do sistema.

Para ajudar a advogada de heróis, você precisa desenvolver um TAD da estrutura de dados Hashing, implementado com endereçamento aberto. O dado que precisa ser armazenado é uma estrutura chamada `Processo`, em que se tem:

- Um valor inteiro `ID` (10^9 ≤ ID ≤ INT_MAX) que será o número identificador e a chave do processo,
- Uma string `nome_proc` (string sem espaço) que armazenará o nome do arquivo do processo,
- Outro valor inteiro `tempo` (10 ≤ tempo ≤ 1000) representando quanto tempo, em dias, o processo está esperando para ser atendido.

Com esse TAD implementado, as seguintes operações poderão ser solicitadas:

### Operações

- **I [id do processo] [nome do processo] [tempo do processo]**
  - Comando para inserir processo na tabela hash
  - Imprime a mensagem “PROCESSO [id do processo] INSERIDO!”
  - Obs.: Assuma que o processo não está armazenado, isto é, não acontecerá um comando para inserir um processo já inserido.

- **R [id do processo]**
  - Comando para remover processo da tabela hash
  - Imprime a mensagem “PROCESSO [id do processo] REMOVIDO!”
  - Nessa operação, é garantido que o processo existe

- **C [id do processo]**
  - Comando para consultar o nome do processo na tabela hash
  - Imprime a mensagem “PROCESSO [id do processo]: [nome do processo]”
  - Nessa operação, não é garantido que o processo exista na tabela. Caso não exista, a seguinte mensagem deve ser impressa: “PROCESSO [id do processo] NAO ENCONTRADO!”

- **T [id do processo]**
  - Comando para consultar o tempo do processo na tabela hash
  - Imprime a mensagem “TEMPO DO PROCESSO [id do processo]: [valor do tempo do processo] DIAS.”
  - Nessa operação, é garantido que o processo existe

### Entrada

A entrada do programa será um valor `N` (5 ≤ N ≤ 2000) representando a quantidade de operações a serem feitas, seguido das operações em si, com cada uma em uma única linha.

**Exemplo:**
5
I 1321468128 caso_wong 10
I 1846162235 abominavel_detalhes 125
I 1545135462 recorrencia_titania 342
C 1321468128
R 1545135462

css
Copiar código

### Saída

A saída do programa deverá ser a impressão de cada operação realizada, finalizando com a mensagem “FINALIZADO!”.

**Exemplo (seguindo o exemplo da Entrada):**
PROCESSO 1321468128 INSERIDO!
PROCESSO 1846162235 INSERIDO!
PROCESSO 1545135462 INSERIDO!
PROCESSO 1321468128: caso_wong
PROCESSO 1545135462 REMOVIDO!
FINALIZADO!
