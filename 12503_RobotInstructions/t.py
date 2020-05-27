import sys

InputCases = int( sys.stdin.readline() )

for JJ in range( InputCases ):
    InstructionSize = int( sys.stdin.readline() )

    InstructionSet = []
    for TT in range( InstructionSize ):
        InputString = sys.stdin.readline()
        InstructionSet.append( InputString.rstrip() )

    #print( InstructionSet )

    InstructionReady = [ 0 ] * len( InstructionSet )

    for FF in range( len( InstructionSet ) ):
        if sum( InstructionReady ) == len( InstructionReady ):
            break
        
        for UU in range( len( InstructionSet ) ):
            if InstructionReady[ UU ] == 1:
                continue
            elif InstructionSet[ UU ] == 'LEFT':
                InstructionReady[ UU ] = 1
                continue
            elif InstructionSet[ UU ] == 'RIGHT':
                InstructionReady[ UU ] = 1
                continue
            else:
                SameString = InstructionSet[ UU ].split()
                InstructionSet[ UU ] = InstructionSet[ int( SameString[ 2 ] ) - 1 ]

    Pos = 0
    for HH in InstructionSet:
        if HH == 'LEFT':
            Pos -= 1
        else:
            Pos += 1
    print( Pos )
    #print( InstructionSet )
    #print( '-------------' )
        
