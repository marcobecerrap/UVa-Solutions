import sys

# Make sorted deck
SortedDeck = []
Suits = [ "Clubs", "Diamonds", "Hearts", "Spades" ]
Values = [ "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" ]
for SS in Suits:
    for VV in Values:
        SortedDeck.append( VV + " of " + SS )
        #print( VV  + " of " + SS )
 

TotalCases = int( ( sys.stdin.readline() ).strip() )
empty = sys.stdin.readline()

for CC in range( TotalCases ):

    if( CC > 0 ):
        print( "" )   
    
    #print( "==============" )


    # Get shuffles
    TotalShuffles = int( ( sys.stdin.readline() ).strip() )
    ShuffleList = []    
    for SS in range( TotalShuffles ):
        NewShuffle = []
        while( len( NewShuffle ) < 52 ):
            InputString = ( sys.stdin.readline() ).strip()
            NewShuffle += [ ( int( XX ) - 1 ) for XX in InputString.split() ]
        #print( repr( NewShuffle ) )
        ShuffleList.append( NewShuffle.copy() )
        

    # Get moves from the dealer
    Moves = []
    GotMove = True    
    while( GotMove == True ):
        InputMove = ( sys.stdin.readline() ).strip()
        #print( repr( InputMove ) )
        if( InputMove == "" ):
            GotMove = False
        else:
            Moves.append( int( InputMove ) - 1 )

    #print( repr( Moves ) )
            

    # Get sorted deck
    CurrentDeck = SortedDeck.copy()
    #print( repr( CurrentDeck ) )
    #print( str( len( CurrentDeck ) ) )

    
    # Make moves
    for MM in Moves:
        #print( "" )
        #print( "Move " + str( MM ) )
        Shuffle = ShuffleList[ MM ].copy()

        NewCurrentDeck = []

        for SS in Shuffle:
            NewCurrentDeck.append( CurrentDeck[ SS ] )

        CurrentDeck = NewCurrentDeck.copy()

    #print( "" )
    #print( "RESULT: " )
    for CC in CurrentDeck:
        print( CC )

    #print( "" )
