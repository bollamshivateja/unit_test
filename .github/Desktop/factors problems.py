'''n=int(input("Enter the number:"))
for i in range(1,n+1):
  if(n%i==0):
    print(i)


n=int(input("Enter the number:"))
count=0
for i in range(1,n+1):
  if(n%i==0):
    count+=1
print("count is:",count)


n=int(input("Enter the number:"))
count=0
for i in range(1,n+1):
   if(n%i==0):
     count+=1
if(count==2):
  print("prime number")
else:
  print("not prime")
  
#armstrong number  
num=int(input("Enter the number:"))
original=num
sum=0
digits=len(str(num))
while (num>0):
  d=num%10
  sum+=d**digits
  num//=10
if(sum==original):
  print("Armstrong number")
else:
  print("Not armstrong number")


#sum of factors count
n=int(input("Enter the number:"))
count=0
for i in range(1,n+1):
   if(n%i==0):
     count+=i
print("sum of factors",count)


n=int(input("Enter the number:"))
count=0
for i in range(1,n):
   if(n%i==0):
     count+=i
     print(i)
print("sum of factors:",count)
if(count==n):
  print("perfect number..")
else:
  print("not perfect number..")
  
  
#sum of digits
n=int(input("enter the number:"))
sum=0
while(n>0):
  d=n%10
  sum+=d
  n=n//10
print("sum of digits:",sum)


#reverse of a number
n=int(input("enter the number:"))
rev=0
while(n>0):
  d=n%10
  rev=rev*10+d
  n=n//10
print("reverse of numbers:",rev)


#strong no.or not
n=int(input("Enter the number:"))
original=n
sum=0
while(n>0):
  d=n%10
  fact=1
  for i in range(1,d+1):
    fact+=i
    sum=sum+fact
  if(sum==original):
    print("Strong number")
else:
  print("Not strong")
'''
  




