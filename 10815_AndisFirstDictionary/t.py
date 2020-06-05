import sys

DebugOn = False

Alphabet = "abcdefghijklmnopqrstuvwxyz"
myDictionary = {}

for InputString in sys.stdin:

    InputString = InputString.replace( "-", " " )
    InputString = InputString.replace( "'", " " )
    InputString = InputString.strip()

    DirtyWords = [ str( SS ) for SS in InputString.split() ]

    for WW in DirtyWords:
        aWord = ""
        for CC in WW.lower():
            if CC in Alphabet:
                aWord += CC
        if( len( aWord ) > 0 ):
            myDictionary[ aWord ] = 0

Keys = list( myDictionary.keys() )

#print( repr( Keys ) )
Keys.sort()

for KK in Keys:
    print( KK )
        
