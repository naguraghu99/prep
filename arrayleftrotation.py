'''
   a - input array
   n - Array size
   k - number of left rotations
'''
def array_left_rotation(a,n,k):
	print ("value of n {},value of k {},value of a {}".format(n,k,a))
	if  not (n>=1 and n<100000):
		return
	if not (k>=1 and k<=n):
		return
	
	output = []
	for i in range((k),len(a)):
		output.append(a[i])
	for i in range (0,k):
		output.append(a[i])
	return output	


n,k = map(int,input().strip().split(' '))
a = list(map(int,input().strip().split(' ')))
answer = array_left_rotation(a,n,k)
print(*answer,sep=' ')
