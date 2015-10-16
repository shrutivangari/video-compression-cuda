tic
F1 = imread ('frame27_1.bmp');
F2 = imread('frame27_2.bmp');
C1 = F1;
C2 = F2;
C1(:,:,1:1:2) = [ ];
C2(:,:,1:1:2) = [ ];
R1 = reshape(C1,1,nzmax(C1));
R2 = reshape(C2,1,nzmax(C2));
D = R1 - R2;
A = abs(D);
m = nzmax (A);
l = 0;
k = 0;
fid = fopen ('output.txt','w+b');
for h = 1:8:m
    for i = h:(h+7)
       l = dec2bin(A(i));
       p = length(l);
       while p<8
       k = [48 l];
       l = k;
       p = p+1;
   end
   fprintf (fid, '%s\n', l);
  end
end
fclose (fid);
toc