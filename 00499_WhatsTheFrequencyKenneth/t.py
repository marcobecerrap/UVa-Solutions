import sys

Alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

for InputString in sys.stdin:

    InputString = InputString.strip()

    InputLetters = list( InputString )

    diccFrequencies = {}

    for LL in Alphabet:
        diccFrequencies[ LL ] = 0

    #print( repr( InputLetters ) )

    for LL in InputLetters:
        if( LL in Alphabet ):
            diccFrequencies[ LL ] += 1

    Frequencies = list( diccFrequencies.values() )

    maxFreq = max( Frequencies )

    maxLetters = ""
    for KK in diccFrequencies:
        if( diccFrequencies[ KK ] == maxFreq and maxFreq > 0 ):
            maxLetters += KK

    print( "".join( sorted( maxLetters ) ) + " " + str( maxFreq ) )
            



