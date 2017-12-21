#ifndef UTILS_H
#define UTILS_H

#include "commands.h"
#include "../ExtremesAlgorithms/BaseAlgo.h"

constexpr const char * get_algo_by_id( std::size_t id )
{
	switch( id )
	{
	case ALGO_GLOBAL_SEARCH:
		return "Global Search Algorithm";
		break;
	default:
		std::cout << "Wrong id = " << id;
		return "";
		break;
	}
}

IBaseAlgo* create_search_algo( std::size_t id )
{
	IBaseAlgo* ptr = nullptr;
	switch( id )
	{
	case ALGO_GLOBAL_SEARCH:
		ptr = new AlgoGlobSearch{};
		break;
	default:
		std::cout << "Wrong id = " << id;
		break;
	}
	return ptr;
}

#endif
