# FILA USANDO LISTA LIGADA
- Fila de pessoas em ordem de prioridade

# ESPECIFICAÇÕES

- Nome com no máx 50 caracteres - (se tive mais, print INVALIDO)
- Permitir inserção, remoção, impressão em ordem (começando com quem ta início da fila) e invertida (começando no último até primeiro da fila)
- Lista duplamente encadeada, para facilitar a impressão de trás para frente (*prev)
- FIFO (first in first out)
- Caso alguém com maior prioridade entrar na fila ela passará na frente de todos os outros com menor prioridade
- NÃO É POSSÍVEL QUE PESSOAS TENHAM A MESMA PRIORIDADE(Cada uma tem uma prioridade distinta)

# ENTRADA
- A entrada conterá várias linhas (EOF), cada uma com um dos comandos abaixo:
    . Inserir -> será passado o código de prioridade e o nome da pessoa, caso um código seja repetido, imprime-se "INVALIDO"
    . Remover -> deve-se retirar a primeira pessoa da fila, caso ela estive vazia, printe "Fila Vazia" como saída
    . ImprimirEmOrdem -> imprimir a fila em ordem no formato: cod1 - nome1; cod2 - nome2; ... Se a fila estiver vazia, printe "Fila Vazia"
    . ImprimirInvetido -> imprimir a fila invetida no formato codn - nome n; cod n-1; nome n-1;...Se a fila estiver vazia, printe "Fila Vazia"

    . Caso um comando de entrada não exista, seu programa deverá imprimir "Comando Inválido"

# SAÍDA
- Só terá saída quando um dos comando de impressão ocorrer:
    . ImprimirEmOrdem
    . ImprimirInvetido

# OBSERVAÇÕES
• A estrutura de dados deve ser alocada dinamicamente e toda a memoria desalocada corretamente c

• As strings (nomes) devem ser recebidos de maneira dinamica e nao deve ser alocado mais bytes do que
o necessario

• E necessario fazer um TAD lista ligada para execucao do exercıcio

• A fila nao tera um tamanho maximo de pessoas.

# PROBLEMAS

- Função List_remove está removendo todos os elementos da lista! (SOLVED)
- Função List_add não funciona quando adiciona-se um elemento no fim da lista (SOLVED)
- Função print e inverted_print estão com problemas, não imprimem todos os elementos da lista (SOLVED)
- De alguma forma, quando ocorre uma adição no meio, as funções print bugam conforme explicitado acima (SOLVED)
- O nome colocado no meio da lista passa a ser o limite final da função print e inicial da função inverted print (SOLVED)
- Além disso, se colocarmos 2 nomes no meio da lista, o programa finaliza com o código de erro: make: ***  [Error-1073741819] (SOLVED)
- Problema no EOF quando ocorre um comando de impressão. Meu programa finaliza antes de imprimir

