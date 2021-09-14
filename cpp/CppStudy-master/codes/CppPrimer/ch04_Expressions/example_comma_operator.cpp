// example: 逗号运算符（p140）

/*
 * 逗号运算符的使用例子，逗号运算符经常被用在for循环当中
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
/*
member-type	definition	notes
value_type	The first template parameter (T)	
allocator_type	The second template parameter (Alloc)	defaults to: allocator<value_type>
reference	value_type&	
const_reference	const value_type&	
pointer	allocator_traits<allocator_type>::pointer	for the default allocator: value_type*
const_pointer	allocator_traits<allocator_type>::const_pointer	for the default allocator: const value_type*
iterator	a random access iterator to value_type	convertible to const_iterator
const_iterator	a random access iterator to const value_type	
reverse_iterator	reverse_iterator<iterator>	
const_reverse_iterator	reverse_iterator<const_iterator>	
difference_type	a signed integral type, identical to:
iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
size_type	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

*/
	vector<int> ivec(10);
    
	vector<int>::size_type cnt = ivec.size();

    
	// 将把从size到1的值赋给ivec的元素
	for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
	{
		ivec[ix] = cnt;
	}

	//----------------------------------------
	
	for (auto i : ivec)
		cout << i << " ";
	cout << endl;

	return 0;
    
}
