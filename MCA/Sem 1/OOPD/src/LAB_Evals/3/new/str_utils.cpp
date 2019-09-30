// Author name: Sourav Dey
// Date of creation: 01-OCT-2018
// Lab evaluation: 3
// Program name: Sort c style string


// custom for strcpy(const char* dst, const char* src)
int cpystr(char dst[], const char src[])
{
    int i;
    for(i=0; src[i] != 0; i++)
        dst[i] = src[i];
    dst[i] = 0; // Set EOS
    return i; // # chars copied -- str len
}

// custom for strcmp(const char* a, const char* b)
int cmpstr(const char a[], const char b[]) 
{
    int i;
    for(i=0; a[i]!=0 && b[i]!=0; i++)
        if(a[i] != b[i])
            return a[i] - b[i];
    
    // check for equal str len, check if next char is not 0
    if(a[i] != 0)
        return 1; // a > b
    else if(b[i] != 0)
        return -1; // a < b
    else 
        return 0; // a == b
}