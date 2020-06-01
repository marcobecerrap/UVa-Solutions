import sys

NCases = int( sys.stdin.readline() )

for CASE in range( NCases ):
    
    dicChars = {}

    # Read Characters
    NChars = int( sys.stdin.readline() )
    for CHAR in range( NChars ):

        InputString = ( sys.stdin.readline() ).strip()

        ListChars = [ str( CC ) for CC in InputString.split() ]

        dicChars[ ListChars[ 0 ] ] = int( ListChars[ 1 ] )

    # Read Text
    Text = ""
    NText = int( sys.stdin.readline() )
    for CHAR in range( NText ):
        Text += ( sys.stdin.readline() ).strip()

    # Compute payment
    Payment = 0
    for KK in dicChars:
        Payment += dicChars[ KK ] * Text.count( KK )
        
    print( "%.2f$" % float( Payment / 100 ) )

    

        
        
