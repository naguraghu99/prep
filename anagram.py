from collections import Counter
def number_needed(a,b):
	c = Counter()
	d = Counter()
	if (len(a) == 0):
		return len(b)
	if(len(b) == 0):
		return len(a)
	for element in a:
		c[element]+=1
	print (c)
	for element in b:
		if (c[element] ==0):
			d[element]+=1	
		else :
			c[element]-=1
	total = 0
	print (c)
	for key, value in c.items():
		total = total + value
	for key, value in d.items():
		total = total + value
	return total

a = input().strip()
b = input().strip()
print(number_needed(a,b))

