// Author name: Sourav Dey
// Date of creation: 01-OCT-2018
// Lab evaluation: 3
// Program name: Sort c style string

#include <cstdio> // to import printf(...) for debug purpose


/* Drawback: 
		1. Won't take multiple spaces into consideration
		2. Output may come correct but splits will be incorrect if multiple spaces are provided
		3. Inefficient in terms of space complexity 
*/
class My_String_1 // previous version
{
	public: 
		const static int MAX_LEN = 80;
		static bool show_debug_info; // DEBUG

	private:
        char data[MAX_LEN];
        char splits[MAX_LEN][MAX_LEN];
        int len, splits_sz;

        void sort(int);

    public:
		My_String_1(const char *str)
        {
            int i, j, k; 
            bool eos=false;
            for(i=0, j=0, k=0; i<MAX_LEN && !eos; i++) {
                data[i] = *(str+i); // also copies EOS mark
                if(*(str+i) == ' ' || (eos=(*(str+i) == 0))) {
                    // switch to next splits array
                    j++;
                    k=0;
                } else
                    splits[j][k++] = *(str+i);
            }
            len = i;
            splits_sz = j;

            if(show_debug_info) 
                printf("  [Constructed My_String_1 object: data='%s', len=%d, splits_sz=%d] \n", data, len, splits_sz);
        }

        void show() { std::cout << data; }

        friend void operator!(My_String_1 &);
};

bool My_String_1::show_debug_info; // DEBUG

void My_String_1::sort(int idx)
{
    if(show_debug_info)
        printf("  [Inside My_String_1::sort(int idx): idx=%d, split[%d]: {%s -> ", idx, idx, splits[idx]);

    for(int a=1, b, key; splits[idx][a] != 0; a++) {
        key = splits[idx][a];
        for(b=a-1; b>=0; b--) {
            if(splits[idx][b] > key) {
                // shift right
                splits[idx][b+1] = splits[idx][b];
            } else break;
        }
        splits[idx][b+1] = key;
    }

    if(show_debug_info)
        printf("%s}] \n", splits[idx]);
}

void operator!(My_String_1 &s)
{
    for(int i=0, j=0; i<s.splits_sz; i++, j++) {
		s.sort(i);
		for(int k=0; s.splits[i][k] != 0; k++, j++)
			s.data[j] = s.splits[i][k];
		s.data[j] = (i == s.splits_sz-1) ? 0 : ' ';
	}
}