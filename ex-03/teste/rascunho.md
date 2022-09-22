# TERCEIRO EXERCÍCIO PRÁTICO - AGENTE FEDERAL (RASCUNHO)

• Toda mensagem é recebida de trás para frente, ou seja, o ultimo digito na realidade é o primeiro da
sequência
*Utilização da Pilha Estática* (LIFO)-> Cada elemento (número) passado será colocado no topo de uma pilha, de modo que no final, faremos a leitura de trás para frente do vetor *data da pilha. A pilha é estática, pois a capacidade máxima da pilha é 10.000.


• Sempre que você receber o número 0, você deve desconsiderar o ultimo digito falado pela sua dupla,
pois é um valor errado para esconder a verdadeira mensagem.
*Ao receber o 0*: O programa deverá chamar uma função (pop) que retira o último elemento da pilha (isto é, retira o elemento do topo da pilha)

• Quando você recebe o número -1 a mensagem é encerrada e você deve desconsiderar qualquer informação que ele te informar após isso, pois é informação falsa.
*Ao receber o -1*: O programa deverá chamar a função (print) que printa o vetor da pilha de trás para frente, fazendo a conversão de inteiro para o alfabeto ASCII


