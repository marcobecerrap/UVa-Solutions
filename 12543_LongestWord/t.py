import sys

Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-"
maxWord = ""

# Read text
for InputString in sys.stdin:
    InputString = InputString.strip()
    Words = [ str( S ) for S in InputString.split() ]


    for WW in Words:
        cleanWord = ""    
        for CC in WW:
            if CC in Alphabet:
                cleanWord += CC

        if( len( maxWord ) < len( cleanWord ) ):
            maxWord = cleanWord        

print( maxWord.lower() )
