/* 11) Write a client server program using message 
		queue to check for string palindrome as per 
		the input given by the client.
		
	>> Globals
*/


#define MAX_SZ 20

struct query_buf {
	long mtype;
	char string[MAX_SZ];
	int slen;
};

struct response_buf {
	long mtype;
	int is_palindrome; // boolean type
};

const long QUERY_MTYPE = 11;
const long RESP_MTYPE = 10;
