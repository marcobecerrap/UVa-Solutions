import sys

for InputString in sys.stdin:
    Items = [ int( I ) for I in InputString.split() ]
    Dressing = Items[ 0 ]*Items[ 1 ]*Items[ 2 ]*Items[ 3 ]*Items[ 3 ]*Items[ 4 ]*Items[ 4 ]
    if Dressing == 0:
        break
    print( Dressing )
