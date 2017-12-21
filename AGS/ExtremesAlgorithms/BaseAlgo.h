#ifndef BASEALGO_H
#define BASEALGO_H

#include <functional>

using BaseFunc = std::function<double(double)>;

class IBaseAlgo
{
public:
	IBaseAlgo() = default;
	virtual ~IBaseAlgo() = default;
	IBaseAlgo( const IBaseAlgo & ) = default;
	IBaseAlgo( IBaseAlgo && ) = default;
	IBaseAlgo & operator=( const IBaseAlgo & ) = default;
	IBaseAlgo & operator=( IBaseAlgo && ) = default;

	virtual void run( const double left, const double right, BaseFunc func ) = 0; // метод выполняет поиск экстремума
};

#endif