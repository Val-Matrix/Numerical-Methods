x = [-5:0.01:10];
y = 0.5*x.^3 - 4*x.^2 + 6*x - 2;
plot(x, y);
xlabel('x'), ylabel('0.5.^3 - 4.^2 + 6*x - 2');
title('cubic Graph');
grid on;
grid minor;
