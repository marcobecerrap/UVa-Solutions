import sys

idx = 0
N1 = 0
N2 = 0
for InputString in sys.stdin:
    if idx == 0:
        idx = 1
        N1 = int( InputString )
    else:
        idx = 0
        N2 = int( InputString )
        print( N1 * N2 )
        
    
