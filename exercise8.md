# MC202AB - Estrutura de Dados

## Lab 8 - Árvore Binária de Busca

**Data da Primeira Chance:** 24 de Outubro de 2022  
**Peso:** 4

Sauron é o antigo general das tropas de Morgoth, o senhor das trevas responsável por destruir a árvore fonte de luz de Valinor, terra dos elfos. Em resposta, os elfos foram à Terra Média a fim de exterminar todo o mal. Muitos foram mortos, porém, a guerra foi ganha, e por muitos anos a Terra Média viveu em paz. Porém, Sauron fugiu.

Galadriel é uma elfa, atual comandante das tropas élficas do Norte. Ela perdeu seu irmão na guerra e jurou que não descansará, ou voltará a Valinor, até que tivesse exterminado toda a ameaça e Sauron estivesse morto.

Para auxiliar Galadriel em sua busca, você implementa um mapa utilizando Árvores Binárias de Busca. Para isso, serão usadas duas árvores:

- **MAPA**: Visam ajudar Galadriel a conhecer todos os lugares que visitou. A árvore MAPA deve ser organizada pelos seguintes critérios:
  - **Nome da Cidade**: O nome, uma vez inserido, nunca é repetido na árvore.
  - **Quantidade de Visitas**: Um valor inteiro que representa o número de vezes que Galadriel já visitou esta cidade.

- **VISITA**: Deve ajudar a manter o registro da busca. A árvore VISITA deve ser organizada pela data da visita e contém:
  - **Data da Visita** (No formato: `aaaammdd` - ano, mês e dia). Só pode haver uma visita por dia.
  - **Nome da Cidade** que ela visitou.
  - **Pista**: Um valor inteiro indicando se ela encontrou uma pista sobre Sauron (valor 1) ou não (valor 0).

### Operações

Você deve garantir que Galadriel consiga fazer as seguintes operações, mantendo as propriedades da estrutura:

- **insere_visita**: Insere nas árvores os valores adequados.
  - **MAPA**: Nome da Cidade.
  - **VISITA**: Data, Nome da Cidade, Pista.
  - Se houver inserção na árvore MAPA, imprimir:
    ```
    ARVORE: MAPA
    CIDADE: [NOME DA CIDADE]
    INSERIDO COM SUCESSO!
    ####
    ARVORE: VISITA
    DATA: [DATA INCLUIDO]
    CIDADE: [NOME DA CIDADE]
    INSERIDO COM SUCESSO!
    ####
    ```
  - Se não houver inserção na árvore MAPA, imprimir:
    ```
    ARVORE: VISITA
    DATA: [DATA INCLUIDO]
    CIDADE: [NOME DA CIDADE]
    INSERIDO COM SUCESSO!
    ####
    ```

- **exclui_visita**: Dada uma data de entrada, exclui a visita na árvore VISITA. Se, após a exclusão, a cidade tiver zero visitas, a cidade deve ser excluída da árvore MAPA. Imprime a quantidade de visitas restantes nessa cidade:
CIDADE: [NOME DA CIDADE]
QUANTIDADE DE VISITAS RESTANTES: [VALOR]

javascript
Copiar código

- **relatorio_data**: Dado um período de entrada (ou seja, a data de início e a data de fim, por exemplo: de `20220101` a `20220917`), todas as visitas devem ser impressas da mais antiga à mais nova:
--VISITAS--
DATA: [DATA]
CIDADE: [NOME DA CIDADE]

DATA: [DATA]
CIDADE: [NOME DA CIDADE]

less
Copiar código

- **relatorio_pista**: Dado um período de entrada (ou seja, a data de início e a data de fim, por exemplo: de `20220101` a `20220917`), todas as visitas em que houve pistas sobre Sauron devem ser impressas da mais nova à mais antiga:
--PISTAS--
DATA: [DATA]
CIDADE: [NOME DA CIDADE]

DATA: [DATA]
CIDADE: [NOME DA CIDADE]

less
Copiar código

### Entrada

A entrada será formada por:
- `N`, um inteiro que representa a quantidade de operações a serem feitas.
- Operações, que recebem a qual das operações será feita. Caso a operação necessite de entrada, elas são recebidas em seguida (Nome da Cidade, Data, Pista).

**Formato:**
[N]
[Operação] [Entradas da Operação ...]

shell
Copiar código

### Saída

A saída é formada pela impressão das operações realizadas, conforme descrito acima.
