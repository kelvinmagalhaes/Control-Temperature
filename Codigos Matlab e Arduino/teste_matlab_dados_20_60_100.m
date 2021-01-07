clear all; close all; clc;

sinal=load('dados_20_60_100.txt')% carrega arquivo txt

  vinte      = sinal(:,1);
  sessenta   = sinal(:,2);
  cem        = sinal(:,3);
  
JanelaTam=20;
ordem=1;
janela20 = (1/JanelaTam)*ones(1,JanelaTam);
janela60 = (1/JanelaTam)*ones(1,JanelaTam);
janela100 = (1/JanelaTam)*ones(1,JanelaTam);
y20 = filter(janela20,ordem,vinte);
y60 = filter(janela60,ordem,sessenta);
y100 = filter(janela100,ordem,cem);




% media movel- amostra nova e antiga.
%hold on
figure(1);
% plot(vinte);
% hold
plot(y20);
title('Acionamento a 20%');

figure(2);
% plot(sessenta);
% hold
plot(y60);
title('Acionamento a 60%');

figure(3);
% plot(cem);
% hold
plot(y100);
title('Acionamento a 100%');

figure(4);
plot(y60);
hold
plot(y100);
legend('60%','100%');



M1=mean(vinte)
M2=mean(sessenta)
M3=mean(cem)