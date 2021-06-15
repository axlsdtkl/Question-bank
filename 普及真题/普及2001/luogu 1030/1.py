def work(l,r,ll,rr):
	mark=0
	for i in range(l,r+1):
		if(s1[i]==s2[rr]):
			mark=i
			break
	print(s2[rr],end="")
	if(mark>l):work(l,mark-1,ll,ll+mark-l-1)
	if(mark<r):work(mark+1,r,ll+mark-l,rr-1)
s1=input().strip()
s2=input().strip()
len1=len(s1)
work(0,len1-1,0,len1-1)
