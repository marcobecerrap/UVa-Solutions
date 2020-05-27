import sys

InputCases = int( sys.stdin.readline() )

for K in range( InputCases ):
    InputLine = sys.stdin.readline()
    InputDice = [ int( S ) for S in InputLine.split() ]
    InputDice.sort()
    Valid = True
    Size = len( InputDice ) - 1
    for D in range( Size ):
        Difference = InputDice[ D + 1 ] - InputDice[ D ]
        if Difference != 1:
            Valid = False
            break
    if Valid == True:
        print( 'Y' )
    else:
        print( 'N' )
