#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>
#include <iterator>

template <class Type>
class MutantStack: public std::stack<Type, std::deque<Type> >
{
	public:
		typedef typename std::stack<Type, std::deque<Type> >::container_type::iterator iterator;
	
		MutantStack(): std::stack<Type, std::deque<Type> >() {}
		MutantStack( const MutantStack & src ) : std::stack<Type, std::deque<Type> >( src ) {}
		MutantStack & operator = ( const MutantStack & rhs )
		{
			if (this == &rhs )
				return (*this);
			this->c = rhs.c;
			return (*this);
		}
	
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
};

#endif
