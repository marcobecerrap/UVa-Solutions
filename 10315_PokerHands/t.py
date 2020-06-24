import sys

DebugOn = False

Values = { "2" : 2, "3" : 3, "4" : 4, "5" : 5, "6" : 6, "7" : 7, "8" : 8, "9" : 9, "T" : 10, "J" : 11, "Q" : 12, "K" : 13, "A" : 14 }

for InputString in sys.stdin:

    if( DebugOn == True ):    
        print( "================" )
    
    InputString = InputString.strip()

    InputHands = [ HAND for HAND in InputString.split() ]

    BlackHand = InputHands[ 0 : 5 ]
    WhiteHand = InputHands[ 5 : 10 ]

    if( DebugOn == True ):    
        print( "BLACK: " + repr( BlackHand ) )
        print( "WHITE: " + repr( WhiteHand ) )

    # Get suits & values lists for each hand
    BlackValues = [ Values[ CC[ 0 ] ] for CC in BlackHand ]
    WhiteValues = [ Values[ CC[ 0 ] ] for CC in WhiteHand ]
    BlackSuits = [ CC[ 1 ] for CC in BlackHand ]
    WhiteSuits = [ CC[ 1 ] for CC in WhiteHand ]

    #print( repr( BlackValues ) )
    #print( repr( BlackSuits ) )
    #print( repr( WhiteValues ) )
    #print( repr( WhiteSuits ) )

    # Test 1: High card
    BlackHighCard = max( BlackValues )
    WhiteHighCard = max( WhiteValues )
    BlackIsHighCard = True    
    WhiteIsHighCard = True

    if( DebugOn == True ):
        print( "TEST 1:" )
        print( "Is black high card: " + repr( BlackIsHighCard ) + " [ " + str( BlackHighCard ) + " ]" )
        print( "Is white high card: " + repr( WhiteIsHighCard ) + " [ " + str( WhiteHighCard ) + " ]" )

    # Test 2: Pair
    BlackRepetitions = [ BlackValues.count( VV ) for VV in BlackValues ]
    WhiteRepetitions = [ WhiteValues.count( VV ) for VV in WhiteValues ]

    BlackIsPair = False
    BlackPair = list()
    BlackNotPair = list()    
    WhiteIsPair = False
    WhitePair = list()
    WhiteNotPair = list()
    if( BlackRepetitions.count( 2 ) == 2 ):
        BlackIsPair = True
        BlackPair = [ BlackValues[ II ] for II in range( len( BlackValues ) ) if ( BlackRepetitions[ II ] == 2 ) ]
        BlackPair = list( set( BlackPair ) )
        BlackNotPair = [ BlackValues[ II ] for II in range( len( BlackValues ) ) if ( BlackRepetitions[ II ] == 1 ) ]
        BlackNotPair.sort()
        BlackNotPair.reverse()
    if( WhiteRepetitions.count( 2 ) == 2 ):
        WhiteIsPair = True
        WhitePair = [ WhiteValues[ II ] for II in range( len( WhiteValues ) ) if ( WhiteRepetitions[ II ] == 2 ) ]
        WhitePair = list( set( WhitePair ) )
        WhiteNotPair = [ WhiteValues[ II ] for II in range( len( WhiteValues ) ) if ( WhiteRepetitions[ II ] == 1 ) ]
        WhiteNotPair.sort()
        WhiteNotPair.reverse()

    if( DebugOn == True ):
        print( "TEST 2:" )
        print( "Is black 1 pair: " + repr( BlackIsPair ) + " P" + str( BlackPair ) + " N" + repr( BlackNotPair ) )
        print( "Is white 1 pair: " + repr( WhiteIsPair ) + " P" + str( WhitePair ) + " N" + repr( WhiteNotPair ) )

    # Test 3: Two pairs
    BlackIsPairs = False
    BlackPairs = list()
    BlackNotPairs = list()
    WhiteIsPairs = False
    WhitePairs = list()
    WhiteNotPairs = list()
    if( ( BlackRepetitions.count( 2 ) ) == 4 ):
        BlackIsPairs = True
        BlackPairs = [ BlackValues[ II ] for II in range( len( BlackValues ) ) if ( BlackRepetitions[ II ] == 2 ) ]
        BlackPairs = list( set( BlackPairs ) )
        BlackPairs.sort()
        BlackPairs.reverse()
        BlackNotPairs = [ BlackValues[ II ] for II in range( len( BlackValues ) ) if ( BlackRepetitions[ II ] == 1 ) ]
    if( ( WhiteRepetitions.count( 2 ) ) == 4 ):
        WhiteIsPairs = True
        WhitePairs = [ WhiteValues[ II ] for II in range( len( WhiteValues ) ) if ( WhiteRepetitions[ II ] == 2 ) ]
        WhitePairs = list( set( WhitePairs ) )
        WhitePairs.sort()
        WhitePairs.reverse()
        WhiteNotPairs = [ WhiteValues[ II ] for II in range( len( WhiteValues ) ) if ( WhiteRepetitions[ II ] == 1 ) ]

    if( DebugOn == True ):
        print( "TEST 3:" )
        print( "Is black 2 pairs: " + repr( BlackIsPairs ) + " PP" + str( BlackPairs ) + " N" + repr( BlackNotPairs ) )
        print( "Is white 2 pairs: " + repr( WhiteIsPairs ) + " PP" + str( WhitePairs ) + " N" + repr( WhiteNotPairs ) )

    # Test 4: Three of a kind
    BlackIsThree = False
    BlackThree = list()
    BlackNotThree = list()
    WhiteIsThree = False
    WhiteThree = list()
    WhiteNotThree = list()
    if( ( BlackRepetitions.count( 3 ) ) == 3 ):
        BlackIsThree = True
        BlackThree = [ BlackValues[ II ] for II in range( len( BlackValues ) ) if ( BlackRepetitions[ II ] == 3 ) ]
        BlackThree = list( set( BlackThree ) )
        BlackNotThree = [ BlackValues[ II ] for II in range( len( BlackValues ) ) if ( BlackRepetitions[ II ] == 1 ) ]
        BlackNotThree.sort()
        BlackNotThree.reverse()
    if( ( WhiteRepetitions.count( 3 ) ) == 3 ):
        WhiteIsThree = True
        WhiteThree = [ WhiteValues[ II ] for II in range( len( WhiteValues ) ) if ( WhiteRepetitions[ II ] == 3 ) ]
        WhiteThree = list( set( WhiteThree ) )
        WhiteNotThree = [ WhiteValues[ II ] for II in range( len( WhiteValues ) ) if ( WhiteRepetitions[ II ] == 1 ) ]
        WhiteNotThree.sort()
        WhiteNotThree.reverse()

    if( DebugOn == True ):
        print( "TEST 4:" )
        print( "Is black three: " + repr( BlackIsThree ) + " T" + str( BlackThree ) + " N" + repr( BlackNotThree ) )
        print( "Is white three: " + repr( WhiteIsThree ) + " T" + str( WhiteThree ) + " N" + repr( WhiteNotThree ) )
                          
    # Test 5: Straight ( 5 cards of consecutive orders)
    BlackIsStraight = False
    BlackSortedValues = BlackValues.copy()
    BlackSortedValues.sort()
    BlackSortedValues.reverse()
    BlackDifference = [ ( BlackSortedValues[ RR - 1 ] - BlackSortedValues[ RR ] ) for RR in range( 1, len( BlackSortedValues ) ) ]
    if( BlackDifference == [ 1, 1, 1, 1 ] ):
        BlackIsStraight = True
    WhiteIsStraight = False
    WhiteSortedValues = WhiteValues.copy()
    WhiteSortedValues.sort()
    WhiteSortedValues.reverse()
    WhiteDifference = [ ( WhiteSortedValues[ RR - 1 ] - WhiteSortedValues[ RR ] ) for RR in range( 1, len( WhiteSortedValues ) ) ]
    if( WhiteDifference == [ 1, 1, 1, 1 ] ):
        WhiteIsStraight = True
    if( DebugOn == True ):
        print( "TEST 5:" )
        print( "Is black straight: " + repr( BlackIsStraight) + " S" + str( BlackSortedValues ) )
        print( "Is white straight: " + repr( WhiteIsStraight) + " S" + str( WhiteSortedValues ) )

    # Test 6: Flush (5 cards of the same suit)
    BlackIsFlush = False
    BlackSuitsNoRep = list( set( BlackSuits ) )
    if( len( BlackSuitsNoRep ) == 1 ):
        BlackIsFlush = True
    WhiteIsFlush = False
    WhiteSuitsNoRep = list( set( WhiteSuits ) )
    if( len( WhiteSuitsNoRep ) == 1 ):
        WhiteIsFlush = True
    if( DebugOn == True ):
        print( "TEST 6:" )
        print( "Is black flush: " + repr( BlackIsFlush) + " S" + str( BlackSuitsNoRep ) )
        print( "Is white flush: " + repr( WhiteIsFlush) + " S" + str( WhiteSuitsNoRep ) )

    # Test 7: Full House
    BlackIsFullHouse = False
    BlackFullHouse = list()
    if( BlackIsPair == True and BlackIsThree == True ):
        BlackIsFullHouse = True
        BlackFullHouse = [ BlackThree[ 0 ], BlackPair[ 0 ] ]
    WhiteIsFullHouse = False
    WhiteFullHouse = list()
    if( WhiteIsPair == True and WhiteIsThree == True ):
        WhiteIsFullHouse = True
        WhiteFullHouse = [ WhiteThree[ 0 ], WhitePair[ 0 ] ]
    if( DebugOn == True ):
        print( "TEST 7: " )
        print( "Is black full house: " + repr( BlackIsFullHouse ) + " S" + str( BlackFullHouse ) )
        print( "Is white full house: " + repr( WhiteIsFullHouse ) + " S" + str( WhiteFullHouse ) )
 
    # Test 8: Four of a kind
    BlackIsFour = False
    BlackFour = list()
    if( 4 in BlackRepetitions ):
        BlackIsFour = True
        BlackFour = [ BlackValues[ II ] for II in range( len( BlackValues ) ) if ( BlackRepetitions[ II ] == 4 ) ]
        BlackFour = list( set( BlackFour ) )
    WhiteIsFour = False
    WhiteFour = list()
    if( 4 in WhiteRepetitions ):
        WhiteIsFour = True
        WhiteFour = [ WhiteValues[ II ] for II in range( len( WhiteValues ) ) if ( WhiteRepetitions[ II ] == 4 ) ]
        WhiteFour = list( set( WhiteFour ) )
    if( DebugOn == True ):
        print( "TEST 8: " )
        print( "Is black four: " + repr( BlackIsFour ) + " F" + str( BlackFour ) )
        print( "Is white four: " + repr( WhiteIsFour ) + " F" + str( WhiteFour ) )

    # Test 9: Straight flush
    BlackIsStraightFlush = False
    if( BlackIsStraight == True and BlackIsFlush == True ):
        BlackIsStraightFlush = True
    WhiteIsStraightFlush = False
    if( WhiteIsStraight == True and WhiteIsFlush == True ):
        WhiteIsStraightFlush = True
    if( DebugOn == True ):
        print( "TEST 9: " )
        print( "Is black straight flush: " + repr( BlackIsStraightFlush ) )
        print( "Is white straight flush: " + repr( WhiteIsStraightFlush ) )

        
    # EVALUATE HANDS HIERARCHICALLY
    if( BlackIsStraightFlush == True and WhiteIsStraightFlush == False ):
        print( "Black wins." )
    elif( BlackIsStraightFlush == False and WhiteIsStraightFlush == True ):
        print( "White wins." )
    elif( BlackIsStraightFlush == True and WhiteIsStraightFlush == True ):
        if( BlackHighCard > WhiteHighCard ):
            print( "Black wins." )
        elif( BlackHighCard < WhiteHighCard ):
            print( "White wins." )
        else:
            print( "Tie." )
    elif( BlackIsFour == True and WhiteIsFour == False ):
        print( "Black wins." )
    elif( BlackIsFour == False and WhiteIsFour == True ):
        print( "White wins." )
    elif( BlackIsFour == True and WhiteIsFour == True ):
        if( BlackFour > WhiteFour ):
            print( "Black wins." )
        else:
            print( "White wins." )
    elif( BlackIsFullHouse == True and WhiteIsFullHouse == False ):
        print( "Black wins." )
    elif( BlackIsFullHouse == False and WhiteIsFullHouse == True ):
        print( "White wins." )
    elif( BlackIsFullHouse == True and WhiteIsFullHouse == True ):
        if( BlackFullHouse > WhiteFullHouse ):
            print( "Black wins." )
        else:
            print( "White wins." )
    elif( BlackIsFlush == True and WhiteIsFlush == False ):
        print( "Black wins." )
    elif( BlackIsFlush == False and WhiteIsFlush == True ):
        print( "White wins." )
    elif( BlackIsFlush == True and WhiteIsFlush == True ):
        if( BlackSortedValues > WhiteSortedValues ):
            print( "Black wins." )
        elif( BlackSortedValues < WhiteSortedValues ):
            print( "White wins." )
        else:
            print( "Tie." )
    elif( BlackIsStraight == True and WhiteIsStraight == False ):
        print( "Black wins." )
    elif( BlackIsStraight == False and WhiteIsStraight == True ):
        print( "White wins." )
    elif( BlackIsStraight == True and WhiteIsStraight == True ):
        if( BlackHighCard > WhiteHighCard ):
            print( "Black wins." )
        elif( BlackHighCard < WhiteHighCard ):
            print( "White wins." )
        else:
            print( "Tie." )
    elif( BlackIsThree == True and WhiteIsThree == False ):
        print( "Black wins." )
    elif( BlackIsThree == False and WhiteIsThree == True ):
        print( "White wins." )
    elif( BlackIsThree == True and WhiteIsThree == True ):
        if( BlackThree > WhiteThree ):
            print( "Black wins." )
        else:
            print( "White wins." )
    elif( BlackIsPairs == True and WhiteIsPairs == False ):
        print( "Black wins." )
    elif( BlackIsPairs == False and WhiteIsPairs == True ):
        print( "White wins." )
    elif( BlackIsPairs == True and WhiteIsPairs == True ):
        if( BlackPairs > WhitePairs ):
            print( "Black wins." )
        elif( BlackPairs < WhitePairs ):
            print( "White wins." )
        else:
            if( BlackNotPairs > WhiteNotPairs ):
                print( "Black wins." )
            elif( BlackNotPairs < WhiteNotPairs ):
                print( "White wins." )
            else:
                print( "Tie." )
    elif( BlackIsPair == True and WhiteIsPair == False ):
        print( "Black wins." )
    elif( BlackIsPair == False and WhiteIsPair == True ):
        print( "White wins." )
    elif( BlackIsPair == True and WhiteIsPair == True ):
        if( BlackPair > WhitePair ):
            print( "Black wins." )
        elif( BlackPair < WhitePair ):
            print( "White wins." )
        else:
            if( BlackNotPair > WhiteNotPair ):
                print( "Black wins." )
            elif( BlackNotPair < WhiteNotPair ):
                print( "White wins." )
            else:
                print( "Tie." )
    elif( BlackSortedValues > WhiteSortedValues ):
        print( "Black wins." )
    elif( BlackSortedValues < WhiteSortedValues ):
        print( "White wins." )
    else:
        print( "Tie." )

        


            
    
