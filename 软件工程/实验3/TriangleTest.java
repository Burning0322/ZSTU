package cn.edu.zstu;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class TriangleTest extends Triangle{
	private Triangle t1;
	private Triangle t2;
	private Triangle t3;
	private Triangle t4;
	public TriangleTest(String n){
		super(n);
	}
	
	@Before
	public void setUp() throws Exception {
		super.setUp();
		t1 = new Triangle(1,3,6);
		t2 = new Triangle(3,3,3);
		t3 = new Triangle(4,4,2);
		t4 = new Triangle(3,4,5);
	}

	@After
	public void tearDown() throws Exception {
		super.tearDown();
		t1 = null;
		t2 = null;
		t3 = null;
		t4 = null;
	}

	@Test
	public void testGetType() {
		assertEquals(Triangle.getType(t1),"不是三角形");
		assertEquals(Triangle.getType(t2),"等边三角形");
		assertEquals(Triangle.getType(t3),"等腰三角形");
		assertEquals(Triangle.getType(t4),"不等边三角形");
	}
	public void testIsType() {
		assertFalse(Triangle.isTriangle(t1));
		assertTrue(Triangle.isTriangle(t2));
		assertTrue(Triangle.isTriangle(t3));
		assertTrue(Triangle.isTriangle(t4));
	}

}
————————————————
版权声明：本文为CSDN博主「蔚蓝星辰mic」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_45532870/article/details/111170540