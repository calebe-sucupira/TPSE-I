# Resolução Operações com BitWise

### 01 - Traduza os seguintes números hexadecimais para binário.

- 0x0 -> 0000
- 0x10 -> 00010000
- 0xF -> 1111
- 0x1F -> 00011111
- 0xA4 -> 10100100
- 0xFF -> 11111111

### 02 - Encontre o AND, OR e XOR bitwise dos seguintes:

- a) 0xC6 com 0x35
    ```
    AND: 00000100 -> 0x04
    OR: 11110111 -> 0xF7
    XOR: 11110011 -> 0xF3
    ```
- b) 0x19 com 0x24
    ```
    AND: 00000000 -> 0x00
    OR: 00111101 -> 0x3D
    XOR: 00111101 -> 0x3D
    ```
- c) 0xD3 com 0xC7
    ```
    AND: 11000011 -> 0xC3
    OR: 11010111 -> 0xD7
    XOR: 00010100 -> 0x14
    ```
- d) 0x17 com 0xFF
    ```
    AND: 00010111 -> 0x17
    OR: 11111111 -> 0xFF
    XOR: 11101000 -> 0xE8
    ```

### 03 - Encontre o complemento de 1 dos seguintes números:

- 0xC6 -> 0x39
- 0x35 -> 0xCA
- 0xD3 -> 0x2C
- 0xC7 -> 0x38

### 04 - Nesta pergunta, "&" representa a operação "and" bit a bit, "|" representa a operação "or" bit a bit, "^" representa a operação "or exclusivo" bit a bit, e "!" representa o complemento de 1. "a" é qualquer número hexadecimal de dois dígitos. Explique por que cada uma das seguintes identidades é verdadeira.

- a) Pois 0xFF tem todos os bits estão definidos em 1 e como o operador é o "&", qualquer outro múmero em hexadecimal será ele mesmo.
- b) Novamente, como 0XFF tem todos os bits estão definidos 1 e o operador é "|", e como a condição de saida para ser vedadeira é se pelo menos uma entrada for verdadeira, logo a saida sempre será 0xFF.
- c) Como 0xFF tem todos o bits definos em 1, e a condição de "^" para ser verdadeiro é quando os bits são diferentes, logo os bits 1 de "a" ficará 0, e os bits 0 de "a" ficará 1.
- d) Como está recebendo uma sequência de bits 0, e a condição do operardor "&" para ser verdadeiro é todas as entradas tem que ser verdadeira, logo seja qual for os bits de "a", sempre a saida será 0.
- e) Como a condição do operador "|" para ser verdadeira se apenas uma das entradas for verdadeira, então a saida será sempre o próprio "a".
- f) Não muda muita coisa em relação ao "|", mas como a condição do operador "^" para ser verdadeira, é os bits serem diferentes, nesse caso sempre será diferente.
- g) Como os bits sempre vão ser iguais, a resultado sempre será falso.
- h)  Pois propriedade da operação XOR é associativo, logo a ordem não importa.
