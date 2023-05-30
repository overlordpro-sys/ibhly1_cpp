import java.util.Scanner;

public class EraseObjectDriver {
	public static void main (String[] args)
	{
		EraseObject eraser = new EraseObject();
		eraser.output();
		boolean run = true;
		Scanner in = new Scanner(System.in);
		while (run)
		{
			int rowNum=-1;
			int colNum=-1;
			while (rowNum==-1)
			{
				try
				{
					System.out.print("Enter row number 1-20: ");
					String row = in.nextLine();
					int temp = Integer.parseInt(row);
					if (temp<1 || temp > 20)
					{
						System.out.println("Please enter a valid number");
					}
					else
					{
						rowNum=temp;
					}
				}
				catch(Exception e)
				{
					System.out.println("Invalid Input. Please try again");
				}
			}
			while (colNum==-1)
			{
				try
				{
					System.out.print("Enter column number 1-20: ");
					String row = in.nextLine();
					int temp = Integer.parseInt(row);
					if (temp<1 || temp > 20)
					{
						System.out.println("Please enter a valid number");
					}
					else
					{
						colNum=temp;
					}
				}
				catch(Exception e)
				{
					System.out.println("Invalid Input. Please try again");
				}
			}
			eraser.erase(rowNum, colNum);
			eraser.output();
			boolean done = false;
			while (!done)
			{
				System.out.print("Do you want to continue erasing (y/n)? : ");
				String line = in.nextLine();
				if (line.equals("y"))
				{
					done=true;
				}
				else if (line.equals("n"))
				{
					run=false;
					done=true;
				}
				else
				{
					System.out.println("Invalid input. Please type 'y' or 'n'");
				}
			}
			
		}
		in.close();
	}
}
