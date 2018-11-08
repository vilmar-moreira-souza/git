print("hello world")
op='0'
num1=0
num2=0
resultado=0
print("0 para sair")
print("1 para somar")
print("2 para subtrair")
print("3 para dividir")
print("4 para multiplicar")

while(op=='0'or op=='1'or op=='2'or op=='3'or op=='4'):
    op=input("digite operacao ou 0 para sair")
    if (op=='0'):
        break

    elif(op=='1'or op=='2'or op=='3'or op=='4'):
        
        num1=input("digite num1")
        num2=input("digite num2")
        if(op=='1'):
            print("resultado",int(num1)+int(num2))
        elif(op=='2'):
            print("resultado=",int(num1)-int(num2))
        elif(op=='3'):
            print("resultado=",int(num1)/int(num2))
        elif(op=='4'): 
            print("resultado=",int(num1)*int(num2))
          
       
       
       
       
       
  





