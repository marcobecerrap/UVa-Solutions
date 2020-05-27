import sys

InputLines = int( sys.stdin.readline() )

CountLettersBig = { 'A' : 0,
                 'B' : 0,
                 'C' : 0,
                 'D' : 0,
                 'E' : 0,
                 'F' : 0,
                 'G' : 0,
                 'H' : 0,
                 'I' : 0,
                 'J' : 0,
                 'K' : 0,
                 'L' : 0,
                 'M' : 0,
                 'N' : 0,
                 'O' : 0,
                 'P' : 0,
                 'Q' : 0,
                 'R' : 0,
                 'S' : 0,
                 'T' : 0,
                 'U' : 0,
                 'V' : 0,
                 'W' : 0,
                 'X' : 0,
                 'Y' : 0,
                 'Z' : 0}

CountLettersSmall = { 'a' : 0,
                 'b' : 0,
                 'c' : 0,
                 'd' : 0,
                 'e' : 0,
                 'f' : 0,
                 'g' : 0,
                 'h' : 0,
                 'i' : 0,
                 'j' : 0,
                 'k' : 0,
                 'l' : 0,
                 'm' : 0,
                 'n' : 0,
                 'o' : 0,
                 'p' : 0,
                 'q' : 0,
                 'r' : 0,
                 's' : 0,
                 't' : 0,
                 'u' : 0,
                 'v' : 0,
                 'w' : 0,
                 'x' : 0,
                 'y' : 0,
                 'z' : 0}

Letters = { 'A' : 'a',
                 'B' : 'b',
                 'C' : 'c',
                 'D' : 'd',
                 'E' : 'e',
                 'F' : 'f',
                 'G' : 'g',
                 'H' : 'h',
                 'I' : 'i',
                 'J' : 'j',
                 'K' : 'k',
                 'L' : 'l',
                 'M' : 'm',
                 'N' : 'n',
                 'O' : 'o',
                 'P' : 'p',
                 'Q' : 'q',
                 'R' : 'r',
                 'S' : 's',
                 'T' : 't',
                 'U' : 'u',
                 'V' : 'v',
                 'W' : 'w',
                 'X' : 'x',
                 'Y' : 'y',
                 'Z' : 'z'}


for JJ in range( InputLines ):
    InputString = sys.stdin.readline()
    InputChars = list( InputString )
    for CC in InputChars:
        if CC in CountLettersBig.keys():
            CountLettersBig[ CC ] += 1
        elif CC in CountLettersSmall.keys():
            CountLettersSmall[ CC ] += 1
        else:
            continue

CountList = []
for LL in Letters:    
    CountLettersBig[ LL ] += CountLettersSmall[ Letters[ LL ] ]
    CountList.append( [ CountLettersBig[ LL ], LL ] )

CountList.sort()
#CountList.reverse()

MaxCount = CountList[ len( CountList ) - 1 ][ 0 ]

for VV in range( MaxCount, 0, -1 ):
    ValList = []
    while CountList[ len( CountList ) - 1 ][ 0 ] == VV:
        PopElement = CountList.pop()
        ValList.append( [ PopElement[ 1 ], PopElement[ 0 ] ] )
    if len( ValList ) > 0:
        ValList.sort()
        for NN in ValList:
            print( NN[ 0 ], ' ', NN[ 1 ], sep='' )
    #print( ValList )
    #print( VV )




        
