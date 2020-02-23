
close all;
clear all;
clc;

bandaPassante = 5;  % Hz
desvio = -0.5;      % dB

s = tf('s');
f = 10;
SecondOrderTransferFunction = (2*pi*f)^2/((s+2*pi*f)*(s+2*pi*f));

aux = 0;
while aux == 0
    Hjw = evalfr(SecondOrderTransferFunction,1j*2*pi*bandaPassante);
    dB = 20*log10(abs(Hjw));
    if dB > -3
        f = f - 0.1;
        SecondOrderTransferFunction = (2*pi*f)^2/((s+2*pi*f)*(s+2*pi*f));
    else
        aux = 1;
    end
end

[mag,phase,wout] = bode(SecondOrderTransferFunction);

fout = wout/(2*pi);
mag_dB = zeros(1,length(mag(1,1,:)));
for i = 1:length(mag(1,1,:))
    mag_dB(i) = 20*log10(mag(1,1,i));
end

freqDesvio = interp1(mag_dB,fout,desvio);

sprintf('Para %f Hz de Banda Passante, a frequencia em que a resposta cai 0.5 dB é: %f Hz.',bandaPassante,freqDesvio)