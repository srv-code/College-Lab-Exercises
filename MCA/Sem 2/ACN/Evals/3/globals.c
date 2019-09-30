struct query_buf {
	long mtype;
    double a, b, c;
};

struct response_buf {
	long mtype;
	double root1, root2;
};

const long QUERY_MTYPE = 11;
const long RESP_MTYPE  = 10;
