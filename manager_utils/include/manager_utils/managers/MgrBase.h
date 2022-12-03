#ifndef MANAGER_UTILS_INCLUDE_MANAGER_UTILS_MANAGERS_MGRBASE_H_
#define MANAGER_UTILS_INCLUDE_MANAGER_UTILS_MANAGERS_MGRBASE_H_
//C system includes

//C++ system includes


//3rd-party includes

//Own includes

//Forward Declaration

enum{
	DRAW_MGR_IDX,
	RSRC_MGR_IDX,
	TIMER_MGR_IDX,
	MANAGERS_COUNT
};



//since we are declaring Singleton - we are making a class with forbidden copy,assingnment,init constructors and only 2 pure virtual methods that point at nullptr
//But since we inherrit it - the two pure virtual pointers will point at the overriten methods in the inherited class. This way we create single global instance of this class.
class MgrBase {
public:

	MgrBase() = default;	//we have to set the base class constructor as well to be default if we want to use the default in the inherited
	virtual ~MgrBase() = default;	//making the destructor virtual will make automatically all other memberfunctions virtuals

	MgrBase(const MgrBase& other) = delete;		//forbid the copy constructor
	MgrBase(MgrBase&& other) = delete;			//forbid the copy and move assignment operators

	MgrBase& operator=(const MgrBase& other) = delete;	//copy-assignment operator
	MgrBase& operator=(MgrBase&& other) = delete;	//move-assignment operator

	virtual void deinit() = 0;
	virtual void process() = 0;
};

#endif /* MANAGER_UTILS_INCLUDE_MANAGER_UTILS_MANAGERS_MGRBASE_H_ */
