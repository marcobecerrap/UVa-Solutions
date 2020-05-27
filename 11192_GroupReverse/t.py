import sys

for InputString in sys.stdin:

    InputData = [ str( N ) for N in InputString.split() ]

    TotalGroups = int( InputData[ 0 ] )
    if( TotalGroups == 0 ):
        break

    DataString = InputData[ 1 ]
    RevDataString = ''

    idx = 0
    step = int( len( DataString ) / TotalGroups )

    while( ( idx * step ) < len( DataString ) ):
        auxStr = DataString[ ( idx * step ) : ( ( idx + 1 ) * step ) ]
        RevDataString += auxStr[ len( auxStr ) : : -1 ]
        idx += 1

    print( RevDataString )
    
