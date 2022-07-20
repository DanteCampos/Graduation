clear all;
clc;

a=imread('Exemplo_Segmentacao_5.jpg'); 
b  = rgb2gray(a);
c = edge(b,'canny');

se=strel('square', 3);
c = imdilate(c,se);

[H,T,R] = hough(c);
P  = houghpeaks(H,5,'threshold',ceil(0.3*max(H(:))));

lines = houghlines(c,T,R,P,'FillGap',5,'MinLength',7);
figure;
subplot(1,3,1);
imshow(a);
title('Original');

subplot(1,3,2);
imshow(c);
title('Canny');

subplot(1,3,3);
imshow(c);
title('Hough');
hold;
max_len = 0;
for k = 1:length(lines)
   xy = [lines(k).point1; lines(k).point2];
   plot(xy(:,1),xy(:,2),'LineWidth',2,'Color','green');

   % Plot beginnings and ends of lines
   plot(xy(1,1),xy(1,2),'x','LineWidth',2,'Color','yellow');
   plot(xy(2,1),xy(2,2),'x','LineWidth',2,'Color','red');

   % Determine the endpoints of the longest line segment
   len = norm(lines(k).point1 - lines(k).point2);
   if ( len > max_len)
      max_len = len;
      xy_long = xy;
   end
end

