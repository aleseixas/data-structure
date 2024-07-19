# MC202AB - Estrutura de Dados

## Lab 3 - Tipo Abstrato de Dados

**Data da Primeira Chance:** 12 de setembro de 2022  
**Peso:** 2

Após a tragédia de Mariana, aumentou-se a atenção sobre o risco de rompimento de várias represas (barragens) de detritos de minérios pelo Brasil. Além disso, as grandes represas de água do país também intensificaram sua fiscalização.

Você é um engenheiro contratado pelo governo federal brasileiro para fiscalizar diariamente o nível e a segurança de diversas represas por todo o país. Você recebe os dados com todas as medições de nível feitas ao longo daquele dia para cada uma das represas pelas quais você é responsável.

Os dados encaminhados a você contém o nome da represa (com tamanho máximo de 100 caracteres), o valor `M` que representa a capacidade máxima dela, o valor `N` (4 ≤ N ≤ 1000) que representa a quantidade de valores medidos, seguido de `N` medidas (em km³) de níveis atuais da represa. Exemplo:
Represa de Ilha Solteira
21.20 5 20 20 20 20 20

markdown
Copiar código
Se houver qualquer incidente, você é o engenheiro responsável. Por isso, você deve emitir um único alerta textual caso alguma medida da represa atinja 90% de sua capacidade máxima. A mensagem do alerta deverá ser: “CAPACIDADE ACIMA DE 90% DA MÁXIMA!”.

Um problema adicional do seu trabalho como engenheiro é que o sistema foi invadido e os nomes de represa foram todos modificados, dificultando a análise de saída da sua tarefa. Para isso, você deve padronizar os nomes de represa da seguinte forma (não necessariamente nesta ordem):
- Somente letras minúsculas
- Caracteres de underline (“_”) devem ser substituídos por espaço (“ ”)
- Somente o nome da represa sem o prefixo “represa de ” (Ex.: “represa_de_itaipu” se tornaria “itaipu”)
  - “represa_de_” é o único prefixo possível
- Caso haja números no nome, remova (Ex.: “represa_de_ilha_solteira3” se torna “ilha solteira”)
  - Por sorte, o invasor fez com que estes números poderão estar apenas no fim do nome da ilha

Os nomes das represas poderão se repetir na entrada, com diferentes medidas. Por exemplo, se a mesma represa aparece 3 vezes na entrada, ela deve ter 3 relatórios de saída na mesma ordem da entrada.

### Tipo Abstrato de Dados (TAD)

Crie um TAD para o tipo “Represa” contendo os seguintes itens:
- Nome da represa
- Valor decimal (float) do nível máximo da represa
- Um valor inteiro que representa a quantidade de medidas existentes no vetor de níveis
- Vetor de valores inteiros contendo as medidas de nível
- Valor inteiro que armazena o nível médio (média aritmética das medidas do vetor acima) da represa

Além disso, as seguintes operações devem ser declaradas para esse TAD:
1. **Função que lê dados de uma represa**  
   Recebe os dados inseridos na entrada do programa na forma `[nome] [M] [N] [medida 1] ... [medida N]` e retorna um dado do tipo Represa.
   - Note que o campo que armazena o valor da média neste dado Represa precisa ser calculado para então ser inserido.

2. **Função que verifica se a capacidade está acima de 90%**  
   Recebe um dado do tipo Represa e retorna 1 caso alguma das medidas desta Represa tem valor maior ou igual a 90% de sua capacidade máxima, ou retorna 0 caso contrário.

3. **Função que imprime informações da represa**  
   Recebe um dado do tipo Represa e imprime na tela informações deste dado na forma:
NOME: [nome]
QTD NÍVEIS: [quantidade de medidas lidas]
MÉDIA: [média das medidas]
[alerta textual (se houver)]

kotlin
Copiar código
- Lembrando que a média dos níveis lidos deve ser um valor inteiro.
- O alerta textual só deve ser mostrado caso alguma das medidas de nível da represa seja maior que 90%.

4. **Função que pré-processa os nomes das represas**  
Recebe um vetor de Represa e um inteiro representando o tamanho do vetor e faz o pré-processamento dos nomes das represas. Detalhes importantes:
- Essa função irá alterar o conteúdo de cada Represa do vetor, ou seja, não é necessário criar novas variáveis do tipo Represa e gerar um novo vetor.
- Essa função deve chamar outras funções que você deve definir para tratar estas strings.

### Entrada

Como dito anteriormente, a tarefa é fazer leitura e análise de dados de medição de uma represa. Então será dado como entrada os dados de `T` represas seguindo a ordem:
- Valor `T` (4 ≤ T ≤ 1000) representando a quantidade de represas a serem analisadas
- `T` linhas de dados de represa, em que cada linha segue o formato:
[nome]
[M] [N] [medida 1] ... [medida N]

perl
Copiar código

### Saída

A saída desta tarefa é a saída da operação de “Listar represas” definida no enunciado, que representa o relatório de cada uma das `T` represas analisadas. Cada relatório deve ser separado com uma linha contendo “#####” (5 caracteres “#”). O formato da saída será:
NOME: [nome]
QTD NÍVEIS: [quantidade de medidas lidas]
MÉDIA: [média das medidas]
[alerta textual (se houver)]
