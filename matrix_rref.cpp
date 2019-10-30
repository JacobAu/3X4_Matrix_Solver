#include <iostream>

#ifndef MARMOSET_TESTING
int main();
#endif

void get_user_input(double row1[4],double row2[4], double row3[4]);
void print_matrix(double row1[4], double row2[4], double row3[4]);
void swapRows(double rowA[4],double rowB[4]);
void scaleRow(double rowA[4], double factor);
void add_to_row(double srcRow[4], double altRow[4], double factor); // altRow means altered row.
void rref(double row1[4], double row2[4], double row3[4]);
void correctPos(double row1[4], double row2[4], double row3[4]);

#ifndef MARMOSET_TESTING
int main(){
	double arr1[4]{};
	double arr2[4]{};
	double arr3[4]{};
	get_user_input(arr1,arr2,arr3);

	std::cout << "You have Entered: " << std::endl;
	print_matrix(arr1,arr2,arr3);

	std::cout << "The RREF form is: " << std::endl;
	rref(arr1,arr2,arr3);
	print_matrix(arr1,arr2,arr3);
}
#endif

void print_matrix(double row1[4], double row2[4], double row3[4]){
	for(std::size_t k = 0; k<4; ++k){
		std::cout << row1[k] << " ";
	}
	std::cout << '\n';

	for(std::size_t k = 0; k<4; ++k){
			std::cout << row2[k] << " ";
	}
	std::cout << '\n';

	for(std::size_t k = 0; k<4; ++k){
			std::cout << row3[k] << " ";
	}
	std::cout <<'\n';
	std::cout << '\n';
}


void get_user_input(double row1[4],double row2[4], double row3[4]){
	std::cout << "Row 1: ";
	std::cin >> row1[0] >> row1[1] >> row1[2] >> row1[3];
	std::cout << "Row 2: ";
	std::cin >> row2[0] >> row2[1] >> row2[2] >> row2[3];
	std::cout << "Row 3: ";
	std::cin >> row3[0] >> row3[1] >> row3[2] >> row3[3];
	std::cout << '\n';
}

void swapRows(double rowA[4],double rowB[4]){
	double hold[4]{};
	for (std::size_t k = 0; k < 4; ++k){
		hold[k] = rowA[k];
		rowA[k] = rowB[k];
		rowB[k] = hold[k];
	}
}

void scaleRow(double rowA[4], double factor){
	for(std::size_t k = 0; k < 4; ++k){
		rowA[k]*= factor;
	}
}

void add_to_row(double srcRow[4], double altRow[4], double factor){
	for(std::size_t k = 0; k < 4; ++k){
		altRow [k] -= srcRow[k]*factor;
	}
}

void rref(double row1[4], double row2[4], double row3[4]){
	//Get to right position.
	correctPos(row1,row2,row3);

	// Check if first column is empty.
	bool emptyFirstColumn{0};
	if((row1[0] == 0) && (row2[0] == 0) && (row3[0] == 0)){
		emptyFirstColumn = true;
	}

	// scale all down to a leading 1.
	if(emptyFirstColumn == true){
		scaleRow(row1,1.0/row1[1]);

		add_to_row(row1,row2,(row2[1]));
		add_to_row(row1,row3,(row3[1]));

		scaleRow(row2,1.0/row2[2]);

		add_to_row(row2,row1,(row1[2]));
		add_to_row(row2,row3,(row3[2]));

		scaleRow(row3,1.0/row3[3]);

		add_to_row(row3,row1,(row1[3]));
		add_to_row(row3,row2,(row2[3]));

	}
	else{
		scaleRow(row1,1.0/row1[0]);

		add_to_row(row1,row2,(row2[0]));
		add_to_row(row1,row3,(row3[0]));

		scaleRow(row2,1.0/row2[1]);

		add_to_row(row2,row1,(row1[1]));
		add_to_row(row2,row3,(row3[1]));

		scaleRow(row3,1.0/row3[2]);

		add_to_row(row3,row1,(row1[2]));
		add_to_row(row3,row2,(row2[2]));
	}


	// clear column 2,

	// clear column 3,

	// clear column 4 IF column 1 is empty.
}

void correctPos(double row1[4], double row2[4], double row3[4]){
	bool emptyFirstRow{0};
		if(row1[0] == 0){
			if(row2[0] == 0){
				if(row3[0] == 0){
					emptyFirstRow = true;
				}
				else{ // Row 3 not empty
					swapRows(row1,row3);
				}
			}
			else{ //row2[0] not empty
				 swapRows(row1,row2);
			}
		}
		// row 1 is now at the correct position.

		if(emptyFirstRow == true){
			if(row1[1] == 0){
				if(row2[1] == 0){
					swapRows(row1,row3);
				}
				else{
					swapRows(row1,row2);
				}
			}
			// Row1 now at the right position.

			if(row2[2] == 0){
				if(row1[2] == 0){
					swapRows(row2,row3);
				}
				else{
					swapRows(row1,row2);
				}
			}

			if(row3[3] == 0){
				if(row1[3] == 0){
					swapRows(row2,row3);
				}
				else if(row3[1] == 0){
					swapRows(row2,row3);
				}
				else{
					swapRows(row1,row3);
				}
			}
		}
		else{
			if(row2[1] == 0){
				if(row1[1] ==0){
					swapRows(row2,row3);
				}
				else{
					swapRows(row1,row2);
				}
			}

			if(row3[2] == 0){
				if(row1[2] == 0){
					swapRows(row2,row3);
				}
				else if(row3[0] == 0){
					swapRows(row2,row3);
				}
				else{
					swapRows(row1,row3);
				}
			}
		}
}
