import sys

InputCases = int( sys.stdin.readline() )

for JJ in range( InputCases ):
    InputString = sys.stdin.readline()
    InputString = InputString.rstrip()
    #print( InputString )
    CountZeros = 0
    Grade = []
    for NN in range( 1, len( InputString ) + 1 ):
        if InputString[ NN - 1 ] == 'O':
            CountZeros += 1
        else:
            CountZeros = 0
        Grade.append( CountZeros )
    print( sum( Grade ) )
    
