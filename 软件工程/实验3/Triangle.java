package cn.edu.zstu;

public class Triangle {
	//定义三角形的三边
	protected long lborderA =0;
	protected long lborderB = 0;
	protected long lborderC= 0;
	//构造函数
	public Triangle(long lborderA, long lborderB, long lborderC){
	this.lborderA = lborderA;
	this.lborderB= lborderB;
	this.lborderC= lborderC;
	}


/**
*判断是否是三角形
*是返回ture;不是返回false
**/
public static boolean isTriangle(Triangle triangle){
	boolean isTriangle = false;
	//判断边界，大于0小于或等于Long.MAX_VALUE，出界返回false
	if((triangle.lborderA > 0 && triangle.lborderA <=Long.MAX_VALUE / 2)
			&& (triangle.lborderB >0 && triangle.lborderB <=Long.MAX_VALUE/2)
			&& (triangle.lborderC >0 && triangle.lborderC <= Long.MAX_VALUE/ 2)){
		//判断两边之和大于第三边
		if ((triangle.lborderA <(triangle.lborderB + triangle.lborderC))
				&& (triangle.lborderB<(triangle.lborderA + triangle.lborderC))
				&& (triangle.lborderC <(triangle.lborderA + triangle.lborderB))) {
			isTriangle = true;
		}
	}
	return isTriangle;
}
/**
*判断三角形类型
*
*只有两条边相等的三角形返回字符串“等腰三角形”;
*三边均相等的三角形返回字符串“等边三角形”;
*三边均不等的三角形返回字符串“不等边三角形”;
**/

public static String getType(Triangle triangle){
	String strType="不是三角形";
	
	//判断是否是三角形
	if (isTriangle(triangle)){
		//判断是否是等边三角形
		if (triangle.lborderA == triangle.lborderB
				&& triangle.lborderB == triangle.lborderC){
			strType="等边三角形";
		}
		//判断是否是不等边三角形
		else if ((triangle.lborderA != triangle.lborderB)
				&& (triangle.lborderB !=triangle.lborderC)
				&& (triangle.lborderA != triangle.lborderC)){
			strType ="不等边三角形";
		}
		//三角形既非三边全部相等，又非全部不等，只能是部分相等即等腰三角形
		else {
			strType ="等腰三角形";
		}
	}
	return strType;

	}
}


