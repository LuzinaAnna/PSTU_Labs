Var  x,a,b,c,t,x1,x2,x3,x4,x5,x6,max1,max2,max3,max4,max5:integer;
  begin 
    write('Введите трехзначное число ');
    read(x);
    while ((x<100) or (x>999)) and ((a=b) or (a=c) or (b=c)) do
       begin
    write('Введенное число не трехзначное,повторите ввод');
    readln(x);
    end;
    a:=x div 100;
    b:=x div 10 mod 10;
    c:=x mod 10;
    writeln('Все возможные последовательности чисел:');
    x1:=a*100+b*10+c;
    writeln(a,b,c);
    t:=c;
    c:=b;
    b:=t;
    x2:=a*100+b*10+c;
    writeln(a,b,c);
    t:=a;
    a:=b;
    b:=t;
    x3:=a*100+b*10+c;
    writeln(a,b,c);
    t:=a;
    a:=c;
    c:=t;
    x4:=a*100+b*10+c;
    writeln(a,b,c);
    t:=c;
    c:=b;
    b:=t;
    x5:=a*100+b*10+c;
    writeln(a,b,c);
    t:=a;
    a:=b;
    b:=t;
    x6:=a*100+b*10+c;
    writeln(a,b,c);
    max1:=max(x1,x2);
    max2:=max(x3,x4);
    max3:=max(x5,x6);
    max4:=max(max1,max2);
    max5:=max(max3,max4);
    writeln('Наибольшее из этих числе: ');
    writeln(max5);
  end.