# NanoTekSpice

NanoTekSpice is a logic circuit simulator written in C++. It allows you to model digital electronic components and to simulate them by manipulating inputs and outputs.

## 🛠️ Compilation

The project can be compiled with a `Makefile`.
Le projet peut être compilé avec un `Makefile`.

### With Makefile
```sh
make
```
The following rules are available :
- `make re` : recompile the project
- `make clean` : deletes object files
- `make fclean` : deletes object files and executable

## 🚀 Use

Execute NanoTekSpice with a configuration file :
```sh
./nanotekspice circuit.nts
```

### Interactive commands
During execution, several commands are available :
- `exit` : close the program
- `display` : displays the current state of the circuit
- `input=value` : modifies the value of an input (`0`, `1` ou `U` for undefined)
- `simulate` : preforms a simulation cycle
- `loop` : runs the simulation continously until a `CTRL+C`

## 📄 Configuration file format 
A file `.nts` describe the components and the connections of the circuit.

Example :
```
.chipsets:
input a
input b
4071 or
output s

.links:
a:1 or:1
b:1 or:2
or:3 s:1
```

## 🔌 Available components

### Special components
- `input` : Entry control by the user
- `output` : Output of the circuit
- `clock` : Clock signal alternating between `0` et `1` at each simulation
- `true` : Always `1`
- `false` : Always `0`

### Elementary components
- `and` : AND gate
- `or` : OR gate
- `xor` : XOR gate
- `not` : NOT gate

### Advanced components
- `4001` : 4 NOR gate
- `4011` : 4 NAND gate
- `4030` : 4 XOR gate
- `4069` : 6 inverters
- `4071` : 4 OR gate
- `4081` : 4 AND gate

## Example Component and
![image](https://github.com/user-attachments/assets/61bcfc65-b535-4135-840b-d11fa14c90fc)

## Contributors 👥

* **Aleksandra RACINE** - ([Github](https://github.com/Aleksrac))  
* **Hélène HOUPLAIN** - ([Github](https://github.com/Houpsi))  
