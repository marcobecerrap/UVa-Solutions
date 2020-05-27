import sys

for InputString in sys.stdin:
    InputNumber = int( InputString )

    if InputNumber == 0:
        break
    
    if ( InputNumber % 17 ) == 0:
        print( '1' )
    else:
        print( '0' )
