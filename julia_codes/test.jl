a = 1
x = randn(2)
y = randn(2)

bar(x) = 2 * x
foo(x) = (2 * x, x - 1)

[bar(x[i]) for i = 1:length(x)]
bar.(x)

z = @. bar(x) * y + 2 

x = 1:2
y = 2:3
xx = @. x + 0 * y'
yy = @. 0 * x + y'

f(x,y) = x * y
