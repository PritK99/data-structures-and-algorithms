# Hashing

Hashing is a technique where we use a data structure to store the mapping from one entity to other.

A hash table is an implementation of hashing by map or set by any method.```unordered_set``` and ```unordered_map``` are examples of set and map in ``c++``

## Direct Addressing

The direct address approach requires that the hash function is a one-to-one mapping for each K integer. Such a function is known as a perfect hashing function: it maps each key to a distinct integer within some manageable range and enables us to trivially build an O(1) search time table. 

The problem however is the amount of memory it requires to hold this hash table. There might be several buckets in this case which might not be used throught the execution, but they still hold memory.

## Chaining

The problem with direct addressing is that the memory required is quite high. Rather, we would want an implementation which would use only hashing for the objects present in our universe.

For example, if we have two numbers say {12,999}, then rather than creating hash table for 1000 numbers, we should just create it for 2 numbers. For this, we require some function to convert the numbers to different numbers, say here {2,9} if we consider hash buckets formed of last digits of number. This is done by hash function.

However, this may lead to collisions according to pigeonhole principle. This is because the cardinality of the hash buckets is finite, and we wish to fit all objects in our universe in those buckets. Thus we make use of chaining to avoid these collisions. Linked List is the underlying data structure used in chaining.