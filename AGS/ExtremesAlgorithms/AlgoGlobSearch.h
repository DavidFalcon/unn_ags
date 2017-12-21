#ifndef ALGOGLOBSEARCH_H
#define ALGOGLOBSEARCH_H

#include "BaseAlgo.h"

class AlgoGlobSearch : public IBaseAlgo
{
public:
	AlgoGlobSearch() = default;
	virtual ~AlgoGlobSearch() = default;
	AlgoGlobSearch(const AlgoGlobSearch &) = default;
	AlgoGlobSearch(AlgoGlobSearch &&) = default;
	AlgoGlobSearch & operator=(const AlgoGlobSearch &) = default;
	AlgoGlobSearch & operator=(AlgoGlobSearch &&) = default;

	virtual void run( const double left, const double right, BaseFunc func );
};

#endif
