#Script to find factorial of given number
#Punithraj G R
#26-07-2019

fnFact<- function(x){
if(x==1)
{
  return(1);
}
  else
  {
      return(x*fnFact(x-1));
    }
}


