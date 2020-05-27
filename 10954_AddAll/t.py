import sys

for InputString in sys.stdin:
    
    if int( InputString ) == 0:
        break
    
    InputCases = sys.stdin.readline()
    Cases = [ int( CC ) for CC in InputCases.split() ]

    Costs = []

    while len( Cases ) > 1:
        Cases.sort()
        Total = Cases[ 0 ] + Cases[ 1 ]
        Costs.append( Total )
        Cases[ 1 ] = Total
        del Cases[ 0 ]
    
    print( sum( Costs ) )
    
