# Resolução Pré-processor e Macros

### 01 - O exemplo gera a resposta 47 em vez da resposta esperada 144. Por quê?
    - A falta dos parênteses que traz esse erro, pois com eles a precedência dos operadores não é levada em consideração. 


### 02 - O exemplo deveria imprimir a mensagem "Erro Fatal: Abort" e encerrar quando receber dados ruins. No entanto, quando recebe dados bons, ele encerra. Por quê?
    - O problema pode ser resolvido colocando os parênteses em  "(fprintf(stderr"FatalError:Abort\n");exit(8));", dessa forma garante que o fprintf e o exit fazem parte do if, pois da forma que é dada no exemplo apenas o fprintf faz parte do if, e como a condição não é satisfeita o progama encerra.


### 03 - O que o Exemplo produz como saída? Tente executá-lo na sua máquina. Por que ele produziu o que produziu? Tente verificar a saída do pré-processador.
   - O exemplo é para mostrar como saida x², porém mais uma vez o problema é falta dos parênteses, pois no exemplo o SRQ recebe como parâmetro (counter+1), ficando da seguinte forma (counter+1 * counter+1), sem os parênteses ele vai respeitar a precendência dos operadores.


### 04 - Por que o Exemplo não produzirá a saída esperada? Em quanto o contador aumentará a cada vez?
    - Pois o counter está sendo incrementado dentro do SRQ, e dessa forma o contador aumenta de 2 em 2. 
    

### 05 - O Exemplo nos informa que temos uma variável indefinida "number", mas nosso único nome de variável é "counter".
    - O problema é apenas um espaço entre o "RECIPROCAL (number)", pois o (number) é um parâmetro de RECIPROCAL. 