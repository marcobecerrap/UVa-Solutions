import sys
from collections import defaultdict

for InputString in sys.stdin:

    # Get ArraySize & QuerySize
    ArraySize, QuerySize = [ int( DD ) for DD in ( InputString.strip() ).split() ]

    # Get Array
    InputArray = [ int( GG ) for GG in ( ( sys.stdin.readline() ).strip() ).split() ]

    # Get Queries
    Queries = []
    for II in range( QuerySize ):
        NewQuery = [ int( GG ) for GG in ( ( sys.stdin.readline() ).strip() ).split() ]
        Queries.append( NewQuery )

        
    ##print( InputArray )
    ##print( Queries )

    # Build occurrences dictionary
    Occurrences = defaultdict( list )

    for II in range( len( InputArray ) ):
        Occurrences[ InputArray[ II ] ].append( II )
    ##print( Occurrences )

    
    # Solve Queries
    for QQ in Queries:
        Place, Key = QQ
        ##print( QQ )

        if( len( Occurrences[ Key ] ) == 0 ):
            print( 0 )
        elif( len( Occurrences[ Key ] ) < Place ):
            print( 0 )
        else: 
            print( ( Occurrences[ Key ] )[ Place - 1  ] + 1 )
            
