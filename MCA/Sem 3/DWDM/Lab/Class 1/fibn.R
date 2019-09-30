# Find n terms of a fibonacci series
# Sourav Dey
# 24-Jul-2019
# input: a (scalar): start num 1
# input: b (scalar): start num 2
# input: n (scalar): count of series members to generate
# return: terms (vector): fib series

fibn <- function(a,b,n) {
  terms<-c(a)
  i<-1
  while(i<n) {
    # print(i)
    i<-i+1
    terms[i]<-b
    tmp=a+b
    a<-b
    b<-tmp
  }
  return(terms)
}
