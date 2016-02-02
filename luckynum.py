t=int(input())
i=0
while(i<t):
    num=int(input())
    count=0
    for div in range(2,int((num/2))+2):
        if(num%div==0):
            strdiv=str(div)
            listdiv=[]
            for z in strdiv:
                listdiv.append(z)
            for letter in listdiv:
                if((letter!='4')and(letter!='7')):
                    listdiv.remove(letter)
            if(len(listdiv)!=0):
                count+=1
    num=str(num)
    lis=[]
    for item in num:
        lis.append(item)
    for it in lis:
        if((it!='4')and(it!='7')):
            lis.remove(it)
    if(len(lis)!=0):
        count+=1
    print(count)
    i+=1
