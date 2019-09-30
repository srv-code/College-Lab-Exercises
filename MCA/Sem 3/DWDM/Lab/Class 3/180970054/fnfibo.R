#Script to find nterms of fibonaccie sequence series
#Punithraj G R
#26-07-2019

fnFibo <- function(n)
{
  i<-0;
  j<-1;
  print(i);
  print(j);
  while(j<=n)
  {
    i=j;
    print(i);
    j=j+i;
  }
  return();
}