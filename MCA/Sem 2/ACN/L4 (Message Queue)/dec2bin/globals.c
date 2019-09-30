/* 12) Write a client server program to convert 
		an array of decimal numbers to their 
		binary equivalent forms.
		
	>> Globals
*/


#define MAX_SZ 20

struct query_buf {
	long mtype;
	int dec_arr[MAX_SZ];
	int len;
};

struct response_buf {
	long mtype;
	int bin_arr[MAX_SZ]; // boolean type
	int len;
};

const long QUERY_MTYPE = 11;
const long RESP_MTYPE = 10;
