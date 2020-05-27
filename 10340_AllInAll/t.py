import sys

for InputString in sys.stdin:
    InputList = InputString.split()

    Str00 = list( InputList[ 0 ] )
    Str01 = list( InputList[ 1 ] )

    IsSubString = False
    while len( Str00 ) > 0:
        #print( '00 ', Str00 )
        #print( '01 ', Str01 )
        
        if len( Str01 ) == 0:
            break
        
        if Str00[ 0 ] == Str01[ 0 ]:
            del Str00[ 0 ]
            del Str01[ 0 ]
        else:
            del Str01[ 0 ]
            
        
    if len( Str00 ) == 0:
        IsSubString = True

    if IsSubString == True:
        print( 'Yes' )
    else:
        print( 'No' )

    #print( '-------------' )
    
