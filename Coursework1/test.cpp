#include <iostream>
#include "Vector3DHeap.h"
#include "Vector3DStack.h"

void stackVectorTest();
void heapVectorTest();

int main(void){

	std::cout << "Coordinates shown in formate {x,y,z}\n\n";

	stackVectorTest();

	heapVectorTest();

	_CrtDumpMemoryLeaks();
	int x;
	std::cin >> x;
	return 0;
}

void stackVectorTest(){
	std::cout << "***** Stack *****\n\n";

	Vector3DStack stackVector1 = Vector3DStack(1.1f,2.2f,3.3f);
	std::cout << "Stack vector 1 coordinates " << stackVector1 << "\n";

	Vector3DStack defaultConstructorVector = Vector3DStack();
	std::cout << "Stack vector 2 uses the defaults from the constructor " << defaultConstructorVector << "\n";

	stackVector1.setCoordinateX(10.0f);
	stackVector1.setCoordinateY(10.0f);
	stackVector1.setCoordinateZ(10.0f);

	std::cout << "Test set coordinate methods by setting each coordinate to 10 " << stackVector1 << "\n";

	std::cout << "\nMagintude\n";
	std::cout << "Magintude of stack vector 1 = " << stackVector1.getMagnitude() << "\n";
	
	std::cout << "\nUnit Vector\n";
	Vector3DStack stackVector2 = stackVector1.unitVector();
	std::cout << "Unit Vector of stack vector " << stackVector1 << " is " << stackVector2 << "\n";

	std::cout << "\nOrthogonal Unit Vector\n";
	Vector3DStack stackVector3 = Vector3DStack(10.0f, 5.0f, 2.0f);
	Vector3DStack stackVector4 = Vector3DStack(1.0f, 1.0f, 1.0f);
	Vector3DStack stackVector5 = stackVector3 % stackVector4;
	std::cout << "Stack Vector 3 % Stack Vector 4 = Stack Vector 5\n" << stackVector3 << " % " << stackVector4 << " = " << stackVector5 << "\n";
	std::cout << "Orthogonal Unit Vector of Stack Vector 3 and Stack Vector 4\n" << stackVector3.orthogonalUnitVector(stackVector4) << "\n";
	std::cout << "This should be equivilant to the unit vector of Stack Vector 5\n" << stackVector5.unitVector() << "\n";
	
	std::cout << "\nOperators\n";
	std::cout << "\n+ and - Vectors\n";
	Vector3DStack stackVector6 = Vector3DStack(2.0f, 3.0f, 4.0f);
	Vector3DStack stackVector7 = stackVector1 + stackVector6;
	Vector3DStack stackVector8 = stackVector1 - stackVector6;

	std::cout << "Stack Vector 2 vector coordinates " << stackVector6 << "\n";
	std::cout << "Stack Vector 1 + Stack Vector 2 = " << stackVector1 << " + " << stackVector6 << " = " << stackVector7 << "\n";
	std::cout << "Stack Vector 1 - Stack Vector 2 = " << stackVector1 << " - " << stackVector6 << " = " << stackVector8 << "\n";

	std::cout << "\n* and / by Scalar\n";
	Vector3DStack stackVector9 = stackVector1 * 10.0f;
	Vector3DStack stackVector10 = stackVector1 / 10.0f;

	std::cout << "Stack Vector 1 * 10.0f = " << stackVector1 << " * 10.0f = " << stackVector9 << "\n";
	std::cout << "Stack Vector 1 / 10.0f = " << stackVector1 << " / 10.0f = " << stackVector10 << "\n";

	std::cout << "\nVector and Scalar Product\n";
	Vector3DStack stackVector11 = Vector3DStack(5.0f, 10.0f, 15.0f);
	
	std::cout << "Scalar Product of Stack Vector 1 and Stack Vector 11\n" << 
		stackVector1 << " * " << stackVector2 << " = " << stackVector1 * stackVector11 << "\n";

	std::cout << "Vector Product of Stack Vector 1 and Stack Vector 11\n" <<
		stackVector1 << " % " << stackVector11 << " = " << stackVector1 % stackVector11 << "\n";

	std::cout << "\nUpdate Operators\n";
	std::cout << "\n+=\n";
	Vector3DStack stackVector12 = Vector3DStack(10.0f, 10.0f, 10.0f);
	std::cout << "Stack Vector 12 += Stack Vector 1 " << stackVector12 << " += " << stackVector1 << "\n";
	stackVector12 += stackVector1;
	std::cout << "Result = " << stackVector12 << "\n";

	std::cout << "\n-=\n";
	Vector3DStack stackVector13 = Vector3DStack(25.0f, 20.0f, 10.0f);
	std::cout << "Stack Vector 13 -= Stack Vector 1 " << stackVector13 << " -= " << stackVector1 << "\n";
	stackVector13 -= stackVector1;
	std::cout << "Result = " << stackVector13 << "\n";

	std::cout << "\n/=\n";
	Vector3DStack stackVector14 = Vector3DStack(25.0f, 20.0f, 10.0f);
	std::cout << "Stack Vector 14 /= 5.0f = " << stackVector14 << " /= 5.0f" << "\n";
	stackVector14 /= 5.0f;
	std::cout << "Result = " << stackVector14 << "\n";

	std::cout << "\n%=\n";
	Vector3DStack stackVector15 = Vector3DStack(25.0f, 20.0f, 10.0f);
	std::cout << "Stack Vector 15 %= Stack Vector 1 " << stackVector13 << " %= " << stackVector1 << "\n";
	stackVector15 %= stackVector1;
	std::cout << "Result = " << stackVector15 << "\n";

	std::cout << "\nBoolean Operators\n";
	Vector3DStack stackVector16 = Vector3DStack(10.0f, 10.0f, 10.0f);
	std::cout << "Stack Vector 16 == Stack Vector 1 = " << stackVector16 << " == " << stackVector1 <<
		" = " << (stackVector16 == stackVector1) << "\n";
	std::cout << "Stack Vector 16 != Stack Vector 1 = " << stackVector16 << " != " << stackVector1 <<
		" = " << (stackVector16 != stackVector1) << "\n";
	std::cout << "Stack Vector 16 == Stack Vector 3 = " << stackVector16 << " == " << stackVector3 <<
		" = " << (stackVector16 == stackVector3) << "\n";
	std::cout << "Stack Vector 16 != Stack Vector 3 = " << stackVector16 << " != " << stackVector3 <<
		" = " << (stackVector16 != stackVector3) << "\n";

	std::cout << "\nAssignment Operator\n";
	Vector3DStack stackVector17 = stackVector1;
	std::cout << "Stack Vector 17 has been assigned to Stack Vector 1\n" <<
		"Stack Vector 17 = " << stackVector17 << ", Stack Vector 1 = " << stackVector1 << "\n";

	Vector3DStack assignment = Vector3DStack(20.0f, 20.0f, 20.0f);
	Vector3DStack assignment2;
	Vector3DStack assignment3;

	assignment2 = assignment3 = assignment;

	std::cout << "assignment2 = assignment3 = assigment: " << assignment2 << ", " << assignment3 << ", " << assignment << "\n";


	std::cout << "\nReverse Overload Operator\n";
	std::cout << "10 * " << stackVector17 << "\n";
	std::cout << 10 * stackVector17 << "\n";
}




void heapVectorTest(){
	std::cout << "\n\n***** Heap *****\n\n";

	Vector3DHeap heapVector1 = Vector3DHeap(1.2f, 2.2f, 3.3f);
	std::cout << "Heap vector 1 coordinates " << heapVector1 << "\n";

	Vector3DHeap defaultConstructorVector = Vector3DHeap();
	std::cout << "Heap 2 uses the defaults from the constructor " << defaultConstructorVector << "\n";

	heapVector1.setCoordinateX(10);
	heapVector1.setCoordinateY(10);
	heapVector1.setCoordinateZ(10);

	std::cout << "Test set coordinate methods by setting each coordinate to 10 " << heapVector1 << "\n";

	std::cout << "\nMagintude\n";
	std::cout << "Magintude of heap vector 1 = " << heapVector1.getMagnitude() << "\n";

	std::cout << "\nUnit Vector\n";
	Vector3DHeap heapVector2 = heapVector1.unitVector();
	std::cout << "Unit Vector of heap vector " << heapVector1 << " is " << heapVector2 << "\n";

	std::cout << "\nOrthogonal Unit Vector\n";
	Vector3DHeap heapVector3 = Vector3DHeap(10.0f, 5.0f, 2.0f);
	Vector3DHeap heapVector4 = Vector3DHeap(1.0f, 1.0f, 1.0f);
	Vector3DHeap heapVector5 = heapVector3 % heapVector4;
	std::cout << "Heap Vector 3 % Heap Vector 4 = Heap Vector 5\n" << heapVector3 << " % " << heapVector4 << " = " << heapVector5 << "\n";
	std::cout << "Orthogonal Unit Vector of Heap Vector 3 and Heap Vector 4\n" << heapVector3.orthogonalUnitVector(heapVector4) << "\n";
	std::cout << "This should be equivilant to the unit vector of Heap Vector 5\n" << heapVector5.unitVector() << "\n";

	std::cout << "\nOperators\n";
	std::cout << "\n+ and - Vectors\n";
	Vector3DHeap heapVector6 = Vector3DHeap(2.0f, 3.0f, 4.0f);
	Vector3DHeap heapVector7 = heapVector1 + heapVector6;
	Vector3DHeap heapVector8 = heapVector1 - heapVector6;

	std::cout << "Heap Vector 2 vector coordinates " << heapVector6 << "\n";
	std::cout << "Heap Vector 1 + Heap Vector 2 = " << heapVector1 << " + " << heapVector6 << " = " << heapVector7 << "\n";
	std::cout << "Heap Vector 1 - Heap Vector 2 = " << heapVector1 << " - " << heapVector6 << " = " << heapVector8 << "\n";

	std::cout << "\n* and / by Scalar\n";
	Vector3DHeap heapVector9 = heapVector1 * 10.0f;
	Vector3DHeap heapVector10 = heapVector1 / 10.0f;

	std::cout << "Heap Vector 1 * 10.0f = " << heapVector1 << " * 10.0f = " << heapVector9 << "\n";
	std::cout << "Heap Vector 1 / 10.0f = " << heapVector1 << " / 10.0f = " << heapVector10 << "\n";

	std::cout << "\nVector and Scalar Product\n";
	Vector3DHeap heapVector11 = Vector3DHeap(5.0f, 10.0f, 15.0f);

	std::cout << "Scalar Product of Heap Vector 1 and Heap Vector 11\n" <<
		heapVector1 << " * " << heapVector2 << " = " << heapVector1 * heapVector11 << "\n";
	
	Vector3DHeap vectorProd = heapVector1 % heapVector11;
	std::cout << "Vector Product of Heap Vector 1 and Heap Vector 11\n" <<
		heapVector1 << " % " << heapVector11 << " = " << vectorProd << "\n";

	std::cout << "\nUpdate Operators\n";
	std::cout << "\n+=\n";
	Vector3DHeap heapVector12 = Vector3DHeap(10.0f, 10.0f, 10.0f);
	std::cout << "Heap Vector 12 += Heap Vector 1 " << heapVector12 << " += " << heapVector1 << "\n";
	heapVector12 += heapVector1;
	std::cout << "Result = " << heapVector12 << "\n";

	std::cout << "\n-=\n";
	Vector3DHeap heapVector13 = Vector3DHeap(25.0f, 20.0f, 10.0f);
	std::cout << "Heap Vector 13 -= Heap Vector 1 " << heapVector13 << " -= " << heapVector1 << "\n";
	heapVector13 -= heapVector1;
	std::cout << "Result = " << heapVector13 << "\n";

	std::cout << "\n/=\n";
	Vector3DHeap heapVector14 = Vector3DHeap(25.0f, 20.0f, 10.0f);
	std::cout << "Heap Vector 14 /= 5.0f = " << heapVector14 << " /= 5.0f" << "\n";
	heapVector14 /= 5.0f;
	std::cout << "Result = " << heapVector14 << "\n";

	std::cout << "\n%=\n";
	Vector3DHeap heapVector15 = Vector3DHeap(25.0f, 20.0f, 10.0f);
	std::cout << "Heap Vector 15 %= Heap Vector 1 " << heapVector13 << " %= " << heapVector1 << "\n";
	heapVector15 %= heapVector1;
	std::cout << "Result = " << heapVector15 << "\n";

	std::cout << "\nBoolean Operators\n";
	Vector3DHeap heapVector16 = Vector3DHeap(10.0f, 10.0f, 10.0f);
	std::cout << "Heap Vector 16 == Heap Vector 1 = " << heapVector16 << " == " << heapVector1 <<
		" = " << (heapVector16 == heapVector1) << "\n";
	std::cout << "Heap Vector 16 != Heap Vector 1 = " << heapVector16 << " != " << heapVector1 <<
		" = " << (heapVector16 != heapVector1) << "\n";
	std::cout << "Heap Vector 16 == Heap Vector 3 = " << heapVector16 << " == " << heapVector3 <<
		" = " << (heapVector16 == heapVector3) << "\n";
	std::cout << "Heap Vector 16 != Heap Vector 3 = " << heapVector16 << " != " << heapVector3 <<
		" = " << (heapVector16 != heapVector3) << "\n";

	std::cout << "\nAssignment Operator\n";
	Vector3DHeap heapVector17 = heapVector1;
	std::cout << "Heap Vector 17 has been assigned to Heap Vector 1\n" <<
		"Heap Vector 17 = " << heapVector17 << ", Heap Vector 1 = " << heapVector1 << "\n";
	heapVector17 = heapVector4;
	std::cout << "Heap Vector 17 has been reassigned to Heap Vector 4\n" <<
		"This should delete the original heap memory allocation and create a new one\n" <<
		heapVector17 << "\n";

	Vector3DHeap assignment = Vector3DHeap(20.0f, 20.0f, 20.0f);
	Vector3DHeap assignment2;
	Vector3DHeap assignment3;

	assignment2 = assignment3 = assignment;

	std::cout << "assignment2 = assignment3 = assigment: " << assignment2 << ", " << assignment3 << ", " << assignment << "\n";

	std::cout << "\nReverse Overload Operator\n";
	std::cout << "10.0f * " << heapVector17 << "\n";
	std::cout << 10.0f * heapVector17;
}