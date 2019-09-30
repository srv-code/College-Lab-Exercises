# Factorial of a given number n
# Sourav Dey
# 24-Jul-2019
# n: scalar
# f: scalar

fact <- function(n) {
  if(n<=1) {
    return(1)
  }
  f<-1
  while(n>1) {
    f<-f*n
    n<-n-1
  }
  return(f)
}
