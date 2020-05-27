import sys

FibNumber = [0, 1]

for InputString in sys.stdin:
    Number = int( InputString )

    while ( Number + 1 ) > len( FibNumber ):
        Last = len( FibNumber ) - 1
        FibNumber.append( FibNumber[ Last ] + FibNumber[ Last - 1 ] )

    print( 'The Fibonacci number for ', Number, ' is ', FibNumber[ Number ], sep='' )
    

    
