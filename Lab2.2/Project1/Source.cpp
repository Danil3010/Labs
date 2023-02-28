enum Citis { NY, LA, Boston };
struct Citi {
	Citis city;
	int amount;
};

int main() {
	Citi myCity[3];
	myCity[0] = { NY, 5000000 };
	myCity[1] = { Boston, 1000000 };
	myCity[2]= { LA, 50000 };

	int count = 0;
	for (int i = 0; i < 3; i++) {
		if (myCity[i].amount > 100000) {
			count++;
		}
	}
}