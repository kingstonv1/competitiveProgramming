def process_words(k, words):
	cur_len = 0
	f = ""
	
	for word in words:
		l = len(word)
		
		if cur_len + l > k:
			f = f[:-1:]
			f += "\n" + word + " "
			cur_len = l
		else:
			f += word + " "
			cur_len += l
	
	return f[:-1:]

	
with open('word.in', 'r') as inp:
	n, k = map(int, inp.readline().split())
	w = inp.readline().split()

with open('word.out', 'w') as output:
	output.write(process_words(k, w))