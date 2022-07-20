%% PSIB 2015, Trabalho final, o problema 2
% This application  performs the filtering of an image in the frequency 
% domain. It applies a low-pass filter for multiplying a transfer function 
% suitable for 2D Fourier transform of the image, then inverse Fourier 
% transform. An image and a cut-off frequency are choosen by user.
% Results are compared to images obtained using spatial filtering
% operators.
%% Input
% Image
% Image file selection dialog box

clear;
clc;

[filename,pathname] = uigetfile('*.jpg;*.tif;*.png;*.gif','Select the image file');
%Reading a file and converting to greyscale
I0 = imread(fullfile(pathname, filename)); %MxNx3
I0grey = im2double(rgb2gray(I0)); %grey, MxN
% Cut-off frequency for low pass filter
prompt = 'Enter a cut-off frequency for a low-pass filter:';
dlg_title = 'Cut-off frequency';
num_lines = 1;
def = {'0.20'};
answer = inputdlg(prompt,dlg_title,num_lines,def);
K0 = str2double(answer);
% If loop that checks if K0 is correct (in range of frequencies)
ff = fft2(I0grey); % Take Fourier Transform 2D
while(1)
    if (K0 >= min(ff(:))) && (K0 <= max(ff(:)))
        break;
    else
        prompt = 'Entered cut-off frequency is incorrect, type another:';
        dlg_title = 'Cut-off frequency';
        num_lines = 1;
        def = {'0.20'};
        answer = inputdlg(prompt,dlg_title,num_lines,def);
        K0 = str2double(answer);
    end
end
%% Processing
% Fourier transform
ff = fft2(I0grey); % Take Fourier Transform 2D
F = 20*log(abs(fftshift(ff))); % Shift center; get log magnitude
% Application of low pass filter in reconstruction
%Image dimensions 
[N,M] = size(I0grey); %[height, width]
%Sampling intervals 
dx = 1; 
dy = 1; 
%Characteristic wavelengths 
KX0 = (mod(1/2 + (0:(M-1))/M, 1) - 1/2); 
KX1 = KX0 * (2*pi/dx); 
KY0 = (mod(1/2 + (0:(N-1))/N, 1) - 1/2); 
KY1 = KY0 * (2*pi/dx); 
[KX,KY] = meshgrid(KX1,KY1); 
%Filter formulation 
lpf = (KX.*KX + KY.*KY < K0^2); 
%Filter Application 
rec = ifft2(lpf.*ff);
%
lp = fir1(32,K0);  % Generate the lowpass filter (order, cut-off frequency)
lp_2D = ftrans2(lp);  % Convert to 2-dimensions
I_double = im2double(I0grey);
I_lowpass_rep = imfilter(I_double,lp_2D,'replicate');
I_lowpass_gray = mat2gray(I_lowpass_rep);
% Spatial filtering operators
% Construction of 2D filters
%with default parameters to not influence ?
h1 = fspecial('gaussian'); %gaussian low-pass filter
h2 = fspecial('log');
% Image filtering
I_f1 = imfilter(I0grey,h1,'replicate');
I_f2= imfilter(I0grey,h2,'replicate');
%% Results
%Graphics
figure;
% Plot original
subplot(2,3,1)
imshow(I0grey); 
xlabel('X','FontSize',14); 
ylabel('Y','FontSize',14);
%show FFT, magnitude
subplot(2,3,2)
mesh(F); colormap(hot); % Plot Fourier Transform as function
xlabel('H Freq','FontSize',12); 
ylabel('V Freq','FontSize',12);
% Reconstruction after filtering in frequency domain
subplot(2,3,3)
imshow(rec);
xlabel('X','FontSize',14); 
ylabel('Y','FontSize',14);
title('Filtro passa-baixo manual');
% Filtered image 1, FIR
subplot(2,3,4)
imshow(I_lowpass_gray);
xlabel('X','FontSize',14); 
ylabel('Y','FontSize',14);
title('FIR Passa-Baixa');
% Filtered image 2, fspecial Gaussian
subplot(2,3,5)
imshow(I_f1);
xlabel('X','FontSize',14); 
ylabel('Y','FontSize',14);
title('Gaussiano');
% Filtered image 3, fspecial Laplacian of Gaussian
subplot(2,3,6)
imshow(I_f2);
xlabel('X','FontSize',14); 
ylabel('Y','FontSize',14);
title('Laplacian of Gaussian');