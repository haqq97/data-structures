#ifndef NODE
#define NODE

template<class Type>
struct SLinkedListNode {
	//attributes
	Type elem;
	SLinkedListNode* next;

	// Default constructor
	SLinkedListNode(); 
	//parametrized constructor
	SLinkedListNode(Type data); 
	~SLinkedListNode();
};

#endif
