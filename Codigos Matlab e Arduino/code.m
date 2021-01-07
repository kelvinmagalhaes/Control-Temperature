clc; clear all; close all;
%% Definicoes
s   = tf('s');

%% Malha aberta
%porcentagem=20;
%porcentagem=60;
%velocidade=(porcentagem*255)/100;

%% Funcao transferencia - Calculadas no relatório
% Gp      = -0.9736/(100*s+1);
% Gpi     = -0.9736/((625*s)+(50*s)+1);
% Gpid    = -0.9736/((2500*(s^2))+(125*s)+1)

%% LGR 
Ke= -0.9736;
num=Ke;
den=[2500 125 1];
G=tf(num,den)
%step(G);
rlocus(G);% LGR
%rltool(Gpid);
%% Discretizacao
% numS    = [-0.9736];
% denS    = [2500 125 1];
% Ts      = 0.1;
% [numZ,denZ]  =  c2dm(numS,denS,Ts,'tustin')
% 
% %% Plots
% figure(1)
% step(Gp+44,Gpi+44,Gpid+44);

