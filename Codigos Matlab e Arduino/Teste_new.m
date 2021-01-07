clear all; close all; clc;
s= tf('s');
%% carrega arquivo txt
sinal20=load('20.txt')
sinal60=load('60.txt')
sinaldescida=load('20-60-1303.txt')
sinaltotal=load('20_60-1303_total.txt')
  

vinte      = sinal20(:,1);
sessenta   = sinal60(:,1);
descida    = sinaldescida(:,1);
total      = sinaltotal(:,1);
  
JanelaTam=20;
ordem=1;
janela = (1/JanelaTam)*ones(1,JanelaTam);
y1 = filter(janela,ordem,vinte);
y2 = filter(janela,ordem,sessenta);
y3 = filter(janela,ordem,total);
y4 = filter(janela,ordem,descida);
% media movel- amostra nova e antiga.

%% 0 para 20%
figure(1)
G20 = (-19.5/((557*s)+1))+ 75.22;
%plot(vinte);
% step(G20,'r');
step(G20,'g');
hold
plot(y1);
title('Acionamento de 0 - 20%');

%% 20 para 60%
figure(2)
% G60 =  (-7.72/((280*s)+1))+ 55.72;
G60 =  (-7.72/((280*s)+1))+ 55.72;
%plot(vinte);
% step(G20,'r');
step(G60,'r');
hold
plot(y2);
title('Acionamento de 20 -  60%');

%% Simulacao completa 0-60%
figure(3);
% plot(y20);
hold
plot(y3);
legend('20%-60%');

%% Simulacao descida
figure(4);
% plot(y20);
hold
plot(y4);
legend('0%-60%');

M1=mean(vinte)
% M2=mean(sessenta)
%% funcao ident
