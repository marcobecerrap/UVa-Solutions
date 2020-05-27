import sys

for InputLine in sys.stdin:
    Cards = [ int( C ) for C in InputLine.split() ]
    if Cards[ 0 ] == Cards[ 1 ]:    
        print( Cards[ 0 ] )
    else:
        print( max( Cards ) )
