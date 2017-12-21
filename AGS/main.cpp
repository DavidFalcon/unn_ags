#include <iostream>
#include <memory>
#include <chrono>
#include "ExtremesAlgorithms\AlgoGlobSearch.h"
#include "common\utils.h"

void get_imput_param( std::size_t & type_algo, double & left, double & right )
{
	std::cout << "Choose an algorithm\n"
		      << "0 : Global search algorithm\n";
	std::cin >> type_algo;
	std::cout << "Enter boundary constraints\n";
	std::cin >> left >> right;
}

double func( double x )
{
	return x * x + 5*x + 10;
}

using SearchExtremes = std::unique_ptr<IBaseAlgo>;


int main( int argc, char ** argv )
{
	std::cout << "Welcome a distant traveler!\n";
			  
	std::size_t type_algo{0};
	double left{0}, right{0};
	
	get_imput_param( type_algo, left, right );

	SearchExtremes algo( create_search_algo( type_algo ) );

	auto start = std::chrono::system_clock::now();

	algo->run( left, right, func );
	
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end-start;

	std::cout << "Algorithm " << get_algo_by_id( type_algo )
			  << " took time " << diff.count() << std::endl;

	return 0;
}