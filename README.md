Compile using:
`make`
Run using:
`./main.out`

At prompt - "Избери игра: " enter either "ramg" or "remg".
Then when ready tap enter to show cards and then enter again
to hide cards and to start typing their values.

The encoding for the numbers and the suits is:\
for 1-9 => just the number\
for 10 => 0\
for jack => j\
for queen => q\
for king => k\
for ace => a

for   Hearts => h\
for Diamonds => d\
for    Clubs => c\
for   Spades => s

So if shown the following utf-8 cards:\
10 of hearts, jack of spades, queen of clubs, 3 of spades\
Then the answer that should be typed is:\
0h js qc 3s*nl*

After a few rounds a statistic is shown and written to a file.
