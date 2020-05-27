import sys

step = 0
Tea = 0
for InputLine in sys.stdin:
    if step == 0:
        Tea = int( InputLine )
        #print( Tea )
        step = 1
    else:
        Count = 0
        GuessList = [ int( G )  for G in InputLine.split() ]
        for G in GuessList:
            if G == Tea:
                Count += 1
        print( Count )
        step = 0
    
