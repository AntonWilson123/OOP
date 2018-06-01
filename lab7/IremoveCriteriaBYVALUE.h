#ifndef IREMOVECRITERIABYVALUE_H
#define IREMOVECRITERIABYVALUE_H

#include "IremoveCriteria.h"

template <class T> class IremoveCriteriaBYVALUE : public IRemoveCriteria<T>{
	public:
		IremoveCriteriaBYVALUE(T&& value) : _value(value) {};
		bool isIt(T* value) override{
			return _value==*value;
		}		
	private:
		T _value;
};
#endif