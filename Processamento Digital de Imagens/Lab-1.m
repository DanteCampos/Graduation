% Questão 1

line = []

for i = 1:1:40
	line = [line,i]
endfor

mat = []
for i = 1:1:40
	mat = [mat;line]
endfor
  
gray = mat2gray(mat)
imshow(gray)

% Questão 2
imshow(gray, [0 2])
imshow(gray, [0.3, 0.7])
imshow(gray, [])