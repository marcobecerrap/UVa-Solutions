import sys

Alphabet = "RDZ."

for InputString in sys.stdin:
    HighwayLen = int( InputString )
    if( HighwayLen == 0 ):
        break

    InputHighway = sys.stdin.readline()
    Highway = ""

    for CC in InputHighway:
        if( CC in Alphabet ):
            if( CC == "." ):
                Highway += " "
            else:
                Highway += CC

    Highway = Highway.strip()

    if( "Z" in Highway ):
        print( "0" )
        continue

    #print( Highway )

    StoreA = Highway[ 0 ]
    if( StoreA == "R" ):
        StoreB = "D"
    else:
        StoreB = "R"

    minDistance = len( Highway )
    step = 0
    for CC in Highway:
        if( CC != StoreA ):
            step += 1
            if( CC == StoreB ):
                if( step < minDistance ):
                    minDistance = step
                step = 0
                StoreA, StoreB = StoreB, StoreA
        else:
            step = 0

            
    print( minDistance )
            
            
