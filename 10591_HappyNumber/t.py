import sys

InputCases = int( sys.stdin.readline() )

for PP in range( InputCases ):
    InputNumber = int( sys.stdin.readline() )

    TestNumber = InputNumber
    CheckedList = []
    IsHappy = False
    while ( TestNumber in CheckedList ) == False:
        #print( TestNumber )
        CheckedList.append( TestNumber )
        DigitList = list ( str( TestNumber ) )
        DigitCount = len( DigitList )
        NewTestNumber = 0
        for D in DigitList:
            NewTestNumber += ( int( D ) )**2
        TestNumber = NewTestNumber
        if NewTestNumber == 1:
            IsHappy = True
            break
        

    if IsHappy == True:
        print( 'Case #', ( PP + 1 ), ': ', InputNumber, ' is a Happy number.', sep = '' )
    else:
        print( 'Case #', ( PP + 1 ), ': ', InputNumber, ' is an Unhappy number.', sep = '' )

    #print( DigitList )

    
