// ConsoleApplication34.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;



class find_peak_1D{
public:
	find_peak_1D(){
		cout << "input array size!" << endl;
		int arr_size;
		cin >> arr_size;

		cout << "input array element sequence!" << endl;
		for (int i = 0; i < arr_size; i++){
			double ele;
			cin >> ele;
			arr.push_back(ele);
		};

	};


	int quick_find_1d_peak(int l,int h){
		int high = h;
		int low = l;
		int mid = low+( high-low)/2;
	
		if (
		

			((arr.at(mid - 1)< arr.at(mid)) || (mid == 0))

			&&

			((arr.at(mid)    > arr.at(mid + 1)) || (mid == arr.size() - 1))

		){
			
			return mid;
		}
		
		else if (arr.at(mid - 1)< arr.at(mid) || mid == 0){

			return quick_find_1d_peak(low, mid - 1);
		}
		else{
			 return quick_find_1d_peak(mid+1, high );
		}

		return -1;
	}
	void print_1D_arr(){
	
		for (int i = 0; i < arr.size(); i++){
			
			cout << arr[i] << " ";
		
		
		}
		cout << endl;
	}

	vector<double> arr;//1D
};

class find_peak_2D{
public:
	find_peak_2D(){

		
	cout << "input 2D array row size! ex: 5" << endl;

	cin >> row_s;
	row_s+=2;

	cout << "input 2D array col size! ex: 5" << endl;
	cin >> col_s;
	col_s+=2;
	cout << "input 2D array element! and element value can not be negative !! " << endl;
	cout << "ex:" << endl;
	cout << "1 3 2 1 1" << endl;
	cout << "6 9 8 1 1" << endl;
	cout << "3 5 4 1 1" << endl;
	cout << "1 1 1 1 1" << endl;
	cout << "1 1 1 1 1" << endl;



	cout << "input array element sequence!" << endl;
	for (int i = 0; i < row_s; i++){
	vector<int> arr_tmp;

	for (int j = 0; j < col_s; j++){



		//cout << "row: " << i << " sequence  " << endl;
		int int_t;
		if (i == 0 || j == 0 || i == row_s - 1 || j == col_s-1  ){
			int_t = 0;
		}
		else{
			cin >> int_t;
		}
		arr_tmp.push_back(int_t);
	}
	arr.push_back(arr_tmp);
	}

	
	/*	row_s = 3;
		col_s = 3;
		vector<int> arr_tmp1;
		arr_tmp1.push_back(1);
		arr_tmp1.push_back(3);
		arr_tmp1.push_back(2);

		vector<int> arr_tmp2;
		arr_tmp2.push_back(7);
		arr_tmp2.push_back(9);
		arr_tmp2.push_back(8);
		vector<int> arr_tmp3;
		arr_tmp3.push_back(4);
		arr_tmp3.push_back(6);
		arr_tmp3.push_back(5);
		arr.push_back(arr_tmp1);
		arr.push_back(arr_tmp2);
		arr.push_back(arr_tmp3);*/
	
	};
			

	void print_2D_arr(int r1, int r2, int c1, int c2){

		cout << "arr visual:　"<<endl;
		for (int i = r1; i <= r2; i++){
			
			for (int j = c1; j <= c2; j++){


				cout << arr[i][j] <<" ";
				
			}
			cout <<  endl;
		}
		cout << endl;
	};


	int quick_find_2d_peak( int i, int j, int c, int d) {
		int m1 = (i + j) / 2;
		int m2 = (c + d) / 2;
		int max = 0;
		int a, b;             /* store the dimension of temporary max */

	
		
		/* find the maximum in (m, a) */
		
		for (int x = c; x <= d; x++) {
			if (arr[m1][x] > max) {
				max = arr[m1][x];
				a = m1; b = x;
			}
		}
		for (int y = i; y <= j; y++) {
			if (arr[y][m2] > max) {
				max = arr[y][m2];
				a = y; b = m2;
			}
		}//a: rows, b: cols
		//cout << "m1 m2: " << m1 << " " << m2 << endl;
		//cout<<"max of row, col: "<< a <<" "<< b<<endl; // array 中間切兩條線 
		//cout << "max_v from 2 mid line: " <<arr[a][b]  << endl; // array 中間切兩條線 

		//if its a peak then return

		

			if (max >= arr[a + 1][b] && max >= arr[a - 1][b] && max >= arr[a][b + 1] && max >= arr[a][b - 1]) {
			    //cout<<"(rows, cols) = ("<<a<<", "<<b<<") is a peak number, which value is ";
				g_peak_r=a;
				g_peak_c=b;
				print_peak_location();
				return max;
			}
			else if (max<arr[a + 1][b]) {
				if (b<m2) {
					//cout<<"leftdown"<<m1+1<<" "<<j-1<<" "<<c+1<<" "<<m2-1<<endl;
					print_2D_arr(m1 + 1, j, c, m2 - 1);
					return quick_find_2d_peak(  m1 + 1, j, c, m2 - 1);		//左下
				}
				else{
					//cout<<"rightdown"<<m1+1<<" "<<j-1<<" "<<m2+1<<" "<<d-1<<endl;
					print_2D_arr(m1 + 1, j, m2 + 1, d);
					return quick_find_2d_peak(  m1 + 1, j, m2 + 1, d);		//右下
				}
			}
			else if (max<arr[a - 1][b]) {
				if (b<m2){
				
					//cout << i << " " << m1 - 1 << " " << c << " " << m2 - 1 << endl;
					print_2D_arr(i, m1 - 1, c, m2 - 1);
					return quick_find_2d_peak(  i, m1 - 1, c, m2 - 1);		//左上

				}
				else {
					//cout<<"rightup"<<i+1<<" "<<m1-1<<" "<<m2+1<<" "<<d-1<<endl;
				
					print_2D_arr(i, m1 - 1, m2 + 1, d);
					return quick_find_2d_peak(  i, m1 - 1, m2 + 1, d);		//右上

				}
			}
			else if (max<arr[a][b + 1]) {
				if (a<m1) {
					//cout<<"rightup"<<i+1<<" "<<m1-1<<" "<<m2+1<<" "<<d-1<<endl;
					print_2D_arr(i, m1 - 1, m2 + 1, d);
					return quick_find_2d_peak(  i, m1 - 1, m2 + 1, d);		//右上
				}
				else {
					//cout<<"rightdown"<<m1+1<<" "<<j-1<<" "<<m2+1<<" "<<d-1<<endl;
					print_2D_arr(m1 + 1, j, m2 + 1, d);
					return quick_find_2d_peak(  m1 + 1, j, m2 + 1, d);		//右下
				}
			}
			//else (max<arr[a][b-1]) {
			else {
				if (a<m1) {
					//cout<<"leftup"<<i+1<<" "<<m1-1<<" "<<c+1<<" "<<m2-1<<endl;
					print_2D_arr(i, m1 - 1, c, m2 - 1);
					return quick_find_2d_peak(  i, m1 - 1, c, m2 - 1);		//左上
				}
				else {
					//cout<<"leftdown"<<m1+1<<" "<<j-1<<" "<<c+1<<" "<<m2-1<<endl;
					print_2D_arr(m1 + 1, j, c, m2 - 1);
					return quick_find_2d_peak(  m1 + 1, j, c, m2 - 1);		//左下
				}
			}
		

		return -1;
	};
	void print_peak_location(){
		cout << "peak location:" << endl
			<< "row index: " << g_peak_r
			<< " col index: " << g_peak_c
			<<endl
			
			;
	}

	

	int row_s;
	int col_s;

	int g_peak_r;
	int g_peak_c;
	vector< vector<int> > arr;//2D
};

//template<class T>


int main()
{
	int homework_type;
	cout <<"HW01 (a) find_1D_peak  press 1" << endl;
	cout << "HW01 (b) find_2D_peak press 2" << endl;
	cin >> homework_type;
	if (homework_type==1){

		find_peak_1D ob;
		cout << "1D peak index: " << ob.quick_find_1d_peak(0, ob.arr.size() - 1) << endl;;
		cout << "1D peak value: " << ob.arr[ob.quick_find_1d_peak(0, ob.arr.size() - 1)] << endl;;
	}
	else if (homework_type==2){

		find_peak_2D ob2;
		//ob2.print_2D_arr(1, ob2.row_s - 1, 1, ob2.col_s - 1);
		ob2.print_2D_arr(0, ob2.row_s-1 , 0, ob2.col_s-1 );
		//quick_find_1d_peak(&arr);
		cout << "peak value: "<< ob2.quick_find_2d_peak(1, ob2.row_s-1, 1, ob2.col_s-1) << endl;;
	}
	else{
		cout << "wrong input type" << endl;
	}
	system("pause");

	return 0;
}


