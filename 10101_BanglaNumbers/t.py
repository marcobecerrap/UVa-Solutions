import sys

NCases = 0

for InputString in sys.stdin:

    NCases += 1

    InputString = InputString.strip()

    DigitList = list( InputString )

    diccBangla = { "kuti_1" : 0, "lakh_1" : 0, "hajar_1" : 0, "shata_1" : 0,  "kuti" : 0, "lakh" : 0, "hajar" : 0, "shata" : 0, "low" : 0 }


    # low digits
    d0 = "0"
    d1 = "0"
    d0 = DigitList.pop()
    if( len( DigitList ) > 0 ):
        d1 = DigitList.pop()
    diccBangla[ "low" ] = int( d1 + d0 )

    # shata digit
    d0 = "0"
    if( len( DigitList ) > 0 ):
        d0 = DigitList.pop()
    diccBangla[ "shata" ] = int( d0 )

    # hajar digits
    d0 = "0"
    d1 = "0"
    if( len( DigitList ) > 0 ):
        d0 = DigitList.pop()
    if( len( DigitList ) > 0 ):
        d1 = DigitList.pop()
    diccBangla[ "hajar" ] = int( d1 + d0 )

    # lakh digits
    d0 = "0"
    d1 = "0"
    if( len( DigitList ) > 0 ):
        d0 = DigitList.pop()
    if( len( DigitList ) > 0 ):
        d1 = DigitList.pop()
    diccBangla[ "lakh" ] = int( d1 + d0 )

    # kuti digits
    d0 = "0"
    d1 = "0"
    if( len( DigitList ) > 0 ):
        d0 = DigitList.pop()
    if( len( DigitList ) > 0 ):
        d1 = DigitList.pop()
    diccBangla[ "kuti" ] = int( d1 + d0 )

    # shata_1 digit
    d0 = "0"
    if( len( DigitList ) > 0 ):
        d0 = DigitList.pop()
    diccBangla[ "shata_1" ] = int( d0 )

    # hajar_1 digits
    d0 = "0"
    d1 = "0"
    if( len( DigitList ) > 0 ):
        d0 = DigitList.pop()
    if( len( DigitList ) > 0 ):
        d1 = DigitList.pop()
    diccBangla[ "hajar_1" ] = int( d1 + d0 )

    # lakh_1 digits
    d0 = "0"
    d1 = "0"
    if( len( DigitList ) > 0 ):
        d0 = DigitList.pop()
    if( len( DigitList ) > 0 ):
        d1 = DigitList.pop()
    diccBangla[ "lakh_1" ] = int( d1 + d0 )

    # kuti_1 digits
    d0 = "0"
    d1 = "0"
    if( len( DigitList ) > 0 ):
        d0 = DigitList.pop()
    if( len( DigitList ) > 0 ):
        d1 = DigitList.pop()
    diccBangla[ "kuti_1" ] = int( d1 + d0 )


    #diccBangla = { "kuti_1" : 0, "lakh_1" : 0, "hajar_1" : 0, "shata_1" : 0,  "kuti" : 0, "lakh" : 0, "hajar" : 0, "shata" : 0, "low" : 0 }

    OutputString = ""
    if( NCases < 10 ):
        OutputString += "   "
    elif( NCases < 100 ):
        OutputString += "  "
    elif( NCases < 1000 ):
        OutputString += " "
    
    OutputString += str( NCases ) + "."

    if( diccBangla[ "kuti_1" ] > 0 ):
        OutputString += " " + str( diccBangla[ "kuti_1" ] ) + " kuti"
    if( diccBangla[ "lakh_1" ] > 0 ):
        OutputString += " " + str( diccBangla[ "lakh_1" ] ) + " lakh"
    if( diccBangla[ "hajar_1" ] > 0 ):
        OutputString += " " + str( diccBangla[ "hajar_1" ] ) + " hajar"
    if( diccBangla[ "shata_1" ] > 0 ):
        OutputString += " " + str( diccBangla[ "shata_1" ] ) + " shata"
    if( diccBangla[ "kuti" ] > 0 ):
        OutputString += " " + str( diccBangla[ "kuti" ] )

    if( ( diccBangla[ "kuti_1" ] +  diccBangla[ "lakh_1" ] + diccBangla[ "hajar_1" ] + diccBangla[ "shata_1" ] + diccBangla[ "kuti" ] ) > 0 ):
        OutputString += " kuti"
        
    if( diccBangla[ "lakh" ] > 0 ):
        OutputString += " " + str( diccBangla[ "lakh" ] ) + " lakh"
    if( diccBangla[ "hajar" ] > 0 ):
        OutputString += " " + str( diccBangla[ "hajar" ] ) + " hajar"
    if( diccBangla[ "shata" ] > 0 ):
        OutputString += " " + str( diccBangla[ "shata" ] ) + " shata"
    if( diccBangla[ "low" ] > 0 ):
        OutputString += " " + str( diccBangla[ "low" ] )


    if( ( diccBangla[ "kuti_1" ] +  diccBangla[ "lakh_1" ] + diccBangla[ "hajar_1" ] + diccBangla[ "shata_1" ] + diccBangla[ "kuti" ] + diccBangla[ "lakh" ] + diccBangla[ "hajar" ] + diccBangla[ "shata" ] + diccBangla[ "low" ] ) == 0 ):
        OutputString += " 0"

    print( OutputString )








    

    #print( repr( diccBangla ) )
