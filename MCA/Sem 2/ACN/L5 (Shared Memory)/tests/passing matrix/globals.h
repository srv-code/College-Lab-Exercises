const int SIG_EXEC = 1;
const int SIG_DONE = 2;
const int SIG_STOP = 3;

#define ELECNT 3
#define MAXROWS 10
#define MAXCOLS 10

const int SHMSZ = ((3*MAXROWS*MAXCOLS)+1+2)*sizeof(int);
