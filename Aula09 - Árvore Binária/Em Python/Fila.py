from No import No

class Fila:

    def __init__(self):
        self.itens = []

    def add(self, no):
        self.itens.append( no )
    
    def remove(self):
        if len( self.itens ) > 0 :
            return self.itens.pop( 0 )
        
