// Author name: Sourav Dey
// Date of creation: 01-OCT-2018
// Lab evaluation: 3
// Program name: Sort c style string

using namespace std;

class My_String_2 // modified (optimised) version
{
	public: 
		const static int MAX_LEN = 80;

	private:
        char data[MAX_LEN];
        int len;

    public:
        My_String_2(const char str[]) 
        {
			len = cpystr(data, str);
        }

        void show() { cout << data; }

		friend void operator!(My_String_2 &);
		friend ostream & operator<<(ostream &stream, My_String_2 &s) 
		{
			stream << s.data;
		}
};

void operator!(My_String_2 &s)
{
    for(int i=0, start=-1; i<=s.len; i++) {
        if(s.data[i] == ' ' || s.data[i] == 0) { // word captured
            if(start != -1) {  // check if valid start point
				if(i-start > 1) { // only sort if word len > 1
                    // sort: insertion sort
                    for(int a=start+1, b, key; a<i; a++) {
                        key = s.data[a];
                        for(b=a-1; b>=0; b--) {
                            if(s.data[b] > key) {
                                // shift right
                                s.data[b+1] = s.data[b];
                            } else break;
                        }
                        s.data[b+1] = key;
                    }
                }
				start = -1; // reset start point
            }
        } else {
			if(start == -1)
				start = i; // init to 1st non-space char
		}
    }
}