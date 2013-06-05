#include <QCoreApplication>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

#define SIZE_OF_ARRAY 9

void ReinitializeArray( int array[] )
{
	for( int i = SIZE_OF_ARRAY, j = 0 ; i > 0 ; i-- )
	{
		array[ j ] = rand() % 100 + 1;
		j++;
	}
}
void printArray( int array[] );
void BubbleSort( int array[] );
void SelectionSort( int array[] );
void InsertionSort( int array[] );
void ShellSort( int array[] );
void CombSort( int array[] );
void MergeSort(int numbers[], int temp[], int array_size);
void msort(int numbers[], int temp[], int left, int right);
void Merge(int numbers[], int temp[], int left, int mid, int right);
void swap( int *x, int *y );
void HeapSort( int a[] );
void QuickSort( int array[], int left, int right );
int main(int argc, char *argv[])
{
	srand (time(NULL));
	int array[SIZE_OF_ARRAY] = { 121 , 9 , 5 , 4 , 3 , 6 , 120 , 98 , 17 };
	//BubbleSort
	std::cout << "Bubble Sort" << std::endl;
	BubbleSort( array );
	ReinitializeArray( array );
	system("PAUSE");

	//Selection Sort
	system("CLS");
	std::cout << "Selection Sort" << std::endl;
	SelectionSort( array );
	ReinitializeArray( array );
	system("PAUSE");

	//Insertion Sort
	system("CLS");
	std::cout << "Insertion Sort" << std::endl;
	InsertionSort( array );
	ReinitializeArray( array );
	system("PAUSE");

	//Shell Sort
	system("CLS");
	std::cout << "Shell Sort" << std::endl;
	ShellSort( array );
	ReinitializeArray( array );
	system("PAUSE");

	//Comb Sort
	system("CLS");
	std::cout << "Comb Sort" << std::endl;
	CombSort( array );
	ReinitializeArray( array );
	system("PAUSE");

	//Merge Sort
	system("CLS");
	std::cout << "Merge Sort" << std::endl;
	int tempArray[SIZE_OF_ARRAY];
	MergeSort( array, tempArray, SIZE_OF_ARRAY);
	ReinitializeArray( array );
	system("PAUSE");

	//Heap Sort
	system("CLS");
	std::cout << "Heap Sort" << std::endl;
	HeapSort( array );
	ReinitializeArray( array );
	system("PAUSE");

	//Quick Sort
	system("CLS");
	std::cout << "Quick Sort" << std::endl;
	QuickSort( array , 0 , SIZE_OF_ARRAY - 1 );
	printArray( array );
	ReinitializeArray( array );
	return 0;
}
void printArray( int array[] )
{
	for ( int i = 0 ; i < SIZE_OF_ARRAY ; i++ )
	{
		std::cout << array[ i ] << std::endl;
	}
}
void BubbleSort( int array[] )
{
	for( int j = 0 ; j < SIZE_OF_ARRAY ; j++ )
	{
		for( int i = 0 ; i < ( SIZE_OF_ARRAY - 1 ) ; i++ )
			if( array[ i ] > array[ i + 1 ] )
			{
				int temp = array[ i ];
				array[ i ] = array[ i + 1 ];
				array[ i +1 ] = temp;
			}
	}
	printArray( array );
}
void SelectionSort( int array[] )
{
	for( int i = 0 ; i < SIZE_OF_ARRAY ; i++ )
	{
		int minVal = array[ i ];
		int posOfMinVal = i;
		for ( int j = i ; j < SIZE_OF_ARRAY ; j++ )
			if ( array[ j ] < minVal )
			{
				minVal = array[ j ];
				posOfMinVal = j;
			}
		array[ posOfMinVal ] = array[ i ];
		array[ i ] = minVal;
	}
	printArray( array );
}
void InsertionSort( int array[] )
{
	int key;
	for ( int i = 1,j = 1 ; i < SIZE_OF_ARRAY ; i++ )
	{
		key = array[ i ];
		for ( j = i - 1 ; ( i >= 0 ) && (array[ j ] > key); j-- )
			array[ j +1 ] = array[ j ];
		array[ j + 1 ] = key;
	}
	printArray( array );
}
void ShellSort( int array[] )
{
	int i, temp, flag = 1;
	int d = SIZE_OF_ARRAY;
	while( flag || (d > 1) )	  // boolean flag (true when not equal to 0)
	{
		flag = 0;		   // reset flag to 0 to check for future swaps
		d = ( d + 1 ) / 2;
		for ( i = 0 ; i < ( SIZE_OF_ARRAY - d ); i++ )
		{
			if ( array[ i + d ] < array[ i ] )
			{
				temp = array[ i + d ];	  // swap positions i+d and i
				array[ i + d ] = array[ i ];
				array[ i ] = temp;
				flag = 1;				  // tells swap has occurred
			}
		}
	}
	printArray( array );
}
int newGap(int gap)
{
	gap = ( gap * 10 ) / 13;
	if ( gap == 9 || gap == 10 )
		gap = 11;
	if ( gap < 1 )
		gap = 1;
	return gap;
}
void CombSort( int array[] )
{
	int gap = SIZE_OF_ARRAY;
	while(true)
	{
		gap = newGap( gap );
		bool swapped = false;
		for ( int i = 0 ; i < SIZE_OF_ARRAY - gap ; i++ )
		{
			int j = i + gap;
			if ( array[ i ] > array  [j] )
			{
				int temp = array[ i ];
				array[ i ] = array[ i + gap ];
				array[ i + gap ] = temp;
				swapped = true;
			}
		}
		if ( gap == 1 && !swapped )
			break;
	}
	printArray( array );
}
void MergeSort( int numbers[], int temp[], int array_size )
{
	msort( numbers, temp, 0, array_size - 1 );
	printArray( numbers );
}
void msort( int numbers[], int temp[], int left, int right )
{
	int mid;
	if ( right > left )
	{
		mid = ( right + left ) / 2;
		msort( numbers, temp, left, mid );
		msort( numbers, temp, ( mid + 1 ), right );
		Merge( numbers, temp, left, ( mid + 1 ), right );
	}
}
void Merge( int numbers[], int temp[], int left, int mid, int right )
{
	int i, left_end, num_elements, tmp_pos;
	left_end = ( mid - 1 );
	tmp_pos = left;
	num_elements = ( right - left + 1 );
	while( ( left <= left_end ) && ( mid <= right ) )
	{
		if ( numbers[ left ] <= numbers[ mid ] )
		{
			temp[ tmp_pos ] = numbers[ left ];
			tmp_pos += 1;
			left += 1;
		}
		else
		{
			temp[ tmp_pos ] = numbers[ mid ];
			tmp_pos += 1;
			mid += 1;
		}
	}
	while ( left <= left_end )
	{
		temp[ tmp_pos ] = numbers[ left ];
		left += 1;
		tmp_pos += 1;
	}
	while ( mid <= right )
	{
		temp[ tmp_pos ] = numbers[ mid ];
		mid += 1;
		tmp_pos += 1;
	}
	//modified
	for ( i = 0 ; i < num_elements ; i++ )
	{
		numbers[ right ] = temp[ right ];
		right -= 1;
	}
}
void swap( int *x, int *y )
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void HeapSort( int a[] )
{
	int i, s, f, n = SIZE_OF_ARRAY;
	for( i = 1 ; i < n ; ++i )
	{
		s = i;
		f = ( s - 1 ) / 2;
		while( a[ f ] < a[ s ] )
		{
			swap( &a[ f ] , &a[ s ] );
			s = f;
			if( s == 0 )
				break;
			f = ( s - 1 ) / 2;
		}
	}
	for( i = n - 1 ; i >= 1 ; --i )
	{
		swap( &a[ 0 ] , &a[ i ] );
		f = 0;
		s = 1;
		if( i == 1 )
			break;
		if( i > 2 )
			if( a[ 2 ] > a[ 1 ] )
				s=2;
		while( a[ f ]< a[ s ] )
		{
			swap( &a[ f ] , &a[ s ] );
			f = s;
			s = 2 * f + 1;
			if( i > s + 1 )
				if( a[ s + 1 ] > a[ s ] )
					s = s + 1;
			if ( s >= i )
				break;
		}
	}
	printArray( a );
}
void QuickSort( int array[], int left, int right )
{
	int i = left, j = right;
	int tmp;
	int pivot = array[ ( left + right ) / 2 ];
	/* partition */
	while ( i <= j )
	{
		while ( array[ i ] < pivot )
			i++;
		while ( array[ j ] > pivot )
			j--;
		if ( i <= j )
		{
			tmp = array[ i ];
			array[ i ] = array[ j ];
			array[ j ] = tmp;
			i++;
			j--;
		}
	};
	/* recursion */
	if ( left < j )
		QuickSort( array, left, j );
	if ( i < right )
		QuickSort( array, i, right );
}


/*int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	
	return a.exec();
}*/
