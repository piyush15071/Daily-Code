t=int(input())
i=0
l=[]
while(i!=(2*t)):
    l.append(input())
    i+=1
j=0
k=[]

while(j!=(2*t)):
    new=''
    for word in l[j]:
        for sword in l[j+1]:
            if(word==sword):
                new=new+word
                break
    k.append(new)
    j+=2
for item in k:
    print(''.join(sorted(item)))

