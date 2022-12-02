B = [
0 0;
25 3.086;
31 3.44;
52 4.146;
62 5.869;
56 6.058;
77 6.294;
73 6.345;
65 7.259;
54 7.965;
78 8.016;
79 8.244;
83 8.376;
70 8.709;
67 10.434;
60 10.952;
58 11.832;
85 12.008;
88 12.254;
80 12.906;
81 13.424;
71 14.01;
90 17.38;
87 18.703;
98 32.058;
96 32.181;

];

A = [
0 0;
25 3.086;
31 3.44;
52 4.146;
62 5.869;
77 6.294;
78 8.016;
79 8.244;
83 8.376;
85 12.008;
88 12.254;
90 17.38;
98 32.058;
];



plot(A(:,1),A(:,2),"-",'linewidth', 3);
hold on;
plot(B(:,1),B(:,2),"*",'linewidth', 4);
hold off;

xlabel("sl","FontSize",33);
ylabel("tc","FontSize",33);
legend("1st Pareto Front", "Other-Solutions", 'fontsize', 20);

for K = 1 : size(A)
  thisX = A(K,1)
  thisY = A(K,2)
  labelstr = sprintf('  (%.2f,%.2f)', thisX, thisY);
%   text(thisX, thisY, labelstr,'FontSize', 10);
end
