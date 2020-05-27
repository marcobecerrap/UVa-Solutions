import sys

InputCases = int( sys.stdin.readline() )

for K in range( InputCases ):
    InputCapacity = sys.stdin.readline()
    Capacity = [ int( S ) for S in InputCapacity.split() ]
    InputData = sys.stdin.readline()
    Data = [ int( S ) for S in InputData.split() ]
    Data.sort()

    Count = 0
    Sum = 0
    for D in Data:
        Sum += D
        if Sum < Capacity[ 1 ]:
            Count += 1
    print( Count )
        
    
    



