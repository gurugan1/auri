function ret = halperin( A )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
temp = size(A);
display(temp);
n = temp(1);
N = n+1;
Y = zeros(N);
Y(N,:) = ones(N,1);
Y(:,N) = ones(1,N);
Y(N,N) = 2*n;
Y = Y/4;
E = [];

for i = 1:n
    for j = 1:i
        if (A(i,j) ==1)
            E = [E;[i,j]];
        end
    end
end

m = size(E);
m = m(1);
display(m);
display(Y);
C = zeros(N,N,m);
for i =1:m
    x = E(i,1);
    y = E(i,2);
    C(x,y,i) = 1;
    C(x,N,i) = 1;
    C(y,N,i) = 1;
    C(N,N,i) = 1;
    %display(C(:,:,i));
end

cvx_begin
    variable R(N,N)  symmetric;
    maximize trace(R*Y);
    subject to
        R == semidefinite(N);
        diag(R) == ones(N,1);
        for j=1:m
            trace(R*C(:,:,j)) == 0;
        end
cvx_end;

display((ones(1,n) + R(N,1:n))/2);
ret = R;
display(cvx_optval)
end

        




