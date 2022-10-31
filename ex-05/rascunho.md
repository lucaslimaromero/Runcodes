# FILA DE PRIORIDADES (RASCUNHO)

• Criação de filas de prioridades (4 Filas)

*Critérios Decrescentes*:
    1 • Pessoas idosas (>= 60 anos) COM agravantes de saúde
    2 • Pessoas com agravantes de saúde
    3 • Pessoas idosas
    4 • Pessoas NÃO idosas sem agravantes de saúde

*Características Pessoa*
    1 • Nome (string) -> função readline
    2 • Idade (int)
    3 • Agravante de saúde - 1 (sim), 0 (não)

*Filas*: (FIFO) - First In First Out (Política de gerenciamento dos elementos de uma fila)
- Lista linear emq ue o primeiro a entrar é o primeiro a sair
- No nosso programa, aqueles que tiverem preferências poderão "furar" a ordem natural da fila

*Lógica das Filas*:
. Enfileirar (Enqueue): 
    - Q[end] = y;
    - end = (end + 1) % capacity;

. Consultar (Peek) o primeiro elemento da fila sem removê-lo:
    - x = Q[begin];

. Desenfileirar (Dequeue):
    - x = Q[begin];
    - begin = (begin + 1) % capacity;

. Fila vazia => begin = end = 0
