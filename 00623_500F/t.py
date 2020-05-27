import sys

FactIndex = 0
Factorial = [ None ]*1002
Factorial[ 0 ] = 1

for InputString in sys.stdin:
    InputNumber = int( InputString )

    print( InputNumber, '!', sep='' )
    
    if InputNumber > FactIndex:
        for JJ in range( FactIndex + 1, InputNumber + 1 ):
            Factorial[ JJ ] = Factorial[ JJ - 1 ] * JJ
        FactIndex = InputNumber

    print( Factorial[ InputNumber ] )


            

#print( Factorial )
