enum Names { Bogdan, Oleg, Danil, Pavlo, Dmytro, Ivan, Mark };
struct Student {
	Names name;
	int course;
	bool army;
};
int main() {
	Student myStudents[7];
	myStudents[0] = { Bogdan, 5, true };
	myStudents[1] = { Oleg, 5, false };
	myStudents[2] = { Danil,1, false };
	myStudents[3] = { Pavlo,5, false };
	myStudents[4] = { Dmytro,5, true };
	myStudents[5] = { Ivan,5, true };
	myStudents[6] = { Mark,3, false };

	int count = 0;
	int var = 0;
	for (int i = 0; i < 7; i++) {
		if (myStudents[i].course == 5) {
			count++;
			if (myStudents[i].army == true) {
				var++;
			}
		}
	}
	float procent = (float)var * 100 / count;
}
