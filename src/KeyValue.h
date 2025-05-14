/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 *
 */

#ifndef _KeyValue_H
#define _KeyValue_H

#include <iostream>

using namespace std;

// ------------------------------------------------------
// Template specification
// ------------------------------------------------------

template <class Key, class Value>		// Key is an ordered type
class KeyValue {
private:
	Key key;
	Value value;
public:
	// PRE: ---
	// DES: Default constructor
	// COM: O(1)
	KeyValue ();

	// PRE: "key" correctly initialized
	// DES: Parameterized constructor 1.
	//		Creates a new KeyValue object setting only its key.
	// COM: O(1)
	KeyValue ( Key key );

	// PRE: "key" and "value" correctly initialized
	// DES: Parameterized constructor 2.
	//		Creates a new KeyValue object setting both its key and value.
	// COM: O(1)
	KeyValue ( Key key, Value value);

	// PRE: ---
	// DES: returns this->key.
	// COM: O(1)
	Key   getKey () const;

	// PRE: ---
	// DES: returns this->value.
	// COM: O(1)
	Value getValue () const;

	// PRE: "kv" correctly initialized
	// DES: returns true if "this" is lower than "kv" (comparing the keys of both objects).
	// COM: O(1)
	bool  operator <  ( const KeyValue &kv ) const;

	// PRE: "kv" correctly initialized
	// DES: returns true if "this" is greater than "kv" (comparing the keys of both objects).
	// COM: O(1)
	bool  operator >  ( const KeyValue &kv ) const;

	// PRE: "kv" correctly initialized
	// DES: returns true if "this" is equal to "kv" (both have the same key).
	// COM: O(1)
	bool  operator == ( const KeyValue &kv ) const;

	// PRE: "kv" correctly initialized
	// DES: returns true if "this" is different from "kv" (their keys are different).
	// COM: O(1)
	bool  operator != ( const KeyValue &kv ) const;

	// PRE: "kv" correctly initialized
	// DES: copies the key and value of "kv" to the key and value of "this"
	//		(similar to a copy constructor).
	// COM: O(1)
	void  operator =  ( const KeyValue &kv );
};

// ------------------------------------------------------
// Template implementation
// ------------------------------------------------------

template<class Key, class Value>
KeyValue <Key, Value>::KeyValue ( ) {
}

template<class Key, class Value>
KeyValue <Key, Value>::KeyValue ( Key key ) {
	this->key = key;
}

template<class Key, class Value>
KeyValue <Key, Value>::KeyValue ( Key key, Value value ) {
	this->key   = key;
	this->value = value;
}

template<class Key, class Value>
Key KeyValue <Key, Value>::getKey ( ) const {
	return this->key;
}

template<class Key, class Value>
Value KeyValue <Key, Value>::getValue ( ) const {
	return this->value;
}

template<class Key, class Value>
bool KeyValue <Key, Value>::operator < ( const KeyValue &kv ) const {
	return this->key < kv.key;
}

template<class Key, class Value>
bool KeyValue <Key, Value>::operator > ( const KeyValue &kv ) const {
	return this->key > kv.key;
}

template<class Key, class Value>
bool KeyValue <Key, Value>::operator == ( const KeyValue &kv ) const {
	return this->key == kv.key;
}

template<class Key, class Value>
bool KeyValue <Key, Value>::operator != ( const KeyValue &kv ) const {
	return this->key != kv.key;
}

template<class Key, class Value>
void KeyValue <Key, Value>::operator = ( const KeyValue &kv ) {
  this->key = kv.key;
  this->value = kv.value;
}

#endif /* _KeyValue_H */

/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 *
 */
