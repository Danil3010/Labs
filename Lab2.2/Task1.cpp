enum Names{Bogdan, Oleg, Danil, Pavlo, Dmytro, Ivan, Mark};
struct Student {
	Names name;
	double average;
	int course;
};
int main(){
	Student myStudents[7];
	myStudents[0] = {Bogdan, 1, 2};
	myStudents[1] = {Oleg, 5, 2};
	myStudents[2] = {Danil,4.3, 1};
	myStudents[3] = {Pavlo,5, 2};
	myStudents[4] = {Dmytro,3.5, 5 };
	myStudents[5] = {Ivan,4, 2};
	myStudents[6] = {Mark,4.5, 2};

	int count = 0;
	int var = 0;
	for (int i = 0; i < 7; i++) {
		if (myStudents[i].course == 2){
			count++;
			if (myStudents[i].average == 5 || myStudents[i].average >= 4.5) {
				var++;
			}
		}
	}
	float procent = (float)var * 100 / count;
}
