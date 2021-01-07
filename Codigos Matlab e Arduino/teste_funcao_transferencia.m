clc;clear all; close all;
s= tf('s');

%% LGR
%            1
% -----------------------
% s (s+2) (s^2 + 8s + 25)

G = (19.55/((158*s)+1))+ 25.42;
step(G);