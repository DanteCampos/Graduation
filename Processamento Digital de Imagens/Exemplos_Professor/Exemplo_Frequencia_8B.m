function PQ = Exemplo_Frequencia_8B(AB, CD, PARAM)
%PADDEDSIZE Computes padded sizes useful for FFT-based filtering.
% PQ = PADDEDSIZE(AB), where AB is a two-element size vector, computes the
% two-element size vecter PQ = 2*AB.
%
% PQ = PADDEDSIZE(AB, 'PWR2') computes the vector PQ such that PQ(1) =
% PQ(2) = 2^nextpow2(2*m), where m is MAX(AB).
%
% PQ = PADDEDSIZE(AB, CD), where AB and CD are two-element size vectors,
% computes the two-element size vector PQ. The elements of PQ are the
% smallest even integers greater than or equal to AB + CD -1.
%
% PQ = PADDEDSIZE(AB, CD, 'PWR2') computes the vector PQ such that PQ(1) =
% PQ(2) = 2^nextpow2(2*m), where m is MAX([AB CD]).
%
% Function rewritten from Gonzalez, Woods, Eddins; Digital Image Processing using Matlab
% Prentice Hall, 2004
if nargin ==1
      PQ = 2*AB;
elseif nargin == 2 & ~ischar(CD)
      PQ = AB +CD -1;
      PQ = 2*ceil(PQ/2);
elseif nargin ==2
      m= max(AB); %Maximum dimension
      %Find power-of-2 at least twice m.
	P = 2^nextpow2(2*m);
	PQ = [P, P];
elseif nargin == 3
      m=max([AB CD]); % Maximum dimension.
      P = 2^nextpow2(2*m);
      PQ = [P, P];
else
      error('Wrong number of inputs')
end