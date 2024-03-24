//Bitset Reimplementation
//by DRCLComputers

short int puteri[8] = { 1, 2, 4, 8, 16, 32, 64, 128 }; //powers of 2

class new_bitset{
public:
	unsigned int nr_grupa=0; // the number of the byte in the array
	short int nr_byte=0; //the number of the bit in the byte
	unsigned char bitset[125000] = {}; //the array

	void input(int nr_adaugat) { //sets given bit to 1
		nr_grupa = nr_adaugat / 8;
		nr_byte = 7- nr_adaugat % 8;
		bitset[nr_grupa] = bitset[nr_grupa] | puteri[nr_byte]; 
	}

	void reset(int nr_adaugat) { //sets given bit to 0
		nr_grupa = nr_adaugat / 8;
		nr_byte = 7 - nr_adaugat % 8;
		bitset[nr_grupa] = bitset[nr_grupa] & (~puteri[nr_byte]);
	}

	bool check(int nr_adaugat) { //checks if given bit is true or false
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
		return 0;
	}

	void show(int start=1, int fin = 1000000) { //prints the index of the 1 bits (optional, you can pass the first and last bit you desire) 
		for (int i = start; i <= fin; i++) {
			if (check(i)) std::cout << i << " ";
		}
	}

	int count(int start = 1, int fin = 1000000) { //counts how many bits are set to true in the array (optional, you can pass the first and last bit you desire)
		int aux = 0;
		for (int i = start; i <= fin; i++) {
			if (check(i)) aux++;
		}
		return aux;
	}
};
