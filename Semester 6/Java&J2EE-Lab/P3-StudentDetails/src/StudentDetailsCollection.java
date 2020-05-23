public class StudentDetailsCollection {
	String name, usn, address;
	int age;
	float s1, s2, s3, s4, s5, s6, s7, s8, cgpa;
	public StudentDetailsCollection(String name, String usn, int age, String address, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8, float cgpa) {
		this.name = name;
		this.usn = usn;
		this.age = age;
		this.address = address;
		this.s1 = s1;
		this.s2 = s2;
		this.s3 = s3;
		this.s4 = s4;
		this.s5 = s5;
		this.s6 = s6;
		this.s7 = s7;
		this.s8 = s8;
		this.cgpa = cgpa;
	}
	
	public String toString() {
		return "Name: "+name+" USN: "+usn+" Age: "+age+" Address: "+address+"\nSGPA Sem1: "+s1+" Sem2: "+s2+" Sem3: "+s3+" Sem4: "+s4+" Sem5: "+s5+" Sem6: "+s6+" Sem7: "+s7+" Sem8: "+s8+"\nCGPA: "+cgpa+"\n\n";
	}
}
