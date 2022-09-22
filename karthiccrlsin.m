clc;
N=1024;
f1=1;
fs=200;
n=0:N-1;
x=sin(2*pi*f1*n/fs);
y=x+10*randn(1,N);
subplot(3,1,1);
plot(x);
title('x(n)pure sinewave');
xlabel('time[s]');
ylabel('amplitude');
grid;
Rxx=xcorr(x);
subplot(3,1,2);
plot(y);
grid;
title('y(n)pure sinewave+noise');
xlabel('time[s]');
ylabel('amplitude');
grid;
Rxy=xcorr(x,y);
subplot(3,1,3);
plot(Rxy);
title('cross correlation Rxy');
xlabel('lags');
ylabel('crosscorrelation');
 
 

