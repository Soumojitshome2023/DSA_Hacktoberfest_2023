import java.util.Scanner;
import java.util.LinkedList;

public class Employee {
	public static void main(String[] args) {
		LinkedList <String> emplist = new LinkedList<>();	
		Scanner input = new Scanner(System.in);
		Scanner inp = new Scanner(System.in);
		
		//Pre-populated linked-list
		emplist.add("Carlos");
		emplist.add("Nikaru");
		emplist.add("Dmitri");
		emplist.add("Juan");
		emplist.add("Juana");
		emplist.add("Liwayway");
		emplist.add("Dorla");
		emplist.add("Xiao Yang");
		emplist.add("Hakamura");
		emplist.add("Nene");
		
		//declare a container for the condition of the while loop
		//this will allow you to break the loop even if its inside the switch statement
		boolean loop = true;
		while (loop) {
			
				System.out.println("---Employee Management Menu---");
				System.out.print("1. Insert\n"+
							"2. Delete\n"+
							"3. Display\n"+
							"4. Search\n"+
							"5. Exit\n");
				System.out.print("Enter your choice: ");
				String choice = input.nextLine();	

				String a_name, s_name;
				switch (choice) {
					case "1":
						System.out.print("Enter employee name: ");	
						a_name = inp.nextLine();
						emplist.addLast(a_name);
						break;
					case "2":
						System.out.print("Deleted: "+emplist.get(0)+"\n\n");	
						emplist.removeFirst();
						break;

					case "3":
						System.out.print("List of Employees:\n "+emplist+"\n");	
						System.out.println();
						break;

					case "4":
						System.out.print("Enter employee name to search: ");
						s_name = inp.nextLine();
						int dex = emplist.indexOf(s_name);
						if (emplist.contains(s_name)) {
							System.out.println("Employee "+s_name+"is in index "+dex+"\n");
						}	
						else
							System.out.println("Employee not found\n");
						break;

					case "5":
						loop = false;
						break;

					default:
						System.out.println("Invalid choice. Please try again");
						break;
					}

		}
	}
}
