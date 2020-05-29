import sys

commentsAllowed = False


NumCase = 1


for InputString in sys.stdin:

    InputString = InputString.rstrip()
    
    if commentsAllowed:
        print( "------------" )
        print( "InputString: " + str( InputString ) )

    InputSoundex = [ 0 ] * len( InputString )

    for NN in range( len( InputString ) ):
        if( InputString[ NN ] in 'BFPV' ):
            InputSoundex[ NN ] = 1
        elif( InputString[ NN ] in 'CGJKQSXZ' ):
            InputSoundex[ NN ] = 2
        elif( InputString[ NN ] in 'DT' ):
            InputSoundex[ NN ] = 3
        elif( InputString[ NN ] in 'L' ):
            InputSoundex[ NN ] = 4
        elif( InputString[ NN ] in 'MN' ):
            InputSoundex[ NN ] = 5
        elif( InputString[ NN ] in 'R' ):
            InputSoundex[ NN ] = 6
        else:
            continue

    for NN in range( len( InputString ) - 1 ):
        if( InputSoundex[ NN ] == InputSoundex[ NN + 1 ] ):
            InputSoundex[ NN ] = 0

    OutputSoundex = ''
    for NN in range( len( InputString ) ):
        if( InputSoundex[ NN ] != 0 ):
            OutputSoundex += str( InputSoundex[ NN ] )

    print( OutputSoundex )


    
            


