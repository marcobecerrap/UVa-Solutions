import sys

commentsAllowed = False


NumCase = 1


for InputString in sys.stdin:

    InputString = InputString.rstrip()

    if commentsAllowed:
        print( "------------" )

    print( "Case " + str( NumCase ) + ":" )
    NumCase += 1

    TotalCases = int( sys.stdin.readline() )

    if commentsAllowed:
        print( "InputString: " + str( InputString ) )
        print( "TotalCases: " + str( TotalCases ) )
    
    for RR in range( TotalCases ):
        InputCaseString = sys.stdin.readline()
        InputCase = [ int( N )  for N in InputCaseString.split() ]

        if commentsAllowed:
            print( repr( InputCase ) )

        lim_low = min( InputCase )
        lim_up = max( InputCase )

        strOnes = '1'*( lim_up - lim_low + 1 )
        strZeros = '0'*( lim_up - lim_low + 1 )

        #print( InputString[ lim_low : ( lim_up + 1 ) ] )
        if( strOnes == InputString[ lim_low : ( lim_up + 1 ) ] or strZeros == InputString[ lim_low : ( lim_up + 1 ) ] ):
            print( "Yes" )
        else:
            print( "No" )
            


