from typing import List, Tuple, Set


WIDTH = 3


def cow_contrib(game: List[str], pts: List[Tuple[int, int]]) -> Set[str]:
	contained = set()
	for pt in pts:
		contained.add(game[pt[0]][pt[1]])
	return contained


with open("tttt.in") as read:
	board = [read.readline() for _ in range(WIDTH)]

winners = [set() for _ in range(WIDTH + 1)]
# Function which adds a winning team to the winners array
insert = lambda c: winners[len(c)].add(tuple(sorted(c)))

# Insert all the rows
for r in range(WIDTH):
	insert(cow_contrib(board, [(r, c) for c in range(WIDTH)]))

# Do the same for the columns
for c in range(WIDTH):
	insert(cow_contrib(board, [(r, c) for r in range(WIDTH)]))

# And finally the diagonals
insert(cow_contrib(board, [(i, i) for i in range(WIDTH)]))
insert(cow_contrib(board, [(i, WIDTH - i - 1) for i in range(WIDTH)]))

with open("tttt.out", "w") as written:
	print(len(winners[1]), file=written)
	print(len(winners[2]), file=written)