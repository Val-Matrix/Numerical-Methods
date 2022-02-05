x = xlsread('C:\\Users\\Valentino\\Desktop\\Polynomial Regression Result.csv', 'A2:A16');
y = xlsread('C:\\Users\\Valentino\\Desktop\\Polynomial Regression Result.csv', 'B2:B16');
xx = xlsread('C:\\Users\\Valentino\\Desktop\\Polynomial Regression Result.csv', 'A21:A121');
yy = xlsread('C:\\Users\\Valentino\\Desktop\\Polynomial Regression Result.csv', 'B21:B121');

figure
hold on
plot(xx,yy)
for i = 1:15
    p = plot(x(i), y(i), 'k.', 'MarkerSize', 16)
    datatip(p, x(i), y(i))
end
grid on
title('Graph of y = 2.782 + 1.936x  - 0.2019x^2')
xlabel('x')
ylabel('y')