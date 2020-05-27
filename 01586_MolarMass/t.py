import sys

InputCases = int( sys.stdin.readline() )

for JJ in range( InputCases ):
    InputFormula = sys.stdin.readline()
    InputFormula = InputFormula.rstrip()
    #print( InputFormula )
    #LastElement = ''
    #Elements = 'CHON'
    #Digits = '1234567890'
    ListElements = []
    ListWeights = []
    IsPreviousElement = False;
    for TT in range( len( InputFormula ) ):
        if InputFormula[ TT ] == 'C':
            ListElements.append( 12.01 )
            ListWeights.append( 1 )
            IsPreviousElement = True
        elif InputFormula[ TT ] == 'H':
            ListElements.append( 1.008) 
            ListWeights.append( 1 )
            IsPreviousElement = True
        elif InputFormula[ TT ] == 'O':
            ListElements.append( 16.00 )
            ListWeights.append( 1 )
            IsPreviousElement = True
        elif InputFormula[ TT ] == 'N':
            ListElements.append( 14.01 )
            ListWeights.append( 1 )
            IsPreviousElement = True
        else:
            if IsPreviousElement == True:
                ListWeights[ len( ListWeights ) - 1 ] = int( InputFormula[ TT ] )
                IsPreviousElement = False
            else:
                ListWeights[ len( ListWeights ) - 1 ] = 10*ListWeights[ len( ListWeights ) - 1 ] + int( InputFormula[ TT ] )
    #print( ListElements )
    #print( ListWeights )

    TotalWeight = 0
    for RR in range( len( ListElements ) ):
        TotalWeight += ListElements[ RR ]*ListWeights[ RR ]
    print( '%.3f'%TotalWeight )
        
            
        
        
    
