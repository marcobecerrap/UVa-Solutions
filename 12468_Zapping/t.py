import sys

for InputString in sys.stdin:
    Channels = [ int( C ) for C in InputString.split() ]
    #print( Channels )
    if Channels[ 0 ] == -1:
        break
    if Channels[ 1 ] > Channels[ 0 ]:
        Current = Channels[ 0 ] + 100
        ChannelUp   = Channels[ 1 ] + 100
        ChannelDown = Channels[ 1 ]
    else:
        Current = Channels[ 0 ]
        ChannelUp   = Channels[ 1 ]+100
        ChannelDown = Channels[ 1 ]
    DistanceUp = ChannelUp - Current
    DistanceDown = Current - ChannelDown
    #print( 'CU ', ChannelUp )
    #print( 'CC ', Current )
    #print( 'CD ', ChannelDown )
    #print( 'U ', DistanceUp )
    #print( 'D ', DistanceDown )
    
    if DistanceUp > DistanceDown:
        Distance = DistanceDown
    else:
        Distance = DistanceUp

    print( Distance )
    #print( '------' )

