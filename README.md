# Secured
# {EPITECH} | First year | Elementary Programming in C

## Description 
The goal of this project is to securing and storing certain information. To achieve this, the program uses a custom hash function to hash the provided data.
The key, is the values you wanted to hash and storing, and the value 
- **Key:** The unique identifier for the information you want to hash and store.
- **Value:** The data you want to store.

Users can perform the following operations:

- Add a key-value pair: `ht_insert(hash_table, "key", "value")`
- Display the contents: `dump(hash_table)`
- Delete a specific key: `ht_delete(hash_table, key)`
- Search for a key: `ht_search(hash_table, key)`
- Delete everything stored in the program: `delete_hashtable(hash_table)`



## Get started
### Compile the programm

Navigate to the root of the repository in your terminal.  
Run ```make``` to build the static library, creating a compiled program.
Use ```make clean``` to delete generated ```.o``` files.

### Testing 
Run ```make run_tests``` to execute program tests.

By following these steps, you can compile and test the Secured program effectively.

* **Hélène HOUPLAIN** - ([Github](https://github.com/Houpsi)) and **Aleksandra RACINE** - ([Github](https://github.com/Aleksrac))
