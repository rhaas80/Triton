
L = 2^15;
Fs = L;
T = 1/Fs;
t = 0:L-1;
ReT = t;
ImT = t;

t = t*T;
ReT = 0.7*sin(2*pi*50*t) + sin(2*pi*120*t) + 2*randn(size(t));
ImT = 0.7*cos(2*pi*50*t) + cos(2*pi*120*t) + 2*randn(size(t));

ReF = fft(ReT+i*ImT)/L;
ImF = imag(ReF);
ReF = real(ReF);

% figure;
% plot(t, ReT, t, ImT);

figure;
plot(t, ReF, t, ImF);

