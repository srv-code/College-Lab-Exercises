#define REQ_MTYPE  1
#define RESP_MTYPE 2

struct req_buf {
	long mtype;
	char words[50][50];
	int len;
};

struct resp_buf {
	long mtype;
	int ccons[50], cvowels[50], csp[50];
};


