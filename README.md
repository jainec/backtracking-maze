# backtracking-maze

Este algoritmo resolve o problema de labirinto abaixo usando backtracking:

> A empresa de tecnologia Poxim Tech está desenvolvendo um robô humanoide que é capaz de se deslocar de forma totalmente autônoma e sem precisar do conhecimento prévio do ambiente físico no qual está localizado.

> Durante o seu deslocamento, que é feito um passo por vez, podem ser realizadas as seguintes operações, listadas em ordem de prioridade:

    Direita (D)
    Frente (F)
    Esquerda (E)
    Trás (T)

> A medida que vai explorando o ambiente, o robô cria uma mapa interno para as rotas exploradas.

> Caso uma rota não gere uma solução, outro caminho deve ser escolhido para ser explorado até que a solução seja obtida ou que não existam mais opções.

> Para demonstrar suas habilidades exploratórias, são criados labirintos com exatamente 1 entrada e até 1 saída, com tamanho máximo de 100 por 100 posições.

> É possível que nenhuma rota seja possível para atravessar o labirinto criado, mas quando existe uma saída, é sempre um espaço livre na borda do labirinto que não é o ponto de partida.

# Formato do arquivo de entrada

    #NL
    [Largura] × [Altura]
    M x,y = 0 → Espa ço livre
    M x,y = 1 → Parede
    M x,y = X → Ponto de partida
    M 0,0
    .
    .
    M A−1,0
    ···
    ..
    .
    ···
    M 0,L−1
    .
    .
    M A−1,L−1

**Exemplo:**

    2
    54
    11111
    10001
    10X01
    11011
    34
    111
    1X1
    101
    111
    
# Formato do arquivo de saída

> A rota é descrita pela sequência de coordenadas visitadas e operações realizadas.

> Saída do labirinto → Espaço livre na extremidade

> Sem saída → Trajeto termina no ponto de partida

**Exemplo:**

    L0:
    INICIO [2,2]
    D [2,2]->[2,3]
    F [2,3]->[1,3]
    E [1,3]->[1,2]
    E [1,2]->[1,1]
    T [1,1]->[2,1]
    BT [1,1]<-[2,1]
    BT [1,2]<-[1,1]
    BT [1,3]<-[1,2]
    BT [2,3]<-[1,3]
    BT [2,2]<-[2,3]
    T [2,2]->[3,2]
    SAIDA [3,2]
    L1:
    INICIO [1,1]
    T [1,1]->[2,1]
    BT [1,1]<-[2,1]
    SEM SAIDA
