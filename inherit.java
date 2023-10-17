class Language{
	void speak(){
		System.out.println("I am the language of God");
	}
}
class Russian extends Language{
	void speak(){
		System.out.println("I speak Russian.");
	}
}
class Indian extends Language{
	void speak(){
		System.out.println("I speak Hindi.");
	}
}


class Exp12{
	public static void main(String args[]){
		Russian rus = new Russian();
		rus.speak();

		Indian ind = new Indian();
		ind.speak();
	}
}
