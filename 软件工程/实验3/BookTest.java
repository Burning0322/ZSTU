package cn.edu.zstu;

import junit.framework.TestCase;

public class BookTest extends TestCase {

	private Book book1;
	private Book book2;
	
	public BookTest(String name) {
		super(name);
	}

	protected void setUp() throws Exception {
		super.setUp();
		book1=new Book("ES",13.89);
		book2=new Book("The Es4",11.39);
	}

	protected void tearDown() throws Exception {
		super.tearDown();
		book1=null;
		book2=null;
	}

	public void testEqualsObject() {
		//fail("Not yet implemented");
		assertFalse(book2.equals(book1));
		assertTrue(book1.equals(book1));
	}

}
