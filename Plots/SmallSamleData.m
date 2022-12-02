B = [
0 0;
3 15;
5 11.667;
7 17.5;
8 18.333;

];

A = [
0 0;
5 11.667;
7 17.5;
8 18.333;
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
  text(thisX, thisY, labelstr,'FontSize', 15);
end

