# 1° Avaliação parcial

### 01)Explique com suas palavras o processo de desenvolvimento (construção, ambiente e gravação) de um sistema embarcado, conforme mostrado no diagrama de blocos da figura abaixo:
![preview](/assets/build.png)

R:  Que os codigos em c, assembly e c++ são transformados em objeto pelo compilador, e o linker ele vincula os arquivos objeto que foi gerado pelo compilador para gerar um arquivo executável, isso seria o processo de construção e ambiente. Na parte de gravação de (host -> embedded system) é quando utiliza um notebook ou desktop para se comunicar com o sistema embarcado, por meio de uma cabo serial ou outros tipos conexão. No de (host ->  simulator(running on the host)), é quando o código é executado em um ambiente virtual, sem a necessidade de um sistema embarcado físico e no de (host -> in-circuit emulator) onde o in-circuit-emulator é conectado ao sistema embarcado para testa o codigo do sistema embarcado em tempo real.

### 02) Escreva um programa que pegue os bits em um número e os desloque para a extremidade esquerda.

- R: questao2.c

### 03) Escreva um código que contenha a seguinte função "int countBits(bool w,unsigned int value)", com parâmetros w (booleano) e value (inteiro e positivo de 32 bits) e que retorne a quantidade de bits w que estão definidos em value.

- R: questao3.c

### 04) Escreva um código que contenha uma função int setBits(bool w, unsigned int i, unsigned int j, unsigned int value) que sete n bits, definido pelo intervalo i e j, com o valor de w (0 ou 1) na variável value e o resultado jogue no retorno.

- R: questao4.c

### 05)
```
#define gpio_enabled     (1<<0)
#define gpio_direction    (1<<1) // output:1 input:0
#define gpio_level          (1<<2)
#define gpio_reset         (1<<3)

int main(){
    unsigned char gpioREG;
}
```

a) Escrever a lógica binária para setar a variável gpioREG como habilitado (gpio_enabled).
- R:  gpioREG |= gpio_enabled;

b) Escrever a lógica binária para testar se a variável gpioREG foi definido como saída (gpio_direction), caso positivo você deve desabilitar (gpio_enabled).
- R: if (gpioREG & gpio_direction) {
        gpioREG &= ~gpio_enabled;
    }

c) Escrever a logica binária para setar a variável gpioREG como entrada (gpio_direction).
- R: gpioREG |= gpio_direction;

d) Escrever a logica binária para alterar o gpioREG como nível alto (gpio_level) ou nível baixo. Ex: se ele estava como alto passar para baixo e vice-versa).
- R: gpioREG ^= gpio_level;
