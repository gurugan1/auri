

P = get_edge(x,y);

cvx_begin
    variable x(n)
    minimize( norm(A*x-b) )
cvx_end
display(x)




function V = get_edge( x, y)
    V = zeros(N,N);
    V(x,y) = 1;
    V(x,N) = 1;
    V(y,N) = 1;
    V(N,N) = 1;
    
end