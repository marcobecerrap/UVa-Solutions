import sys

def ReduceOneDigit( Val ):
    Numbers = "0123456789"
    while( Val >= 10 ):
        newVal = 0
        strVal = str( Val )
        for DD in strVal:
            newVal += Numbers.index( DD )
        Val = newVal        
    return ( Val )

for Person1 in sys.stdin:

    Person1 = Person1.strip()
    Person1 = Person1.lower()

    Person2 = sys.stdin.readline()
    Person2 = Person2.strip()
    Person2 = Person2.lower()

    Alphabet = "abcdefghijklmnopqrstuvwxyz"

    NameClean1 = ""
    Value1 = 0
    for CC in Person1:
        if( CC in Alphabet ):
            NameClean1 += CC
            Value1 += Alphabet.index( CC ) + 1

    NameClean2 = ""
    Value2 = 0
    for CC in Person2:
        if( CC in Alphabet ):
            NameClean2 += CC
            Value2 += Alphabet.index( CC ) + 1

    Value1 = ReduceOneDigit( Value1 )
    Value2 = ReduceOneDigit( Value2 )

    Love = float( min( [ Value1, Value2 ] ) ) / float( max( [ Value1, Value2 ] ) )

    #print( NameClean1 + " " + str( ReduceOneDigit( Value1 ) ) )
    #print( NameClean2 + " " + str( ReduceOneDigit( Value2 ) ) )
    print( "%.2f %%" % ( Love * 100 ) )
    #print( "----" )

    
