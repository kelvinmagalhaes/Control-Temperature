clear all; close all; clc;
s= tf('s');

sinal=load('20_60-1303_descida.txt')% carrega arquivo txt
  

%   zero       = sinal(:,1);
  vinte      = sinal(:,1);
  sessenta   = sinal(:,2);
%   cem        = sinal(:,4);
  
JanelaTam=50;
ordem=1;
% janela0 = (1/JanelaTam)*ones(1,JanelaTam);
janela20 = (1/JanelaTam)*ones(1,JanelaTam);
janela60 = (1/JanelaTam)*ones(1,JanelaTam);
% janela100 = (1/JanelaTam)*ones(1,JanelaTam);
% y0 = filter(janela0,ordem,zero);
y20 = filter(janela20,ordem,vinte);
y60 = filter(janela60,ordem,sessenta);
% y100 = filter(janela100,ordem,cem);




% media movel- amostra nova e antiga.
%hold on

% G0 = (28.83/((275*s)+1))+ 25.42;
% figure(1);
% % plot(zero);
% step(G0,'r')
% hold
% plot(y0);
% title('Acionamento a 0%');

% G20 = (19.55/((160*s)+1))+ 25.42;
G20 =  (-21.5/((37*s)+1))+ 77.22;
figure(2);
%plot(vinte);
step(G20,'r');
hold
plot(y20);
title('Acionamento a 20%');

% G60 = (11.24/((100*s)+1))+ 25.42;
G60 =  (-29.81/((20*s)+1))+ 77.22;
figure(3);
%plot(sessenta);
step(G60,'r');
hold
plot(y60);
title('Acionamento a 60%');


% G100 = (8.3/((75*s)+1))+ 25.42;
% figure(4);
% % plot(cem);
% step(G100,'r');
% hold
% plot(y100);
% title('Acionamento a 100%');

figure(5);
plot(y20);
hold
plot(y60);
legend('20%','60%');


% M0=mean(zero)
M1=mean(vinte)
M2=mean(sessenta)
% M3=mean(cem)