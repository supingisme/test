#include <iostream>

template <class type>
struct cell
{
	type cellID;
};

typedef struct cell<int> cell_t;

#if 0
template <>
struct CELL<cell_t>
{
	cell_t cell;
};	
#endif

int main()
{
	struct cell<int> cell;	

	return 0;
}
