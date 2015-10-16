tic
F1 = imread ('frame27_1.bmp');
F2 = imread('frame27_2.bmp');
C1 = F1;
C2 = F2;
%C1(:,:,1:1:2) = [ ];
%C2(:,:,1:1:2) = [ ];
%R1 = reshape(F1,100,100);
%R2 = reshape(F2,100,100);
%R1=C1(100,100);
%R2=C2(100,100);
R1 = C1(1:100,1:100);
dlmwrite('Frame1.txt',R1,' ');
R2 = C2(1:100,1:100);
dlmwrite('Frame2.txt',R2,' ');
D = R1 - R2;
A = abs(D);
SAD1 = sum(sum(A));
fprintf('%d',SAD1);
dlmwrite('Frame12.txt',A, ' ');
toc