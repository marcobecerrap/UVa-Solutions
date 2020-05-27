import sys

def fib( NN, FibList ):

    LastFib = len( FibList )

    if NN > LastFib:
        for JJ in range( LastFib, NN + 1  ):
            FibList.append( FibList[ JJ - 1 ] + FibList[ JJ - 2 ] )
    
    return FibList[ NN ]


FibList = [ 0, 1 ]
for InputLine in sys.stdin:
    Num = int( InputLine )
    print( fib( Num, FibList ) )
