import sys

DebugOn = False

for InputCases in sys.stdin:

    TotalCases = int( InputCases )
    
    dCountryWoman = {}
    
    for NN in range( TotalCases ):
        InputString = ( sys.stdin.readline() ).strip()

        DataSplit = [ str( S ) for S in InputString.split() ]

        Country = DataSplit[ 0 ]

        Name = ( InputString.replace( Country, "" ) ).strip()

        if DebugOn:
            print( "Country: " + Country )
            print( "Name: " + Name )

        if( Country in dCountryWoman ):
            dCountryWoman[ Country ].append( Name )
        else:
            dCountryWoman[ Country ] = list( [ Name ] )

    #print( repr( dCountryWoman ) )

    CountryNames = list()
    for NN in dCountryWoman:
        CountryNames.append( NN )

    CountryNames.sort()
    for CC in CountryNames:
        print( CC + " " + str( len( dCountryWoman[ CC ] ) ) )
            
    


    
            


