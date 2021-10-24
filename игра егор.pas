Var x:real; a1,i:integer;
  begin
    x:=random(100);
    writeln('Вводите числа от 1 до 100');
     writeln('У вас есть 7 попыток');
     for i:=1 to 7 do
       begin
     writeln(i,'-я попытка:');
     read(a1);
     if a1<>x then
       begin
       if a1>x then 
         writeln('Нужное число меньше, чем',' ',a1)
         else
           writeln('Нужное число больше, чем',' ',a1);
         end
         else 
           begin
           write('Поздравляем, вы отгадали число!');
           halt;
           end;
           end;
           writeln('Не угадали:(');
           writeln('Число=',x);         
           end.