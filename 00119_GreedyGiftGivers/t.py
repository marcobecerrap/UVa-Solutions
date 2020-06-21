import sys

DebugOn = False

nCase = 0

for TotalFriends in sys.stdin:

    if( nCase > 0 ):
        print( "" )
    
    InputNames = ( sys.stdin.readline() ).strip()
    Names = [ str( FF ) for FF in InputNames.split() ]


    dNamesFriends = {}
    dNamesBank = {}
    dNamesGift = {}

    for NN in range( int( TotalFriends ) ):
        # Read data for each friend
        InputString = ( sys.stdin.readline() ).strip()
        DataSplit = [ str( S ) for S in InputString.split() ]

        # Separate data [ Name, Money, Friends ]
        Name = DataSplit[ 0 ]
        Money = int( DataSplit[ 1 ] )
        Friends = DataSplit[ 3 : len( DataSplit ) ]

        # Assign Friend list
        dNamesFriends[ Name ] = Friends

        # No income ( gifts received ) or money spent ( gifts given )
        dNamesBank[ Name ] = 0

        
        if( len( Friends ) == 0 ): # No Friends, the gift size is 0
            dNamesGift[ Name ] = 0
        else: # Divide money equally between friends
            dNamesGift[ Name ] = int( Money / len( Friends ) )


    for NN in Names:
        if( len( dNamesFriends[ NN ] ) == 0 ):
            continue
        else:
            MoneyToGive = dNamesGift[ NN ]

        #Give money to friends
        for FF in dNamesFriends[ NN ]:
            #print( FF )
            dNamesBank[ FF ] += MoneyToGive # Add gift to friend bank account
            dNamesBank[ NN ] -= MoneyToGive # Take out gift from giver bank account


    if DebugOn:
        print( "-------" )
        print( repr( Names ) )
        print( repr( dNamesFriends ) )
        print( "BANK: " + repr( dNamesBank ) )
        print( "GIFT: " + repr( dNamesGift ) )



    for SS in Names:
        print( SS + " " + str( dNamesBank[ SS ] ) )

    nCase += 1
