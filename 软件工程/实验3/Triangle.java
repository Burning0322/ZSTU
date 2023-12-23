package cn.edu.zstu;

public class Triangle
{
	private int a;
	private int b;
	private int c;
	
	public Triangle(int a,int b,int c)
	{
		this.a=a;
		this.b=b;
		this.c=c;
	}
	
	public int what_triangle()
	{
		if(a+b<=c||a+c<=b||b+c<=a)
		{
			System.out.println(a+" "+b+" "+c+"不能构成三角形");
			return 0;
		}
		else
		{
			if(a==b&&b==c)
			{
				System.out.println(a+" "+b+" "+c+"构成等边三角形");
				return 3;
			}
			else if(a==b||a==c||b==c)
			{
				System.out.println(a+" "+b+" "+c+"构成等腰三角形");
				return 2;
			}
			else
			{
				System.out.println(a+" "+b+" "+c+"构成普通三角形");
				return 1;
			}
		}
	
}
}

			

