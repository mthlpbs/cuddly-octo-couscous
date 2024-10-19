class a {

	public static void main(String... args) {
	  for (int x=0, cnt= 5; x<5; x++, cnt --) {
		for (int y=0; y<cnt; y++) System.out.print(" ");
		for (int y=0; y<x+1; y++) System.out.print("*");
		System.out.println();
	}
  }
}
