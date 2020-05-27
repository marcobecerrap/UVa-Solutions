import sys

for InputString in sys.stdin:
    Number = int( InputString )



    if Number == 0:
        break

    if ( Number % 11 ) == 0:
        print( InputString.strip() , 'is a multiple of 11.' )
    else:
        print( InputString.strip() , 'is not a multiple of 11.' )
