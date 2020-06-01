import sys

for SIZE in sys.stdin:

    MatrixSize = int( SIZE.strip() )

    if( MatrixSize == 0 ):
        break

    # Make raw vectors
    ListRaw = list()
    for NN in range( MatrixSize ):
        InputString = sys.stdin.readline()
        ListRaw.append( [ int( II ) for II in InputString.split() ] )

    # Make raw vectors
    ListColumn = list()
    for NN in range( MatrixSize ):
        Column = []
        for FF in range( MatrixSize ):
            Column.append( ( ListRaw[ FF ] )[ NN ] )
        ListColumn.append( Column )

    # Get parity
    ParityRaw = [ ( sum( RR ) % 2 ) for RR in ListRaw ]
    ParityColumn = [ ( sum( CC ) % 2 ) for CC in ListColumn ]

    if( sum( ParityRaw ) == 0 and sum( ParityColumn ) == 0 ):
        print( "OK" )
    elif( sum( ParityRaw ) == 1 and sum( ParityColumn ) == 1 ):
        changeRaw = ParityRaw.index( 1 ) + 1
        changeColumn = ParityColumn.index( 1 ) + 1
        print( "Change bit (%d,%d)" % ( changeRaw, changeColumn ) )
    else:
        print( "Corrupt" )



    #print( "-------" )        
    #print( repr( ListRaw ) )
    #print( repr( ParityRaw ) )
    #print( repr( ListColumn ) )
    #print( repr( ParityColumn ) )

