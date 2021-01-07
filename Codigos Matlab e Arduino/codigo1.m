clc ; clear all; close all;

    board = arduino('COM7','Uno');  
    temperatura = [10000];
    porcentagem =20;
    pwm= (porcentagem*5)/100;
    writePWMVoltage(board, 'D9',pwm);  
    
    x=0
    while 1
%     for i=1:100
    analog = readVoltage(board,'A0');
    temperatura = (analog/(0.0048875))*0.48828125;
    disp(['',num2str(temperatura)]);
    %x = [x temperatura];
    plot(temperatura);
    grid;
    %set(handles.edit1,'String',num2str(temperatura));
    pause(1);
    end