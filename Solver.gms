$onInline
sets
i /1,2,3/
j /1,2,3,4,5/
k /1,2,3,4,5,6,7/
l /1,2/;  

/*Here,
    i -> number of rows
    j -> number of columns
    l -> number of destination
    k -> number of trucks
*/

Parameter
c(k)
/   1 10
    2 5
    3 16
    4 8
    5 7
    6 3
    7 9/
/*c(k) is the capcity of the k-th truck.*/

len(k)
/   1 3
    2 1
    3 4
    4 2
    5 2
    6 1
    7 3/
/*len(k) is the length of the k-th truck.*/

mil(k)
/   1 5
    2 10
    3 8
    4 20
    5 15
    6 5
    7 10/
/*mil(k) is the mileage of the k-th truck.*/

dist(l)
/   1 50
    2 100/;
/*dist(l) is the distance l-th truck.*/
    
Scalar
MaxCost /84.16667/;

Table z(i,j)
    1 2 3 4 5
1   4 0 0 0 0
2   1 2 0 0 0
3   1 2 0 0 0;
/*z(i, j) -> size of the (i,j)-th block in the parking lot.*/

Variables
a(i,j,k)
b(k,l)
sl
tc;
/*Here,
        a(i, j, k) = kth truck is parked at the (i,j)th block in the parking lot.
        
        b(k, l) = k-th truck is assigned to l-th truck destination.

        sl = sure load
        tc = maximum cost of delivering to any destination.
*/


Integer Variables
a(i,j,k)
b(k,l);


Equations
load(i,l)
cost(l)
block(k)
destination(k)
block_and_destination(k)
block_size(i,j);


load(i,l).. sum(k,c(k)*b(k,l))-sum(k,c(k)*b(k,l)*(sum(j,a(i,j,k))))=g=sl;

cost(l).. sum(k,(dist(l)/mil(k))*b(k,l))=l=tc;

block(k).. sum((i,j),a(i,j,k))=l=1;

destination(k).. sum(l,b(k,l))=l=1;

block_and_destination(k).. sum((i,j),a(i,j,k))-sum(l,b(k,l))=e=0;

block_size(i,j).. sum((k),len(k)*a(i,j,k))=l=z(i,j);


a.lo(i,j,k)=0;
b.lo(k,l)=0;

a.up(i,j,k)=1;
b.up(k,l)=1;

a.l(i,j,k)=0;
b.l(k,l)=0;

sl.l=0;
tc.l=0;


Model multi_obj / all /;

Set counter / c1*c41 /;

Scalar E;

Parameter report(counter,*), ranges(*);


/* finding maximum(worst) value of TC by maximizing SL without any additional constraints*/
solve multi_obj using minlp maximizing sl;
ranges('SLmax') = sl.l;
ranges('TCmax') = tc.l;


/* finding minimum(best) value of TC by minimizing TC without any additional constraints*/
solve multi_obj using minlp minimizing tc;
ranges('TCmin') = tc.l;
ranges('SLmin') = sl.l;



/* 
    solving multi-objective by restricting TC
    epsilon value(E) is varied from TCmin to TCmax 
*/

 loop(counter,
   E = (ranges('TCmax') - ranges('TCmin'))*(ord(counter)-1)/(card(counter) - 1)+ranges('TCmin');
   tc.up = E;
   solve multi_obj using minlp maximizing sl;
   report(counter,'SL') = sl.l;
   report(counter,'TC') = tc.l;
   report(counter,'E')   = E;
); 

display ranges;
display report;
