import sys

def CountChangeOptions50( Cents, OutCoin, Memo50 ):
    if Cents == 0:
        return 1
    elif Memo50[ Cents ] == None:
        Count = 1 # case all 1-cent coins
        if Cents >= 50 and OutCoin >= 50:
            Count += CountChangeOptions50( Cents - 50, 50, Memo50 )
        if Cents >= 25 and OutCoin >= 25:
            Count += CountChangeOptions25( Cents - 25, 25, Memo25 )
        if Cents >= 10 and OutCoin >= 10:
            Count += CountChangeOptions10( Cents - 10, 10, Memo10 )
        if Cents >= 5 and OutCoin >= 5:
            Count += CountChangeOptions5( Cents - 5, 5, Memo5 )
        Memo50[ Cents ] = Count
        return Count
    else:
        return Memo50[ Cents ]
    return Count


def CountChangeOptions25( Cents, OutCoin, Memo25 ):
    if Cents == 0:
        return 1
    elif Memo25[ Cents ] == None:
        Count = 1 # case all 1-cent coins
        if Cents >= 25 and OutCoin >= 25:
            Count += CountChangeOptions25( Cents - 25, 25, Memo25 )
        if Cents >= 10 and OutCoin >= 10:
            Count += CountChangeOptions10( Cents - 10, 10, Memo10 )
        if Cents >= 5 and OutCoin >= 5:
            Count += CountChangeOptions5( Cents - 5, 5, Memo5 )
        Memo25[ Cents ] = Count
        return Count
    else:
        return Memo25[ Cents ]
    return Count


def CountChangeOptions10( Cents, OutCoin, Memo10 ):
    if Cents == 0:
        return 1
    elif Memo10[ Cents ] == None:
        Count = 1 # case all 1-cent coins
        if Cents >= 10 and OutCoin >= 10:
            Count += CountChangeOptions10( Cents - 10, 10, Memo10 )
        if Cents >= 5 and OutCoin >= 5:
            Count += CountChangeOptions5( Cents - 5, 5, Memo5 )
        Memo10[ Cents ] = Count
        return Count
    else:
        return Memo10[ Cents ]
    return Count


def CountChangeOptions5( Cents, OutCoin, Memo5 ):
    if Cents == 0:
        return 1
    elif Memo5[ Cents ] == None:
        Count = 1 # case all 1-cent coins
        if Cents >= 5 and OutCoin >= 5:
            Count += CountChangeOptions5( Cents - 5, 5, Memo5 )
        Memo5[ Cents ] = Count
        return Count
    else:
        return Memo5[ Cents ]
    return Count




MAX_LIMIT = 7489
#MAX_LIMIT = 100
Memo50 = ( MAX_LIMIT + 1 )*[None]
Memo25 = ( MAX_LIMIT + 1 )*[None]
Memo10 = ( MAX_LIMIT + 1 )*[None]
Memo5 = ( MAX_LIMIT + 1 )*[None]

for InputLine in sys.stdin:
    TotalCents = int( InputLine )
    print( CountChangeOptions50( TotalCents, 100 , Memo50 ) )
    #print( Memo )


