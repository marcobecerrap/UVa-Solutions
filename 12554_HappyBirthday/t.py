import sys

InputCases = int( sys.stdin.readline() )

ListPersons = []

for JJ in range( InputCases ):
    InputString = sys.stdin.readline()
    InputString = InputString.rstrip()
    ListPersons.append( InputString )

ListSinger= [ 0 ] * len( ListPersons )

ListSong = [ 'Happy', 'birthday', 'to', 'you', 'Happy', 'birthday', 'to', 'you', 'Happy', 'birthday', 'to', 'Rujia', 'Happy', 'birthday', 'to', 'you' ]

idx = 0
while sum( ListSinger ) < len( ListSinger ):

    for TT in ListSong:
        idx_sing = idx % len( ListSinger )
        print( ListPersons[ idx_sing ], ': ', TT, sep='' )
        ListSinger[ idx_sing ] = 1
        idx += 1
