import sys

TotalCases = int( ( sys.stdin.readline() ).strip() )

for CC in range( TotalCases ):

    People = [] # Register of people
    PeopleKey = {} # Name of the group they belong
    Network = {} # Lists of groups by name
    
    TotalInteractions = int( ( sys.stdin.readline() ).strip() )    
    for II in range( TotalInteractions ):
        NewFriends = [ FF for FF in ( ( sys.stdin.readline() ).strip() ).split() ]
        #print( repr( NewFriends ) )

        Friend0_Key = NewFriends[ 0 ]        
        if( NewFriends[ 0 ] in People ):
            Friend0_Key = PeopleKey[ NewFriends[ 0 ] ]
        else:
            People.append( NewFriends[ 0 ] )
            PeopleKey[ NewFriends[ 0 ] ] = NewFriends[ 0 ]            
            Network[ NewFriends[ 0 ] ] = 1

        Friend1_Key = NewFriends[ 1 ]        
        if( NewFriends[ 1 ] in People ):
            Friend1_Key = PeopleKey[ NewFriends[ 1 ] ]
        else:
            People.append( NewFriends[ 1 ] )
            PeopleKey[ NewFriends[ 1 ] ] = NewFriends[ 1 ]
            Network[ NewFriends[ 1 ] ] = 1

        if( Friend0_Key == Friend1_Key ): # They belong to the same network
            print( str( Network[ Friend0_Key ] ) )
            continue
        else:

            # Make NewKey the group with more members
            NewKey = Friend0_Key
            OldKey = Friend1_Key
            if( Network[ Friend1_Key ] > Network[ Friend0_Key ] ): 
                NewKey = Friend1_Key
                OldKey = Friend0_Key

            # Merge groups
            Network[ NewKey ] += Network[ OldKey ] # These are disjoint sets (lists), so they don't have repeated members
                
            # Update keys of old key
            for MM in People:
                if( PeopleKey[ MM ] == OldKey ):
                    PeopleKey[ MM ] = NewKey
            del Network[ OldKey ]

            print( str( Network[ NewKey ] ) )

            
            



