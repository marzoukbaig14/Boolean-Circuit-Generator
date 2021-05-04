/*
 * File: main.c
 * Creator: George Ferguson
 * Created: Mon Nov 28 14:11:17 2016
 * Time-stamp: <Tue Jul 17 16:02:29 EDT 2018 ferguson>
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Circuit.h"

/**
 * Two AND gates connected to make a 3-input AND circuit.
 */
// static Circuit* and3_Circuit() {
// 	Boolean* x = new_Boolean(false);
// 	Boolean* y = new_Boolean(false);
// 	Boolean* z = new_Boolean(false);
// 	Boolean** inputs = new_Boolean_array(3);
// 	inputs[0] = x;
// 	inputs[1] = y;
// 	inputs[2] = z;

// 	Boolean* out = new_Boolean(false);
// 	Boolean** outputs = new_Boolean_array(1);
// 	outputs[0] = out;

// 	Gate* A1 = new_AndGate();
// 	Gate* A2 = new_AndGate();
// 	Gate** gates = new_Gate_array(2);
// 	gates[0] = A1;
// 	gates[1] = A2;

// 	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 2, gates);
// 	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
// 	Circuit_connect(circuit, y, Gate_getInput(A1, 1));
// 	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A2, 0));
// 	Circuit_connect(circuit, z, Gate_getInput(A2, 1));
// 	Circuit_connect(circuit, Gate_getOutput(A2), out);
// 	return circuit;
// }

// (a)
static Circuit* parity_Circuit() {
	Boolean* x = new_Boolean(false);
	Boolean* y = new_Boolean(false);
	Boolean** inputs = new_Boolean_array(2);
	inputs[0] = x;
	inputs[1] = y;

	Boolean* out = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate* A1 = new_NandGate();
	Gate* A2 = new_OrGate();
	Gate* A3 = new_AndGate();
	Gate** gates = new_Gate_array(3);
	gates[0] = A1;
	gates[1] = A2;
	gates[2] = A3;

	Circuit *circuit = new_Circuit(2, inputs, 1, outputs, 3, gates);
	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
	Circuit_connect(circuit, y, Gate_getInput(A1, 1));
	Circuit_connect(circuit, x, Gate_getInput(A2, 0));
	Circuit_connect(circuit, y, Gate_getInput(A2, 1));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A3, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(A3, 1));
	Circuit_connect(circuit, Gate_getOutput(A3), out);
	return circuit;
}

// (b)
static Circuit* And_Nand_Or() {
	Boolean* x = new_Boolean(false);
	Boolean* y = new_Boolean(false);
	Boolean* z = new_Boolean(false);
	Boolean** inputs = new_Boolean_array(3);
	inputs[0] = x;
	inputs[1] = y;
	inputs[2] = z;

	Boolean* out = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate* A1 = new_AndGate();
	Gate* A2 = new_NandGate();
	Gate* A3 = new_OrGate();
	Gate** gates = new_Gate_array(2);
	gates[0] = A1;
	gates[1] = A2;
	gates[2] = A3;

	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 3, gates);
	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
	Circuit_connect(circuit, y, Gate_getInput(A1, 1));
	Circuit_connect(circuit, y, Gate_getInput(A2, 0));
	Circuit_connect(circuit, z, Gate_getInput(A2, 1));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A3, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(A3, 1));
	Circuit_connect(circuit, Gate_getOutput(A3), out);
	return circuit;
}

// (c)
static Circuit* threeNot_threeAnd_twoOr() {
	Boolean* x = new_Boolean(false);
	Boolean* y = new_Boolean(false);
	Boolean* z = new_Boolean(false);
	Boolean** inputs = new_Boolean_array(3);
	inputs[0] = x;
	inputs[1] = y;
	inputs[2] = z;

	Boolean* out = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate* N1 = new_Inverter();
	Gate* N2 = new_Inverter();
	Gate* N3 = new_Inverter();
	Gate* A1 = new_AndGate();
	Gate* A2 = new_AndGate();
	Gate* A3 = new_AndGate();
	Gate* O1 = new_OrGate();
	Gate* O2 = new_OrGate();
	Gate** gates = new_Gate_array(8);
	gates[0] = N1;
	gates[1] = N2;
	gates[2] = N3;
	gates[3] = A1;
	gates[4] = A2;
	gates[5] = A3;
	gates[6] = O1;
	gates[7] = O2;

	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 8, gates);
	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
	Circuit_connect(circuit, x, Gate_getInput(N3, 0));
	Circuit_connect(circuit, y, Gate_getInput(A2, 0));
	Circuit_connect(circuit, y, Gate_getInput(N1, 0));
	Circuit_connect(circuit, z, Gate_getInput(A3, 0));
	Circuit_connect(circuit, z, Gate_getInput(N2, 0));
	Circuit_connect(circuit, Gate_getOutput(N1), Gate_getInput(A1, 1));
	Circuit_connect(circuit, Gate_getOutput(N2), Gate_getInput(A2, 1));
	Circuit_connect(circuit, Gate_getOutput(N3), Gate_getInput(A3, 1));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(O1, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(O1, 1));
	Circuit_connect(circuit, Gate_getOutput(O1), Gate_getInput(O2, 0));
	Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(O2, 1));
	Circuit_connect(circuit, Gate_getOutput(O2), out);
	return circuit;
	

}

// Extra Credit one-bitadder Circuit
static Circuit* one_Bit_Adder() {
	Boolean* x = new_Boolean(false);
	Boolean* y = new_Boolean(false);
	Boolean* c = new_Boolean(false);
	Boolean** inputs = new_Boolean_array(3);
	inputs[0] = x;
	inputs[1] = y;
	inputs[2] = c;

	Boolean* z = new_Boolean(false);
	Boolean* d = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(2);
	outputs[0] = z;
	outputs[1] = d;

	Gate* N1 = new_Inverter();
	Gate* N2 = new_Inverter();
	Gate* N3 = new_Inverter();
	Gate* A1 = new_And3Gate();
	Gate* A2 = new_And3Gate();
	Gate* A3 = new_And3Gate();
	Gate* A4 = new_And3Gate();
	Gate* A5 = new_And3Gate();
	Gate* A6 = new_And3Gate();
	Gate* A7 = new_And3Gate();
	Gate* O1 = new_Or4Gate();
	Gate* O2 = new_Or4Gate();
	Gate** gates = new_Gate_array(12);
	gates[0] = N1;
	gates[1] = N2;
	gates[2] = N3;
	gates[3] = A1;
	gates[4] = A2;
	gates[5] = A3;
	gates[6] = A4;
	gates[7] = A5;
	gates[8] = A6;
	gates[9] = A7;
	gates[10] = O1;
	gates[11] = O2;

	Circuit* circuit = new_Circuit(3, inputs, 2, outputs, 12, gates);
	Circuit_connect(circuit, x, Gate_getInput(N1, 0));
	Circuit_connect(circuit, y, Gate_getInput(N2, 0));
	Circuit_connect(circuit, c, Gate_getInput(N3, 0));
	Circuit_connect(circuit, x, Gate_getInput(A4, 0));
	Circuit_connect(circuit, x, Gate_getInput(A5, 0));
	Circuit_connect(circuit, x, Gate_getInput(A6, 0));
	Circuit_connect(circuit, x, Gate_getInput(A7, 0));
	Circuit_connect(circuit, y, Gate_getInput(A2, 0));
	Circuit_connect(circuit, y, Gate_getInput(A3, 0));
	Circuit_connect(circuit, y, Gate_getInput(A6, 1));
	Circuit_connect(circuit, y, Gate_getInput(A7, 1));
	Circuit_connect(circuit, c, Gate_getInput(A7, 2));
	Circuit_connect(circuit, c, Gate_getInput(A5, 1));
	Circuit_connect(circuit, c, Gate_getInput(A3, 1));
	Circuit_connect(circuit, c, Gate_getInput(A1, 0));

	Circuit_connect(circuit, Gate_getOutput(N1), Gate_getInput(A1, 1));
	Circuit_connect(circuit, Gate_getOutput(N1), Gate_getInput(A2, 1));
	Circuit_connect(circuit, Gate_getOutput(N1), Gate_getInput(A3, 2));
	Circuit_connect(circuit, Gate_getOutput(N2), Gate_getInput(A1, 2));
	Circuit_connect(circuit, Gate_getOutput(N2), Gate_getInput(A4, 1));
	Circuit_connect(circuit, Gate_getOutput(N2), Gate_getInput(A5, 2));
	Circuit_connect(circuit, Gate_getOutput(N3), Gate_getInput(A6, 2));
	Circuit_connect(circuit, Gate_getOutput(N3), Gate_getInput(A4, 2));
	Circuit_connect(circuit, Gate_getOutput(N3), Gate_getInput(A2, 2));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(O1, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(O1, 1));
	Circuit_connect(circuit, Gate_getOutput(A4), Gate_getInput(O1, 2));
	Circuit_connect(circuit, Gate_getOutput(A7), Gate_getInput(O1, 3));
	Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(O2, 0));
	Circuit_connect(circuit, Gate_getOutput(A5), Gate_getInput(O2, 1));
	Circuit_connect(circuit, Gate_getOutput(A6), Gate_getInput(O2, 2));
	Circuit_connect(circuit, Gate_getOutput(A7), Gate_getInput(O2, 3));
	Circuit_connect(circuit, Gate_getOutput(O1), z);
	Circuit_connect(circuit, Gate_getOutput(O2), d);
	return circuit;
	
}

// int to boolean
static Boolean* i2b(int i) {
	if (i == 0) {return false;}
	else {return true;}
}

static int exponent(int x, int y) {
	for (int j = 1; j < y; j++) {
		x*x;
	}
	return x;
}

// To find 3 bit combinations
Boolean** three_Bit_Combinations_helper(int i) {
		Boolean** combination_Array = new_Boolean_array(8);
		int a = i/4%2;
		int b = i/2%2;
		int c = i%2;
		combination_Array[0] = i2b(a);
		combination_Array[1] = i2b(b); 
		combination_Array[2] = i2b(c);

		return combination_Array;
	
}

// To find 2 bit combinations
Boolean** two_Bit_Combinations_helper(int i) {
		Boolean** combination_Array = new_Boolean_array(4);
		int a = i/2%2;
		int b = i%2;
		combination_Array[0] = i2b(a);
		combination_Array[1] = i2b(b);

		return combination_Array;
	
}

static void test(Circuit* circuit1, int num_inputs, int num_Outputs) {
	if (num_inputs == 3 && num_Outputs == 1) {


		int x = exponent(2, num_inputs);
		for (int i = 0; i <  8; ++i) {
			Boolean** input = three_Bit_Combinations_helper(i);
			test3In1Out(circuit1, input[0], input[1], input[2]);
		}
	}
	if (num_inputs == 3 && num_Outputs == 2) {


		int x = exponent(2, num_inputs);
		for (int i = 0; i <  8; ++i) {
			Boolean** input = three_Bit_Combinations_helper(i);
			test3In2Out(circuit1, input[0], input[1], input[2]);
		}
	}

	if (num_inputs == 2 && num_Outputs == 1) {
		int x = exponent(2, num_inputs);
		for (int i = 0; i <  4; ++i) {
		Boolean** input = two_Bit_Combinations_helper(i);
		test2In1Out(circuit1, input[0], input[1]);
		}
	}
}


static char* b2s(bool b) {
	return b ? "T" : "F";
}

// static int* b2i(bool b) {
// 	return b ? 1 : 0;
// }

void test3In1Out(Circuit* circuit, bool in0, bool in1, bool in2) {
	Circuit_setInput(circuit, 0, in0);
	Circuit_setInput(circuit, 1, in1);
	Circuit_setInput(circuit, 2, in2);
	Circuit_update(circuit);
	bool out0 = Circuit_getOutput(circuit, 0);
	printf("%s %s %s -> %s\n", b2s(in0), b2s(in1), b2s(in2), b2s(out0));
}

void test3In2Out(Circuit* circuit, bool in0, bool in1, bool in2) {
	Circuit_setInput(circuit, 0, in0);
	Circuit_setInput(circuit, 1, in1);
	Circuit_setInput(circuit, 2, in2);
	Circuit_update(circuit);
	bool z = Circuit_getOutput(circuit, 0);
	bool d = Circuit_getOutput(circuit, 1);
	printf("%s %s %s -> %s%s\n", b2s(in0), b2s(in1), b2s(in2), b2s(z), b2s(d));
}


// To test circuits with 2 inputs. 
	void test2In1Out(Circuit* circuit, bool in0, bool in1) {
	Circuit_setInput(circuit, 0, in0);
	Circuit_setInput(circuit, 1, in1);
	Circuit_update(circuit);
	bool out0 = Circuit_getOutput(circuit, 0);
	printf("%s %s -> %s\n", b2s(in0), b2s(in1), b2s(out0));
}





int main(int argc, char **argv) {

	// Testing parity_Circuit();
	Circuit* circuit1 = parity_Circuit();
	printf("\nTesting of part (a): Parity circuit :\n\n");
	Circuit_dump(circuit1);
	printf("\n");
	test(circuit1, 2, 1);
	Circuit_free(circuit1);


	printf("\n\n---------------\n\n");

	// Testing And_Nand_Or();
	Circuit* circuit2 = And_Nand_Or();
	printf("\nTesting of part (b): And Nand Or Circuit :\n\n");
	Circuit_dump(circuit2);
	printf("\n");
	test(circuit2, 3, 1);
	Circuit_free(circuit2);
	

	printf("\n\n---------------\n\n");

	// Testing threeNot_threeAnd_twoOr();
	Circuit* circuit3 = threeNot_threeAnd_twoOr();
	printf("\nTesting of part (c): 3 Not 3 And 2 Or circuit :\n");
	Circuit_dump(circuit3);
	printf("\n");
	test(circuit3, 3, 1);
	Circuit_free(circuit3);
	

	printf("\n\n---------------\n\n");

	// Testing One bit Adder 
	printf("Testing extra credit: One bit adder\n");
	Circuit* Circuit5 = one_Bit_Adder();
	Circuit_dump(Circuit5);
	printf("\n");
	test(Circuit5, 3, 2);
	Circuit_free(Circuit5);
	

}
