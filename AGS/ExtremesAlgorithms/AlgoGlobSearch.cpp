#include <vector>
#include <queue>
#include <iostream>
#include "AlgoGlobSearch.h"
#include "..\common\commands.h"

class Compare
{
public:
	bool operator() (const std::pair<double, std::size_t> & left, const std::pair<double, std::size_t> & right)
	{
		// Если характеристики равны то в начале будет характеристика с наименьшим t
		if (left.first == right.first) return left.second > right.second;
		return left.first < right.first;
	}
	bool operator() (const std::pair<double, double> & left, const std::pair<double, double> & right)
	{
		// Если y равны, то в начале будет координата с меньшим x
		if (left.first == right.first) return left.second > right.second;
		return left.first > right.first;
	}
};

using Feature = std::priority_queue<std::pair<double, std::size_t>, std::vector<std::pair<double, std::size_t>>, Compare>;
using Result = std::priority_queue<std::pair<double, double>, std::vector<std::pair<double, double>>, Compare>;



/*
*            Zi - Zi-1
*   M = max| --------- |
*            Xi - Xi-1
*/
static inline auto get_M( const double z_l, const double z_r, const double x_l, const double x_r )
{
	return std::abs((z_r - z_l) / (x_r - x_l));
}

/*
*                        (Zi - Zi-1)^2
*   R = m*(Xi - Xi-1) +  -------------  - 2*(Xi + Xi-1)
*                        m*(Xi - Xi-1)     
*/
static inline auto get_R(const double z_l, const double z_r, const double x_l, const double x_r, const double m)
{
	return m * (x_r - x_l) + (std::pow((z_r - z_l), 2) / (m*(x_r - x_l))) - 2 * (z_r + z_l);
}

static inline auto get_max_R(const std::vector<double> & z, const std::vector<double> & x, const double m)
{
	Feature R;
	for( std::size_t i = 1; i < z.size(); ++i )
		R.push(std::make_pair(get_R(z[i - 1], z[i], x[i - 1], x[i], m), i));
	return R.top();
}



void AlgoGlobSearch::run(const double left, const double right, BaseFunc func)
{
	std::size_t k{ 1 };;
	std::vector<double> z, x;
	std::priority_queue<double> m;
	Result res;
	z.reserve(10000);
	x.reserve(10000);

	z.push_back(func(left));
	z.push_back(func(right));
	x.push_back(left);
	x.push_back(right);

	while (std::abs(x[k] - x[k-1]) > epsilon)
	{
		m.push(get_M( z[k-1], z[k], x[k-1], x[k] ));

		auto M = m.top();
		double m_cur = M ? r_param * M : 1;
		auto R = get_max_R(z, x, m_cur);
		auto t = R.second;
		x.push_back(0.5*(x[t] + x[t - 1]) - ((z[t] - z[t - 1]) / (2.0 * m_cur)));
		z.push_back(func(x.back()));
		++k;
		res.push(std::make_pair(z.back(), x.back()));
	}

	std::cout << "Result is f(x) = " << res.top().first
		      << " where x =" << res.top().second
		      << " take of iterations k = " << k << std::endl;
}