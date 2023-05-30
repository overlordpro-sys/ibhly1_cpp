import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class EraseObject {
	private char[][] cells;
	private static final char WALL = '*';
	private static final char SPACE = '-';
	public EraseObject()
	{
		cells = new char[21][21];
		for (char[] row : cells)
		{
			Arrays.fill(row, '-');
		}
		loadFile("digital.txt");
		
	}
	
	public void erase (int row, int col)
	{
		startErase(cells, row, col);
	}
	
	private void startErase(char[][] cells, int r, int c)
	{
		if (r>0 && r<21 && c>0 && c<21)
		{
			if (cells[r][c] == WALL)
			{
				cells[r][c] = SPACE;
				
				startErase(cells, r+1, c);
				startErase(cells, r-1, c);
				startErase(cells, r, c+1);
				startErase(cells, r, c-1);
				
			}
		}
	}
	
	private void loadFile(String fileName)
	{
		try
        {
           Scanner read = new Scanner(new File(fileName)).useDelimiter("");
           int pairs = Integer.valueOf(read.nextLine());
           for (int i = 1; i <= pairs; i++)
           {
        	   String[] line = read.nextLine().split(" ");
        	   cells[Integer.valueOf(line[0])][Integer.valueOf(line[1])] = WALL;
        	   
           }
        }
        catch (IOException error)
        {
            System.out.println (error.getMessage());
        } 
	}
	
	public void output()
	{	
		System.out.print("   12345678901234567890");
		System.out.println();
		for (int r = 1; r<=20; r++)
		{
			System.out.printf("%3s", r+" ");
			for (int c = 1; c<=20; c++)
			{
				System.out.print(cells[r][c]);
			}
			System.out.println();
		}
	}
}
