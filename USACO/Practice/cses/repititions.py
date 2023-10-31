import re
import sys

sequence = sys.stdin.readline()
r = re.compile(r'((.)\2*)', re.I)
res = r.findall(sequence)
groups = list(map(lambda x: x[0], res))
lengths = list(map(lambda x: len(x), groups))
print(max(lengths))
