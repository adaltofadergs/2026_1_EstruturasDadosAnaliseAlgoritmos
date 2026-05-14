from No import No
from Fila import Fila

def inserir( raiz: No , numero):
    if raiz is None:
        return No( numero )
    
    if numero < raiz.dado:
        raiz.esq = inserir( raiz.esq, numero)
    
    if numero > raiz.dado:
        raiz.dir = inserir( raiz.dir, numero)
    
    return raiz

def imprimirEmOrdem( raiz : No):
    if raiz is not None:
        imprimirEmOrdem( raiz.esq )
        print( raiz.dado, end = " - " )
        imprimirEmOrdem( raiz.dir )

def imprimirPreOrdem( raiz : No):
    if raiz is not None:
        print( raiz.dado, end = " - " )
        imprimirPreOrdem( raiz.esq )
        imprimirPreOrdem( raiz.dir )

def imprimirPosOrdem( raiz : No):
    if raiz is not None:
        imprimirPosOrdem( raiz.esq )
        imprimirPosOrdem( raiz.dir )
        print( raiz.dado, end = " - " )

def imprimirReverso( raiz : No):
    if raiz is not None:
        imprimirReverso( raiz.dir )
        print( raiz.dado, end = " - " )
        imprimirReverso( raiz.esq )


def imprimirEmNivel(raiz : No):
    if raiz == None:
        return 
    fila = Fila()
    fila.add( raiz )

    while len( fila.itens ) > 0:
        atual = fila.remove()

        print( atual.dado , " - " )

        if atual.esq is not None:
            fila.add( atual.esq )

        if atual.dir is not None:
            fila.add( atual.dir )
    
    #print()

        
raiz_arvore = None

raiz_arvore = inserir( raiz_arvore, 53)
inserir( raiz_arvore, 36)
inserir( raiz_arvore, 90)
inserir( raiz_arvore, 77)
inserir( raiz_arvore, 24)
inserir( raiz_arvore, 40)
inserir( raiz_arvore, 98)
inserir( raiz_arvore, 95)
inserir( raiz_arvore,  5)

print( "\nEm ordem (ERD): ")
imprimirEmOrdem(raiz_arvore)
print( "\n------------------------")
print( "\nPré-ordem (RED): ")
imprimirPreOrdem(raiz_arvore)
print( "\n------------------------")
print( "\nPós-ordem (EDR): ")
imprimirPosOrdem(raiz_arvore)
print( "\n------------------------")
print( "\nOrdem Reversa (DRE): ")
imprimirReverso(raiz_arvore)
print( "\n------------------------")
print( "\nEm nível: ")
imprimirEmNivel(raiz_arvore)


