#ifndef ITERATOR_H
#define ITERATOR_H
#include <memory>
#include <iostream>


template <class node, class T> class Iterator {
	public:
		Iterator(std::shared_ptr<node> n){
			node_ptr = n;
		}

		std::shared_ptr<T> operator * (){
			return node_ptr->GetObject();
		}

		std::shared_ptr<T> operator -> (){
			return node_ptr->GetObject();
		}
		
		void operator ++ (){
			node_ptr = node_ptr->GetNext();
		}

		Iterator operator ++ (int){
			Iterator iter(*this);
			++(*this);
			return iter;
		}
		bool operator == (Iterator const& i){
			return node_ptr == i.node_ptr;
		}

		bool operator != (Iterator const& i){
			return !(*this == i);
		}
	private:
		std::shared_ptr<node> node_ptr;
	};
#endif
