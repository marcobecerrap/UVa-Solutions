import sys

BaseAlphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

for InputString in sys.stdin:

    InputString = InputString.strip()

    listDigits = list()

    for CC in InputString:
        if( CC in BaseAlphabet ):
            listDigits.append( BaseAlphabet.index( CC ) )

    Base = max( listDigits ) + 1
    if( Base < 2 ):
        Base = 2


    listDigits.reverse()


    FoundBase = False
    while( FoundBase == False and Base <= 62 ):
        Number = 0
    
        for DD in range( len( listDigits ) ):
            Number += ( Base ** DD ) * listDigits[ DD ]

        if( ( Number % ( Base - 1 ) ) == 0):
            FoundBase = True
            break
        else:
            Base += 1


    if( FoundBase == True ):
        print( str( Base ) )
    else:
        print( "such number is impossible!" )

            
