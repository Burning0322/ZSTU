package cn.edu.zstu;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class TriangleTest {

    private Triangle equilateralTriangle;
    private Triangle isoscelesTriangle;
    private Triangle normalTriangle;
    private Triangle invalidTriangle;

    @Before
    public void setUp() throws Exception {
        // 设置四个不同的三角形用于测试
        equilateralTriangle = new Triangle(5, 5, 5);       // 等边三角形
        isoscelesTriangle = new Triangle(5, 5, 8);        // 等腰三角形
        normalTriangle = new Triangle(3, 4, 5);           // 普通三角形
        invalidTriangle = new Triangle(1, 2, 3);          // 无效的三角形
    }

    @After
    public void tearDown() throws Exception {
    }

    @Test
    public void testEquilateralTriangle() {
        assertEquals(3, equilateralTriangle.what_triangle());
        // 断言：方法正确识别等边三角形
    }

    @Test
    public void testIsoscelesTriangle() {
        assertEquals(2, isoscelesTriangle.what_triangle());
        // 断言：方法正确识别等腰三角形
    }

    @Test
    public void testNormalTriangle() {
        assertEquals(1, normalTriangle.what_triangle());
        // 断言：方法正确识别普通三角形
    }

    @Test
    public void testInvalidTriangle() {
        assertEquals(0, invalidTriangle.what_triangle());
        // 断言：方法正确识别无效的三角形
    }
}
