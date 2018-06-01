#ifndef IREMOVECRITERIAALL_H
#define IREMOVECRITERIAALL_H
#include "IremoveCriteria.h"

template <class T> class IremoveCriteriaALL : public IRemoveCriteria<T>{
	public:
		IremoveCriteriaALL() {};
		bool isIt(T* value) override{
			return true;
		}
private:
};

#endif