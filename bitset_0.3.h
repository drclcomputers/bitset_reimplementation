
short int puteri[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };

class new_bitset{
public:
	unsigned int nr_grupa=0;
	short int nr_byte=0;
	unsigned char bitset[125000] = {};

	void input(int nr_adaugat) {
		nr_grupa = nr_adaugat / 8;
		nr_byte = 7- nr_adaugat % 8;
		bitset[nr_grupa] = bitset[nr_grupa] | puteri[nr_byte];
		//std::cout << "nr din grupa" << int(bitset[nr_grupa]) << '\n';
	}

	void reset(int nr_adaugat) {
		nr_grupa = nr_adaugat / 8;
		nr_byte = 7 - nr_adaugat % 8;
		bitset[nr_grupa] = bitset[nr_grupa] & (~puteri[nr_byte]);
	}

	bool check(int nr_adaugat) {
		nr_grupa = nr_adaugat / 8;
		nr_byte = 7-nr_adaugat % 8;
		int aux = bitset[nr_grupa];
		int x = 0;
		bool rest = aux % 2;
		
		while (aux != 0) {
			if (x == nr_byte) {
				if (rest) return 1;
				else return 0;
			}
			aux /= 2;
			rest = aux % 2;
			x++;
		}
		if (x == nr_byte) {
			if (rest) return 1;
			else return 0;
		}
	}

	void show(int start=1, int fin = 1000000) {
		for (int i = start; i <= fin; i++) {
			if (check(i)) std::cout << i << " ";
		}
	}

	int count(int start = 1, int fin = 1000000) {
		int aux = 0;
		for (int i = start; i <= fin; i++) {
			if (check(i)) aux++;
		}
		return aux;
	}
};
