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

## Hash functions

Hash Functions are responsible for mapping of objects to [1,m] where m is cardinality of hash table. Thus, we need to choose our hash function such that,

* It doesn't require lot of computation to calculate the hash value
* Objects are evenly distributed 

One of the possible hash function that satisfies above conditions is to randomly assign hash value. However this is non deterministic. But this does indicate that random choice is indeed helpful, like choosing random pivot in quick sort. Hence we use the idea of randomness and dynamic array and create hash table using universal family of hash function.

### Universal family of hash functions

![image](https://github.com/PritK99/data-structures-and-algorithms/assets/103832825/245210cb-a723-440c-81ce-85fea08e6e4b)


Consider U as finite universe of all objects. For eg. in case of phone numbers, U represents all possible phone numbers. H is the hash function we randomly choose from the universal hash function family. This function H maps U to V, where V is hash table with cardinality n.

### Hashing Integers

![image](https://github.com/PritK99/data-structures-and-algorithms/assets/103832825/4df1e760-5fc3-42e1-ae09-128122389681)


