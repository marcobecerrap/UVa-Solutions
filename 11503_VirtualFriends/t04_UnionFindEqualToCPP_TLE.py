import sys

People = [] # Names of people
PeopleID = {} # People IDs    
Parent = [] # People parent
GroupSize = [] # Size of group with Key root parent


def FindRootParent( Person ):
    if( Parent[ Person ] != Person ):
        Parent[ Person ] = FindRootParent( Parent[ Person ] )
    return Parent[ Person ]


TotalCases = int( ( sys.stdin.readline() ).strip() )
for CC in range( TotalCases ):

    People.clear() # Names of people
    PeopleID.clear() # People IDs    
    Parent.clear() # People parent
    GroupSize.clear()
    IDcount = 0
    
    TotalInteractions = int( ( sys.stdin.readline() ).strip() )    
    for II in range( TotalInteractions ):

        #print("==============================")
        Friend_0, Friend_1 = [ FF for FF in ( ( sys.stdin.readline() ).strip() ).split() ]
        #print( Friend_0 + " " + Friend_1 )

        if( Friend_0 not in People ):
            People.append( Friend_0 )
            PeopleID[ Friend_0 ] = IDcount
            Parent.append( IDcount )
            GroupSize.append( 1 )
            IDcount += 1

        if( Friend_1 not in People ):
            People.append( Friend_1 )
            PeopleID[ Friend_1] = IDcount
            Parent.append( IDcount )
            GroupSize.append( 1 )
            IDcount += 1

        ID_0 = PeopleID[ Friend_0 ]
        ID_1 = PeopleID[ Friend_1 ]

        #print( "ADD INTERACTION: " + Friend_0 + " " + Friend_1 )
        #print( "parents: "  + FindRootParent( Friend_0 ) + " " + FindRootParent( Friend_1 ) )
        #print( repr( People ) )

        # FIND root parents of Friends
        Parent_0 = FindRootParent( ID_0 )
        Parent_1 = FindRootParent( ID_1 )

        #print( "Parent of " + Friend_0 + " is " + RootParent_0 + ", group size is " + str( PeopleGroupSize[ RootParent_0 ] ) )
        #print( "Parent of " + Friend_1 + " is " + RootParent_1 + ", group size is " + str( PeopleGroupSize[ RootParent_1 ] ) )

        if( Parent_0 != Parent_1 ):
            # UNION of groups
            Parent[ Parent_1 ] = Parent_0
            GroupSize[ Parent_0 ] += GroupSize[ Parent_1 ]
        print( GroupSize[ Parent_0 ] )


        

            
            



