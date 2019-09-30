# tabulate avg mpg for diff no of gears in dataset mtcars 

gears<-unique(mtcars$gear)
rec<-dim(gears.length, 1)
for(g in unique(mtcars$gear)) { print(g); print(mean(mtcars[mtcars$gear==g,1])); }