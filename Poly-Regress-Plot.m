x = [1:0.01:10];
y = 2.782 + 1.936*x  - 0.2019*x.^2;
plot(x, y);
xlabel('x'), ylabel('y = 2.782 + 1.936*x  - 0.2019*x.^2');
title('Graph of y = 2.782 + 1.936*x  - 0.2019*x.^2');
grid on;
grid minor;
hold on 
plot(1.2, 4.5, 'r*', 'displayName', 'x0')
plot(1.5, 5.1, 'r*', 'displayName', 'x1')
plot(1.8, 5.8, 'r*', 'displayName', 'x2')
plot(2.6, 6.7, 'r*', 'displayName', 'x3')
plot(3.1, 7.0, 'r*', 'displayName', 'x4')
plot(4.3, 7.3, 'r*', 'displayName', 'x5')
plot(4.9, 7.6, 'r*', 'displayName', 'x6')
plot(5.3, 7.4, 'r*', 'displayName', 'x7')
plot(5.7, 7.2, 'r*', 'displayName', 'x8')
plot(6.4, 6.9, 'r*', 'displayName', 'x9')
plot(7.1, 6.6, 'r*', 'displayName', 'x10')
plot(7.6, 5.1, 'r*', 'displayName', 'x11')
plot(8.6, 4.5, 'r*', 'displayName', 'x12')
plot(9.2, 3.4, 'r*', 'displayName', 'x13')
plot(9.8, 2.7, 'r*', 'displayName', 'x14')
